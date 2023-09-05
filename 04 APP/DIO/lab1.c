/*
 *	main.c
 *  Description:	
 *  Created on : Aug 5, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Lab to turn on a LED
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/MDIO/MDIO_interface.h"

int main(void)
{
	MDIO_voidSetPinDirection(PA0,DIO_OUTPUT);
	MDIO_voidSetPinValue(PA0,DIO_HIGH);

	while(1)
	{



	}
}
