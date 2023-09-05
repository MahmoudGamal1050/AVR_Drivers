/*
 *	main.c
 *  Description:	
 *  Created on : Aug 9, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Traffic light assignment
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "HAL/HSSD/HSSD_interface.h"

/* Function to send 2-digit count to 7-sements */
void SSD_voidWriteCount(u8 copy_u8Num);
int main(void)
{

	/* Initialize LEDs */
	HLED_voidInit(PA0);		/* Red LED */
	HLED_voidInit(PA1);		/* Yellow LED */
	HLED_voidInit(PA2);		/* Green LED */
	HLED_voidWrite(PA0, LED_OFF);   /* Red LED is off at first */
	HLED_voidWrite(PA1, LED_OFF);   /* Yellow LED is off at first */
	HLED_voidWrite(PA2, LED_ON);    /* Green LED is on at first */

	HSSD_voidInit();		/* Initialize seven segment */
	/* Output pin to control first 7-segment */
	MDIO_voidSetPinDirection(PA3, DIO_OUTPUT);
	/* Output pin to control second 7-segment */
	MDIO_voidSetPinDirection(PA4, DIO_OUTPUT);
	/* Variable for LEDs to take turns */
	u8 ledState=0;
	/* Variable to determine max count of 7-segment */
	u8 count =10;

	while(1)
	{

		/* Loop to count down using 7-segments  */
		for(u8 j=count;j>0;j--)
		{	
			SSD_voidWriteCount(j);
		}
		

		if(ledState%2==0)
		{
			/* Turn on Yellow LED between Red and Green for 3s */
			HLED_voidWrite(PA0, LED_OFF);
			HLED_voidWrite(PA1, LED_ON);
			HLED_voidWrite(PA2, LED_OFF);
			
			/* Increment ledState to turn red or green LEDs next cycle */
			ledState++ ;
			/* Max count down is 3s for yellow led */
			count =3;
		}
		else if(ledState ==1)
		{
			/* Turn on Red LED */
			HLED_voidWrite(PA0, LED_ON);
			HLED_voidWrite(PA1, LED_OFF);
			HLED_voidWrite(PA2, LED_OFF);
			/* Increment ledState to turn yellow LED next cycle */
			ledState++;
			/* Max count down is 10s for red led */
			count =10;

		}

		else if(ledState ==3)

		{
			/* Turn on Green LED */
			HLED_voidWrite(PA0, LED_OFF);
			HLED_voidWrite(PA1, LED_OFF);
			HLED_voidWrite(PA2, LED_ON);
			/*  Turn yellow LED next cycle */
			ledState = 0;
			/* Max count down is 10s for green led */
			count =10;

		}

	}

}

void SSD_voidWriteCount(u8 copy_u8Num)
{
	/* Loop that approximately takes 1 second */
	for(int i=0;i<90;i++)
	{
		/* Disable both 7-segments */
		MDIO_voidSetPinValue(PA3, DIO_LOW);
		MDIO_voidSetPinValue(PA4, DIO_LOW);
		/* Write first digit to first 7-segment */
		HSSD_voidWrite(copy_u8Num%10);
		/* Enable first 7-segment */
		MDIO_voidSetPinValue(PA3, DIO_HIGH);
		_delay_ms(5);

		/* Disable both 7-segments */
		MDIO_voidSetPinValue(PA3, DIO_LOW);
		MDIO_voidSetPinValue(PA4, DIO_LOW);
		/* Write second digit to second 7-segment */
		HSSD_voidWrite(copy_u8Num/10);
		/* Enable second 7-segment */
		MDIO_voidSetPinValue(PA4, DIO_HIGH);
		_delay_ms(5);
	}
}
