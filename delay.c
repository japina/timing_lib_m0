#include "delay.h"

// for q = 8 Mhz and divider 100000 30us
// for q = 8 Mhz and divider 10000 100us
// for q = 8 Mhz and divider 1000 1ms


#ifndef SystemCoreClock
// 8Mhz RC clock
//#define SystemCoreClock 8000000
// 14.74660 Mhz quartz
#define SystemCoreClock 48000000
#endif

static __IO uint32_t TimingDelay;

  void Delay_ms(__IO uint32_t nTime) {
	uint8_t i;
	for(i=0;i<100;i++) {
	  TimingDelay = nTime;
	  while(TimingDelay != 0);
	}
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
    //if (SysTick_Config(SystemCoreClock / 1000))
    //if (SysTick_Config(SystemCoreClock / 100000))
    // fq = 48000000
		// 600000 10 ms
    if (SysTick_Config(SystemCoreClock / 600000)) // 
    // fq = 14746600
    //if (SysTick_Config(SystemCoreClock / 147466))
  {
    /* Capture error */
    while (1);
  }
}
