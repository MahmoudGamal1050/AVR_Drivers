/*
 *	HKPD_interface.h
 *  Description:	
 *  Created on : Aug 10, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef HAL_HKPD_HKPD_INTERFACE_H_
#define HAL_HKPD_HKPD_INTERFACE_H_

/* Function to initialize the keypad */
void HKPD_voidInit(void);
/* Function to get pressed key */
u8 HKPD_u8GetPressedKey(void);

#endif 
