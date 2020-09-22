#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"
#include "driver/gpio.h"
#define BLINK_GPIO GPIO_SEL_2

void init_gpio(void);
void gpio_toggle(void);
//static inline void delay(uint32_t delay_input);

void delay(unsigned long ms)
{
  volatile unsigned long i,j;
  for (i = 0; i < ms; i++ )
  for (j = 0; j < 1227; j++ );
}

void init_gpio(){
	gpio_config_t io_conf;

	io_conf.intr_type = GPIO_INTR_DISABLE;
	io_conf.mode = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = BLINK_GPIO;
	io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
	io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
	gpio_config(&io_conf);
	gpio_set_level(BLINK_GPIO, 1);
}
void gpio_toggle(){

}

void app_main(void){
	
	init_gpio();
    while (1) {
    	gpio_set_level(BLINK_GPIO, 1);
    	delay(20000);
		printf(" Hello world Luise naja!\n");
		}        ////printf(" Hello world Luise naja!\n", i);      
    }




