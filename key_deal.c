//#include "include.h"
//
//
//void  KEY_GPIO_init(void)
//{
//    P2DIR &=~(BIT1);                //设置 P2.1,P1.1设置为输入
//    P1DIR &=~(BIT1);                //设置 P2.1,P1.1设置为输入
//    P2OUT |=BIT1;                   // P2.1输出高电平,
//    P2REN |=BIT1;                   // P2.1内部上拉
//    P1OUT |=BIT1;                   // P1.1 输出高电平,
//    P1REN |=BIT1;                   // P1.1内部上拉
//
//    P1IES |= BIT1;                  // P1.1设为下降沿中断
//    P1IE  |= BIT1 ;                 // 允许P1.1中断
//
//    P2IES |= BIT1;                  // P2.1设为下降沿中断
//    P2IE  |= BIT1 ;                 // 允许P2.1中断
//}
//
//void P1_IODect()
//{
//    unsigned int Push_Key=0;
//    //-----排除输出IO的干扰后，锁定唯一被触发的中断标志位-----
//    Push_Key=P1IFG&(~P1DIR);
//    //-----延时一段时间，避开机械抖动区域-----
//    __delay_cycles(100000);                //消抖延时
//    //----判断按键状态是否与延时前一致-----
//    if((P1IN&Push_Key)==0)                //如果该次按键确实有效
//   {
//     //----判断具体哪个IO被按下，调用该IO的事件处理函数-----
//      switch(Push_Key)
//      {
////   case BIT0:    P10_Onclick();      break;
//     case BIT1:     P11_Onclick();      break;
////   case BIT2:     P12_Onclick();      break;
////    case BIT3:     P13_Onclick();      break;
////   case BIT4:     P14_Onclick();      break;
////   case BIT5:     P15_Onclick();      break;
////   case BIT6:     P16_Onclick();      break;
////   case BIT7:     P17_Onclick();      break;
//     default:        break;      //任何情况下均加上default
//     }
//   }
//}
//
///******************************************************************************************************
// * 名       称：P1_IODect()
// * 功       能：判断具体引发中断的IO，并调用相应IO的中断事件处理函数
// * 入口参数：无
// * 出口参数：无
// * 说       明：该函数兼容所有8个IO的检测，请根据实际输入IO激活“检测代码”。
// * 本例中，仅有P1.1被用作输入IO，所以其他7个IO的“检测代码”没有被“激活”。
// * 范       例：无
// ******************************************************************************************************/
//void P2_IODect()
//{
//    unsigned int Push_Key=0;
//    //-----排除输出IO的干扰后，锁定唯一被触发的中断标志位-----
//    Push_Key=P2IFG&(~P2DIR);
//    //-----延时一段时间，避开机械抖动区域-----
//    __delay_cycles(100000);                //消抖延时
//    //----判断按键状态是否与延时前一致-----
//    if((P2IN&Push_Key)==0)                //如果该次按键确实有效
//   {
//     //----判断具体哪个IO被按下，调用该IO的事件处理函数-----
//      switch(Push_Key)
//      {
////   case BIT0:    P10_Onclick();      break;
//     case BIT1:     P21_Onclick();      break;
////   case BIT2:     P12_Onclick();      break;
////   case BIT3:     P13_Onclick();      break;
////   case BIT4:     P14_Onclick();      break;
////   case BIT5:     P15_Onclick();      break;
////   case BIT6:     P16_Onclick();      break;
////   case BIT7:     P17_Onclick();      break;
//     default:        break;      //任何情况下均加上default
//     }
//   }
//}
//
///******************************************************************************************************
// * 名       称：P21_Onclick()
// * 功       能：P2.1的中断事件处理函数，即当P2.1键被按下后，下一步干什么
// * 入口参数：无
// * 出口参数：无
// * 说       明：使用事件处理函数的形式，可以增强代码的移植性和可读性
// * 范       例：
// ******************************************************************************************************/
///******************************************************************************************************
// * 名       称：P11_Onclick()
// * 功       能：P1.1的中断事件处理函数，即当P1.2键被按下后，下一步干什么
// * 入口参数：无
// * 出口参数：无
// * 说       明：使用事件处理函数的形式，可以增强代码的移植性和可读性
// * 范       例：无
// ******************************************************************************************************/
//void  P11_Onclick(void)
//{
//    P1OUT ^= BIT0;
//    Position_Target = Position_Target + 1000;
//    //Draw_LQLogo();  //显示图片
//}
//
//
//void  P21_Onclick(void)
//{
//    P4OUT ^= BIT7;
//}
//
//
