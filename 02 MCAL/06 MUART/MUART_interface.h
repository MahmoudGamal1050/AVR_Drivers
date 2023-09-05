/*
 *	MUART_interface.h
 *  Description:	
 *  Created on : Aug 19, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MUART_MUART_INTERFACE_H_
#define MCAL_MUART_MUART_INTERFACE_H_

/* Function to initialize UART with a certain baud rate */
void MUART_voidInit(u16 copy_u16Baudrate);
/* Function to send data through UART */
void MUART_voidSendData(u16 Copy_u16Data);
/* Function to send string through UART */
void MUART_u16SendString(u8 *Str);
/* Function to receive through UART */
u16 MUART_u16ReceiveData(void);

#endif /* MCAL_MUART_MUART_INTERFACE_H_ */
