/*
 *	main.c
 *  Description:	
 *  Created on : Aug 16, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Display temperature on LCD
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "MCAL/MADC/MADC_interface.h"
#include "MCAL/MGIE/MGIE_interface.h"

/* Function to get temperature reading after ADC conversion */
void Temp_voidGet(void);	
u16 result;


int main(void)
{

	HLCD_voidInit();	/* Initialize LCD */
	MADC_voidInit();	/* Initialize ADC */
	MADC_voidSetCallBack(POT_voidDisplay);	/* Set call back function */
	MGIE_voidEnable();	/* Enable Global Interrupt */
	while (1)
	{

		MADC_voidStartConversion();	/* Start ADC conversion */

		HLCD_voidClearScreen();	/* Clear LCD */
		HLCD_voidWriteString("Temp : ");		/* Write to LCD */
		/* Calculate temperature then write it to LCD */
		HLCD_voidWriteNumber(result*500/1023);
		HLCD_voidWriteString(" C");		/* Write to LCD */
		_delay_ms(1000);


	}
}


void Temp_voidGet(void)
{
	/* Get ADC digital value */
	result =MADC_u16GetDataAsynch();

}

