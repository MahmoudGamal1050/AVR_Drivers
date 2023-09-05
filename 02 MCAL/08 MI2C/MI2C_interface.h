/*
 *	MI2C_interface.h
 *  Description:	
 *  Created on : Aug 22, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MI2C_MI2C_INTERFACE_H_
#define MCAL_MI2C_MI2C_INTERFACE_H_

/* Function to initialize I2C as a master */
void MI2C_voidInitMaster(void);
/* Function to initialize I2C as a slave */
void MI2C_voidInitSlave(void);
/* Function to send start condition to the bus */
void MI2C_voidStartCondition(void);
/* Function for the master to send a slave address with write command */
void MI2C_voidMasterSendSlaveAddresswrite(u8 copy_u8Address);
/* Function for the master to send a slave address with read command */
void MI2C_voidMasterSendSlaveAddressRead(u8 copy_u8Address);
/* Function for the master to send data */
void MI2C_voidMasterSendData(u8 Copy_u8Data);
/* Function for the master to receive data */
u8 MI2C_u8MasterReceiveData(void);
/* Function for the slave to send data */
void MI2C_voidSlaveSendData(u8 Copy_u8Data);
/* Function for the slave to receive data */
u8 MI2C_u8SlaveReceiveData(void);

/* Function to send stop condition to the bus */
void MI2C_voidStopCondition(void);
/* Function to send repeated start condition to the bus */
void MI2C_voidRepeatedStartCondition(void);



#endif /* MCAL_MI2C_MI2C_INTERFACE_H_ */
