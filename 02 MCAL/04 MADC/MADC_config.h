/*
 *	MADC_config.h
 *  Description:	
 *  Created on : Aug 15, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MADC_MADC_CONFIG_H_
#define MCAL_MADC_MADC_CONFIG_H_

/* ADC Voltage Reference options:
*			 AREF
*	         AVCC
*            INTERNAL
*/

#define VOLTAGE_REF        AVCC

/* ADC Adjust Result options:
*			 LEFT_ADJUST
*            RIGHT_ADJUST
*/

#define ADJUST_RESULT      RIGHT_ADJUST

/* ADC Modes options:
*			 SINGLE_CONVERSION
*            AUTO_TRIGGER
*/

#define ADC_MODE	SINGLE_CONVERSION

/*  ADC Auto Trigger Source options:
*			 FREE_RUNNING
*            ANALOG_COMPARATOR
*            EXTERNAL_INTERRUPT_REQUEST0
*            TIMER0_COMPARE_MATCH
*            TIMER0_OVERFLOW
*            TIMER_COMPARE_MATCH_B
*            TIMER1_OVERFLOW
*            TIMER1_CAPTURE_EVENT
*/
#define AUTO_TRIGGER_SOURCE		FREE_RUNNING



/*  ADC Prescaler Selections options:
*			 DIV_FACTOR_2
*            DIV_FACTOR_4
*            DIV_FACTOR_8
*            DIV_FACTOR_16
*            DIV_FACTOR_32
*            DIV_FACTOR_64
*            DIV_FACTOR_128
*/
#define PRESCALER       DIV_FACTOR_64

/* ADC Interrupt Control options :
 * 			 ENABLE
 * 			 DISABLE
 */
#define INTERRUPT_CONTROL	ENABLE


/*  ADC Channel Selections options:
*			 CH0
*            CH1
*            CH2
*            CH3
*            CH4
*            CH5
*            CH6
*            CH7
*/
#define ADC_CHANNEL		CH0

#endif /* MCAL_MADC_MADC_CONFIG_H_ */
