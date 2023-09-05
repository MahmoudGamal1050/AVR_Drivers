/*
 *	main.c
 *  Description:	
 *  Created on : Aug 22, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Servo motor Assignment
 */

#include "util/delay.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HSERVO/HSERVO_interface.h"

int main(void)
{
	/* Set PD5 (OC1A) as output for PWM signal */
	MDIO_voidSetPinDirection(PD5, DIO_OUTPUT);
	/* initialize the servo */
	HSERVO_voidInit();
    while (1)
     {
    	/* Write angles to servo */
    	HSERVO_voidSetAngle(0);
    	_delay_ms(500);
    	HSERVO_voidSetAngle(45);
    	_delay_ms(500);
    	HSERVO_voidSetAngle(90);
    	_delay_ms(500);
    	HSERVO_voidSetAngle(135);
    	_delay_ms(500);
    	HSERVO_voidSetAngle(180);
   		_delay_ms(500);
    	HSERVO_voidSetAngle(135);
    	_delay_ms(500);
   		HSERVO_voidSetAngle(90);
    	_delay_ms(500);
    	HSERVO_voidSetAngle(45);
    	_delay_ms(500);
    	HSERVO_voidSetAngle(0);
    	_delay_ms(500);

     }
}




