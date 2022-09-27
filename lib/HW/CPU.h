
#ifndef CPU_H
#define CPU_H


// подключение заголовочных файлов модулей проекта
#include "stm32f4xx.h"                  // Device header


// 
#define cPLLM 	4				// main PLL (PLLM) = 8 MHz / 4 = 2 MHz
#define cPLLN 	168			// VCO output = PLLM * 168 = 336 MHz
#define cPLLP 	2				// PLLP = VCO output / 2 = 168 MHz
#define cPLLQ 	4


// прототипы функций
void	clockSetup(void);					// тактирование
void	periphClockSetup(void);		// 
void	CPU_init(void);						// инициализация CPU


#endif
