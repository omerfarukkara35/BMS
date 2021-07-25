


#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f1xx_hal.h"
#include "timer.h"
#include "util.h"
#include "stm32f1xx_it.h"
#include "can.h"


void GPIO_Init(void);
void SystemClock_Config(void);

#endif /* __MAIN_H */

