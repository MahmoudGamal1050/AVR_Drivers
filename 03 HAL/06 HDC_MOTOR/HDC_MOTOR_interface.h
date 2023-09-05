/*
 *	HDC_MOTOR_interface.h
 *  Description:	
 *  Created on : Aug 13, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef HAL_HDCMOTOR_HDC_MOTOR_INTERFACE_H_
#define HAL_HDCMOTOR_HDC_MOTOR_INTERFACE_H_

#define CW_DIRECTION	1
#define CCW_DIRECTION	2

/* Function to initialize the motor */
void HDCMOTOR_voidInit(void);
/* Function to set motor rotation direction */
void HDCMOTOR_voidSetDirection(u8 copy_u8Direction);
/* Function to start the motor */
void HDCMOTOR_voidStart(void);
/* Function to stop the motor */
void HDCMOTOR_voidStop(void);
/* Function to control the motor speed */
void HDCMOTOR_voidControlSpeed(u8 copy_u8Speed);




#endif /* HAL_HDCMOTOR_HDC_MOTOR_INTERFACE_H_ */
