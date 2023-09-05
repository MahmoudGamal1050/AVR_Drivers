/********************************************************************************/
/* File Name    	: 	HBUTTON_program.c   		                                */
/* Author       	: 	Mahmoud Gamal                                           */
/* Version      	: 	1.0.0                                                   */
/* Date 		 	: 	08/19/2023                                              */
/********************************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/MDIO/MDIO_interface.h"

#include "HBUTTON_private.h"

#include "HBUTTON_config.h"
#include "HBUTTON_interface.h"




/*********************************************************************************
***************************** Function Implementation ****************************
*********************************************************************************/

void HBUTTON_voidInit(u8 Copy_u8PinNumber)
{
	MDIO_voidSetPinDirection(Copy_u8PinNumber, DIO_INPUT);
}

u8 HBUTTON_u8GetValue(u8 Copy_u8PinNumber)
{

	return MDIO_u8GetPinValue(Copy_u8PinNumber);
}

void HBUTTON_voidInternalPullUp(u8 Copy_u8PinNumber)
{
	MDIO_voidSetPinValue(Copy_u8PinNumber, DIO_HIGH);
}

