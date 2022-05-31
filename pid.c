#include "pid.h"
float Kp=1.1,Ki=0.01;
float Position_KP=5;Position_KI=0;Position_KD=50;

//-----速度闭环控制-----
float Speed_PI(int Encoder,int Target)  // 实际值  目标值
{
     static float Bias,Pwm,Last_bias,Bias_Integral;
     Bias=Target-Encoder;                   // 误差计算
     Bias_Integral +=Bias;                  // 误差累计
     //Pwm+=Kp*(Bias-Last_bias)+Ki*Bias;   //增量式PI
     Pwm=Kp*Bias+Bias_Integral*Ki;   //位置式PI
     Last_bias=Bias;                       //
     return Pwm;                         //
}


float Position_PID(int Encoder,int Target)
 {
     static float Bias,Pwm,Integral_bias,Last_Bias;
     Bias=Target-Encoder;
     Integral_bias+=Bias;
     Pwm=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);
     Last_Bias=Bias;
     return Pwm;
}

//int velocity(int encoder_left)
//{
//        static float Velocity,Encoder_Least,Movement=0;
//        ki2=kp2/100;
//        Encoder_Least =Encoder_Left/25-0;
//        Encoder *= 0.8;
//        Encoder += Encoder_Least*0.2;
//        Encoder_Integral +=Encoder;
//        Encoder_Integral=Encoder_Integral-Movement;
//        if(Encoder_Integral>3000)      Encoder_Integral=3000;
//        if(Encoder_Integral<-3000) Encoder_Integral=-3000;
//        Velocity=Encoder*kp2+Encoder_Integral*ki2;
//        return Velocity;
//}


