/*
 *	MADC_private.h
 *  Description:	
 *  Created on : Aug 15, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MADC_MADC_PRIVATE_H_
#define MCAL_MADC_MADC_PRIVATE_H_

/************************************************
*  ADC Registers Addesses Definition		    *
*************************************************/

/* ADC Multiplexer Selection Register */
#define ADMUX     *((volatile u8  *) 0x27)
#define MUX0      0		/* Analog Channel and Gain Selection Bit0 */
#define MUX1      1		/* Analog Channel and Gain Selection Bit1 */
#define MUX2      2		/* Analog Channel and Gain Selection Bit2 */
#define MUX3      3		/* Analog Channel and Gain Selection Bit3 */
#define MUX4      4		/* Analog Channel and Gain Selection Bit4 */
#define ADLAR     5		/* ADC Left Adjust Result */
#define REFS0     6		/* Reference Selection Bit0 */
#define REFS1     7		/* Reference Selection Bit1 */

/* ADC Control and Status Register A */
#define ADCSRA    *((volatile u8  *) 0x26)
#define ADPS0     0		/* ADC Prescaler Select Bit0 */
#define ADPS1     1		/* ADC Prescaler Select Bit1 */
#define ADPS2     2		/* ADC Prescaler Select Bit2 */
#define ADIE      3		/* ADC Interrupt Enable */
#define ADIF      4		/* ADC Interrupt Flag */
#define ADATE     5		/* ADC Auto Trigger Enable */
#define ADSC      6		/* ADC Enable */
#define ADEN      7		/* ADC Enable */

/* The ADC High Data Register */
#define ADCH      *((volatile u8  *) 0x25)
/* The ADC Low Data Register */
#define ADCL      *((volatile u8  *) 0x24)
/* The ADC combined Data Register */
#define ADC_DATA       *((volatile u16 *) 0x24)

/* Special FunctionIO Register */
#define SFIOR     *((volatile u8  *) 0x50)
#define ADTS0     5		/* ADC Auto Trigger Source Bit0 */
#define ADTS1     6		/* ADC Auto Trigger Source Bit1 */
#define ADTS2     7		/* ADC Auto Trigger Source Bit2 */



/* Voltage Reference Selections for ADC Definition */

#define AREF        0
#define AVCC        1
#define INTERNAL    3


/* ADC ADJUST_RESULT Definition */
#define RIGHT_ADJUST     	0
#define LEFT_ADJUST      	1

/* ADC Modes Definition */
#define SINGLE_CONVERSION	0
#define AUTO_TRIGGER		1

/* ADC Channels Definition */
#define CH0                 0
#define CH1                 1
#define CH2                 2
#define CH3                 3
#define CH4                 4
#define CH5                 5
#define CH6                 6
#define CH7                 7
/* ADC Prescaler Selections Definition */
#define DIV_FACTOR_2        1
#define DIV_FACTOR_4   	    2
#define DIV_FACTOR_8        3
#define DIV_FACTOR_16       4
#define DIV_FACTOR_32       5
#define DIV_FACTOR_64       6
#define DIV_FACTOR_128      7



/* ADC Auto Trigger Source Selections Definition */

#define FREE_RUNNING 					0
#define ANALOG_COMPARATOR				1
#define EXTERNAL_INTERRUPT_REQUEST0		2
#define TIMER0_COMPARE_MATCH			3
#define TIMER0_OVERFLOW					4
#define TIMER_COMPARE_MATCH_B			5
#define TIMER1_OVERFLOW					6
#define TIMER1_CAPTURE_EVENT			7

#define ENABLE	1
#define DISABLE	0



/* ADC ISR function prototype */
#define ISR(vector)\
void vector (void) __attribute__((signal,used));\
void vector(void)


#endif /* MCAL_MADC_MADC_PRIVATE_H_ */
