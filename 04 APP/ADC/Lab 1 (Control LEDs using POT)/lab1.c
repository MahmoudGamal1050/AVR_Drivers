/*
 *	main.c
 *  Description:	
 *  Created on : Aug 20, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Control 3 LEDs using POT
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MADC/MADC_interface.h"
#include "HAL/HLED/HLED_interface.h"

int main(void)
{
	f32 result;		/* Float variable to save ADC result */
	MADC_voidInit();	/* Initialize ADC */
	/* Initialize 3 LEDs */
	HLED_voidInit(PB0);		/* Red LED */
	HLED_voidInit(PB1);		/* Yellow LED */
	HLED_voidInit(PB2);		/* Green Led */

	while (1)
	{

		MADC_voidStartConversion();	/* Start conversion */
		/* Get ADC digital value then calculate analog value */
		result = (f32)MADC_u16GetDataSynch()*5/1024;
		if(result>=0 && result<=1.5)
		{
			/* Turn on red LED and turn off the others */
			HLED_voidWrite(PB0, LED_ON);
			HLED_voidWrite(PB1, LED_OFF);
			HLED_voidWrite(PB2, LED_OFF);

		}
		else if(result>1.5 && result<=3)
		{
			/* Turn on red yellow and turn off the others */
			HLED_voidWrite(PB0, LED_OFF);
			HLED_voidWrite(PB1, LED_ON);
			HLED_voidWrite(PB2, LED_OFF);

		}
		else
		{
			/* Turn on green LED and turn off the others */
			HLED_voidWrite(PB0, LED_OFF);
			HLED_voidWrite(PB1, LED_OFF);
			HLED_voidWrite(PB2, LED_ON);

		}

		_delay_ms(200);





	}
}



