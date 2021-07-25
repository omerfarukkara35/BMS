

#include "main.h"


void TIM3_IRQHandler(void){

	HAL_TIM_IRQHandler(&timer3);

}


