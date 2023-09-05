/*
 *	main.c
 *  Description:	
 *  Created on : Aug 9, 2023
 *  Author     : Mahmoud Gamal
 *  Description: LCD Assignment 1 ( writing name moving in sine wave )
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLCD/HLCD_interface.h"


int main(void)
{
	/* Initialize LCD */
	HLCD_voidInit();
	while(1)
	{

		/* Loop until reaching end of LCD */
		for(u8 i=0;i<10;i++)
		{
			/* Clear LCD */
			HLCD_voidClearScreen();
			/* Set cursor to different row every iteration
				and increment the column */
			HLCD_voidSetPosition(i%2, i);
			/* Write my name to LCD */
			HLCD_voidWriteString("Mahmoud");
			_delay_ms(1000);
		}

	}
}


