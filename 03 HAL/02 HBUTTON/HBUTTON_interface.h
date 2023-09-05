/********************************************************************************/
/* File Name    	: 	HBUTTON_interface.h   		                                */
/* Author       	: 	Mahmoud Gamal                                           */
/* Version      	: 	1.0.0                                                   */
/* Date 		 	: 	08/19/2023                                              */
/********************************************************************************/
#ifndef HBUTTON_INTERFACE_H
#define HBUTTON_INTERFACE_H



/*********************************************************************************
****************************** Functions Prototypes ******************************
*********************************************************************************/

/* Function to initialize the button */
void HBUTTON_voidInit(u8 Copy_u8PinNumber);
/* Function to enable internal pull up resistor */
void HBUTTON_voidInternalPullUp(u8 Copy_u8PinNumber);
/* Function to read button value */
u8 HBUTTON_u8GetValue(u8 Copy_u8PinNumber);


#endif 
