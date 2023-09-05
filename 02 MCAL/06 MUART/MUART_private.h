/*
 *	MUART_private.h
 *  Description:	
 *  Created on : Aug 19, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MUART_MUART_PRIVATE_H_
#define MCAL_MUART_MUART_PRIVATE_H_

#define F_CPU 8000000UL				/* CPU frequency definition */
/* Calculate UBBR register value in asynchronous normal speed mode */
#define UBRR_NORMAL_SPEED(baud)     (F_CPU/(16UL*baud))-1
/* Calculate UBBR register value in asynchronous double speed mode */
#define UBRR_DOUBLE_SPEED(baud)     (F_CPU/(8UL*baud))-1
/* Calculate UBBR register value in synchronous mode */
#define UBRR_SYNC(baud)     		(F_CPU/(2UL*baud))-1


/*********************************************
* UART Registers Addresses Definition.  	 *
**********************************************/
/*USART I/O Data Register – UDR */
#define UDR       *((volatile u8 *) 0x2C)
/*USART Control and Status Register A –UCSRA */
#define UCSRA     *((volatile u8 *) 0x2B)
/*USART Control and Status Register B –UCSRB */
#define UCSRB     *((volatile u8 *) 0x2A)
/*USART Control and Status Register C –UCSRC */
#define UCSRC     *((volatile u8 *) 0x40)
/* USART Baud Rate Register Low – UBRRL */
#define UBRRL     *((volatile u8 *) 0x29)
/* USART Baud Rate Register High – UBRRH */
#define UBRRH     *((volatile u8 *) 0x40)


/* Control and Status Register-A (UCSRA) PINS Definition */
#define MPCM     0
#define U2X      1
#define PE       2
#define DOR      3
#define FE       4
#define UDRE     5
#define TXC      6
#define RXC      7


/* Control and Status Register-B (UCSRB) PINS Definition */
#define TXB8     0
#define RXB8     1
#define UCSZ2    2
#define TXEN     3
#define RXEN     4
#define UDRIE    5
#define TXCIE    6
#define RXCIE    7


/* Control and Status Register-C (UCSRC) PINS Definition */
#define UCPOL    0
#define UCSZ0    1
#define UCSZ1    2
#define USBS     3
#define UPM0     4
#define UPM1     5
#define UMSEL    6
#define URSEL    7


/* UART_MODE Definitions */
#define UART_NORMAL_SPEED  		0
#define UART_DOUBLE_SPEED  		1
#define UART_SYNC				2



/* UART_DATA_FRAME Definitions */
#define UART_5BitData 		0
#define UART_6BitData 		1
#define UART_7BitData 		2
#define UART_8BitData		3
#define UART_9BitData		7

/* UART_PARITY Definitions */
#define UART_DISABLE_PARITY		0
#define UART_EVEN_PARITY		2
#define UART_ODD_PARITY			3

/* UART_STOP_BITS Definitions */
#define UART_1_STOP_BIT			0
#define UART_2_STOP_BIT2		1

/* UART_CLOCK_POLARITY Definitions */
#define RISING_SAMPLING			0
#define FALLING_SAMPLING		1

/* UART ISR attribute */
#define ISR(vector)\
void vector (void) __attribute__((signal,used));\
void vector(void)






#endif /* MCAL_MUART_MUART_PRIVATE_H_ */
