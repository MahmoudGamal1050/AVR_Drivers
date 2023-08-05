/*********************************************************************
* File Name    	: 	DIO_interface.h                                  *
* Author       	: 	Mahmoud Gamal                                    *
* Version      	: 	1.0.0                                            *
* Date  		: 	5/8/2023                                         *
* Description   : 	DIO APIs         				                 *                         
*********************************************************************/

#ifndef DIO_INTERFACE
#define	DIO_INTERFACE

/* DIO Ports Definitions */
#define DIO_PORTA	1
#define	DIO_PORTB	2
#define	DIO_PORTC	3
#define	DIO_PORTD	4

/* DIO Pins Definitions */
#define	PA0		0
#define	PA1		1
#define	PA2		2
#define	PA3		3
#define	PA4		4
#define	PA5		5
#define	PA6		6
#define	PA7		7

#define	PB0		8
#define	PB1		9
#define	PB2		10
#define	PB3		11
#define	PB4		12
#define	PB5		13
#define	PB6		14
#define	PB7		15


#define	PC0		16
#define	PC1		17
#define	PC2		18
#define	PC3		19
#define	PC4		20
#define	PC5		21
#define	PC6		22
#define	PC7		23


#define	PD0		24
#define	PD1		25
#define	PD2		26
#define	PD3		27
#define	PD4		28
#define	PD5		29
#define	PD6		30
#define	PD7		31

/* DIO Pin mode definitions */
#define  DIO_INPUT      0
#define  DIO_OUTPUT     1

/* DIO Pin value definitions */
#define  DIO_LOW        0
#define  DIO_HIGH       1

/*******************************************************
*			Functions Prototypes					   *
********************************************************/


/**********************************************************************
* Function Name : DIO_voidSetPinDirection						 	  *
* Parameters 	: PIN number(PA0 -> PD7), Mode(OUTPUT, INPUT).   	  *			                      *
* Return type 	: void                                           	  *
* Descriptio 	: Function to set DIO pin direction (OUTPUT, INPUT)   *
***********************************************************************/
void DIO_voidSetPinDirection(u8 copy_u8Pin, u8 copy_u8Mode);

/**********************************************************************
* Function Name : DIO_voidSetPinValue						 		  *
* Parameters 	: PIN number(PA0 -> PD7), Value(HIGH, LOW)   	 	  *			                      *
* Return type 	: void                                           	  *
* Descriptio 	: Function to set DIO pin value (HIGH, LOW)		      *
***********************************************************************/
void DIO_voidSetPinValue(u8 copy_u8Pin, u8 copy_u8Value);

/**********************************************************************
* Function Name : DIO_voidTogglePin						 		  	  *
* Parameters 	: PIN number(PA0 -> PD7)   	 	 					  *			                      *
* Return type 	: void                                           	  *
* Descriptio 	: Function to toggle DIO pin value  				  *
***********************************************************************/
void DIO_voidTogglePin(u8 copy_u8Pin);

/**********************************************************************
* Function Name : DIO_u8GetPinValue						 		  	  *
* Parameters 	: PIN number(PA0 -> PD7)   	 	 					  *			                      *
* Return type 	: u8                                      	     	  *
* Descriptio 	: Function to get DIO pin value  					  *
***********************************************************************/
u8 DIO_u8GetPinValue(u8 copy_u8Pin);




#endif
