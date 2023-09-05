/*
 *	MGIE_program.c
 *  Description:	
 *  Created on : Aug 14, 2023
 *  Author     : Mahmoud Gamal
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MGIE_private.h"
#include "MGIE_config.h"
#include "MGIE_interface.h"

void MGIE_voidEnable(void)
{
	/* Enable global interrupt */
	SET_BIT(SREG, GIE);
}

void MGIE_voidDisable(void)
{
	/* Disable global interrupt */
	CLR_BIT(SREG, GIE);
}
