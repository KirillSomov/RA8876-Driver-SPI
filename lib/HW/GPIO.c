
#include "GPIO.h"
#include "stm32f4xx_gpio.h"


// конфигурация портов на вход
void	GPIO_gpiSetup(void)
{
  //
  GPIO_InitTypeDef GPIO_initGpi;
  GPIO_StructInit(&GPIO_initGpi);
  
  GPIO_initGpi.GPIO_Mode  = GPIO_Mode_IN;
  GPIO_initGpi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_initGpi.GPIO_OType = GPIO_OType_PP;
  GPIO_initGpi.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  
  GPIO_initGpi.GPIO_Pin   = GPIO_Pin_5;					// PD5 - LCD_IRQ
  GPIO_Init(GPIOD, &GPIO_initGpi); 							// PD5 - LCD_IRQ
}	

// конфигурация портов на выход
void	GPIO_gpoSetup(void)
{
  //
  GPIO_InitTypeDef GPIO_initGpo;
  GPIO_StructInit(&GPIO_initGpo);
  
  GPIO_initGpo.GPIO_Mode  = GPIO_Mode_OUT;
  GPIO_initGpo.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_initGpo.GPIO_OType = GPIO_OType_PP;
  GPIO_initGpo.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  
  GPIO_initGpo.GPIO_Pin   = GPIO_Pin_9;															// PC9 - LCD_DC
  GPIO_Init(GPIOC,&GPIO_initGpo); 																	// PC9 - LCD_DC
  
  GPIO_initGpo.GPIO_Pin   = GPIO_Pin_8;															// PA8 - MODBUS MASTER TX EN
  GPIO_Init(GPIOA,&GPIO_initGpo); 																	// PC9 - LCD_DC
  
  GPIO_initGpo.GPIO_Pin   = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;		// PD3 - LCD_RST, PD4 - TOUCH_FT5316_RSTN
  GPIO_Init(GPIOD,&GPIO_initGpo);																															// PD3 - LCD_RST, PD4 - TOUCH_FT5316_RSTN
                                                                                              // PD0 - MODBUS SLAVE LED, PD1 - MODBUS MASTER LED
}

// конфигурация порта для работы интерфейса SPI (SSP2)
void	GPIO_spi1Setup(void)
{
  // PA5 - SCK, PA6 - MISO, PA7 - MOSI
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
  
  GPIO_InitTypeDef GPIO_initSPI1;
  GPIO_StructInit(&GPIO_initSPI1);
  
  GPIO_initSPI1.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_initSPI1.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_initSPI1.GPIO_OType = GPIO_OType_PP;
  GPIO_initSPI1.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  GPIO_initSPI1.GPIO_Pin   = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
  
  GPIO_Init(GPIOA,&GPIO_initSPI1); 								//

  // PA4 - CS
  GPIO_initSPI1.GPIO_Mode  = GPIO_Mode_OUT;
  GPIO_initSPI1.GPIO_Pin   = GPIO_Pin_4;
  GPIO_Init(GPIOA, &GPIO_initSPI1);
}

// конфигурация порта для работы интерфейса SPI (SSP3)
void	GPIO_spi3Setup(void)
{
  // PC10 - SCK, PC11 - MISO, PC12 - MOSI
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_SPI3);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_SPI3);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource12, GPIO_AF_SPI3);
  
  GPIO_InitTypeDef GPIO_initSPI3;
  GPIO_StructInit(&GPIO_initSPI3);
  
  GPIO_initSPI3.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_initSPI3.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_initSPI3.GPIO_OType = GPIO_OType_PP;
  GPIO_initSPI3.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  GPIO_initSPI3.GPIO_Pin   = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;
  
  GPIO_Init(GPIOC,&GPIO_initSPI3); 								//

  // PA15 - CS
  GPIO_initSPI3.GPIO_Mode  = GPIO_Mode_OUT;
  GPIO_initSPI3.GPIO_Pin   = GPIO_Pin_15;
  GPIO_Init(GPIOA, &GPIO_initSPI3);
}

// конфигурация порта для работы интерфейса I2C (I2C1)
void	GPIO_i2c1Setup(void)
{
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_I2C1);
  
  GPIO_InitTypeDef GPIO_initI2C1;
  GPIO_StructInit(&GPIO_initI2C1);
  
  GPIO_initI2C1.GPIO_Pin		=	GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_initI2C1.GPIO_Mode		=	GPIO_Mode_AF; 
  GPIO_initI2C1.GPIO_Speed	=	GPIO_Speed_50MHz;
  GPIO_initI2C1.GPIO_OType	=	GPIO_OType_OD;
  GPIO_initI2C1.GPIO_PuPd		= GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_initI2C1);
}

// конфигурация порта для работы интерфейса UART
void	GPIO_uartSetup(void)
{

  GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_UART4);  // U4 
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_UART4);  // U4
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); // U2
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);	// U2

  
  GPIO_InitTypeDef GPIO_initUART;
  GPIO_StructInit(&GPIO_initUART);
  
  GPIO_initUART.GPIO_Pin		=	GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_initUART.GPIO_Mode		=	GPIO_Mode_AF; 
  GPIO_initUART.GPIO_Speed	=	GPIO_Speed_50MHz;
  GPIO_initUART.GPIO_OType	=	GPIO_OType_PP;
  GPIO_initUART.GPIO_PuPd		= GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_initUART);
}


// конфигурация портов
void	GPIO_setup(void)
{
  GPIO_gpiSetup();						// конфигурация портов на вход
  GPIO_gpoSetup();						// конфигурация портов на выход
  GPIO_spi1Setup();						// конфигурация порта для работы интерфейса SPI (SSP2)
  GPIO_spi3Setup();						// конфигурация порта для работы интерфейса SPI (SSP3)
  GPIO_i2c1Setup();						// конфигурация порта для работы интерфейса I2C (I2C1)
  GPIO_uartSetup();						// конфигурация порта для работы интерфейса UART (U1 U2)
}
