

#include "main.h"

//N2

void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan){

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);

}

void HAL_CAN_TxMailbox1CompleteCallback(CAN_HandleTypeDef *hcan){

	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);

}
void HAL_CAN_TxMailbox2CompleteCallback(CAN_HandleTypeDef *hcan){


}
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){

	uint8_t rcvd_msg[8];


	if(HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO0,&RxHeader,rcvd_msg) != HAL_OK)
	{
		Error_handler();

	}

	if(RxHeader.StdId == 0x65D && RxHeader.RTR == 0){

		//Data frame sent n1 to n2
		LED_Manage_Output(rcvd_msg[0]);

	}else if (RxHeader.StdId == 0x651 && RxHeader.RTR == 1){

		Send_Response(RxHeader.StdId);
	}

}


void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan){

	Error_handler();

}


