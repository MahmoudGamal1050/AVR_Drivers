/*
 *	MADC_interface.h
 *  Description:	
 *  Created on : Aug 15, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MADC_MADC_INTERFACE_H_
#define MCAL_MADC_MADC_INTERFACE_H_


/* ADC Initialization Function */
void MADC_voidInit(void);

/* Function to start ADC conversion */
void MADC_voidStartConversion(void);

/* Function to read ADC data by polling */
u16 MADC_u16GetDataSynch(void);

/* Function to read ADC data by interrupt */
u16 MADC_u16GetDataAsynch(void);


/* Function to set call back function */
void MADC_voidSetCallBack(void(*ptr)(void));



#endif /* MCAL_MADC_MADC_INTERFACE_H_ */
