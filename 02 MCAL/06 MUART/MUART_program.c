/*
 *	MUART_program.c
 *  Description:	
 *  Created on : Aug 19, 2023
 *  Author     : Mahmoud Gamal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MUART_private.h"
#include "MUART_config.h"
#include "MUART_interface.h"
#include "../MDIO/MDIO_interface.h"
void MUART_voidInit(u16 copy_u16Baudrate)
{
	/* Set baud rate depending on the mode using macro function */
#if UART_MODE== UART_NORMAL_SPEED
	/* Assign most significant bits to UBRRH */
	UBRRH = (u8)(UBRR_NORMAL_SPEED(copy_u16Baudrate))>>8;
	/* Assign least significant bits to UBRRL */
	UBRRL = UBRR_NORMAL_SPEED(copy_u16Baudrate);

#elif UART_MODE== UART_DOUBLE_SPEED
	/* Assign most significant bits to UBRRH */
	UBRRH = (u8)(UBRR_DOUBLE_SPEED(copy_u16Baudrate))>>8;
	/* Assign least significant bits to UBRRL */
	UBRRL = UBRR_DOUBLE_SPEED(copy_u16Baudrate);
	/* Enable UART asynchronous double speed mode */
	SET_BIT(UCSRA,U2X);


#elif UART_MODE== UART_SYNC
	/* Assign most significant bits to UBRRH */
	UBRRH = (u8)(UBRR_SYNC(copy_u16Baudrate))>>8;
	/* Assign least significant bits to UBRRL */
	UBRRL = UBRR_SYNC(copy_u16Baudrate));
	/* Select Asynchronous mode */
	UCSRC = (1<<URSEL)| (1<<UMSEL)

#endif

	/* Enable receiver and transmitter and assign data frame
	 * (UCSZ1:0) bits to UCSRB register */
	UCSRB = (UART_DATA_FRAME &0x04) |(1<<RXEN)|(1<<TXEN);
	/* Set parity state , stop bits , clock polarity and data frame(UCSZ2) bit */
	UCSRC |= (1<<URSEL)|(UART_PARITY<<UPM0)|(UART_STOP_BITS<<USBS)
			| (UART_CLOCK_POLARITY<<UCPOL) | ((UART_DATA_FRAME<<UCSZ0)&0x06);

}
void MUART_voidSendData(const u16 Copy_u16Data)
{
	/* Polls UDRE Flag to Check if TX Register UDR Can be Written */
	while(GET_BIT(UCSRA,UDRE)==0){ /* Do Nothing */ }

	if(UART_DATA_FRAME == UART_9BitData)
	{
		/* In case 9-bits data frame assign 9th bit to TXB8 bit of UCSRB register */
		UCSRB = (UCSRB & 0xFE)|((Copy_u16Data & (1<<8)) >> 8);
	}
	/* Assign Data to UDR Register to be Sent using UART */
	UDR = (u8)Copy_u16Data;

}

void MUART_u16SendString(u8 *Str)
{
	u8 Local_u8counter = 0;	/* Counter to parse the whole string */
	/* Loop until reaching null terminator */
	while(Str[Local_u8counter] != '\0')
	{
		/* Send character through UART */
		MUART_voidSendData(Str[Local_u8counter]);
		Local_u8counter++;	/* Increment the counter */
	}

}
u16 MUART_u16ReceiveData(void)
{
	u16 Local_u16Ret = 0;	/* Variable to return UART received data */

		/* Polls RXC flag to check if RX register UDR can be read for new incoming data */
		while((UCSRA & (1<<RXC))==0){ /* Do Nothing */ }

		if(UART_DATA_FRAME == UART_9BitData)
		{
			/* In case 9-bits data frame read 9th bit from RXB8 bit of UCSRB register */
			Local_u16Ret = (UCSRB & (1<<RXB8)) << 7;
		}

		Local_u16Ret |= UDR;	/* Assign UDR data to return variable */
		return Local_u16Ret;	/* Return data */
}
