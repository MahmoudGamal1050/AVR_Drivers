/*
 *	main.c
 *  Created on : Aug 30, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Lab to control LEDs using Putty and UART
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MUART/MUART_interface.h"



int main(void)
{
	/* Set PORTA as output for 8 LEDs */
	MDIO_voidSetPortDirection(DIO_PORTA, DIO_OUTPUT);
	/* Initialize UART with 9600 baud rate */
	MUART_voidInit(9600);
	/* Variable to get data from UART */
	u8 data;

	while (1)
	{
		/* Receive data from UART */
		data = MUART_u16ReceiveData();
		/* Toggle the corresponding LED
		 * get the numbers from ascii by subtracting '0'
		 * LED0(PA0):LED7(PA7) -> 0:7
		 */
		MDIO_voidTogglePin(data-'0');


	}
}

