/*
 *	main.c
 *  Description:	
 *  Created on : Aug 23, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Master MC1
 */

#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "MCAL/MSPI/MSPI_interface.h"
int main(void)
{
	u8 message1[15] = "Hi I'm MC1";			/* First message */
	u8 message2[15] = "How are you?";		/* Second Message */
	/* Initialize MC as SPI master */
	MSPI_voidInitMaster();
	/* Enable slave select by writing low to PB4 */
	MDIO_voidSetPinValue(PB4, DIO_LOW);
	/* Initialize LCD */
	HLCD_voidInit();
	/* Send message1 */
	MSPI_voidSendString(message1);
	_delay_ms(1000);
	/* Write the received message to LCD */
	HLCD_voidWriteString(message1);
	_delay_ms(1000);
	/* Send message2 */
	MSPI_voidSendString(message2);
	_delay_ms(1000);
	/* Move cursor */
	HLCD_voidSetPosition(1, 0);
	/* Write the received message to LCD */
	HLCD_voidWriteString(message2);




	while (1)
     {

     }
}




