#include "driver/ledc.h"
#include "esp_err.h"
#include "esp_log.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"




#include "mpu6050.h"

#include "pin_defs.h"
#include "utils.h"




// STEP and DIRECTION output pins for stepper motor driver.
static const gpio_num_t step_pin = GPIO_NUM_16;
static const gpio_num_t direction_pin = GPIO_NUM_17;

static const uint32_t update_period = 30; // milliseconds to wait between updates

//speed limitations of stepper motor in steps per sefind_fcond
static const int32_t max_freq = 1200;
static const int32_t min_freq = 20;


//finds freq
float find_freq(float freq, float freq_change, int32_t update_period)
{
    freq = freq + (freq_change*update_period/1000);
    return freq;
}

//sets freq_current
void set_freq(ledc_mode_t speed_mode, ledc_timer_t timer_num, float freq)
{
    if ((int)abs(freq) < min_freq)
    {
        gpio_set_level(step_pin, 1);
    }
	else if ((int)abs(freq) > max_freq)
	{
		ledc_set_freq(speed_mode, timer_num, max_freq);
	}
    else
    {
        ledc_set_freq(speed_mode, timer_num, (int)abs(freq));
    }   
}

//finds and changes direction 
void set_direction(float freq)
{
    int direction_current = (freq > 0);
    gpio_set_level(direction_pin, direction_current);
}





float mpu_offset[2] = {0.0f, 0.0f};


static const char *TAG = "mpu6050";

// constants related to system (assumed for now)
static const float radius = 0.6; // pulley radius in cm
static const int m_c = 240;     // mass of cart in gm
static const int m_p = 1670;     // maass of pendulum in gm
// static const int l_p = 50;   	// length of pendulum in cm
// static const float g = 980;     // acc due to gravity in cm/s^2

float k[4] = {-84080 , -53007, -18253000,  -4054000};   // value of K matrix I got from octave for theses conditions


//takes average of first 100 readings to find initial theta
// float initial_theta(float *mpu_offset)
// {
// 	int16_t acce_raw_value[BUFF_SIZE / 2], gyro_raw_value[BUFF_SIZE / 2];
// 	float prev_theta = 0;
// 	for (int i = 0; i < 100; i++)
// 	{
// 		float theta[2];
// 		complementary_filter(acce_raw_value, gyro_raw_value, theta, mpu_offset);
// 		prev_theta = prev_theta + theta[0];
// 		vTaskDelay(10 / portTICK_PERIOD_MS);
// 	}
// 	prev_theta = prev_theta/100;
// 	prev_theta = prev_theta*M_PI/180;
// 	if (prev_theta < 0)
// 	{
// 		prev_theta = 2*M_PI + prev_theta;
// 	}
// 	return prev_theta;
// }

//finds position of cart
float new_x(float prev_pos,float linear_vel,float freq, uint32_t update_period)
{
	float x;
	x = prev_pos + linear_vel*update_period/1000;
	return x;
}

//finds velocity of cart
float new_x_dot(float freq)
{
	float x_dot;
	if (abs(freq) > min_freq && abs(freq) < max_freq)
	{
		x_dot = ((int)freq)*M_PI*radius/100;
	}
	else if(abs(freq) > max_freq)
	{
		if (freq > 0)
		{
			x_dot = max_freq*M_PI*radius/100;
		}
		else
		{
			x_dot = -max_freq*M_PI*radius/100;
		}	
	}
	else
	{
		x_dot = 0;
	}
	return x_dot;
}

//finds new angular pos
float new_theta(float *mpu_offset)
{
	int16_t acce_raw_value[BUFF_SIZE / 2], gyro_raw_value[BUFF_SIZE / 2];
	float buffer[2];
	float theta;
	complementary_filter(acce_raw_value, gyro_raw_value, buffer, mpu_offset);
	theta = M_PI + buffer[0]*M_PI/180;
	
	return theta;
}

//finds angular vel
float new_theta_dot(float theta, float prev_theta, uint32_t update_period)
{
    float theta_dot = ((theta - prev_theta)*1000)/update_period;
    return theta_dot;
}

//finds linear acc
float acceleration(float x, float x_dot, float th, float th_dot, float k[], float state_setpoint[])
{
	float u = -(k[0]*(x - state_setpoint[0]) + k[1]*(x_dot - state_setpoint[1]) + k[2]*(th - state_setpoint[2]) + k[3]*(th_dot - state_setpoint[3]));
	// printf("K0: %f\t, k1: %f\tk2: %f\tk3: %f\n", k[0], k[1], k[2], k[3]);
	float linear_acc;
	// linear_acc = (-m_p*g*sin(th)*cos(th) - m_p*th_dot*th_dot*l_p*sin(th) + u)/(m_c + m_p*sin(th)*sin(th));
	
	linear_acc = u/(m_c + m_p);
	return linear_acc;
}

//finds freq_change 
float motor_acc(float linear_acc)
{
	float freq_change;
	freq_change = (linear_acc*100) /(M_PI * radius);	
	if (abs(freq_change) < 5000)
	{
		return freq_change;
	}
	else
	{
		if (freq_change < 0)
		{
			freq_change = -5000;
		}
		else if(freq_change > 0)
		{
			freq_change = 5000;
		}
		return freq_change;
	}
}





void app_main()
{
	// some configuration related to ledc
	ledc_timer_config_t ledc_timer = {
        // Running Timer 0 in high speed mode. Not picky about which source
        // clock to use, so let it auto-select.
        .timer_num = LEDC_TIMER_0,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .clk_cfg = LEDC_APB_CLK,

        .freq_hz = 10000,  
        .duty_resolution = LEDC_TIMER_12_BIT,
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        
        .timer_sel  = LEDC_TIMER_0,
        .speed_mode = LEDC_HIGH_SPEED_MODE,

        // Details for this output
        .channel    = LEDC_CHANNEL_0,
        .duty       = 0, // Start out stopped (0% duty cycle)
        .hpoint     = 0,
        .gpio_num   = step_pin,
    };
    ledc_channel_config(&ledc_channel);

	gpio_config_t io_conf = {
        .mode = GPIO_MODE_OUTPUT,
        .intr_type = GPIO_INTR_DISABLE,
        .pull_down_en = 0,
        .pull_up_en = 0,
        .pin_bit_mask = (1ULL<<direction_pin),
    };
    gpio_config(&io_conf);
 
    ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, 2048);
    ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);



    // Enable the MPU-6050 Sensor
    enable_mpu6050();

	//initialising required variables
	float freq_change = 0; // Hz. Speed change per update will not exceed this amount
	float freq = 0; 
	float state_setpoint[4] = {0, 0, M_PI, 0};
	float x = 0, x_dot = 0, th = 0, th_dot = 0; 
	
	float linear_acc = 0;
	float prev_theta = 0;
	int16_t buffer1[BUFF_SIZE / 2], buffer2[BUFF_SIZE / 2];
	float buffer3[2];

	// prev_theta = initial_theta(mpu_offset);
	complementary_filter(buffer1, buffer2, buffer3, mpu_offset);
	th = M_PI + buffer3[0]*M_PI/180;
	prev_theta = th;
	
    
	// starting while loop if mpu readings can be read
    while (read_mpu6050_raw(buffer1, buffer2) == ESP_OK)
    {   
		x_dot = new_x_dot(freq);
		x = new_x(x, x_dot,freq, update_period);
		if (abs(x) > 40)
		// {
		// 	gpio_set_level(step_pin, 1);
		// 	break;
		// }
	
        complementary_filter(buffer1, buffer2, buffer3, mpu_offset);
		th = M_PI + buffer3[0]*M_PI/180;
		

		th_dot = new_theta_dot(th, prev_theta, update_period);
		prev_theta = th;
		
		linear_acc = acceleration(x, x_dot, th, th_dot, k, state_setpoint);
		freq_change = motor_acc(linear_acc);
		freq = find_freq(freq, freq_change, update_period);
		set_direction(freq);

		set_freq(ledc_timer.speed_mode, ledc_timer.timer_num, freq);
        

        printf("x: %f\tx_dot: %f\ttheta: %f\ttheta_dot: %f\tfreq: %f\tfreq_change: %f\tacc: %f\n", x, x_dot, th, th_dot, freq, freq_change, linear_acc);

		vTaskDelay(update_period / portTICK_PERIOD_MS);
    }
	
    ESP_LOGE(TAG, "%s", "Error reading values!");
}
