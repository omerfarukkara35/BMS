/*
 * can.h
 *
 *  Created on: May 2, 2021
 *      Author: Stable
 */

#ifndef INC_CAN_H_
#define INC_CAN_H_

	CAN_HandleTypeDef hcan;
	uint8_t led_no;
	CAN_TxHeaderTypeDef TxHeader;
	CAN_RxHeaderTypeDef RxHeader;

void CAN_Init(void);
void CAN_Filter_Config(void);
void CAN_Rx(void);
void CAN_Tx(void);

void USB_HP_CAN1_TX_IRQHandler(void);
void USB_LP_CAN1_RX0_IRQHandler(void);
void CAN1_RX1_IRQHandler(void);
void CAN1_SCE_IRQHandler(void);


void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox1CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox2CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan);


#endif /* INC_CAN_H_ */
