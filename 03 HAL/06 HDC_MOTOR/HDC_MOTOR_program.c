/*
 *	HDC_MOTOR_program.c
 *  Description:	
 *  Created on : Aug 13, 2023
 *  Author     : Mahmoud Gamal
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/MDIO/MDIO_interface.h"
#include "../../MCAL/MTIMER/MTIMER_interface.h"

#include "HDC_MOTOR_private.h"
#include "HDC_MOTOR_config.h"
#include "HDC_MOTOR_interface.h"

/* define motor state enum with stop state at the beginning */
MotorState_t MotorState = STOP;

void HDCMOTOR_voidInit(void)
{
	/* Set motor control pins as output */
	MDIO_voidSetPinDirection(MOTOR_CW_PIN0, DIO_OUTPUT);
	MDIO_voidSetPinDirection(MOTOR_CW_PIN1, DIO_OUTPUT);
	MDIO_voidSetPinDirection(MOTOR_CCW_PIN0, DIO_OUTPUT);
	MDIO_voidSetPinDirection(MOTOR_CCW_PIN1, DIO_OUTPUT);

}

void HDCMOTOR_voidSetDirection(u8 copy_u8Direction)
{
	/* In case the direction is CW */
	if(copy_u8Direction==1)
	{
		/* Disable CCW control pins */
		MDIO_voidSetPinValue(MOTOR_CCW_PIN0, DIO_LOW);
		MDIO_voidSetPinValue(MOTOR_CCW_PIN1, DIO_LOW);
		/* Change motor state to CW */
		MotorState = CW;

	}
	/* In case the direction is CCW */
	else if (copy_u8Direction==2)
	{
		/* Disable CW control pins */
		MDIO_voidSetPinValue(MOTOR_CW_PIN0, DIO_LOW);
		MDIO_voidSetPinValue(MOTOR_CW_PIN1, DIO_LOW);
		/* Change motor state to CCW */
		MotorState = CCW;

	}

	else
	{
		/* Wrong Direction */
	}

}

void HDCMOTOR_voidStart(void)
{
	/* In case the direction is CW */
	if(MotorState==CW)
	{
		/* Enable CW control pins */
		MDIO_voidSetPinValue(MOTOR_CW_PIN0, DIO_HIGH);
		MDIO_voidSetPinValue(MOTOR_CW_PIN1, DIO_HIGH);

	}

	/* In case the direction is CCW */
	else if (MotorState==CCW)
	{
		/* Enable CCW control pins */
		MDIO_voidSetPinValue(MOTOR_CCW_PIN0, DIO_HIGH);
		MDIO_voidSetPinValue(MOTOR_CCW_PIN1, DIO_HIGH);

	}

	else
	{
		/* Wrong Direction */
	}



}
void HDCMOTOR_voidStop(void)
{
	/* In case the direction is CW */
	if(MotorState==CW)
	{
		MDIO_voidSetPinValue(MOTOR_CW_PIN0, DIO_LOW);
		MDIO_voidSetPinValue(MOTOR_CCW_PIN1, DIO_HIGH);

	}

	/* In case the direction is CCW */
	else if (MotorState==CCW)
	{
		MDIO_voidSetPinValue(MOTOR_CCW_PIN1, DIO_LOW);
		MDIO_voidSetPinValue(MOTOR_CW_PIN0, DIO_HIGH);

	}

	else
	{
		/* Wrong Direction */
	}



}

void HDCMOTOR_voidControlSpeed(u8 copy_u8Speed)
{
	MDIO_voidSetPinDirection(PB3, DIO_OUTPUT);
	MTIMER_voidInit();
	MTIMER_voidSetCompareValue(TIMER0, (u16)(copy_u8Speed*255)/100);
	MTIMER_voidGenerateFastPWMSignal(TIMER0);
	MTIMER_voidStart(TIMER0);

}

