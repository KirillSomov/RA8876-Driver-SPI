
#include "stm32f4xx.h"                  // Device header
#include "CPU.h"
#include "Timer.h"
#include "GPIO.h"
#include "SPI.h"
#include "I2C.h"
#include "LCD_api.h"

uint16_t tX = 0;
uint16_t tY = 0;


struct _ts_event ts_event = {0};
extern const unsigned char image_deb[];
extern const unsigned char image_deb_8bpp[];


int main(void)
{
  CPU_init();
  GPIO_setup();
  TIM6_DAC_init();
  SPIxInit(SPI3, 0, 0); //~13 MHz
   
  I2C1_init();
  //EXTI_init();
  Touch_init();
  LCD_init();

  LCD_setPage(PAGE0_START_ADDR);
  LCD_cleanCurrentPage(White);
  LCD_setPage(PAGE1_START_ADDR);
  LCD_cleanCurrentPage(White);
  LCD_setPage(PAGE0_START_ADDR);
  LCD_showPage(PAGE0_START_ADDR);
  LCD_drawBitmap(&image_deb, MODE_16BPP, 10, 10, 400, 422);
  LCD_drawBitmapPageBuf(&image_deb_8bpp, MODE_8BPP, PAGE1_START_ADDR, PAGE0_START_ADDR, MODE_16BPP, 420, 10, 400, 422);

  while(1)
  {
    Touch_handler();
    if(Touch_sampleTouch(&tX, &tY))
    {
      LCD_drawFilledCircle(tX, tY, 5, Magenta);
    }

    delay_ms(1);
  }


  while(1)
  {
    /*LCD_setPage(PAGE0_START_ADDR);
    delay_ms(2000);
    LCD_setPage(PAGE1_START_ADDR);
    delay_ms(2000);*/
    //Geometric();
    for(int i = 200; i < 900; i++)
    {
      for(int j = 100; j < 400; j++)
      {
        LCD_SetPoint(i, j, 0x0000);
      }
    }

    LCD_drawSquare(100, 100, 500, 500, Black);
    delay_ms(500);
    LCD_drawSquare(100+20, 100+20, 500+20, 500+20, Green);
    delay_ms(500);
    LCD_drawFilledSquare(100+50, 100+50, 500+50, 500+50, Yellow);
    delay_ms(500);
    LCD_drawCircle(300, 300, 50, Magenta);
    delay_ms(500);
    LCD_drawFilledCircle(300, 300, 25, Magenta);
    delay_ms(500);
    LCD_drawCircleSquare(100+100, 100+100, 400+100, 400+100, 20, 20, Green);
    delay_ms(500);
    LCD_drawFilledCircleSquare(100+150, 100+150, 400+50, 400+50, 50, 50, Blue);
    delay_ms(500);
    LCD_drawEllipse(600, 300, 50, 150, White);
    delay_ms(500);
    LCD_drawFilledEllipse(600, 300, 25, 75, White);
    delay_ms(500);
    LCD_cleanCurrentPage(Red);
  }
  
  
  while(1)
  {
    //ts_event = touchGetPoint();
    Graphic_Cursor_XY(-1*(ts_event.x1-1023), -1*(ts_event.y1-599));
    delay_ms(1);
  }


  while(1)
  {
    for(int j=0;j<2;j++)
    {
      for(int i=0;i<1024;i++)
      {
        Graphic_Cursor_XY(i,508+j*20);	
        delay_ms(2);   
      }
    }
    Graphic_Cursor_XY(0,508);	
    delay_ms(2000);
  } 

}
