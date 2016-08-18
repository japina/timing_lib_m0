#include "delay.h"

#ifndef SystemCoreClock
// 8Mhz RC clock
#define SystemCoreClock 8000000
// 14.74660 Mhz quartz
//#define SystemCoreClock 48000000
#endif

static __IO uint32_t TimingDelay;

  void Delay_ms(__IO uint32_t nTime) {
  TimingDelay = nTime;
  while(TimingDelay != 0);
}

/*void Delay_ms(__IO uint32_t nTime) {
  uint32_t i=0;
  while (i<nTime){
    Delay_us(1000);
    i++;
  }
} */


void SysTick_Handler(void){
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}

void TimingDelay_Decrement(void){
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}

void init_timer(void){
    // fq = 8000000
    if (SysTick_Config(SystemCoreClock / 1000))
    //if (SysTick_Config(SystemCoreClock / 100000))
    // fq = 48000000
    //if (SysTick_Config(SystemCoreClock / 48000))
    // fq = 14746600
    //if (SysTick_Config(SystemCoreClock / 147466))
  {
    /* Capture error */
    while (1);
  }
}
