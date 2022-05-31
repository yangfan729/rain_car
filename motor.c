
#include "motor.h"
#include "include.h"


void Motor_Config(void) // 初始化电机控制引脚与PWM输入
{
    P1DIR|=BIT2;
    P1SEL|=BIT2;//输出PWM1波正转

    P7DIR |=BIT4+BIT0;
    P7OUT |=BIT4;    //AN1=1   反转
    P7OUT &=~BIT0;   //AN2=0
//    P7OUT &=~BIT4;    //AN1=0    正转
//    P7OUT |=BIT0;     //AN2=1

    TA0CCR0=MAX_PERIOD;             //10khz
    TA0CTL=TASSEL_2+MC_1+TACLR;
    TA0CCTL1=OUTMOD_7;//初始化模式
    Motor_PWM_Set_Left(2500);
//     Motor_PWM_Set_Right(1200);
}


void Motor_PWM_Set_Left(int motor1)
{
    if(motor1> MAX_PWM) motor1 = MAX_PWM;
    if(motor1<-MAX_PWM) motor1 =-MAX_PWM;

    if(motor1>=0)    //zhengzhuan
    {
//        P7OUT |=BIT4;    //AN1=1   反转
//        P7OUT &=~BIT0;   //AN2=0
          TA0CCR1=motor1;
    }
    else             //Fangzhuan
    {
//                 P7OUT &=~BIT4;    //AN1=0    正转
//                 P7OUT |=BIT0;     //AN2=1
          TA0CCR1 =-motor1;
    }
}

