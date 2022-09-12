
#include "EXTI.h"
#include "stm32f4xx_exti.h"


//
void	EXTI_init(void)
{
  //
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource5);
  
  //
  EXTI_InitTypeDef EXTI_InitStruct;
  EXTI_StructInit(&EXTI_InitStruct);
  
  EXTI_InitStruct.EXTI_Line			=	EXTI_Line5;
  EXTI_InitStruct.EXTI_Mode			=	EXTI_Mode_Interrupt;
  EXTI_InitStruct.EXTI_Trigger	=	EXTI_Trigger_Falling;
  EXTI_InitStruct.EXTI_LineCmd	=	ENABLE;
  EXTI_Init(&EXTI_InitStruct);
  
  //
  NVIC_InitTypeDef NVIC_InitStruct;
  
  NVIC_InitStruct.NVIC_IRQChannel										=	EXTI9_5_IRQn;
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	=	0x00;
  NVIC_InitStruct.NVIC_IRQChannelSubPriority				=	0x00;
  NVIC_InitStruct.NVIC_IRQChannelCmd								=	ENABLE;
  NVIC_Init(&NVIC_InitStruct);
}


//
void	EXTI9_5_IRQHandler(void)
{	
  if(EXTI_GetITStatus(EXTI_Line5) != RESET)
  {
    //GUI_getTouchPoint();
    //GUI.flag_touch = 1;
    EXTI_ClearITPendingBit(EXTI_Line5);
  }
}
