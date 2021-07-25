
#include "main.h"


void SysTick_Handler(void){

	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();

}

void USB_HP_CAN1_TX_IRQHandler(void){

	HAL_CAN_IRQHandler(&hcan);

}
void USB_LP_CAN1_RX0_IRQHandler(void){

	HAL_CAN_IRQHandler(&hcan);

}
void CAN1_RX1_IRQHandler(void){

	HAL_CAN_IRQHandler(&hcan);

}



