/*
 *	MEXTI_program.c
 *  Description:	
 *  Created on : Aug 14, 2023
 *  Author     : Mahmoud Gamal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../MDIO/MDIO_interface.h"
#include "MEXTI_private.h"
#include "MEXTI_config.h"
#include "MEXTI_interface.h"

static void (*EXTI0_CallBack)(void)= NULL;
static void (*EXTI1_CallBack)(void)= NULL;
static void (*EXTI2_CallBack)(void)= NULL;



void MEXTI_voidEnable(u8 copy_u8EXTINumber)
{
	switch(copy_u8EXTINumber)
	{
		case EXTI0 :
			/* Enable peripheral interrupt */
			SET_BIT(GICR,INT0);
			break;
		case EXTI1 :
			/* Enable peripheral interrupt */
			SET_BIT(GICR,INT1);
			break;
		case EXTI2 :
			/* Enable peripheral interrupt */
			SET_BIT(GICR,INT2);
			break;



	}
}
void MEXTI_voidDisable(u8 copy_u8EXTINumber)
{
	switch(copy_u8EXTINumber)
	{
		case EXTI0 :
			/* Disable peripheral interrupt */
			CLR_BIT(GICR,INT0);
			break;
		case EXTI1 :
			/* Disable peripheral interrupt */
			CLR_BIT(GICR,INT1);
			break;
		case EXTI2 :
			/* Disable peripheral interrupt */
			CLR_BIT(GICR,INT2);
			break;

	}
}
void MEXTI_voidSetSenseMode(u8 copy_u8EXTINumber, u8 copy_u8SenseMode)
{
	switch(copy_u8EXTINumber)
	{
		case EXTI0 :
			MCUCR = (MCUCR&0xFC) | (copy_u8SenseMode);
			break;
		case EXTI1 :
			MCUCR = (MCUCR&0xF3) | (copy_u8SenseMode);
			break;
		case EXTI2 :
			MCUCR = (MCUCR&0xBF) | (copy_u8SenseMode);
			break;

	}
}

void MEXTI_voidSetCallBack(u8 copy_u8EXTINumber,void(*ptr)(void))
{
	switch(copy_u8EXTINumber)
	{
		case EXTI0 :
			EXTI0_CallBack =ptr;
			break;
		case EXTI1 :
			EXTI1_CallBack =ptr;
			break;
		case EXTI2 :
			EXTI2_CallBack =ptr;
			break;

	}
}


ISR(__vector_1)
{
	EXTI0_CallBack();
}

ISR(__vector_2)
{
	EXTI1_CallBack();
}

ISR(__vector_3)
{
	EXTI2_CallBack();
}
