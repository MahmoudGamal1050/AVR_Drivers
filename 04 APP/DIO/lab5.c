/*
 *	main.c
 *  Description:	
 *  Created on : Aug 6, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Lab to use 7-segment
 */
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HSSD/HSSD_interface.h"

int main(void)
{
	HSSD_voidInit();
	u8 num=0;
	while(1)
	{
		HSSD_voidWrite(num);
		num++;
		if(num==10)
		{
			num=0;
		}
		_delay_ms(1000);




	}
}
