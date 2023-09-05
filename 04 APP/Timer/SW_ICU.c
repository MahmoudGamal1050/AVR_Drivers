/*
 *	main.c
 *  Description:	
 *  Created on : Aug 16, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Test timer
 */
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MGIE/MGIE_interface.h"
#include "MCAL/MTIMER/MTIMER_interface.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "MCAL/MEXTI/MEXTI_interface.h"
void ICU_SW(void);

/* Choose high prescalar for timer0 so that the processor could measure frequency
 *  and also high prescalar for timer1 to avoid overflow
 */
u8 timeOn=0;
u8 periodicTime=0;
u8 dutyCycle=0;


int main(void)
{
	MDIO_voidSetPinDirection(PB3, DIO_OUTPUT);
	MDIO_voidSetPinDirection(PD2, DIO_INPUT);


	HLCD_voidInit();
	HLCD_voidWriteString("Duty Cycle: ");
	HLCD_voidSetPosition(0, 15);
	HLCD_voidWriteData('%');
	HLCD_voidSetPosition(1, 0);
	HLCD_voidWriteString("Freq: ");
	HLCD_voidSetPosition(1, 9);
	HLCD_voidWriteString("HZ");



	MEXTI_voidSetCallBack(EXTI0, ICU_SW);
	MEXTI_voidEnable(EXTI0);
	MEXTI_voidSetSenseMode(EXTI0, RISING_EDGE);

	MTIMER_voidInit();
	MTIMER_voidSetCompareValue(TIMER0, 64);
	//MTIMER_voidSetCallBack(LED_voidToggle, TIMER1_COMPB_INTERRUPT);
	//MTIMER_voidInterruptEnable(TIMER1_COMPB_INTERRUPT);
	MTIMER_voidGenerateFastPWMSignal(TIMER0);
	MTIMER_voidStart(TIMER0);
	MGIE_voidEnable();
	while((timeOn == 0)|(periodicTime == 0));

	dutyCycle = timeOn*100/periodicTime;
	HLCD_voidSetPosition(0, 12);
	HLCD_voidWriteNumber(dutyCycle);
	HLCD_voidSetPosition(1, 9);
	HLCD_voidWriteNumber( (u16)7812/periodicTime);
	while (1)
	{




	}
}

void ICU_SW(void){


	static u8 Local_u8Counter = 0;
	Local_u8Counter++;

	if(1 == Local_u8Counter){

		/* First rising edge */
		MTIMER_voidStart(TIMER1);
		MEXTI_voidSetSenseMode(EXTI0, FALLING_EDGE);

	}
	else if(2 == Local_u8Counter){

		timeOn = MTIMER_u16Read(TIMER1);
		/* Change trigger to falling edge */
		MEXTI_voidSetSenseMode(EXTI0, RISING_EDGE);
	}
	else if(3 == Local_u8Counter){

		/* Timer reading now is period ticks + on ticks */
		periodicTime = MTIMER_u16Read(TIMER1);

		/* Disable INT0 interrupt */
		MEXTI_voidDisable(EXTI0);
	}

}


