
#include "main.h"

int main(void)
{

	HAL_Init();

	SystemClock_Config();

	GPIO_Init();

	UART2_Init();

	TIMER6_Init();

	CAN1_Init();

	CAN_Filter_Config();

	if(HAL_CAN_ActivateNotification(&hcan,CAN_IT_TX_MAILBOX_EMPTY|CAN_IT_RX_FIFO0_MSG_PENDING|CAN_IT_BUSOFF)!= HAL_OK)
	{
			Error_handler();
	}


	if( HAL_CAN_Start(&hcan) != HAL_OK)
	{
		Error_handler();
	}



	while(1);

	return 0;
}
