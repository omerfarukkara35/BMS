

#include "main.h"

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htimer){

	__HAL_RCC_TIM3_CLK_ENABLE();

	HAL_NVIC_SetPriority(TIM3_IRQn, 15, 0);

	HAL_NVIC_EnableIRQ(TIM3_IRQn);



}
