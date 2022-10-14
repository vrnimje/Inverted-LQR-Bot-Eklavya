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

#define PI  3.14159

// STEP and DIRECTION output pins for stepper motor driver.
static const gpio_num_t step_pin = GPIO_NUM_16;
static const gpio_num_t direction_pin = GPIO_NUM_17;

static const uint32_t update_period = 50; // milliseconds to wait between updates


//speed limitations of stepper motor 
static const int32_t max_freq = 3900;
static const int32_t min_freq = 3;
static const int32_t max_freq_change = 25000;


//finds new frequency
float find_freq(float freq, float freq_change, int32_t update_period)
{
    freq = freq + (freq_change*update_period/1000);
	if (abs(freq) > max_freq)
	{
		if (freq < 0)
		{
			freq = -max_freq;
		}
		else
		{
			freq = max_freq;
		}
	}
	else if (abs(freq) < min_freq)
	{
		freq = 0;
	}
    return freq;
}


//sets freq_current
void set_freq(ledc_mode_t speed_mode, ledc_timer_t timer_num, float freq)
{
	if (abs(freq) < min_freq)
	{
		gpio_set_level(step_pin, 0);
	}
	else 
	{
		ledc_set_freq(speed_mode, timer_num, abs(8*freq));
	}	   
}


//finds and changes direction 
int prev_dir = 0;
void set_direction(float freq)
{
    int direction_current = (freq > 0);
    gpio_set_level(direction_pin, direction_current);

}


// constants related to system (assumed for now)
static const float radius = 0.6; // pulley radius in cm
static const int M = 410;     // mass of cart in gm
static const int m = 160;     // maass of pendulum in gm
float state_setpoint[4] = {0, 0, PI, 0};	// Setpoint to which system needs to move

/*
## State Equations ##
	 
	dy(1,1) = y(2);
  	dy(2,1) = (-(g*sin_theta) + (dy(4,1)*cos_theta))/L;
	dy(3,1) = y(4);
  	dy(4,1) = (-(m*g*cos_theta*sin_theta) + (m*L*sin_theta*((y(2))^2) - f*y(4)) + u)/(M + m*(sin_theta^2));

## State Matrix ##
	
		|	  0 		        1		0	 	 0       | 
	        | (g+(m*g/M))/L		0		0		-f/(M*L) |
		|  	  0 			0 		0		 1       |
		|   -m*g/M 			0 		0 		-f/M     |

## Input Matrix ## 
  	
	    B = |	   0      |
		| -1/(L*(M))      |
		|	   0	  |
		|	 1/(M)	  |

*/


// value of K matrix we get from octave for theses conditions
float k[4] = {-182.50 , -383.36, -963930,  -100520};   


//initialising required variables
float freq_change = 0; 						// Speed change per update will not exceed this amount
float freq = 0; 							// input of motor in steps per second 
float x = 0, x_dot = 0, th = 0, th_dot = 0; // store values of state variables
float linear_acc = 0;						// linear acceleration of cart
float prev_theta = 0;						// previous angular position
	

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
	if (abs(freq) >= min_freq && abs(freq) < max_freq)
	{
		x_dot = ((int)freq)*PI*radius/100;
	}
	else if(abs(freq) >= max_freq)
	{
		if (freq > 0)
		{
			x_dot = max_freq*PI*radius/100;
		}
		else
		{
			x_dot = -max_freq*PI*radius/100;
		}	
	}
	else
	{
		x_dot = 0;
	}
	return x_dot;
}



//finds angular velocity
float new_theta_dot(float theta, float prev_theta, uint32_t update_period)
{
    float theta_dot = ((theta - prev_theta)*1000)/update_period;
    return theta_dot;
}


//finds linear acc
float acceleration(float x, float x_dot, float th, float th_dot, float k[], float state_setpoint[])
{
	float u = -((k[0]*(x - state_setpoint[0])) + (k[1]*(x_dot - state_setpoint[1])) + (k[2]*(th - state_setpoint[2])) + (k[3]*(th_dot - state_setpoint[3])));
	float linear_acc;
	
	linear_acc = u/(M + m);
	return linear_acc;
}


//finds freq_change 
float motor_acc(float linear_acc)
{
	float freq_change;
	freq_change = (linear_acc*100) /(PI * radius);	
	if (abs(freq_change) < max_freq_change)
	{
		return freq_change;
	}
	else
	{
		if (freq_change < 0)
		{
			freq_change = -max_freq_change;
		}
		else if(freq_change > 0)
		{
			freq_change = max_freq_change;
		}
		return freq_change;
	}
}


// Task which finds current angle 
float mpu_offset[2] = {0.0f, 0.0f};
int mpu_started = 0;
void find_theta(float *mpu_offset)
{

	enable_mpu6050();

		int16_t buffer1[BUFF_SIZE / 2], buffer2[BUFF_SIZE / 2];
		float buffer3[2];
		complementary_filter(buffer1, buffer2, buffer3, mpu_offset);
		printf("well\n");
		// read_mpu6050(buffer3, mpu_offset);
		th = PI + buffer3[0]*PI/180;
		prev_theta = th;

		while (read_mpu6050_raw(buffer1, buffer2) == ESP_OK)
		{	
			complementary_filter(buffer1, buffer2, buffer3, mpu_offset);
			// read_mpu6050(buffer3, mpu_offset);
			th = ((PI + buffer3[0]*PI/180)*100)/100;
			mpu_started = 1;	
		}
		printf("could not read from mpu\n");
}

//calculates other state variables from angle and initial position also runs motor to balance pendulum accordingly
void run_motor()
{	
	// some configuration related to ledc
	ledc_timer_config_t ledc_timer = {
        // Running Timer 0 in high speed mode. Not picky about which source
        .timer_num = LEDC_TIMER_0,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .clk_cfg = LEDC_APB_CLK,

        .freq_hz = 10000,  
        .duty_resolution = LEDC_TIMER_10_BIT,
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
	ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, 512);
    ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);
	

	while (1)
	{
		if (mpu_started)
		{
			x_dot = new_x_dot(freq);
			x = new_x(x, x_dot,freq, update_period);	
			th_dot = new_theta_dot(th, prev_theta, update_period);
			prev_theta = th;

			linear_acc = acceleration(x, x_dot, th, th_dot, k, state_setpoint);
			freq_change = motor_acc(linear_acc);
			freq = find_freq(freq, freq_change, update_period);
			
			set_direction(freq);	
			set_freq(ledc_channel.speed_mode, ledc_timer.timer_num, freq);
			
			// printf("x: %f\tx_dot: %f\ttheta: %f\ttheta_dot: %f\tfreq: %f\tfreq_change: %f\tacc: %f\n", x, x_dot, th, th_dot, freq, freq_change, linear_acc);
			
			vTaskDelay(update_period / portTICK_PERIOD_MS);
		}
	}		
	gpio_set_level(step_pin, 1);
}


void app_main()
{
	xTaskCreate(&find_theta, "finding angle", 10000, &mpu_offset, 5, NULL);
	xTaskCreate(&run_motor, "running motor", 10000, NULL, 1, NULL);
}

