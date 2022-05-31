 /*
P1.2-------PWMA
P7.0-------AIN2;
P7.4-------AIN1;

P1.3-------PWMB
P6.4------ BIN1;
P6.6------ BIN2;
P2.2------左电机B相
P2.3------右电机B相
P2.4------左电机A相  捕获
P2.5------左电机A相  捕获
OLED引脚分配
DO(SCLK)------P4.3
D1(DATA)------P4.0
RES-----------P3.7
DC------------P8.2
CS------------P8.1

按键1 P1.1---------正反转；
按键2 P2.1---------加减速

*/

#include <msp430f5529.h>
#include "include.h"


void  P1_IODect();
void  P2_IODect();
void  P11_Onclick();
void  P21_Onclick();
void  KEY_GPIO_init();


extern int Position,Target_Left,Position_Target;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    LCD_Init();                 //初始化OLED     
    KEY_GPIO_init();            //初始化键盘输入
    Config_CLK();               //配置时钟
    Motor_Config();             //初始化电机控制引脚与PWM输入
    Encoder_Config();           //初始化编码器输入捕获 定时器
    Init_LED();                 //初始化LED灯

    _EINT();//全总中断

    while(1)
    {

       LCD_P6x8Str(0,0,"EIE19040YF");

       LCD_P6x8Str(0,2,"Encoder:");
       OLED_Write_Float(80,2,Encoder_Left_Show);

       LCD_P6x8Str(0,3,"Encoder_Tar:");
       OLED_Write_Float(80,3,Target_Left);

       LCD_P6x8Str(0,5,"Position:");
       OLED_Write_Float(80,5,Position);

       LCD_P6x8Str(0,6,"Position_Tar:");
       OLED_Write_Float(80,6,Position_Target);
       OLED_Write_Float(0,2,Encoder_Right);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          __delay_cycles(7820000);
    }


}


void  KEY_GPIO_init(void)
{
    P2DIR &=~(BIT1);                //设置 P2.1,P1.1设置为输入
    P1DIR &=~(BIT1);                //设置 P2.1,P1.1设置为输入
    P2OUT |=BIT1;                   // P2.1输出高电平,
    P2REN |=BIT1;                   // P2.1内部上拉
    P1OUT |=BIT1;                   // P1.1 输出高电平,
    P1REN |=BIT1;                   // P1.1内部上拉

    P1IES |= BIT1;                  // P1.1设为下降沿中断
    P1IE  |= BIT1 ;                 // 允许P1.1中断

    P2IES |= BIT1;                  // P2.1设为下降沿中断
    P2IE  |= BIT1 ;                 // 允许P2.1中断
}

void P1_IODect()
{
    unsigned int Push_Key=0;
    //-----排除输出IO的干扰后，锁定唯一被触发的中断标志位-----
    Push_Key=P1IFG&(~P1DIR);
    //-----延时一段时间，避开机械抖动区域-----
    __delay_cycles(100000);                //消抖延时
    //----判断按键状态是否与延时前一致-----
    if((P1IN&Push_Key)==0)                //如果该次按键确实有效
   {
     //----判断具体哪个IO被按下，调用该IO的事件处理函数-----
      switch(Push_Key)
      {
//   case BIT0:    P10_Onclick();      break;
     case BIT1:     P11_Onclick();      break;
//   case BIT2:     P12_Onclick();      break;
//    case BIT3:     P13_Onclick();      break;
//   case BIT4:     P14_Onclick();      break;
//   case BIT5:     P15_Onclick();      break;
//   case BIT6:     P16_Onclick();      break;
//   case BIT7:     P17_Onclick();      break;
     default:        break;      //任何情况下均加上default
     }
   }
}

/******************************************************************************************************
 * 名       称：P1_IODect()
 * 功       能：判断具体引发中断的IO，并调用相应IO的中断事件处理函数
 * 入口参数：无
 * 出口参数：无
 * 说       明：该函数兼容所有8个IO的检测，请根据实际输入IO激活“检测代码”。
 * 本例中，仅有P1.1被用作输入IO，所以其他7个IO的“检测代码”没有被“激活”。
 * 范       例：无
 ******************************************************************************************************/
void P2_IODect()
{
    unsigned int Push_Key=0;
    //-----排除输出IO的干扰后，锁定唯一被触发的中断标志位-----
    Push_Key=P2IFG&(~P2DIR);
    //-----延时一段时间，避开机械抖动区域-----
    __delay_cycles(100000);                //消抖延时
    //----判断按键状态是否与延时前一致-----
    if((P2IN&Push_Key)==0)                //如果该次按键确实有效
   {
     //----判断具体哪个IO被按下，调用该IO的事件处理函数-----
      switch(Push_Key)
      {
//   case BIT0:    P10_Onclick();      break;
     case BIT1:     P21_Onclick();      break;
//   case BIT2:     P12_Onclick();      break;
//   case BIT3:     P13_Onclick();      break;
//   case BIT4:     P14_Onclick();      break;
//   case BIT5:     P15_Onclick();      break;
//   case BIT6:     P16_Onclick();      break;
//   case BIT7:     P17_Onclick();      break;
     default:        break;      //任何情况下均加上default
     }
   }
}

/******************************************************************************************************
 * 名       称：P21_Onclick()
 * 功       能：P2.1的中断事件处理函数，即当P2.1键被按下后，下一步干什么
 * 入口参数：无
 * 出口参数：无
 * 说       明：使用事件处理函数的形式，可以增强代码的移植性和可读性
 * 范       例：
 ******************************************************************************************************/
/******************************************************************************************************
 * 名       称：P11_Onclick()
 * 功       能：P1.1的中断事件处理函数，即当P1.2键被按下后，下一步干什么
 * 入口参数：无
 * 出口参数：无
 * 说       明：使用事件处理函数的形式，可以增强代码的移植性和可读性
 * 范       例：无
 ******************************************************************************************************/
void  P11_Onclick(void)
{
    P1OUT ^= BIT0;
    Position_Target = Position_Target + 1000;
    //Draw_LQLogo();  //显示图片
}


void  P21_Onclick(void)
{
    P4OUT ^= BIT7;
}

/******************************************************************************************************
 * 名       称：PORT1_ISR()
 * 功       能：响应P1口的外部中断服务
 * 入口参数：无
 * 出口参数：无
 * 说       明：P1.0~P1.8共用了PORT1中断，所以在PORT1_ISR()中必须查询标志位P1IFG才能知道
 *                   具体是哪个IO引发了外部中断。P1IFG必须手动清除，否则将持续引发PORT1中断。
 * 范       例：无
 ******************************************************************************************************/
#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
    //-----启用Port1事件检测函数-----
    P1_IODect();                  //检测通过，则会调用事件处理函数     // 反转P1.0
    P1IFG = 0;                      //退出中断前必须手动清除IO口中断标志
}

#pragma vector = PORT2_VECTOR
__interrupt void PORT2_ISR(void)
{
    //-----启用Port2事件检测函数-----
    P2_IODect();                  //检测通过，则会调用事件处理函数     // 反转P4.7
    P2IFG = 0;                      //退出中断前必须手动清除IO口中断标志
}


