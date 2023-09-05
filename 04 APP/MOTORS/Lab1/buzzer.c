/*
 *	main.c
 *  Description:	
 *  Created on : Aug 9, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Buzzer Lab
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HBUZZER/HBUZZER_interface.h"

int main(void)
{
	HBUZZER_voidInit();

	while(1)
	{
		HBUZZER_voidTurnOn();
		_delay_ms(1000);
		HBUZZER_voidTurnOff();
		_delay_ms(1000);

	}




}


