

#include "main.h"

void HAL_MspInit(void)
{

	//1. Set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);


	//2. Enable the required system exceptions of the arm cortex mx processor
	SCB->SHCSR = 0x7 << 16; // usage fault, memory fault, bus fault exceptions


	//3. configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);

}

