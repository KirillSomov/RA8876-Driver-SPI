
#include "Timer.h"
#include "stm32f4xx_tim.h"


void TIM10_init(void)
{
  TIM_TimeBaseInitTypeDef base_timer;
  TIM_TimeBaseStructInit(&base_timer);
  base_timer.TIM_Prescaler = 41999;
  base_timer.TIM_Period = 0xFFFF;
  TIM_TimeBaseInit(TIM10, &base_timer);
  TIM_Cmd(TIM10, ENABLE);
}


void delay_ms(uint16_t ms)
{
  volatile uint16_t start_count = TIM10->CNT;
  
  while (((uint16_t)((uint16_t)TIM10->CNT - start_count)) < ms);
}
