/*
 *	main.c
 *  Description:	
 *  Created on : Aug 16, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Display POT readings on LCD
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "MCAL/MADC/MADC_interface.h"


int main(void)
{
	f32 result;		/* Float variable to save ADC result */
	HLCD_voidInit();	/* Initialize LCD */
	MADC_voidInit();	/* Initialize ADC */

	while (1)
	{

		MADC_voidStartConversion();	/* Start conversion */
		/* Get ADC digital value then calculate analog value */
		result = (f32)MADC_u16GetDataSynch()*5/1024;
		HLCD_voidClearScreen();	/* Clear LCD */
		HLCD_voidWriteString("POT : ");		/* Write to LCD */
		/* Write the analog value to LCD */
		HLCD_voidWriteFloatNumber(result);
		HLCD_voidWriteString(" v");		/* Write to LCD */
		_delay_ms(200);


	}
}



