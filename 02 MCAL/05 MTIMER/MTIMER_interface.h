/*
 *	MTIMER_interface.h
 *  Description:	
 *  Created on : Aug 17, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MTIMER_MTIMER_INTERFACE_H_
#define MCAL_MTIMER_MTIMER_INTERFACE_H_

/* Select timer  */
#define TIMER0			0
#define TIMER1			1	/* If timer1 is selected both channels works with same values */
#define TIMER2			2
/* In case of timer1 select required channel */
#define TIMER1_OCR1A	3
#define TIMER1_OCR1B	4

/* ISR IDs for all timers */
#define TIMER0_OVF_INTERRUPT		0
#define TIMER0_COMP_INTERRUPT		1
#define TIMER1_OVF_INTERRUPT		2
#define TIMER1_COMPA_INTERRUPT		3
#define TIMER1_COMPB_INTERRUPT		4
#define TIMER1_CAPT_INTERRUPT		5
#define TIMER2_OVF_INTERRUPT		6
#define TIMER2_COMP_INTERRUPT		7

/* Timer1 ICU edge trigger */
#define ICU_RISING_EDGE	1
#define ICU_FALLING_EDGE	0

/* Function to initialize all timers */
void MTIMER_voidInit(void);
/* Function to start a specific timer */
void MTIMER_voidStart(u8 copy_u8TimerId);
/* Function to stop a specific timer */
void MTIMER_voidStop(u8 copy_u8TimerId);
/* Function to read current counting value for a specific timer */
u16 MTIMER_u16Read(u8 copy_u8TimerId);
/* Function to start first counting from a certain value */
void MTIMER_voidPreload(u8 copy_u8TimerId, u16 copy_u16PreloadValue);
/* Function to select the compare value in registers OCRn */
void MTIMER_voidSetCompareValue(u8 copy_u8TimerId, u16 copy_u16LoadValue);
/* Function to set call back functions by selecting the ISR ID */
void MTIMER_voidSetCallBack(void(*ptr)(void), u8 copy_u8ISR_ID );
/* Function to enable interrupt for an ISR ID */
void MTIMER_voidInterruptEnable(u8 copy_u8ISR_ID);
/* Function to disable interrupt for an ISR ID */
void MTIMER_voidInterruptDisable(u8 copy_u8ISR_ID);
/* Function to generate non PWM on OCn pins */
void MTIMER_voidGenerateNonPWMSignal(u8 copy_u8TimerId);
/* Function to generate fast PWM on OCn pins */
void MTIMER_voidGenerateFastPWMSignal(u8 copy_u8TimerId);
/* Function to generate phase correct PWM on OCn pins */
void MTIMER_voidGeneratePhaseCorrectPWMSignal(u8 copy_u8TimerId);

void MTIMER1_voidSetICR1(u16 copy_u16LoadValue);

void MTIMER1_voidGetICUFreqDutyCycle(u32 *copy_u8Frequency, u8 *copy_u8DutyCycle);
/* Function to read timer1 input capture register */
u16 MTIMER1_u16GetICR1(void);
/* Function to set timer1 input capture trigger edge */
void MTIMER1_voidSetICUTrigger(u8 copu_u8Edge);

void MTIMER_voidSetInterval(u8 copy_u8SystemTicks, void(*ptr)(void));


#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */
