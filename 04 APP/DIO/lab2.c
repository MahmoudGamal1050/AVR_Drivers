/*
 *	main.c
 *  Description:	
 *  Created on : Aug 5, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Lab to blink a LED
 */
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/MDIO/MDIO_interface.h"

int main(void)
{
	MDIO_voidSetPinDirection(PA0,DIO_OUTPUT);

	while(1)
	{
		MDIO_voidSetPinValue(PA0,DIO_HIGH);
		_delay_ms(1000);
		MDIO_voidSetPinValue(PA0,DIO_LOW);
		_delay_ms(1000);


	}
}
