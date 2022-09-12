
#ifndef GPIO_H
#define GPIO_H


// подключение заголовочных файлов модулей проекта
#include "stm32f4xx.h"                  // Device header


// прототипы функций
void	GPIO_gpiSetup(void);						// конфигурация портов на вход
void	GPIO_gpoSetup(void);						// конфигурация портов на выход
void	GPIO_spi3Setup(void);						// конфигурация порта для работы интерфейса SPI (SSP3)
void	GPIO_i2c1Setup(void);						// конфигурация порта для работы интерфейса 
void	GPIO_uartSetup(void);	

void	GPIO_setup(void);								// конфигурация портов


#endif
