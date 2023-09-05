/*
 *	main.c
 *  Description:	
 *  Created on : Aug 9, 2023
 *  Author     : Mahmoud Gamal
 *  Description: 2-digit SSD Counter
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HSSD/HSSD_interface.h"

/* Function to send 2-digit count to 7-sements */
void SSD_voidWriteCount(u8 copy_u8Num);
int main(void)
{

	

	HSSD_voidInit();		/* Initialize seven segment */
	/* Output pin to control first 7-segment */
	MDIO_voidSetPinDirection(PA3, DIO_OUTPUT);
	/* Output pin to control second 7-segment */
	MDIO_voidSetPinDirection(PA4, DIO_OUTPUT);
	/* Variable for LEDs to take turns */
	u8 count=0;
	while(1)
	{

		/* Count up using 2 7-segments  */
		SSD_voidWriteCount(count);
		/* Increment the counter */
		count++;
		
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
