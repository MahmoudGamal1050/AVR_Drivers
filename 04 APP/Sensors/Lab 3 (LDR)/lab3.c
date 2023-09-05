/*
 *	main.c
 *  Description:	
 *  Created on : Aug 16, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Control LED using LDR
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MADC/MADC_interface.h"
#include "MCAL/MGIE/MGIE_interface.h"
#include "HAL/HLED/HLED_interface.h"

/* Function to get LDR reading after ADC conversion */
void LDR_voidGet(void);	
u16 result;


int main(void)
{
	HLED_voidInit(PB0);	/* Initialize LED at PB0 */
	MADC_voidInit();	/* Initialize ADC */
	MADC_voidSetCallBack(LDR_voidGet);	/* Set call back function */
	MGIE_voidEnable();	/* Enable Global Interrupt */
	while (1)
	{

		MADC_voidStartConversion();	/* Start ADC conversion */

		if(result<500)
		{
			/* Turn LED on when the room is dark */
			HLED_voidWrite(PB0, LED_ON);
		}
		else
		{
			/* Turn LED off when there is light */
			HLED_voidWrite(PB0, LED_OFF);
		}


	}
}

void LDR_voidGet(void)
{
	/* Get ADC digital value */
	result =MADC_u16GetDataAsynch();

}

