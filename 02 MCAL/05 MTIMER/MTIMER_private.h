/*
 *	MTIMER_private.h
 *  Description:	
 *  Created on : Aug 17, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MTIMER_MTIMER_PRIVATE_H_
#define MCAL_MTIMER_MTIMER_PRIVATE_H_



/***************************************************
* TIMER0 Registers Addresses Definition.  		   *
****************************************************/

/* Timer/Counter Register – TCNT0 */
#define TCNT0    *((volatile u8 *) 0x52)
/* Timer/Counter Control Register – TCCR0. */
#define TCCR0    *((volatile u8 *) 0X53)
/* Output Compare Register – OCR0 */
#define OCR0     *((volatile u8 *) 0x5C)
/* Timer/Counter Interrupt Mask Register – TIMSK  */
#define TIMSK    *((volatile u8 *) 0x59)
/* Timer/Counter Interrupt Flag Register – TIFR  */
#define TIFR     *((volatile u8 *) 0x58)


/* TCCR0 Register PINS Definition. */
#define CS00      0
#define CS01      1
#define CS02      2
#define WGM01     3
#define COM00     4
#define COM01     5
#define WGM00     6
#define FOC0      7

/* TIMSK Register PINS Definition.  */
#define TOIE0     0
#define OCIE0     1
#define TOIE1     2
#define OCIE1B    3
#define OCIE1A    4
#define TICIE1    5
#define TOIE2     6
#define OCIE2     7

/* TIFR Register PINS Definition.  */
#define TOV0      0
#define OCF0      1
#define TOV1 	  2
#define OCF1B	  3
#define OCF1A	  4
#define ICF1 	  5
#define TOV2	  6
#define OCF2 	  7


/* Timer0 Modes Definitions. */
#define TIMER0_NORMAL_MODE  		0		/* WGM00 = WGM01 = 0 */
#define TIMER0_CTC_MODE     		1		/* WGM00 = 0, WGM01 =1 */
#define TIMER0_PHASE_CORRECT		8		/* WGM00 = 1, WGM01 =0 */
#define TIMER0_FAST_PWM     		9		/* WGM00 = 1, WGM01 =1 */

/* Timer0 COMPARE_OUTPUT_MODE Definitions. */
#define TIMER0_OC0_DISCONNECTED	    0     	/* COM01 = COM00 = 0 */
#define TIMER0_TOGGLE_OC0			1     	/* COM01 = 0,COM00 =1 */
#define TIMER0_CLEAR_OC0			2     	/* COM01 = 1,COM00 =0 */
#define TIMER0_SET_OC0				3     	/* COM01 = 1,COM00 =1 */
#define TIMER0_NON_INVERTING		2       /* COM01 = 1,COM00 =0 */
#define TIMER0_INVERTING			3       /* COM01 = 1,COM00 =1 */


/* Timer Prescaler Selections Definition */
#define NO_CLOCK_SOURCE          0
#define NO_PRESCALAR             1
#define DIV_FACTOR_8             2
#define DIV_FACTOR_64            3
#define DIV_FACTOR_256           4
#define DIV_FACTOR_1024        	 5
#define EX_CLOCK_FALLING_EDGE    6
#define EX_CLOCK_RISING_EDGE	 7

/**************************************************
* TIMER1 Registers Addresses Definition. 		  *
***************************************************/

#define TCCR1A    *((volatile u8 *) 0x4F)   /* Timer/Counter1 Control Register A –TCCR1A */
#define TCCR1B    *((volatile u8 *) 0x4E)	/* Timer/Counter1 Control Register B –TCCR1B */
#define TCNT1H    *((volatile u8 *) 0x4D)	/* Timer/Counter1 – TCNT1H */
#define TCNT1L    *((volatile u8 *) 0x4C)	/* Timer/Counter1 – TCNT1L */
#define OCR1AH    *((volatile u8 *) 0x4B)	/* Output Compare Register 1 A –OCR1AH */
#define OCR1AL    *((volatile u8 *) 0x4A)	/* Output Compare Register 1 A –OCR1AL */
#define OCR1BH    *((volatile u8 *) 0x49)	/* Output Compare Register 1 B –OCR1BH */
#define OCR1BL    *((volatile u8 *) 0x48)	/* Output Compare Register 1 B –OCR1BL */
#define ICR1H     *((volatile u8 *) 0x47)	/* Input Capture Register 1 – ICR1H */
#define ICR1L     *((volatile u8 *) 0x46)	/* Input Capture Register 1 – ICR1L */

#define TCNT1     *((volatile u16 *) 0x4C)	/* Timer/Counter1 – TCNT1H and TCNT1L combined */
#define OCR1A     *((volatile u16 *) 0x4A)	/* Timer/Counter1 – OCR1AH and OCR1AL combined */
#define OCR1B     *((volatile u16 *) 0x48)	/* Timer/Counter1 – OCR1BH and OCR1BL combined */
#define ICR1      *((volatile u16 *) 0x46)	/* Timer/Counter1 – ICR1H and ICR1L combined */

/* TCCR1A Register PINS Definition. */
#define WGM10      0
#define WGM11      1
#define FOC1B      2
#define FOC1A      3
#define COM1B0     4
#define COM1B1     5
#define COM1A0     6
#define COM1A1     7

/* TCCR1B Register PINS Definition. */
#define CS10       0
#define CS11       1
#define CS12       2
#define WGM12      3
#define WGM13      4
#define ICES1      6
#define ICNC1      7

/* Timer1 Modes Definitions. */
#define TIMER1_NORMAL_MODE       						0x00
#define TIMER1_PHASE_CORRECT_8BIT_MODE           		0x01
#define TIMER1_PHASE_CORRECT_9BIT_MODE                  0x02
#define TIMER1_PHASE_CORRECT_10BIT_MODE                 0x03
#define TIMER1_CTC_OCR1A_MODE                           0x08
#define TIMER1_FAST_PWM_8BIT_MODE                       0x09
#define TIMER1_FAST_PWM_9BIT_MODE                       0x0A
#define TIMER1_FAST_PWM_10BIT_MODE                      0x0B
#define TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_MODE         0x10
#define TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_MODE        0x11
#define TIMER1_PWM_PHASE_CORRECT_ICR1_MODE              0x12
#define TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE             0x13
#define TIMER1_CTC_ICR1_MODE                            0x18
#define TIMER1_FAST_PWM_ICR1_MODE                       0x1A
#define TIMER1_FAST_PWM_OCR1A_MODE                      0x1B

/* Timer1 COMPARE_OUTPUT_MODE Definitions. */
#define TIMER1_OC1_DISCONNECTED		0     	/* COM1A1/COM1B1 = COM1A0/COM1B0 = 0 */
#define TIMER1_TOGGLE_OC1			1     	/* COM1A1/COM1B1 = 0 , COM1A0/COM1B0 = 1 */
#define TIMER1_CLEAR_OC1			2     	/* COM1A1/COM1B1 = 1 , COM1A0/COM1B0 = 0 */
#define TIMER1_SET_OC1				3     	/* COM1A1/COM1B1 = 1 , COM1A0/COM1B0 = 1 */
#define TIMER1_NON_INVERTING		2       /* COM1A1/COM1B1 = 1 , COM1A0/COM1B0 = 0 */
#define TIMER1_INVERTING			3       /* COM1A1/COM1B1 = 1 , COM1A0/COM1B0 = 1 */


#define ENABLE    0
#define DISABLE   1

/* TIMER ISR attribute */
#define ISR(vector)\
void vector (void) __attribute__((signal,used));\
void vector(void)

#endif /* MCAL_MTIMER_MTIMER_PRIVATE_H_ */
