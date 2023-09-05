/*
 *	main.c
 *  Description:	
 *  Created on : Aug 23, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Slave MC2
 */

#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "MCAL/MSPI/MSPI_interface.h"
int main(void)
{

	u8 message1[15] = "Hi I'm MC2";    /* First message */
	u8 message2[15] = "I'm okay";      /* Second Message */
	/* Initialize LCD */
	HLCD_voidInit();
	/* Initialize MC as SPI slave */
	MSPI_voidInitSlave();
	/* Send message1 */
	MSPI_voidReceiveString(message1);
	/* Write the received message to LCD */
	HLCD_voidWriteString(message1);
	/* Send message2 */
	MSPI_voidReceiveString(message2);
	/* Move cursor */
	HLCD_voidSetPosition(1, 0);
	/* Write the received message to LCD */
	HLCD_voidWriteString(message2);




	while (1)
     {



     }
}




