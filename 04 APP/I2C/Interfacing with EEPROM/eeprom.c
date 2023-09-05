/*
 *	main.c
 *  Description:	
 *  Created on : Sep 2, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Interface with EEPROM using I2C
 */


#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "MCAL/MI2C/MI2C_interface.h"
#include "HAL/HEEPROM/HEEPROM_interface.h"
int main(void)
{
	/* Variable to get data from EEPROM */
	u8 data;
	/* Initialize LCD */
	HLCD_voidInit();
	/* Write to LCD */
	HLCD_voidWriteString("Write'A'to EPROM");
	HLCD_voidSetPosition(1, 0);
	HLCD_voidWriteString("Then read it: ");
	/* Initialize EEPROM */
	HEEPROM_voidInit();
	/* Write 'A' at address 0x00ff */
	HEEPROM_voidWriteByte('A', 0x00ff);
	_delay_ms(10);
	/* Read the data from the same address */
	data = HEEPROM_u8ReadByte(0x00ff);
	/* Write data to LCD */
	HLCD_voidWriteData(data);

    while (1)
     {

     }
}




