/*
 *	main.c
 *  Created on : Aug 9, 2023
 *  Author     : Mahmoud Gamal
 *  Description: LED Animation Assignment 2
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLED/HLED_interface.h"

/* Function to flash all LEDs every 500ms */
void LED_voidFlash(void);
/* Function to shift left the LEDs every 250ms */
void LED_voidShiftLeft(void);
/* Function to shift right the LEDs every 250ms */
void LED_voidShiftRight(void);
/* Function to converge 2 LEDs every 300ms */
void LED_voidConverge(void);
/* Function to diverge 2 LEDs every 300ms */
void LED_voidDiverge(void);
/* Function to apply ping pong effect every 250ms */
void LED_voidPingPong(void);
/* Function to apply snake effect every 300ms */
void LED_voidSnakeEffect(void);
/* Function to converge then diverge 2 LEDs every 300ms */
void LED_voidConvergeDiverge(void);


int main(void)
{
	/* Variables to have 3 DIP switches values	*/
	u8 dip1,dip2,dip3;
	/* Variables to have concatenated DIP value	*/
	u8 dip;
	/* Initialize 3 DIP switches to PA0:PA2 */
	HBUTTON_voidInit(PA0);
	HBUTTON_voidInit(PA1);
	HBUTTON_voidInit(PA2);
	/* Enable internal pull up resistors for every switches */
	HBUTTON_voidInternalPullUp(PA0);
	HBUTTON_voidInternalPullUp(PA1);
	HBUTTON_voidInternalPullUp(PA2);

	/* Configure PORTC as output for 8 LEDs */
	MDIO_voidSetPortDirection(DIO_PORTC, DIO_OUTPUT);
	/* All LEDs are off at the beginning */
	MDIO_voidSetPortValue(DIO_PORTC, 0x00);
	while(1)
	{
		/* store first switch state at bit0 */
		dip1 = !HBUTTON_u8GetValue(PA0);
		/* store second switch state at bit1 */
		dip2 = (!HBUTTON_u8GetValue(PA1))<<1;
		/* store third switch state at bit2 */
		dip3 = (!HBUTTON_u8GetValue(PA2))<<2;
		/* Concatenate all states in one variable */
		dip = dip1|dip2|dip3;
		switch(dip)
		{
			case 0 :
				LED_voidFlash();
				break;

			case 1 :
				LED_voidShiftLeft();
				break;

			case 2 :
				LED_voidShiftRight();
				break;

			case 3 :
				LED_voidConverge();
				break;

			case 4 :
				LED_voidDiverge();
				break;

			case 5 :
				LED_voidPingPong();
				break;

			case 6 :
				LED_voidSnakeEffect();
				break;

			case 7 :
				LED_voidConvergeDiverge();
				break;

			default :
				break;

		}

	}
}


void LED_voidFlash(void)
{
	/* Turn on all LEDs */
	MDIO_voidSetPortValue(DIO_PORTC, 0xFF);
	_delay_ms(500);
	/* Turn off all LEDs */
	MDIO_voidSetPortValue(DIO_PORTC, 0x00);
	_delay_ms(500);
}
void LED_voidShiftLeft(void)
{
	/* Turn on 1st LED at 1st iteration */
	u8 i= 0x01;
	/* Loop until over flow occurs */
	while(i!=0)
	{
		/* Turn on one LED at every iteration */
		MDIO_voidSetPortValue(DIO_PORTC, i);
		/* Shift left by 1 to turn on next LED */
		i <<= 1;
		_delay_ms(250);
	}


}
void LED_voidShiftRight(void)
{
	/* Turn on last LED at 1st iteration */
	u8 i=0b10000000;
	/* Loop until under flow occurs */
	while(i!=0)
	{
		/* Turn on one LED at every iteration */
		MDIO_voidSetPortValue(DIO_PORTC, i);
		/* Shift right by 1 to turn on next LED */
		i >>= 1;
		_delay_ms(250);
	}
}
void LED_voidConverge(void)
{
	/* Turn on 1st and 8th LEDs (0b1000 0001) */
	MDIO_voidSetPortValue(DIO_PORTC, 0x81);
	_delay_ms(300);
	/* Turn on 2nd and 7th LEDs (0b0100 0010) */
	MDIO_voidSetPortValue(DIO_PORTC, 0x42);
	_delay_ms(300);
	/* Turn on 3rd and 6th LEDs (0b0010 0100) */
	MDIO_voidSetPortValue(DIO_PORTC, 0x24);
	_delay_ms(300);
	/* Turn on 4th and 5th LEDs (0b0001 1000) */
	MDIO_voidSetPortValue(DIO_PORTC, 0x18);
	_delay_ms(300);

}
void LED_voidDiverge(void)
{
	/* Turn on 4th and 5th LEDs (0b0001 1000) */
	MDIO_voidSetPortValue(DIO_PORTC, 0x18);
	_delay_ms(300);
	/* Turn on 3rd and 6th LEDs (0b0010 0100) */
	MDIO_voidSetPortValue(DIO_PORTC, 0x24);
	_delay_ms(300);
	/* Turn on 2nd and 7th LEDs (0b0100 0010) */
	MDIO_voidSetPortValue(DIO_PORTC, 0x42);
	_delay_ms(300);
	/* Turn on 1st and 8th LEDs (0b1000 0001) */
	MDIO_voidSetPortValue(DIO_PORTC, 0x81);
	_delay_ms(300);
}

void LED_voidPingPong(void)
{
	/* Shift LEDs left until overflow */
	for(u8 i =1; i!=0 ; i<<=1)
	{
		MDIO_voidSetPortValue(DIO_PORTC, i);
		_delay_ms(250);

	}

	/* Shift LEDs right until underflow */
	for(u8 i =0x80; i!=0 ; i>>=1)
	{
		MDIO_voidSetPortValue(DIO_PORTC, i);
		_delay_ms(250);
	}


}

void LED_voidSnakeEffect(void)
{
	/* Turn on 1st LED */
	HLED_voidWrite(PC0, DIO_HIGH);
	_delay_ms(250);
	/* Turn on 2nd LED */
	HLED_voidWrite(PC1, DIO_HIGH);
	_delay_ms(250);
	/* Turn on 3rd LED */
	HLED_voidWrite(PC2, DIO_HIGH);
	_delay_ms(250);
	/* Turn on 4th LED */
	HLED_voidWrite(PC3, DIO_HIGH);
	_delay_ms(250);
	/* Turn on 5th LED */
	HLED_voidWrite(PC4, DIO_HIGH);
	_delay_ms(250);
	/* Turn on 6th LED */
	HLED_voidWrite(PC5, DIO_HIGH);
	_delay_ms(250);
	/* Turn on 7th LED */
	HLED_voidWrite(PC6, DIO_HIGH);
	_delay_ms(250);
	/* Turn on 8th LED */
	HLED_voidWrite(PC7, DIO_HIGH);
	_delay_ms(250);
	/* Turn off all LEDs */
	MDIO_voidSetPortValue(DIO_PORTC, 0x00);
	_delay_ms(250);


}
void LED_voidConvergeDiverge(void)
{
	/* Call converge function */
	LED_voidConverge();
	/* Then Call diverge function */
	LED_voidDiverge();
}
