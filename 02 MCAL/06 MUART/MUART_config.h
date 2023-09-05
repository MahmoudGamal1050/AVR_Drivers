/*
 *	MUART_config.h
 *  Description:	
 *  Created on : Aug 19, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MUART_MUART_CONFIG_H_
#define MCAL_MUART_MUART_CONFIG_H_

/* UART_MODE Options :
 * 		UART_NORMAL_SPEED
 * 		UART_DOUBLE_SPEED
 * 		UART_SYNC
 */
#define UART_MODE	UART_NORMAL_SPEED

/* UART_DATA_FRAME Options :
 * 		UART_5BitData
 * 		UART_6BitData
 * 		UART_7BitData
 * 		UART_8BitData
 * 		UART_9BitData
 */
#define UART_DATA_FRAME		UART_8BitData


/* UART_PARITY Options :
 * 		UART_DISABLE_PARITY
 * 		UART_EVEN_PARITY
 * 		UART_ODD_PARITY
 */
#define	UART_PARITY		UART_DISABLE_PARITY

/* UART_STOP_BITS Options :
 * 		UART_1_STOP_BIT
 * 		UART_2_STOP_BIT2
 */
#define	UART_STOP_BITS		UART_1_STOP_BIT

/* UART_CLOCK_POLARITY Options :
 * 		RISING_SAMPLING
 * 		FALLING_SAMPLING
 * The UART_CLOCK_POLARITY sets the relationship between data output change
 *  and data input sample, and the synchronous clock (XCK).
 *  Choose RISING_SAMPLING in asynchronous mode.
 */
#define	UART_CLOCK_POLARITY		RISING_SAMPLING
#endif /* MCAL_MUART_MUART_CONFIG_H_ */
