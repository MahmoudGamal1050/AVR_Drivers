/*
 *	main.c
 *  Created on : Aug 16, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Input capture using timers
 */
#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MGIE/MGIE_interface.h"
#include "MCAL/MTIMER/MTIMER_interface.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLCD/HLCD_interface.h"

/* Generate PWM using timer0 :
 * 		 Duty cycle = 25% -> Compare value = 64
 * 		 F_CPU = 8MHz,prescalar =1024 ->Frequency = 8MHz/1024/255= 31Hz
 */
int main(void)
{
	u8 dutyCycle;
	u32 freq;
	/* Configure PB3(OC0) as output for timer0 PWM signal */
	MDIO_voidSetPinDirection(PB3, DIO_OUTPUT);
	/* Configure PD6(ICP1) as input for timer1 ICU */
	MDIO_voidSetPinDirection(PD6, DIO_INPUT);

	HLCD_voidInit();	/* initialize LCD */
	/* Write to LCD */
	HLCD_voidWriteString("Duty Cycle: ");
	HLCD_voidSetPosition(0, 15);
	HLCD_voidWriteData('%');
	HLCD_voidSetPosition(1, 0);
	HLCD_voidWriteString("Freq: ");
	HLCD_voidSetPosition(1, 10);
	HLCD_voidWriteString("HZ");
	/* Initialize the timers */
	MTIMER_voidInit();
	/* Set timer0 compare value with 64 to Genterate PWM with 25% duty cycle */
	MTIMER_voidSetCompareValue(TIMER0, 64);
	/* Genterate PWM on OC0 pin */
	MTIMER_voidGenerateFastPWMSignal(TIMER0);
	/* Start timer0 */
	MTIMER_voidStart(TIMER0);
	/* Get frequency and duty cycle of timer0 PWM using timer1 ICU */
	MTIMER1_voidGetICUFreqDutyCycle(&freq, &dutyCycle);
	/* Do nothing as long there is no signal */
	while((freq == 0)|(dutyCycle == 0));
	/* Write duty cycle to LCD */
	HLCD_voidSetPosition(0, 12);
	HLCD_voidWriteNumber(dutyCycle);
	/* Write frequency to LCD */
	HLCD_voidSetPosition(1, 6);
	HLCD_voidWriteNumber(freq);

	while (1)
	{

	}
}


