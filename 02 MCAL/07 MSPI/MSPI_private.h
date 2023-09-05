/*
 *	MSPI_private.h
 *  Description:	
 *  Created on : Aug 21, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MSPI_MSPI_PRIVATE_H_
#define MCAL_MSPI_MSPI_PRIVATE_H_


/*********************************************
* SPI Registers Addresses Definition.  	     *
**********************************************/

/* SPI Control Register -SPCR */
#define SPCR          *((volatile u8*)(0x2D))
/* SPCR Pins Definitions */
#define SPIE          7         /* Bit 7 – SPIE: SPI Interrupt Enable */
#define SPE           6         /* Bit 6 – SPE: SPI Enable */
#define DORD          5         /* Bit 5 – DORD: Data Order */
#define MSTR          4         /* Bit 4 – MSTR: Master/Slave Select */
#define CPOL          3         /* Bit 3 – CPOL: Clock Polarity */
/* CPOL Functionality
CPOL      Leading Edge       Trailing Edge
0         Rising             Falling
1         Falling            Rising
*/
#define CPHA          2         /* Bit 2 – CPHA: Clock Phase */
/* CPHA Functionality
CPHA       Leading Edge     Trailing Edge
0          Sample           Setup
1          Setup            Sample
*/
#define SPR1          1        /* Bits 1– SPR1: SPI Clock Rate Select 1 */
#define SPR0          0        /* Bits 0– SPR0: SPI Clock Rate Select 0 */

/* SPI Status Register -SPSR */
#define SPSR          *((volatile u8*)(0x2E))

/* SPSR Pins Definitions */
#define SPIF          7        /* Bit 7 – SPIF: SPI Interrupt Flag */
#define WCOL          6        /* Bit 6 – WCOL: Write COLlision Flag */
#define SPI2X         0        /* Bit 0 – SPI2X: Double SPI Speed Bit */


/* Relationship Between SCK and the Oscillator Frequency
 SPI2X    SPR1    SPR0    SCK Frequency
 0        0        0          fosc/4
 0        0        1          fosc/16
 0        1        0          fosc/64
 0        1        1          fosc/128
 1        0        0          fosc/2
 1        0        1          fosc/8
 1        1        0          fosc/32
 1        1        1          fosc/64
*/


/* SPDR Status Register -SPSR */
#define SPDR          *((volatile u8*)(0x2F))


/* SPI Data Order definitions */
#define LSB     0
#define MSB     1

/* SPI Clock Polarity definitions */
#define RISING_FALLING     0
#define FALLING_RISING     1

/* SPI Clock Phase definitions */
#define SAMPLE_SETUP       0
#define SETUP_SAMPLE       1

/* SPI Clock Rate definitions */
#define NORMAL_SPEED_DIV_4       0
#define NORMAL_SPEED_DIV_16      1
#define NORMAL_SPEED_DIV_64      2
#define NORMAL_SPEED_DIV_128     3
#define DOUBLE_SPEED_DIV_2       4
#define DOUBLE_SPEED_DIV_8       5
#define DOUBLE_SPEED_DIV_32      6
#define DOUBLE_SPEED_DIV_64      7

/* SPI ISR attribute */
#define ISR(vector)\
void vector (void) __attribute__((signal,used));\
void vector(void)




#endif /* MCAL_MSPI_MSPI_PRIVATE_H_ */
