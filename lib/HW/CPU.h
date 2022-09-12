
#ifndef CPU_H
#define CPU_H


// подключение заголовочных файлов модулей проекта
#include "stm32f4xx.h"                  // Device header


// 
#define cPLLM 	4				// main PLL (PLLM) = 8 MHz / 4 = 2 MHz
#define cPLLN 	210			// VCO output = PLLM * 210 = 420 MHz
#define cPLLP 	1				// PLLP = VCO output / 4 = 105 MHz
#define cPLLQ 	8


// прототипы функций
void	clockSetup(void);					// тактирование
void	periphClockSetup(void);		// 
void	CPU_init(void);						// инициализация CPU


#endif
