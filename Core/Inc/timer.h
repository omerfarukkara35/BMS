/*
 * timer.h
 *
 *  Created on: May 1, 2021
 *      Author: Stable
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

TIM_HandleTypeDef timer3;
void TIM3_Init(void);
void TIM3_IRQHandler(void);

#endif /* INC_TIMER_H_ */
