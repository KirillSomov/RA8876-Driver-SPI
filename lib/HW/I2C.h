
#ifndef I2C_H
#define I2C_H


// подключение заголовочных файлов модулей проекта
#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_i2c.h"


// прототипы функций
void I2C1_init(void);							// инициализация модуля I2C
// отправка данных по шине I2C
void I2Cx_writeData(I2C_TypeDef* I2Cx,
                    uint8_t slaveAddress,       // адрес устройства на шине I2C
                    uint8_t registerAddress,  	// адрес регистра памяти устройства
                    uint8_t data);             	// передаваемые данные
// получение данных по шине I2C
uint8_t I2Cx_readData(I2C_TypeDef* I2Cx,
                      uint8_t slaveAddress,				// адрес устройства на шине I2C
                      uint8_t registerAddress);		// адрес регистра памяти устройства
// последовательное получение нескольких пакетов данных
void I2Cx_readDataBurst(I2C_TypeDef* I2Cx,
                        uint8_t slaveAddress,			// адрес устройства на шине I2C
                        uint8_t registerAddress,	// адрес начального регистра памяти устройства
                        uint8_t amount,						// количество циклов чтения
                        uint8_t *buffer);					// буфер для хранения результатов чтения


#endif
