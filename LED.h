#ifndef __LED_H
#define __LED_H

#include <msp430F5529.h>


//****************************************************


#define LED1_PORT_DIR   P1DIR
#define LED1_PORT_IN    P1IN
#define LED1_PORT_OUT   P1OUT
#define LED1_BIT        BIT0

#define LED1_ON         LED1_PORT_OUT |=  LED1_BIT //
#define LED1_OFF        LED1_PORT_OUT &= ~LED1_BIT
#define LED1_REVERSE    P1OUT ^= BIT0   //LED1_PORT_OUT ^=LED1_BIT

//****************************************************
#define LED2_PORT_DIR   P4DIR
#define LED2_PORT_IN    P4IN
#define LED2_PORT_OUT   P4OUT
#define LED2_BIT        BIT7

#define LED2_ON         LED2_PORT_OUT |=  LED2_BIT
#define LED2_OFF        LED2_PORT_OUT &= ~LED2_BIT
#define LED2_REVERSE    LED2_PORT_OUT^=LED2_BIT
//****************************************************

void Init_LED(void);

void LED1_Reverse(void);
void LED1_Test(void);

void LED2_Reverse(void);
void LED2_Test(void);

#endif


//------------------End of File----------------------------
