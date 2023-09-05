/*
 *	MSPI_interface.h
 *  Description:	
 *  Created on : Aug 21, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MSPI_MSPI_INTERFACE_H_
#define MCAL_MSPI_MSPI_INTERFACE_H_

/* Function to initialize SPI as a master */
void MSPI_voidInitMaster(void);
/* Function to initialize SPI as a slave */
void MSPI_voidInitSlave(void);
/* Function to exchange master and slave data */
void MSPI_voidSendReceive(u8 *Copy_u8PtrData);
/* Function to send string through SPI */
void MSPI_voidSendStringBlocking(u8 *Copy_u8String);
/* Function to enable SPI interrupt when transfer is done */
void MSPI_voidEnableInterrupt(void);
/* Function to disable SPI interrupt */
void MSPI_voidDisableInterrupt(void);
/* Function to set a callback function to be called when SPI transfer interrupt occurs */
void MSPI_voidSetCallBack(void(*ptr)(void));
#endif /* MCAL_MSPI_MSPI_INTERFACE_H_ */
