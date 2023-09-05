/*
 *	MI2C_config.h
 *  Description:	
 *  Created on : Aug 22, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MI2C_MI2C_CONFIG_H_
#define MCAL_MI2C_MI2C_CONFIG_H_

/* Select address when acting as a slave */
#define SLAVE_ADDRESS	20

/* Select I2C clock frequency when acting as a master */
#define SCL_FREQUENCY     100000UL

/*Select prescaler value option :
*   		   PRESCALER_VALUE_1
*			   PRESCALER_VALUE_4
*			   PRESCALER_VALUE_16
*			   PRESCALER_VALUE_64
*/
#define PRESCALER     PRESCALER_VALUE_1




#endif /* MCAL_MI2C_MI2C_CONFIG_H_ */
