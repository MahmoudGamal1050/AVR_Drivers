/*
 *	main.c
 *  Description:	
 *  Created on : Aug 16, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Toggle 3 LEDs using timer
 */

/* F_CPU = 8000000, prescalar = 1024
 * tick_time = 1024/8000000 = 125 us
 * We need 8000 tick to count 1s (1s/125us)
 * Use timer1 in CTC mode with compare value = 8000
 */
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MGIE/MGIE_interface.h"
#include "MCAL/MTIMER/MTIMER_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "MCAL/MDIO/MDIO_interface.h"

/* Function to toggle 3 LEDs */
void LED_voidToggle(void);


int main(void)
{
	/* Initialize 3 LEDs */
	HLED_voidInit(PB0);
	HLED_voidInit(PB1);
	HLED_voidInit(PB2);

	MTIMER_voidInit();	/* Initialize the timer */
	/* Set compare value for timer1 as 8000 */
	MTIMER_voidSetCompareValue(TIMER1, 8000);
	/* Set call back function for timer1 channel A interrupt */
	MTIMER_voidSetCallBack(LED_voidToggle, TIMER1_COMPA_INTERRUPT);
	/* Enable interrupt for channel A compare match */
	MTIMER_voidInterruptEnable(TIMER1_COMPA_INTERRUPT);
	/* Start the timer */
	MTIMER_voidStart(TIMER1);
	MGIE_voidEnable();	/* Enable global interrupt */
	while (1)
	{

	}
}


void LED_voidToggle(void)
{
	static u8 Led_u8Flag=0;	/* Flag to determine which LEDs should be toggled */
	Led_u8Flag++;	/* Increment the flag every interrupt */
	/* Toggle LED1 every interrupt (1s) */
	HLED_voidWrite(PB0, LED_TOG);
	/* Toggle LED2 every 2 interrupts (2s) */
	if(Led_u8Flag%2 == 0)
	{
		HLED_voidWrite(PB1, LED_TOG);

	}
	/* Toggle LED3 every 3 interrupts (3) */
	if(Led_u8Flag%3 == 0)
	{
		HLED_voidWrite(PB2, LED_TOG);
	}






}

