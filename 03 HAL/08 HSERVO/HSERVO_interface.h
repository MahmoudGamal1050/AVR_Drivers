/*
 *	HSERVO_interface.h
 *  Description:	
 *  Created on : Aug 22, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef HAL_HSERVO_HSERVO_INTERFACE_H_
#define HAL_HSERVO_HSERVO_INTERFACE_H_


/* Function to initialize servo with Timer1 OCA1 Pin */
void HSERVO_voidInit(void);
/* Function to select motor angle from 0 to 180 */
void HSERVO_voidSetAngle(u8 Copy_u8Angle);
#endif /* HAL_HSERVO_HSERVO_INTERFACE_H_ */
