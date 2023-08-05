/*********************************************************************
* File Name    	: 	BIT_MAT.h                                        *
* Author       	: 	Mahmoud Gamal                                    *
* Version      	: 	1.0.0                                            *
* Date  		: 	5/8/2023                                         *
* Description   : 	DIO APIs implementation                          *                         */
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
void DIO_voidSetPinDirection(u8 copy_u8Pin, u8 copy_u8Mode)
{
	if(copy_u8Mode==DIO_INPUT)
	{
		if(copy_u8Pin>=0 && copy_u8Pin<=7)
		{
			CLR_BIT (DDRA,copy_u8Pin);
		}
		else if(copy_u8Pin>=8 && copy_u8Pin<=15)
		{
			CLR_BIT (DDRB,copy_u8Pin-8);
		}
		else if(copy_u8Pin>=16 && copy_u8Pin<=23)
		{
			CLR_BIT (DDRC,copy_u8Pin-16);
		}
		else if(copy_u8Pin>=24 && copy_u8Pin<=31)
		{
			CLR_BIT (DDRD,copy_u8Pin-24);
		}
		else
		{
			/* Wrong DIO pin number */
		}
	}
	else if(copy_u8Mode==DIO_OUTPUT )
	{
		if(copy_u8Pin>=0 && copy_u8Pin<=7)
		{
			SET_BIT (DDRA,copy_u8Pin);
		}
		else if(copy_u8Pin>=8 && copy_u8Pin<=15)
		{
			SET_BIT (DDRB,copy_u8Pin-8);
		}
		else if(copy_u8Pin>=16 && copy_u8Pin<=23)
		{
			SET_BIT (DDRC,copy_u8Pin-16);
		}
		else if(copy_u8Pin>=24 && copy_u8Pin<=31)
		{
			SET_BIT (DDRD,copy_u8Pin-24);
		}
		else
		{
			/* Wrong DIO pin number */
		}
		
	}
	
	else
	{
		/* Wrong DIO mode */
	}
}
void DIO_voidSetPinValue(u8 copy_u8Pin, u8 copy_u8Value)
{
	if(copy_u8Value==DIO_LOW)
	{
		if(copy_u8Pin>=0 && copy_u8Pin<=7)
		{
			CLR_BIT (PORTA,copy_u8Pin);
		}
		else if(copy_u8Pin>=8 && copy_u8Pin<=15)
		{
			CLR_BIT (PORTB,copy_u8Pin-8);
		}
		else if(copy_u8Pin>=16 && copy_u8Pin<=23)
		{
			CLR_BIT (PORTC,copy_u8Pin-8);
		}
		else if(copy_u8Pin>=24 && copy_u8Pin<=31)
		{
			CLR_BIT (PORTD,copy_u8Pin-24);
		}
		else
		{
			/* Wrong DIO pin number */
		}

	}
	else if(copy_u8Value==DIO_HIGH )
	{
		if(copy_u8Pin>=0 && copy_u8Pin<=7)
		{
			SET_BIT (PORTA,copy_u8Pin);
		}
		else if(copy_u8Pin>=8 && copy_u8Pin<=15)
		{
			SET_BIT (PORTB,copy_u8Pin-8);
		}
		else if(copy_u8Pin>=16 && copy_u8Pin<=23)
		{
			SET_BIT (PORTC,copy_u8Pin-16);
		}
		else if(copy_u8Pin>=24 && copy_u8Pin<=31)
		{
			SET_BIT (PORTD,copy_u8Pin-24);
		}
		else
		{
			/* Wrong DIO pin number */
		}
		
	}
	
	else
	{
		/* Wrong DIO mode */
	}
}
void DIO_voidTogglePin(u8 copy_u8Pin)
{
	if(copy_u8Pin>=0 && copy_u8Pin<=7)
	{
		TOG_BIT (PORTA,copy_u8Pin);
	}
	else if(copy_u8Pin>=8 && copy_u8Pin<=15)
	{
		TOG_BIT (PORTB,copy_u8Pin-8);
	}
	else if(copy_u8Pin>=16 && copy_u8Pin<=23)
	{
		TOG_BIT (PORTC,copy_u8Pin-16);
	}
	else if(copy_u8Pin>=24 && copy_u8Pin<=31)
	{
		TOG_BIT (PORTD,copy_u8Pin-24);
	}
	else
	{
		/* Wrong DIO pin number */
	}
	
}

u8 DIO_u8GetPinValue(u8 copy_u8Pin)
{
	u8 Local_u8PinValue;
	if(copy_u8Pin>=0 && copy_u8Pin<=7)
	{
		Local_u8PinValue = GET_BIT (PINA,copy_u8Pin);
	}
	else if(copy_u8Pin>=8 && copy_u8Pin<=15)
	{
		Local_u8PinValue = GET_BIT (PORTB,copy_u8Pin-8);
	}
	else if(copy_u8Pin>=16 && copy_u8Pin<=23)
	{
		Local_u8PinValue = GET_BIT (PORTC,copy_u8Pin-16);
	}
	else if(copy_u8Pin>=24 && copy_u8Pin<=31)
	{
		Local_u8PinValue = GET_BIT (PORTD,copy_u8Pin-24);
	}
	else
	{
		/* Wrong DIO pin number */
	}
	
	return Local_u8PinValue;
	
	
}
