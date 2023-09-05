/*
 *	MSPI_program.c
 *  Description:	
 *  Created on : Aug 21, 2023
 *  Author     : Mahmoud Gamal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MSPI_private.h"
#include "MSPI_config.h"
#include "MSPI_interface.h"
#include "../MDIO/MDIO_interface.h"

/* Private pointer to function to set interrupt call back */
static void (*SPI_CallBack)(void) = NULL;

void MSPI_voidInitMaster(void)
{
	/* Configure PB4(SS) as output pin */
	MDIO_voidSetPinDirection(PB4, DIO_OUTPUT);
	/* Configure PB5(MOSI) as output pin */
	MDIO_voidSetPinDirection(PB5, DIO_OUTPUT);
	/* Configure PB7(SCK) as output pin */
	MDIO_voidSetPinDirection(PB7, DIO_OUTPUT);

	/* Enable SPI
	 * Set data order
	 * Configure as a master
	 * Set clock polarity, phase and rate */
	SPCR = (1<<SPE) | (DARA_ORDER<<DORD) | (1<<MSTR)|(CLOCK_POLARITY|CPOL)
			|(CLOCK_PHASE<<CPHA) | (CLOCK_RATE & 0x03);;

	/* Set clock rate */
	SPSR |= CLOCK_RATE>>2;
}

void MSPI_voidInitSlave(void)
{
	/* Configure PB6(MISO) as output pin */
	MDIO_voidSetPinDirection(PB6, DIO_OUTPUT);

	/* Enable SPI and Set data order */
	SPCR = (1<<SPE) | (DARA_ORDER<<DORD);
	/* Set clock rate */
	SPSR |= CLOCK_RATE>>2;

}

void MSPI_voidSendReceive(u8 *Copy_u8PtrData)
{
	/* Load data to data register */
	SPDR = *Copy_u8PtrData;

	/* Wait till exchange is complete */
	while(GET_BIT(SPSR, SPIF)==0);

	/* Return data */
	*Copy_u8PtrData = SPDR;

}

void MSPI_voidSendStringBlocking(u8 *Copy_u8String)
{
	/* Parse the string until reaching NULL terminator */
	while(*Copy_u8String != '\0')
	{
		/* Send a character each iteration */
		MSPI_voidSendReceive(Copy_u8String);
		Copy_u8String++;	/* Increment the pointer */
	}

}

void MSPI_voidEnableInterrupt(void)
{
	SET_BIT(SPCR, SPIE);	/* Set SPIE bit in SPCR register to enable interrupt */

}
void MSPI_voidDisableInterrupt(void)
{
	CLR_BIT(SPCR, SPIE);	/* Clear SPIE bit in SPCR register to disable interrupt */

}
void MSPI_voidSetCallBack(void(*ptr)(void))
{
	SPI_CallBack = ptr;		/* Get the address of the call back function */
}

/* SPI transfer complete ISR */
ISR(__vector_12)
{
	SPI_CallBack();
}
