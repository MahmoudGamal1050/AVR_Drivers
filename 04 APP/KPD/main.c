/*
 *	main.c
 *  Description:	
 *  Created on : Aug 9, 2023
 *  Author     : Mahmoud Gamal
 *  Description: keypad with 7-segment
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLED/HLED_interface.h"
#include "HAL/HKPD/HKPD_interface.h"
#include "HAL/HSSD/HSSD_interface.h"
int main(void)
{
	HKPD_voidInit();
	HSSD_voidInit();
	s8 key;
	HSSD_voidWrite(0);

	while(1)
	{
		/* If there is a pressed key, write it to 7-segment */ 
		key = HKPD_u8GetPressedKey();
		if(key!=-1)
		{
			HSSD_voidWrite(key);
		}

	}
}

