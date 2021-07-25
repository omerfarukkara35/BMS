

#include "main.h"


void GPIO_Init(void){

	GPIO_InitTypeDef gpio;

__HAL_RCC_GPIOC_CLK_ENABLE();


	gpio.Pin = GPIO_PIN_13;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOC, &gpio);


}
