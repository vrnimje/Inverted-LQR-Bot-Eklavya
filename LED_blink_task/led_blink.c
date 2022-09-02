#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"    //header files to access and configure gpio pins
#include "esp_log.h"


// Defining pins for LEDs
#define BG_LED_1 32
#define BG_LED_2 33
#define BG_LED_3 25
#define BG_LED_4 26
#define BG_LED_5 27
#define BG_LED_6 14
#define BG_LED_7 12
#define BG_LED_8 13

 
//array containing pin numbers
static const int pin_out[8] = {BG_LED_1, BG_LED_2, BG_LED_3, BG_LED_4, BG_LED_5, BG_LED_6, BG_LED_7, BG_LED_8};

int app_main()
{
    //configuring gpio all pins
    gpio_config_t io_conf;
    
    // bit mask for the pins, each bit maps to a GPIO
    io_conf.pin_bit_mask = (1ULL << BG_LED_1) | (1ULL << BG_LED_2) | (1ULL << BG_LED_3) | (1ULL << BG_LED_4) | (1ULL << BG_LED_5) | (1ULL << BG_LED_6) | (1ULL << BG_LED_7) | (1ULL << BG_LED_8);
    
    // set gpio mode to output
    io_conf.mode = GPIO_MODE_OUTPUT;
    
    // enable pull up resistors
    io_conf.pull_up_en = 0;
    
    // disable pull down resistors
    io_conf.pull_down_en = 1;
    
    // disable gpio interrupts
    io_conf.intr_type = GPIO_INTR_DISABLE;

    gpio_config(&io_conf);
    
    // continuously blinking LEDs one after another
    while (1)
    {
        for(int i = 0; i < 8; i++)
        {  
            gpio_set_level((gpio_num_t)pin_out[i], 1);
            vTaskDelay(1000 / portTICK_RATE_MS);
            
            gpio_set_level((gpio_num_t)pin_out[i], 0);
            vTaskDelay(1000 / portTICK_RATE_MS);
        }
    }
    return 0;
}