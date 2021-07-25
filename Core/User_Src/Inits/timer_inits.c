

#include "main.h"

// 72 MHz, 1S Delay with interrupt
void TIM3_Init(void){

	timer3.Instance = TIM3;
	timer3.Init.Period = 4999;
	timer3.Init.Prescaler = 14400-1;
	HAL_TIM_Base_Init(&timer3);

}

