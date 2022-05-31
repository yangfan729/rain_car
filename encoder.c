
//#include "encoder.h"
#include "include.h"

int Target_Left=600, Target_Right=0;
int Position,PWM_Position;

int Position_Target = 5000;

int Encoder_Left,Encoder_Right;
int PWM_Left,PWM_Right,Encoder_Left_Show;
/////////////////////

unsigned int Last_capture,Over_flow_counter,Down_Last_capture;
unsigned long capture_num=0,CapFlag=0,Average_period,High_width;

float f, test_f1,test_f2,test_width;
///////////////
unsigned int  p1,p2;
unsigned long f1=0;f2=0;
unsigned int cap_one1=0,cap_one2=0;

void init_TA1(void)
{
      TA1CCTL0=CCIE;
      TA1CCR0=167;   //5ms  327  1/32768 * x = zms
      TA1CTL=TASSEL_1+MC_1+TACLR;
}

void init_TA2(void)
{
    TA2CTL=TASSEL_2+MC_2+TACLR+TAIE;//timer_A2设置
    P2DIR&=~BIT4;//left——A向
    P2DIR&=~BIT2;//left——B向
    P2SEL|=BIT4;//方波输入1,2启用定时器复用功能
    TA2CCTL1=CM_1+SCS+CAP+CCIE+CCIS_0;//cap1

    //P2SEL|=BIT5;//pwm输入2启用定时器复用功能
    // P2DIR&=~BIT5;//right—A向
    // P2DIR&=~BIT3;//right——B向
    //TA2CCTL2=CM_1+SCS+CAP+CCIE+CCIS_0;//cap2
}

void Encoder_Config(void)
{
    init_TA1(); //5ms中断
    init_TA2();//测频
}



//--------5ms定时中断----------
#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER1_A0_ISR(void)
{
      _EINT();  //允许中断，捕获中断具有更高的优先级

      Position=+CapFlag;
     // CapFlag=0;
      if(cap_one1==1)//left_motor  run forward
      {
          Encoder_Left=-f1;
          Encoder_Left_Show=-f1;
      }
      else if(cap_one1==2) //left_motor  run backward
      {
           Encoder_Left=f1;
           Encoder_Left_Show=f1;
      }

      if(Encoder_Left>=0)  //判断
       {
          // 位置环
          PWM_Position=Position_PID(Position,Position_Target);  //位置式位置控制PID
          Motor_PWM_Set_Left(PWM_Position);                     //PWM控制量写入寄存器


          // 速度环
//          PWM_Left=Speed_PI(Encoder_Left,Target_Left);// veocility control
//          Motor_PWM_Set_Left(PWM_Left);
//

          //PWM_Left=PWM_Left+ PWM_Position;
          //PWM_Left=Speed_PI(Encoder_Left,PWM_Position);// veocility control

       }
//       if(Encoder_Left<0)
//       {
//           PWM_Left=Position_PID(-Position,Position_Target);
//           PWM_Left=Speed_PI(-Encoder_Left,Target_Left);// veocility control
//           Motor_PWM_Set_Left(PWM_Left);
//       }


}

// 测量编码器的频率，即电机的转速 及 正反转
#pragma vector=TIMER2_A1_VECTOR
__interrupt void TIMER2_A1_ISR(void)
{
       switch(__even_in_range(TA2IV,14))
        {
        case  0: break;                   // No interrupt
        case  2 :                         // CCR1 捕获中断  即P2.4捕获中断
           {
              CapFlag++;   //捕获次数++
              p1=P2IN&BIT2; //读取left motor P2.2编码器B相的输入状态
              if(p1==4)
                   {cap_one1=1;}    //left motor 正转
              else
                   {cap_one1=2;}    //left motor 反转

              Average_period=Over_flow_counter*65535-Last_capture+TA2CCR1;  //测量两个上升沿的间隔的时钟个数
              Last_capture=TA2CCR1;         //当前上升沿捕获值保存
              Over_flow_counter=0;          //溢出清零
              f1=25000000/Average_period;   //f1肯定是正数

           }
               TA2CCTL1&=~CCIFG;             //清除中断
                 break;
        case  4: break;                          // CCR2 not used
        case  6: break;                          // reserved
        case  8: break;                          // reserved
        case 10: break;                          // reserved
        case 12: break;                          // reserved
        case 14:                                 // overflow TAFIG溢出中断
                Over_flow_counter++;
                TA2CTL&=~TAIFG;
                 break;
        default: break;

   }

}


