/********************************************************************************/
/* File Name    	: 	LED_program.c   		                                */
/* Author       	: 	Mahmoud Gamal                                           */
/* Version      	: 	1.0.0                                                   */
/* Date 		 	: 	08/19/2023                                              */
/********************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/MDIO/MDIO_interface.h"
#include "HLED_config.h"
#include "HLED_interface.h"
#include "HLED_private.h"


/*********************************************************************************
***************************** Function Implementation ****************************
*********************************************************************************/


void HLED_voidInit(u8 Copy_u8PinNumber)
{
	/* Setting the pin as output */
	MDIO_voidSetPinDirection(Copy_u8PinNumber, DIO_OUTPUT);
	
	/* Setting the initial value as low */
	MDIO_voidSetPinValue(Copy_u8PinNumber, DIO_LOW);

}


void HLED_voidWrite(u8 Copy_u8PinNumber, u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
		case LED_ON :
			/* Setting the pin value as high */
			MDIO_voidSetPinValue(Copy_u8PinNumber, LED_MODE);
			break;

		case LED_OFF:
			/* Setting the pin value as low */
			MDIO_voidSetPinValue(Copy_u8PinNumber, !(LED_MODE));
			break;

		case LED_TOG:
			/* Setting the pin value as toggle */
			MDIO_voidTogglePin(Copy_u8PinNumber);
			break;
		

	}

}
