
#include "main.h"

void CAN_Init(void){

	hcan.Instance = CAN1;
	hcan.Init.Mode = CAN_MODE_NORMAL;
	hcan.Init.AutoBusOff = ENABLE;
	hcan.Init.AutoRetransmission = ENABLE;
	hcan.Init.AutoWakeUp = DISABLE;
	hcan.Init.ReceiveFifoLocked = DISABLE;
	hcan.Init.TimeTriggeredMode = DISABLE;
	hcan.Init.TransmitFifoPriority = DISABLE;

	//Setting up the bit timing
	hcan.Init.Prescaler = 4;
	hcan.Init.TimeSeg1 = CAN_BS1_15TQ;
	hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
	hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;

	if(HAL_CAN_Init(&hcan) != HAL_OK){
			Error_handler();
		}
}


void CAN_Filter_Config(void)
{
	CAN_FilterTypeDef can1_filter_init;

	can1_filter_init.FilterActivation = ENABLE;
	can1_filter_init.FilterBank  = 0;
	can1_filter_init.FilterFIFOAssignment = CAN_RX_FIFO0;
	can1_filter_init.FilterIdHigh = 0x0000;
	can1_filter_init.FilterIdLow = 0x0000;
	can1_filter_init.FilterMaskIdHigh = 0x0000;
	can1_filter_init.FilterMaskIdLow = 0x0000;
	can1_filter_init.FilterMode = CAN_FILTERMODE_IDMASK;
	can1_filter_init.FilterScale = CAN_FILTERSCALE_32BIT;

	if( HAL_CAN_ConfigFilter(&hcan,&can1_filter_init) != HAL_OK)
	{
		Error_handler();
	}

}


void CAN_Tx(void){


		CAN_TxHeaderTypeDef TxHeader;
		uint32_t TxMailbox;

		uint8_t message;

		TxHeader.DLC = 1;
		TxHeader.StdId = 0x65D;
		TxHeader.IDE = CAN_ID_STD;
		TxHeader.RTR = CAN_RTR_DATA;

		message = ++led_no;

		if(led_no == 4){
			led_no = 0;
		}

		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // indication of the transmission over the board

		if(HAL_CAN_AddTxMessage(&hcan, &TxHeader, &message, &TxMailbox) != HAL_OK){
			Error_handler();
		}
}

void CAN_Rx(void){

		CAN_RxHeaderTypeDef RxHeader;
		uint8_t rcvd_msg[5];

		char msg[50];

		//we are waiting for at least one message in to the RX FIFO0
		while(! HAL_CAN_GetRxFifoFillLevel(&hcan,CAN_RX_FIFO0));
		//Not needed when IT used

		if(HAL_CAN_GetRxMessage(&hcan,CAN_RX_FIFO0,&RxHeader,rcvd_msg) != HAL_OK)
		{
			Error_handler();
		}
}
