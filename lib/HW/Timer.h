
#ifndef TIMER_H
#define TIMER_H

#include "stm32f4xx.h"


void TIM10_init(void);
void delay_ms(uint16_t ms);

#define TIMEOUT_MS(cmd, timeout /*, success_flag*/) { \
  uint16_t start_tick = TIM10->CNT; \
  /*(success_flag) = true;*/ \
  while( (cmd) ) { \
    if ( (uint16_t)(TIM10->CNT - start_tick) > (uint16_t)(timeout) ) { \
      /*(success_flag) = false;*/ \
      break; \
    } \
  } \
}


#endif
