/*
 *	main.c
 *  Description:	
 *  Created on : Aug 14, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Toggle LED using External interrupt
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "HAL/HLED/HLED_interface.h"
#include "HAL/HBUTTON/HBUTTON_interface.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "MCAL/MGIE/MGIE_interface.h"
#include "MCAL/MEXTI/MEXTI_interface.h"
#include "MCAL/MDIO/MDIO_interface.h"

/* Functions to be called by EXTI ISR */
void EXTI0_voidFunc(void);
void EXTI1_voidFunc(void);

/* Flag to manage LCD access between super loop and interrupts */
u8 LCDFlag=0;
int main(void)
{

	HLCD_voidInit();	/* Initialize LCD */
	HLCD_voidSetPosition(0, 3);		/* Set LCD Position to row0 and col3 */
	HLCD_voidWriteString("Super Loop");		/* Write to LCD */
	HBUTTON_voidInit(PD2);	/* Initialize button at PD2 for EXTI0 */
	HBUTTON_voidInit(PD3);	/* Initialize button at PD3 for EXTI1 */
	HBUTTON_voidInternalPullUp(PD2);	/* Enable internal pull up */
	HBUTTON_voidInternalPullUp(PD3);	/* Enable internal pull up */

	MEXTI_voidInit();		/* Initialize external interrupt */
	MEXTI0_voidSetCallBack(EXTI0_voidFunc);	/* Set call back function for EXTI0 */
	MEXTI1_voidSetCallBack(EXTI1_voidFunc);	/* Set call back function for EXTI1 */

	MGIE_voidEnable();		/* Enable global interrupt */

	while (1)
	{
		/* Do nothing as long as flag=0 */
		if(LCDFlag!=0)
		{
			/* After returning from interrupt write again to LCD */
			HLCD_voidClearScreen();
			HLCD_voidSetPosition(0, 3);
			HLCD_voidWriteString("Super Loop");
			LCDFlag=0;
			_delay_ms(1000);
		}
	}
}

/* Function to execute when EXTI0 occurs */
void EXTI0_voidFunc(void)
{
	/* Interrupt occurred at EXTI0 */
	HLCD_voidClearScreen();
	HLCD_voidSetPosition(0, 5);
	HLCD_voidWriteString("EXTI0");
	LCDFlag=1;
	_delay_ms(1000);


}

/* Function to execute when EXTI1 occurs */
void EXTI1_voidFunc(void)
{
	/* Interrupt occurred at EXTI1 */
	HLCD_voidClearScreen();
	HLCD_voidSetPosition(0, 5);
	HLCD_voidWriteString("EXTI1");
	LCDFlag=1;
	_delay_ms(1000);


}

