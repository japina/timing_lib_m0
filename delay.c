#include "delay.h"

#define SystemCoreClock 8000000


static __IO uint32_t TimingDelay;

  void Delay(__IO uint32_t nTime) { 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

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
    if (SysTick_Config(SystemCoreClock / 1000))
  {
    /* Capture error */ 
    while (1);
  }   
}