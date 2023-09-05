/*
 *	main.c
 *  Description:	
 *  Created on : Aug 13, 2023
 *  Author     : Mahmoud Gamal
 *  Description: DC Motor Assignment 1 ( Control direction through 2 buttons )
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HDC_MOTOR/HDC_MOTOR_interface.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "HAL/HBUTTON/HBUTTON_interface.h"

/* Enum to save motor state */
enum State
{
	CW,
	CCW,
	STOP
}MotorState;
int main(void)
{

	/* Initialize the DC motor */
	HDCMOTOR_voidInit();
	/* Initialize LCD */
	HLCD_voidInit();
	/* Initialize 2 buttons */
	HBUTTON_voidInit(PA6);
	HBUTTON_voidInit(PA7);
	/* Enable internal pull up for the buttons */
	HBUTTON_voidInternalPullUp(PA6);
	HBUTTON_voidInternalPullUp(PA7);

	/* Motor state is STOP at the beginning */
	MotorState=STOP;
	HLCD_voidWriteString("DC Motor Assign");
	HLCD_voidSetPosition(1, 0);
	HLCD_voidWriteString("Control Direction");

	while(1)
	{
		/* Check if first button (CW) is pressed */
		if(!HBUTTON_u8GetValue(PA6))
		{
			_delay_ms(100);
			if(!HBUTTON_u8GetValue(PA6))
			{
				/* Do nothing if the motor is already in CW state */
				if(MotorState!=CW)
				{
					/* Stop the motor */
					HDCMOTOR_voidStop();
					_delay_ms(1000);
					/* Change direction to CW */
					HDCMOTOR_voidSetDirection(CW_DIRECTION);
					/* Start the motor again */
					HDCMOTOR_voidStart();
				}
				/* Change motor state */
				MotorState =CW;
				/* Write state to LCD */
				HLCD_voidClearScreen();
				HLCD_voidWriteString("Direction : CW ");


			}
		}
		/* Check if second button (CCW) is pressed */
		if(!HBUTTON_u8GetValue(PA7))
		{
			_delay_ms(100);
			if(!HBUTTON_u8GetValue(PA7))
			{
				/* Do nothing if the motor is already in CCW state */
				if(MotorState!=CCW)
				{
					/* Stop the motor */
					HDCMOTOR_voidStop();
					_delay_ms(1000);
					/* Change direction to CCW */
					HDCMOTOR_voidSetDirection(CCW_DIRECTION);
					/* Start the motor again */
					HDCMOTOR_voidStart();
				}
				/* Change motor state */
				MotorState =CCW;
				/* Write state to LCD */
				HLCD_voidClearScreen();
				HLCD_voidWriteString("Direction : CCW ");

			}
		}




	}
}


