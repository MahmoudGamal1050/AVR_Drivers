/*
 *	HSERVO_program.c
 *  Description:	
 *  Created on : Aug 22, 2023
 *  Author     : Mahmoud Gamal
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "HSERVO_private.h"
#include "HSERVO_config.h"
#include "HSERVO_interface.h"
#include "../../MCAL/MDIO/MDIO_interface.h"
#include "../../MCAL/MTIMER/MTIMER_interface.h"

/*	F_CPU = 8000000, prescalar = 8 -> tick time = 8/8MHz = 1us.
 * Servo needs pwm of 20ms -> Top value(ICR1) = 20ms/1us = 20000
 * Duty cycle should be between 1/20ms (0) to 2/20ms(180).
 *
 *
 */
void HSERVO_voidInit(void)
{
	/* Initialize timer1 in fast PWM and ICR1 as top */
	MTIMER_voidInit();
	/* Set ICR1 value to get 20ms PWM */
	MTIMER1_voidSetICR1(19999);


}
void HSERVO_voidSetAngle(u8 Copy_u8Angle)
{
	/* Calculate compare value(OCR1A) using the angle */
	MTIMER_voidSetCompareValue(TIMER1_OCR1A, ((u32)Copy_u8Angle*2150/180)+415);
	/* Generate fast PWM at OC1A pin */
	MTIMER_voidGenerateFastPWMSignal(TIMER1);
	/* Start the timer */
	MTIMER_voidStart(TIMER1);
}
