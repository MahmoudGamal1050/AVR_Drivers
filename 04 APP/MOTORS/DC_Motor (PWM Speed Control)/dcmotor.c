/*
 *	main.c
 *  Description:	
 *  Created on : Aug 22, 2023
 *  Author     : Mahmoud Gamal
 *  Description: DC Motor Control using PWM 
 */

#include "util/delay.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HDC_MOTOR/HDC_MOTOR_interface.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "HAL/HBUTTON/HBUTTON_interface.h"
int main(void)
{
	u8 speed=0;	/* Variable to save motor speed */
	HLCD_voidInit();	/* Initialize LCD */
	/* Set PC0 and PC1 as output for motor driver control */
	MDIO_voidSetPinDirection(PC0, DIO_OUTPUT);
	MDIO_voidSetPinDirection(PC1, DIO_OUTPUT);
	MDIO_voidSetPinValue(PC0, DIO_HIGH);
	/* Initialize 2 switches to control motor speed */
	HBUTTON_voidInit(PB0);	/* Button to increase speed */
	HBUTTON_voidInit(PB1);	/* Button to decrease speed */

    while (1)
     {
		 /* First button is pressed */
    	if(HBUTTON_u8GetValue(PB0)==0)
    	{
			/* Wait until button is released */
    		while(HBUTTON_u8GetValue(PB0)==0);
    		speed +=10;		/* Increment speed */
			/* Speed max value is 100% */
    		if(speed>100)
    		{
    			speed=100;
    		}
			/* Set motor speed using timer0 PWM */ 
        	HDCMOTOR_voidControlSpeed(speed);
			/* Write speed to LCD */
        	HLCD_voidClearScreen();
        	HLCD_voidWriteString("  Motor Speed ");
        	HLCD_voidSetPosition(1, 6);
        	HLCD_voidWriteNumber(speed);
        	HLCD_voidSetPosition(1, 10);
        	HLCD_voidWriteData('%');
    	}
		 /* Second button is pressed */
    	if(HBUTTON_u8GetValue(PB1)==0)
    	{
			/* Wait until button is released */
    		while(HBUTTON_u8GetValue(PB1)==0);
    		speed -=10;	/* Decrement Speed */
			/* Speed minimum value is 0% */
       		if(speed>100)
        	{
        		speed=0;
        	}
			/*Set motor speed using timer0 PWM */ 
        	HDCMOTOR_voidControlSpeed(speed);
			/* Write speed to LCD */
        	HLCD_voidClearScreen();
        	HLCD_voidWriteString("  Motor Speed ");
        	HLCD_voidSetPosition(1, 6);
        	HLCD_voidWriteNumber(speed);
        	HLCD_voidSetPosition(1, 10);
        	HLCD_voidWriteData('%');

    	}


     }
}




