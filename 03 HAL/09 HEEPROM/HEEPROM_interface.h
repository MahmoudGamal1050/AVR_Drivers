/*
 *	interface.h
 *  Description:	
 *  Created on : Sep 2, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef HAL_HEEPROM_HEEPROM_INTERFACE_H_
#define HAL_HEEPROM_HEEPROM_INTERFACE_H_


/**********************************************************
************ Functions Prototypes *************************
***********************************************************/

/* Function to initialize EEPROM */
void HEEPROM_voidInit(void);
/* Function to write to EEPROM */
void HEEPROM_voidWriteByte(u8 Copy_u8Data, u16 Copy_u16Address);
/* Function to read from EEPROM */
u8 HEEPROM_u8ReadByte(u16 Copy_u16Address);

#endif /* HAL_HEEPROM_HEEPROM_INTERFACE_H_ */
