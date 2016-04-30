#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f0xx.h"

void Delay(__IO uint32_t nTime);
void TimingDelay_Decrement(void);
void SysTick_Handler(void);
void init_timer(void);

#endif