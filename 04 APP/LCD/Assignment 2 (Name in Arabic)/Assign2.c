/*
 *	main.c
 *  Description:	
 *  Created on : Aug 9, 2023
 *  Author     : Mahmoud Gamal
 *  Description: LCD Assignment 2 ( writing arabic name )
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HLCD/HLCD_interface.h"


int main(void)
{
	/* Array for each letter generated using LCD pattern generator */
	u8 letter0[] = {0x00,0x00,0x00,0x00,0x1f,0x09,0x0f,0x00};  	/* حرف الميم */
	u8 letter1[] = {0x00,0x00,0x0e,0x01,0x1f,0x00,0x00,0x00};  	/* حرف الحاء */
	u8 letter2[] = {0x00,0x00,0x0f,0x09,0x0f,0x01,0x06,0x0c};  	/* حرف الواو */
	u8 letter3[] = {0x00,0x00,0x06,0x01,0x0f,0x00,0x00,0x00};   /* حرف الدال */
	u8 letter4[] = {0x00,0x00,0x0e,0x01,0x1f,0x00,0x04,0x00};   /* حرف الجيم */
	u8 letter5[] = {0x04,0x04,0x04,0x04,0x07,0x00,0x00,0x00};   /* حرف الألف */
	u8 letter6[] = {0x01,0x01,0x01,0x11,0x11,0x0e,0x00,0x00};   /* حرف اللام */

	/* Initialize the LCD */
	HLCD_voidInit();
	/* Save all custom letters to CGRAM */
	HLCD_voidSaveCustomChar(letter0, 0);
	HLCD_voidSaveCustomChar(letter1, 1);
	HLCD_voidSaveCustomChar(letter2, 2);
	HLCD_voidSaveCustomChar(letter3, 3);
	HLCD_voidSaveCustomChar(letter4, 4);
	HLCD_voidSaveCustomChar(letter5, 5);
	HLCD_voidSaveCustomChar(letter6, 6);
	
	/* Set cursor */
	HLCD_voidSetPosition(0, 4);

	/* Write 'ل' letter */
	HLCD_voidWriteData(0x06);
	/* Write 'ا' letter */
	HLCD_voidWriteData(0x05);
	/* Write 'م' letter */
	HLCD_voidWriteData(0x00);
	/* Write 'ج' letter */
	HLCD_voidWriteData(0x04);
	/* Write space */
	HLCD_voidWriteData(' ');
	/* Write 'د' letter */
	HLCD_voidWriteData(0x03);
	/* Write 'و' letter */
	HLCD_voidWriteData(0x02);
	/* Write 'م' letter */
	HLCD_voidWriteData(0x00);
	/* Write 'ح' letter */
	HLCD_voidWriteData(0x01);
	/* Write 'م' letter */
	HLCD_voidWriteData(0x00);

	while(1)
	{

	}
}


