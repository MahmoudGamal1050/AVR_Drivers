/*
 *	MEXTI_interface.h
 *  Description:	
 *  Created on : Aug 14, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

/* Select EXTI ID */
#define EXTI0	0
#define EXTI1	1
#define EXTI2	2

/* Select sense mode for INT0 and INT1 */
#define LOW_LEVEL			0
#define ON_CHANGE			1
#define	FALLING_EDGE		2
#define RISING_EDGE			3
/* Select sense mode for INT2 */
#define	FALLING_EDGE_INT2	0
#define RISING_EDGE_INT2	1

/****************************************
* 	Function Prototypes					*
*****************************************/

/* Function to eneble external interrupt */
void MEXTI_voidEnable(u8 copy_u8EXTINumber);
/* Function to disable external interrupt */
void MEXTI_voidDisable(u8 copy_u8EXTINumber);
/* Function to set sense mode */
void MEXTI_voidSetSenseMode(u8 copy_u8EXTINumber, u8 copy_u8SenseMode);
/* Function to set call back function */
void MEXTI_voidSetCallBack(u8 copy_u8EXTINumber,void(*ptr)(void));

#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
