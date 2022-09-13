
#include "stm32f4xx.h"                  // Device header
#include "GPIO.h"
#include "CPU.h"
#include "Timer.h"
#include "SPI.h"

uint16_t data = 0;

#include "RA8876.h"
#include "FT5316.h"
#include "LCD_demo.h"
#include "LCD_api.h"


struct _ts_event ts_event = {0};
extern const unsigned char image_deb[];


int main(void)
{
  CPU_init();
  GPIO_setup();
  TIM6_DAC_init();
  SPIxInit(SPI3, 0, 0); //~13 MHz
   
  //I2C1_init();
  //EXTI_init();
  //TOUCH_Init();
  LCD_init();
  //LCD_cleanCurrentPage(White);
  //LCD_drawBitmap3(&image_foggy_forest_landscape_small, 100, 100, 300, 168);
  LCD_setPage(PAGE1_START_ADDR);
  LCD_cleanCurrentPage(0x0000);
  delay_ms(500);
  LCD_setPage(0);
  LCD_drawBitmap(&image_deb, 10, 10, 400, 422);
  LCD_drawBitmapPageBuf(&image_deb, PAGE1_START_ADDR, PAGE0_START_ADDR, 420, 10, 400, 422);


  while(1)
  {


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
    ts_event = touchGetPoint();
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


  /*GUI_CTC_pageLogoInit();
  delay_ms(1000);
  GUI_pagesStorageInit();
  GUI_cryoInit();
  while(1)
  {
    {
      static int32_t GUI_tick = 0;
      const  int32_t GUI_period = 20;
      int32_t dT = (int32_t)(SysTickMs - GUI_tick);
      if(dT >= GUI_period)
      {
        GUI_tick = SysTickMs;
        GUI_Handler(dT);
      }
    }
  }*/

}
