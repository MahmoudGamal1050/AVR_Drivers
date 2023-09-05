/*
 *	MTIMER_config.h
 *  Description:	
 *  Created on : Aug 17, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MTIMER_MTIMER_CONFIG_H_
#define MCAL_MTIMER_MTIMER_CONFIG_H_

/***************************************************
* 		TIMER0 Configurations  					   *
****************************************************/
/* Timer0 Control :
 * 		ENABLE
 * 		DISABLE
 */
#define TIMER0_CONTROL		ENABLE

/* Timer0 Modes Options:
*			 TIMER0_NORMAL_MODE
*	         TIMER0_CTC_MODE
*            TIMER0_FAST_PWM
*            TIMER0_PHASE_CORRECT
*/
#define TIMER0_MODE		TIMER0_FAST_PWM


/* COMPARE_OUTPUT_MODE Options :
*	non-PWM: TIMER0_OC0_DISCONNECTED   Fast PWM and Phase Correct:
*			 TIMER0_TOGGLE_OC0                TIMER0_OC0_DISCONNECTED
*			 TIMER0_CLEAR_OC0                 TIMER0_NON_INVERTING
*	         TIMER0_SET_OC0                   TIMER0_INVERTING
*/
#define TIMER0_COMPARE_OUTPUT_MODE		TIMER0_NON_INVERTING

/*  Timer0 Prescaler Selections options:
*			 NO_CLOCK_SOURCE
*			 NO_PRESCALAR
*            DIV_FACTOR_8
*            DIV_FACTOR_64
*            DIV_FACTOR_256
*            DIV_FACTOR_1024
*            EX_CLOCK_FALLING_EDGE
*            EX_CLOCK_RISING_EDGE
*/
#define TIMER0_PRESCALER       DIV_FACTOR_1024

/***************************************************
* 		TIMER1 Configurations  					   *
****************************************************/
/* Timer1 Control */
#define TIMER1_CONTROL		ENABLE

/* Timer1 Modes Options:
*			 TIMER1_NORMAL_MODE
*	         TIMER1_PHASE_CORRECT_8BIT_MODE
*            TIMER1_PHASE_CORRECT_9BIT_MODE
*            TIMER1_PHASE_CORRECT_10BIT_MODE
*            TIMER1_CTC_OCR1A_MODE
*            TIMER1_FAST_PWM_8BIT_MODE
*            TIMER1_FAST_PWM_9BIT_MODE
*            TIMER1_FAST_PWM_10BIT_MODE
*            TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_MODE
*            TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_MODE
*            TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
*            TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
*            TIMER1_CTC_ICR1_MODE
*            TIMER1_FAST_PWM_ICR1_MODE
*            TIMER1_FAST_PWM_OCR1A_MODE
*/
#define TIMER1_MODE		TIMER1_NORMAL_MODE


/* COMPARE_OUTPUT_MODE for Channel A and B :
*	non-PWM:   							 Fast PWM and Phase Correct:
*			 TIMER1_OC1_DISCONNECTED       TIMER1_OC1_DISCONNECTED
*			 TIMER1_TOGGLE_OC1              TIMER1_NON_INVERTING
*	         TIMER1_CLEAR_OC1               TIMER1_INVERTING
*	         TIMER1_SET_OC1
*/
#define TIMER1_COMPARE_OUTPUT_MODE_A		TIMER1_OC1_DISCONNECTED
#define TIMER1_COMPARE_OUTPUT_MODE_B		TIMER1_OC1_DISCONNECTED



/*  Timer1 Prescaler Selections options:
*			 NO_CLOCK_SOURCE
*			 NO_PRESCALAR
*            DIV_FACTOR_8
*            DIV_FACTOR_64
*            DIV_FACTOR_256
*            DIV_FACTOR_1024
*            EX_CLOCK_FALLING_EDGE
*            EX_CLOCK_RISING_EDGE
*/
#define TIMER1_PRESCALER       DIV_FACTOR_1024




/***************************************************
* 		TIMER2 Configurations  					   *
****************************************************/
/* Timer2 Control */
#define TIMER2_CONTROL		DISABLE

#endif /* MCAL_MTIMER_MTIMER_CONFIG_H_ */
