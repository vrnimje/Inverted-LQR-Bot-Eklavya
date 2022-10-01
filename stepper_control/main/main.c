#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "esp_err.h"
#include "esp_log.h"
#include "math.h"


// STEP and DIRECTION output pins for stepper motor driver.
static const gpio_num_t step_pin = GPIO_NUM_23;
static const gpio_num_t direction_pin = GPIO_NUM_22;



static const int32_t update_period = 1000; // milliseconds to wait between updates
int32_t accel_limit = 0; // Hz. Speed change per update will not exceed this amount
int32_t speed_current = 0;  // Speed within acceleration limites sent to PWM.


int find_speed(int32_t speed_current, int32_t accel_limit, int32_t update_period)
{
    speed_current = speed_current + round(accel_limit*update_period/1000);
    return speed_current;
}

void app_main(void)
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
    
    
    while (1)
    {
        gpio_set_level(direction_pin, 0);
        ledc_set_freq(ledc_timer.speed_mode, ledc_timer.timer_num, abs(100));
        vTaskDelay(update_period / portTICK_PERIOD_MS);
        gpio_set_level(step_pin, 0);
        vTaskDelay(20 / portTICK_PERIOD_MS);
        gpio_set_level(direction_pin, 1);
        ledc_set_freq(ledc_timer.speed_mode, ledc_timer.timer_num, abs(90));
        vTaskDelay(update_period / portTICK_PERIOD_MS);
    }
        
}
