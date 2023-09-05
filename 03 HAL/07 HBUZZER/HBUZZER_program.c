/*
 *	HBUZZER_program.c
 *  Description:	
 *  Created on : Aug 13, 2023
 *  Author     : Mahmoud Gamal
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "HBUZZER_private.h"
#include "HBUZZER_config.h"
#include "HBUZZER_interface.h"
#include "../../MCAL/MDIO/MDIO_interface.h"

void HBUZZER_voidInit(void)
{
	/* Set control pin as output */
	MDIO_voidSetPinDirection(BUZZER_CONTROL_PIN, DIO_OUTPUT);
}

void HBUZZER_voidTurnOn(void)
{
	/* Write high to control pin to enable the buzzer */
	MDIO_voidSetPinValue(BUZZER_CONTROL_PIN, DIO_HIGH);
}
void HBUZZER_voidTurnOff(void)
{
	/* Write low to control pin to disable the buzzer */
	MDIO_voidSetPinValue(BUZZER_CONTROL_PIN, DIO_LOW);

}
