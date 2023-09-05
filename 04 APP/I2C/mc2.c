/*
 *	main.c
 *  Description:	
 *  Created on : Aug 23, 2023
 *  Author     : Mahmoud Gamal
 *  Description: I2C test
 */

#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "MCAL/MI2C/MI2C_interface.h"
int main(void)
{
	HLCD_voidInit();
	MI2C_voidInitSlave();
	u8 data =MI2C_u8SlaveReceiveData();
	HLCD_voidWriteData(data);
	while (1)
     {

     }
}




