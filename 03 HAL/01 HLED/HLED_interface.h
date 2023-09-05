/********************************************************************************/
/* File Name    	: 	LED_interface.h   		                                */
/* Author       	: 	Mahmoud Gamal                                           */
/* Version      	: 	1.0.0                                                   */
/* Date 		 	: 	08/19/2023                                              */
/********************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


#define LED_OFF		0
#define LED_ON		1
#define LED_TOG		2

/*********************************************************************************
****************************** Functions Prototypes ******************************
*********************************************************************************/

void HLED_voidInit(u8 Copy_u8PinNumber);

void HLED_voidWrite(u8 Copy_u8PinNumber, u8 Copy_u8State);



#endif 
