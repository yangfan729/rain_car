
#ifndef __motor_H
#define __motor_H
#include <msp430.h>

#define MAX_PERIOD 2500
#define MAX_PWM 2400


void Motor_Config(void);
void Motor_PWM_Set(int motor1,int motor2);
void Motor_PWM_Set_Left(int motor1);
void Motor_PWM_Set_Right(int motor2);

#endif  
	 



