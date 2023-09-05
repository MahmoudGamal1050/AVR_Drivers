/*
 *	MI2C_private.h
 *  Description:	
 *  Created on : Aug 22, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MI2C_MI2C_PRIVATE_H_
#define MCAL_MI2C_MI2C_PRIVATE_H_

/* Private macro function to calculate TWBR register value
 * depending on CPU frequency, prescalar and required clock rate for I2C */
#define BIT_RATE(SCL_FREQUENCY)	(((F_CPU/SCL_FREQUENCY)-16)/(2*PRESCALER))

/*******************************************************
* I2C(TWI) Registers Addresses Definition	 		   *
********************************************************/
/* TWI Bit Rate Register –TWBR */
#define TWBR     *((volatile u8 *) 0x20)
/* TWI Status Register –TWSR */
#define TWSR     *((volatile u8 *) 0x21)
/* TWI (Slave) Address Register –TWAR */
#define TWAR     *((volatile u8 *) 0x22)
/* TWI Data Register –TWDR */
#define TWDR     *((volatile u8 *) 0x23)
/* TWI Control Register –TWCR */
#define TWCR     *((volatile u8 *) 0x56)

/* TWI Control Register (TWCR) PINS Definition */
#define TWIE      0
#define TWEN      2
#define TWWC      3
#define TWSTO     4
#define TWSTA     5
#define TWEA      6
#define TWINT     7


/* TWI Status Register (TWSR) PINS Definition */
#define TWPS0     0
#define TWPS1     1



/* Prescaler Values Definition */
#define PRESCALER_VALUE_1		1
#define PRESCALER_VALUE_4		4
#define PRESCALER_VALUE_16		16
#define PRESCALER_VALUE_64		64


/* TWI Status Bits in the TWSR Register */
#define TWI_START         				0x08   /* Start condition transmitted                              */
#define TWI_REP_START     				0x10   /* Repeated start condition transmitted                     */
#define TWI_MT_SLA_ACK    				0x18   /* SLA+W transmitted, ACK received                          */
#define TWI_MT_SLA_NACK   				0x20   /* SLA+W transmitted, NACK received                         */
#define TWI_MT_DATA_ACK   				0x28   /* Data byte transmitted, ACK received                      */
#define TWI_MT_DATA_NACK 				0x30   /* Data byte transmitted, NACK received                     */
#define TWI_MR_SLA_ACK    				0x40   /* SLA+R transmitted, ACK received                          */
#define TWI_MR_SLA_NACK   				0x48   /* SLA+R transmitted, NACK received                         */
#define TWI_MR_DATA_ACK   				0x50   /* Data byte received, ACK returned                         */
#define TWI_MR_DATA_NACK  				0x58   /* Data byte received, NACK returned                        */
#define TWI_ST_SLA_ACK    				0xA8   /* SLA+R received, ACK returned                             */
#define TWI_ST_ARB_LOST_SLA_ACK 	 	0xB0   /* Arbitration lost, SLA+R received, ACK returned           */
#define TWI_ST_DATA_ACK   				0xB8   /* Data byte transmitted, ACK received                      */
#define TWI_ST_DATA_NACK  				0xC0   /* Data byte transmitted, NACK received                     */
#define TWI_ST_LAST_DATA_ACK    		0xC8   /* Last data byte transmitted, ACK received                 */
#define TWI_SR_SLA_ACK   				0x60   /* SLA+W received, ACK returned                             */
#define TWI_SR_ARB_LOST_SLA_ACK  		0x68   /* Arbitration lost, SLA+W received, ACK returned           */
#define TWI_SR_GCALL_ACK    			0x70   /* General call received, ACK returned                      */
#define TWI_SR_ARB_LOST_GCALL_ACK  		0x78   /* Arbitration lost, General call received, ACK returned    */
#define TWI_SR_DATA_ACK   				0x80   /* Data byte received, ACK returned                         */
#define TWI_SR_DATA_NACK  				0x88   /* Data byte received, NACK returned                        */
#define TWI_SR_GCALL_DATA_ACK    		0x90   /* General call data received, ACK returned                 */
#define TWI_SR_GCALL_DATA_NACK   		0x98   /* General call data received, NACK returned                */
#define TWI_SR_STOP       				0xA0   /* Stop or repeated start condition received while selected */
#define TWI_NO_INFO       				0xF8   /* No relevant state information available TWINT = 0        */
#define TWI_BUS_ERROR     				0x00   /* Bus error due to illegal start or stop condition         */

#endif /* MCAL_MI2C_MI2C_PRIVATE_H_ */
