/*
 *	MI2C_program.c
 *  Description:	
 *  Created on : Aug 22, 2023
 *  Author     : Mahmoud Gamal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MI2C_private.h"
#include "MI2C_config.h"
#include "MI2C_interface.h"
#include "../MDIO/MDIO_interface.h"


void MI2C_voidInitMaster(void)
{
	/* Set prescalar values */
	#if   PRESCALER == PRESCALER_VALUE_1
		/* TWPS1:0 = 00 */
		CLR_BIT(TWSR, TWPS0);
		CLR_BIT(TWSR, TWPS1);

	#elif PRESCALER == PRESCALER_VALUE_4
		/* TWPS1:0 = 01 */
		SET_BIT(TWSR, TWPS0);
		CLR_BIT(TWSR, TWPS1);

	#elif PRESCALER == PRESCALER_VALUE_16
		/* TWPS1:0 = 10 */
		CLR_BIT(TWSR, TWPS0);
		SET_BIT(TWSR, TWPS1);

	#elif PRESCALER == PRESCALER_VALUE_64
		/* TWPS1:0 = 11 */
		SET_BIT(TWSR, TWPS0);
		SET_BIT(TWSR, TWPS1);

	#endif

	/* Calculate bit rate then assign the value to TWBR register */
	TWBR =BIT_RATE(SCL_FREQUENCY);
	//TWBR = 32;
	TWCR =  (1<<TWEN);		/* Enable TWI */
}
void MI2C_voidInitSlave(void)
{
	/* Assign slave address to the most significant 7-bits of TWAR */
	TWAR =SLAVE_ADDRESS<<1;
	/* Enable TWI, Enable acknowledge, Clear TWI interrupt flag */
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);

}
void MI2C_voidStartCondition(void)
{
	/* Enable start condition, Enable TWI, Clear TWI interrupt flag */
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	/* Wait until TWINT flag is set again */
	while(GET_BIT(TWCR, TWINT) == 0);
	/* Check status register */
	if((TWSR & 0XF8) !=TWI_START)
	{
		/* Sending start condition error */
	}

}

void MI2C_voidRepeatedStartCondition(void)
{
	/* Enable start condition, Enable TWI, Clear TWI interrupt flag */
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);

	/* Wait until TWINT flag is set again */
	while(GET_BIT(TWCR, TWINT) == 0);
	/* Check status register */
	if((TWSR & 0XF8) !=TWI_REP_START)
	{
		/* Sending repeated start condition error */
	}
}

void MI2C_voidStopCondition(void)
{
	/* Enable stop condition, Enable TWI, Clear TWI interrupt flag */
	TWCR = (1<<TWSTO)|(1<<TWEN)|(1<<TWINT);
}
void MI2C_voidMasterSendSlaveAddresswrite(u8 copy_u8Address)
{
	/* Assign slave address to the most significant 7-bits of TWDR
	 * and write 0 to bit0 to send write command */
	TWDR = copy_u8Address<<1;
	/* Enable TWI, Clear TWI interrupt flag */
	TWCR = (1<<TWEN)| (1<<TWINT) ;
	/* Wait until TWINT flag is set again */
	while(GET_BIT(TWCR, TWINT)==0);
	/* Check status register */
	if((TWSR & 0XF8) != TWI_MT_SLA_ACK)
	{
		/* Sending SLA+W error */
	}

}

void MI2C_voidMasterSendSlaveAddressRead(u8 copy_u8Address)
{
	/* Assign slave address to the most significant 7-bits of TWDR
	 * and write 1 to bit0 to send read command */
	TWDR = (copy_u8Address<<1)| 0x01;
	/* Enable TWI, Clear TWI interrupt flag */
	TWCR = (1<<TWEN)| (1<<TWINT);
	/* Wait until TWINT flag is set again */
	while(GET_BIT(TWCR, TWINT)==0);
	/* Check status register */
	if((TWSR & 0XF8) !=TWI_MR_SLA_ACK)
	{
		/* Sending SLA+R error */
	}
}

void MI2C_voidMasterSendData(u8 Copy_u8Data)
{
	/* Assign data to TWDR register */
	TWDR = Copy_u8Data;
	/* Enable TWI, Clear TWI interrupt flag */
	TWCR = (1<<TWEN)| (1<<TWINT);
	/* Wait until TWINT flag is set again */
	while(GET_BIT(TWCR, TWINT)==0);
	/* Check status register */
	if((TWSR & 0XF8) !=TWI_MT_DATA_ACK)
	{
		/* Sending data error */
	}

}

u8 MI2C_u8MasterReceiveData(void)
{

	/* Enable TWI, Enable acknowledge, Clear TWI interrupt flag */
	 TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);
	/* Wait until TWINT flag is set again */
	while(0 == GET_BIT(TWCR, TWINT));
	/* Check status register */
	if((TWSR & 0XF8) !=TWI_MR_DATA_ACK)
	{
		/* Master receiving data error */
	}

	/* Return received data */
	return TWDR;
}

void MI2C_voidSlaveSendData(u8 Copy_u8Data)
{
	/* Enable TWI, Enable acknowledge, Clear TWI interrupt flag */
	TWCR = (1<<TWEN)|(1<<TWEA)|(1<<TWINT);

	/* Wait until TWINT flag is set again */
	while(GET_BIT(TWCR, TWINT)==0);
	if((TWSR&0xF8) != TWI_ST_SLA_ACK)
	{
		/* SLA+R receiving error */
	}
	TWDR = Copy_u8Data;	/* Assign data to TWDR register */
	/* Enable TWI, Clear TWI interrupt flag */
	TWCR = (1<<TWEN)| (1<<TWINT);
	/* Wait until TWINT flag is set again */
	while(GET_BIT(TWCR, TWINT)==0);
	if((TWSR&0xF8) != TWI_ST_DATA_ACK)
	{
		/* Slave sending data error */
	}

}

u8 MI2C_u8SlaveReceiveData(void)
{

	/* Enable TWI, Enable acknowledge, Clear TWI interrupt flag */
	 TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);

	/* Wait until TWINT flag is set again */
	while(0 == GET_BIT(TWCR, TWINT));
	if((TWSR&0xF8) != TWI_SR_SLA_ACK)
	{
		/* SLA+W receiving error */
	}
	/* Enable TWI, Enable acknowledge, Clear TWI interrupt flag */
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);
	/* Wait until TWINT flag is set again */
	while(GET_BIT(TWCR, TWINT)==0);
	if((TWSR&0xF8) != TWI_SR_DATA_ACK)
	{
		/* Slave receiving data error */
	}

	/* Return data */
	return TWDR;

}


