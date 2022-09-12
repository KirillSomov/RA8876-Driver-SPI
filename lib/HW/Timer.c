
#include "Timer.h"
#include "stm32f4xx_tim.h"


volatile uint32_t Delay_dec = 0;
volatile int32_t  TIM6_tick = 0;


void TIM6_DAC_init(void)
{
  TIM_TimeBaseInitTypeDef base_timer;
  TIM_TimeBaseStructInit(&base_timer);
  base_timer.TIM_Prescaler = 26250-1;
  base_timer.TIM_Period = 1;
  TIM_TimeBaseInit(TIM6, &base_timer);

  /* Разрешаем прерывание по обновлению (в данном случае -
   * по переполнению) счётчика таймера TIM6.
   */
  TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
  /* Включаем таймер */
  TIM_Cmd(TIM6, ENABLE);

  /* Разрешаем обработку прерывания по переполнению счётчика
   * таймера TIM6. Так получилось, что это же прерывание
   * отвечает и за опустошение ЦАП.
   */
  NVIC_EnableIRQ(TIM6_DAC_IRQn);
}

void TIM6_DAC_IRQHandler(void)
{
  /* Так как этот обработчик вызывается и для ЦАП, нужно проверять,
   * произошло ли прерывание по переполнению счётчика таймера TIM6.
   */
  if(TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET)
  {
    if(Delay_dec > 0)
      Delay_dec--;
    TIM6_tick++;
    /* Очищаем бит обрабатываемого прерывания */
    TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
  }
}


void delay_ms(uint32_t Delay_ms_Data)
{
  Delay_dec = Delay_ms_Data;
  while(Delay_dec) {};
}


void TIM7_init(void)
{
  TIM_TimeBaseInitTypeDef base_timer;
  TIM_TimeBaseStructInit(&base_timer);
  base_timer.TIM_Prescaler = 26250-1;
  base_timer.TIM_Period = 1;
  TIM_TimeBaseInit(TIM7, &base_timer);

  TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM7, ENABLE);

  NVIC_EnableIRQ(TIM7_IRQn);
}

/*
void TIM7_IRQHandler(void)
{
  for(uint8_t objButNum = 0; objButNum < GUI.pages[GUI.currentPage]->objList.ObjButtonNum; objButNum++)
  {
    if(GUI.pages[GUI.currentPage]->objList.ObjButtonList[objButNum].timerVal > 0)
    {
      GUI.pages[GUI.currentPage]->objList.ObjButtonList[objButNum].timerVal--;
    }
    else
    {
      GUI.pages[GUI.currentPage]->objList.ObjButtonList[objButNum].flag_buttonWasClicked = 0;
    }
  }
  
  TIM_ClearITPendingBit(TIM7, TIM_IT_Update);
}
*/