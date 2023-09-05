/*
 *	HKPD_program.c
 *  Description:	
 *  Created on : Aug 10, 2023
 *  Author     : Mahmoud Gamal
 */
#include <util/delay.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "HKPD_config.h"
#include "HKPD_interface.h"
#include "HKPD_private.h"
#include "../../MCAL/MDIO/MDIO_interface.h"
void HKPD_voidInit(void)
{
	/* Configure rows as input */
	MDIO_voidSetPinDirection(KPD_ROW1_PIN, DIO_INPUT);
	MDIO_voidSetPinDirection(KPD_ROW2_PIN, DIO_INPUT);
	MDIO_voidSetPinDirection(KPD_ROW3_PIN, DIO_INPUT);
	MDIO_voidSetPinDirection(KPD_ROW4_PIN, DIO_INPUT);
	/* Configure columns as output */
	MDIO_voidSetPinDirection(KPD_COL1_PIN, DIO_OUTPUT);
	MDIO_voidSetPinDirection(KPD_COL2_PIN, DIO_OUTPUT);
	MDIO_voidSetPinDirection(KPD_COL3_PIN, DIO_OUTPUT);
	MDIO_voidSetPinDirection(KPD_COL4_PIN, DIO_OUTPUT);
	/* Enable internal pull up for rows */
	MDIO_voidSetPinValue(KPD_ROW1_PIN, DIO_HIGH);
	MDIO_voidSetPinValue(KPD_ROW2_PIN, DIO_HIGH);
	MDIO_voidSetPinValue(KPD_ROW3_PIN, DIO_HIGH);
	MDIO_voidSetPinValue(KPD_ROW4_PIN, DIO_HIGH);
	/* Write high to all columns */
	MDIO_voidSetPinValue(KPD_COL1_PIN, DIO_HIGH);
	MDIO_voidSetPinValue(KPD_COL2_PIN, DIO_HIGH);
	MDIO_voidSetPinValue(KPD_COL3_PIN, DIO_HIGH);
	MDIO_voidSetPinValue(KPD_COL4_PIN, DIO_HIGH);


}
u8 HKPD_u8GetPressedKey(void)
{
	u8 Local_u8Row;		/* Variable to iterate rows */
	u8 Local_u8Col;		/* Variable to iterate columns */
	u8 Local_u8Key=0;	/* Variable to return pressed key */
	/* Loop for columns */
	for(Local_u8Col=0;Local_u8Col<KPD_COLS;Local_u8Col++)
	{
		/* Write low to this iteration column */
		MDIO_voidSetPinValue(KPD_COL1_PIN+Local_u8Col, DIO_LOW);
		/* Loop for rows */
		for(Local_u8Row=0;Local_u8Row<KPD_ROWS;Local_u8Row++)
		{
			/* Check if there is a pressed key */
			if(!MDIO_u8GetPinValue(KPD_ROW1_PIN+Local_u8Row))
			{
				/* Get pressed key from array */
				Local_u8Key=KPD_Number[Local_u8Row][Local_u8Col];
				/* Wait until the key is released */
				while(!MDIO_u8GetPinValue(KPD_ROW1_PIN+Local_u8Row));
				_delay_ms(10);
				break;
			}
		}
		/* Return the currnt column to high again */
		MDIO_voidSetPinValue(KPD_COL1_PIN+Local_u8Col, DIO_HIGH);

	}

	return Local_u8Key;

}


