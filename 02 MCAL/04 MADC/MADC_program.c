/*
 *	MADC_program.c
 *  Description:	
 *  Created on : Aug 15, 2023
 *  Author     : Mahmoud Gamal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../MDIO/MDIO_interface.h"
#include "MADC_private.h"
#include "MADC_config.h"
#include "MADC_interface.h"

static void (*ADC_CallBack)(void) = NULL;

void MADC_voidInit(void)
{

	/* Write voltage reference to Bit 7:6 – REFS1:0 of ADMUX */
	ADMUX = (ADMUX & 0x3F) | (VOLTAGE_REF<<REFS0); /* 0x3F : 0b0011 1111 */
	/* Write result adjust to Bit5 (ADLAR) of ADMUX */
	ADMUX = (ADMUX & 0xDF) | (ADJUST_RESULT<<ADLAR);	/* 0xDF : 0b1101 1111 */
	/* Write Channel number to Bits 4:0 - MUX4:0 of ADMUX */
	ADMUX = (ADMUX & 0xE0) | ADC_CHANNEL;	/* 0xE0 : 0b1110 0000 */
	/* Write ADC mode to Bit5(ADATE) of ADCSRA
	 * ADATE = 0 : Single Conversion , ADATE = 1 : Auto trigger */
	ADCSRA = (ADCSRA &0xDF) | (ADC_MODE<<ADATE);		/* 0xDF : 0b1101 1111 */

	/* In case the mode is auto trigger select auto trigger source */
	SFIOR = (SFIOR & 0x1F) | (AUTO_TRIGGER_SOURCE<<ADTS0);

	/* Select prescalar by writing to Bit 2:0 - ADPS2:0 of ADCSRA */
	ADCSRA = (ADCSRA & 0xF8) | PRESCALER;

	/* Select if ADC will work as polling or interrupt */
	ADCSRA = (ADCSRA & 0xF7) | (INTERRUPT_CONTROL<<ADIE);
	/* Enable ADC */
	SET_BIT(ADCSRA,ADEN);

}


void MADC_voidStartConversion(void)
{
		/* Start conversion */
		SET_BIT(ADCSRA, ADSC);
}

u16 MADC_u16GetDataSynch(void)
{
	u16 Local_u16Ret;
	/* Polling until the conversion complete flag is set */
	while(GET_BIT(ADCSRA, ADIF)==0);
	/* Clear the conversion complete flag by writing 1 to it */
	SET_BIT(ADCSRA, ADIF);

	/* Return ADC Data */
	Local_u16Ret = ADC_DATA;
	return Local_u16Ret;
}

u16 MADC_u16GetDataAsynch(void)
{
	/* Return ADC Data */
	return ADC_DATA;

}

void MADC_voidSetCallBack(void(*ptr)(void))
{


	ADC_CallBack = ptr;

}

ISR(__vector_16)
{
	ADC_CallBack();
}




