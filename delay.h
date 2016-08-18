#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f0xx.h"

/* Delay_us
   input: uint32_t time
   text:
   delay in us
*/
void Delay_us(__IO uint32_t nTime);
/* Delay_ms
   input: uint32_t time
   text:
   delay in us
*/
void Delay_ms(__IO uint32_t nTime);
void TimingDelay_Decrement(void);
void SysTick_Handler(void);
void init_timer(void);

#endif
