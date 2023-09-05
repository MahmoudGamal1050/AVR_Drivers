/*
 *	HKPD_config.h
 *  Description:	
 *  Created on : Aug 10, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef HAL_HKPD_HKPD_CONFIG_H_
#define HAL_HKPD_HKPD_CONFIG_H_

/* Keypad number of rows and columns */
#define KPD_ROWS 	4
#define KPD_COLS	4

/* Keypad rows pins */
#define KPD_ROW1_PIN	PA0
#define KPD_ROW2_PIN	PA1
#define KPD_ROW3_PIN	PA2
#define KPD_ROW4_PIN	PA3
/* Keypad columns pins */
#define KPD_COL1_PIN	PA4
#define KPD_COL2_PIN	PA5
#define KPD_COL3_PIN	PA6
#define KPD_COL4_PIN	PA7

/* Array that has keypad characters */
const u8 KPD_Number[KPD_ROWS][KPD_COLS] =
{
	{ '1', '2', '3', '+' },
	{ '4', '5', '6', '-' },
	{ '7', '8', '9', 'C' },
	{ '*', '0', '/', '=' }

};

#endif 
