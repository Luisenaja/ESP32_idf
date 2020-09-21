#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#define BLINK_GPIO GPIO_SEL_2

void init_gpio(void);
//void gpio_toggle(void);
//static inline void delay(uint32_t delay_input);

void init_gpio(){
	

	gpio_reset_pin(BLINK_GPIO);
	gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}
// void gpio_toggle(){
// 	gpio_set_level(BLINK_GPIO, 1);
// 	vTaskDelay(1000/ portTICK_PERIOD_MS);
// 	gpio_set_level(BLINK_GPIO, 0);
// 	vTaskDelay(1000/ portTICK_PERIOD_MS);
// }
// static inline void delay(uint32_t delay_input){
// 	vTaskDelay(delay_input/ portTICK_PERIOD_MS);
// }
void app_main(void){
	gpio_config_t io_conf;

	io_conf.intr_type = GPIO_INTR_DISABLE;
	io_conf.mode = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = BLINK_GPIO;
	io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
	io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
	gpio_config(&io_conf);
	gpio_set_level(BLINK_GPIO, 1);
	// gpio_pad_select_gpio(BLINK_GPIO);
	// gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    while (1) {
    	gpio_set_level(BLINK_GPIO, 1);
		vTaskDelay(500/ portTICK_PERIOD_MS);
		printf(" Hello world Luise naja!\n");
		}        ////printf(" Hello world Luise naja!\n", i);      
    }




