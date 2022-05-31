
#ifndef __encoder_H
#define __encoder_H
#include <msp430.h>

extern int Encoder_Left,Encoder_Right;
extern  int PWM_Left,PWM_Right;
extern  int Encoder_Left_Show;
extern int Position_Target;
void Encoder_Config(void);

#endif  
	 



