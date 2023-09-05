/*
 *	main.c
 *  Description:	
 *  Created on : Aug 9, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Motor Lab 2
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HBUTTON/HBUTTON_interface.h"


int main(void)
{
	MDIO_voidSetPinDirection(PA1, DIO_OUTPUT);
	MDIO_voidSetPinValue(PA1, DIO_HIGH);

	HBUTTON_voidInit(PA0);
	HBUTTON_voidInternalPullUp(PA0);
	while(1)
	{
		if(!HBUTTON_u8GetValue(PA0))
		{
			MDIO_voidSetPinValue(PA1, DIO_LOW);
			while(!HBUTTON_u8GetValue(PA0))
			{

			}
			MDIO_voidSetPinValue(PA1, DIO_HIGH);



		}




	}
}


