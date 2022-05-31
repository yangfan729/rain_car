#ifndef _LQOLED_H
#define _LQOLED_H
#include "include.h"
void delay_(void);
#define delay_12864   delay_();


#define LCD12864_SCL_PORT_DIR   P4DIR
#define LCD12864_SCL_PORT_OUT   P4OUT
#define LCD12864_SCL_BIT        BIT3

#define LCD12864_SDA_PORT_DIR   P4DIR
#define LCD12864_SDA_PORT_OUT   P4OUT
#define LCD12864_SDA_BIT        BIT0


#define LCD12864_RST_PORT_DIR   P3DIR
#define LCD12864_RST_PORT_OUT   P3OUT
#define LCD12864_RST_BIT        BIT7


#define LCD12864_DC_PORT_DIR    P8DIR
#define LCD12864_DC_PORT_OUT    P8OUT
#define LCD12864_DC_BIT         BIT2

#define LCD12864_CS_PORT_DIR    P8DIR
#define LCD12864_CS_PORT_OUT    P8OUT
#define LCD12864_CS_BIT         BIT1


#define LCD_SCL(x)  {if(x==1){LCD12864_SCL_PORT_OUT|=LCD12864_SCL_BIT;}else{LCD12864_SCL_PORT_OUT&=~LCD12864_SCL_BIT;}}
#define LCD_SDA(x)  {if(x==1){LCD12864_SDA_PORT_OUT|=LCD12864_SDA_BIT;}else{LCD12864_SDA_PORT_OUT&=~LCD12864_SDA_BIT;}}
#define LCD_RST(x)  {if(x==1){LCD12864_RST_PORT_OUT|=LCD12864_RST_BIT;}else{LCD12864_RST_PORT_OUT&=~LCD12864_RST_BIT;}}
#define LCD_DC(x)   {if(x==1){LCD12864_DC_PORT_OUT |=LCD12864_DC_BIT; }else{LCD12864_DC_PORT_OUT &=~LCD12864_DC_BIT; }}


#define byte unsigned char  //自己加的
#define word unsigned int   //自己加的
 void Paint_Angle(float Angle);
 void List_Paint(void);
 void List_Move(signed char New_Data);
 void Paint_List(float New_Data,float Paint_Ave,float Paint_Margin);
 void OLED_Write_Float(unsigned char x,unsigned char y,float Number);
 //extern byte longqiu96x64[768];
 extern byte Ly[1024];
 void LCD_Init(void);                       // LCD初始化
 void LCD_CLS(void);
 void LCD_P6x8Str(byte x,byte y,byte ch[]);
 void LCD_P8x16Str(byte x,byte y,byte ch[]);
 void LCD_P14x16Str(byte x,byte y,byte ch[]);
 void LCD_Print(byte x, byte y, byte ch[]);
 void LCD_PutPixel(byte x,byte y);
 void LCD_Rectangle(byte x1,byte y1,byte x2,byte y2,byte gif);
 //void Draw_LQLogo(void);
 void Draw_LibLogo(void);
 void Draw_BMP(byte x0,byte y0,byte x1,byte y1,byte bmp[]); 
 void LCD_Fill(byte dat);
 void Set_NOP(void);
 void LCD_WrDat(byte data);
 void LCD_Set_Pos(byte x, byte y);
 

#endif

