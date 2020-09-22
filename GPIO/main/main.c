// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/gpio.h"
// #include "esp_system.h"

// #define BLINK_GPIO GPIO_SEL_2
// void init_gpio(void);
// void delay(uint32_t dely_ms);
// //static inline void delay(uint32_t delay_input);


// void init_gpio(void){
// 	gpio_config_t pin_config;
// 	pin_config.pin_bit_mask = BLINK_GPIO;
// 	pin_config.mode = GPIO_MODE_OUTPUT;
// 	pin_config.pull_up_en = GPIO_PULLUP_DISABLE;
// 	pin_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
// 	pin_config.intr_type = GPIO_PIN_INTR_DISABLE;
// 	gpio_config(&pin_config);
// 	gpio_set_level(BLINK_GPIO, 1);
// }

// void app_main(void){

// 	nvs_flash_init();
// 	xTaskCreate(&blinky, "blinky", 512,NULL,5,NULL );
//     while (1) {
    	
//   //   	gpio_set_level(BLINK_GPIO, 0);
//   //       vTaskDelay(1000 / portTICK_RATE_MS);
//   //       /* Blink on (output high) */
//   //       gpio_set_level(BLINK_GPIO, 1);
//   //       vTaskDelay(1000 / portTICK_RATE_MS);

// 		// printf(" Hello world Luise naja!\n");


// 		}        ////printf(" Hello world Luise naja!\n", i);      
//     }


// void blinky(void *pvParameter)
// {
 
// 	init_gpio();
//     while(1) {
//         /* Blink off (output low) */
//         gpio_set_level(BLINK_GPIO, 0);
//         vTaskDelay(1000 / portTICK_RATE_MS);
//         /* Blink on (output high) */
//         gpio_set_level(BLINK_GPIO, 1);
//         vTaskDelay(1000 / portTICK_RATE_MS);
//     }
// }

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
 
#define BLINK_GPIO GPIO_SEL_2
 
 
void hello_task(void *pvParameter)
{
 
	while(1)
	{
	    printf("Hello world!\n");
	    vTaskDelay(100 / portTICK_RATE_MS);
	}
}
 
void blinky(void *pvParameter)
{
 
    gpio_pad_select_gpio(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    while(1) {
        /* Blink off (output low) */
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(5000 / portTICK_RATE_MS);
        /* Blink on (output high) */
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(5000 / portTICK_RATE_MS);
    }
}
 
 
void app_main()
{
    ets_timer_init();
    xTaskCreate(&hello_task, "hello_task", 2048, NULL, 5, NULL);
    xTaskCreate(&blinky, "blinky", 512,NULL,5,NULL );
}
