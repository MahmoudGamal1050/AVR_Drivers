/*
 *	main.c
 *  Description:	
 *  Created on : Aug 6, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Lab to make LED animation
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"

int main(void)
{
	u8 led=1;
	MDIO_voidSetPortDirection(DIO_PORTB, DIO_OUTPUT);
	while(1)
	{
		MDIO_voidSetPortValue(DIO_PORTB, led);
		_delay_ms(1000);
		led <<= 1;
		if(led==0)
		{
			led=1;
		}


	}
}
