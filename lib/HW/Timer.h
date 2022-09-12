
#ifndef TIMER_H
#define TIMER_H


// подключение заголовочных файлов модулей проекта
#include "stm32f4xx.h"                  // Device header


// прототипы функций	
extern volatile int32_t TIM6_tick;
#define SysTickMs TIM6_tick
void TIM6_DAC_init(void);
void TIM6_DAC_IRQHandler(void);

void delay_ms(uint32_t Delay_ms_Data);	// функия задержки в мс

#define TIMEOUT_MS(cmd, timeout /*, success_flag*/) { \
  int32_t start_tick = TIM6_tick; \
  /*(success_flag) = true;*/ \
  while( (cmd) ) { \
    if ( (int32_t)(TIM6_tick - start_tick) > (int32_t)(timeout) ) { \
      /*(success_flag) = false;*/ \
      break; \
    } \
  } \
}

void TIM7_init(void);
void TIM7_IRQHandler(void);


#endif
