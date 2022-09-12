
#ifndef SPI_H
#define SPI_H


// подключение заголовочных файлов модулей проекта
#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_spi.h"


// директивы работы с линией FSS	
#define SPI3_CS_RESET		GPIO_ResetBits(GPIOA, GPIO_Pin_15)
#define SPI3_CS_SET			GPIO_SetBits(GPIOA, GPIO_Pin_15)


// прототипы функций
void SPIx_reset(SPI_TypeDef* SPIx);
void SPIxInit(SPI_TypeDef* SPIx, uint8_t mode, uint8_t f);
uint16_t SPIx_rxtx(SPI_TypeDef* SPIx, uint16_t data);


#endif
