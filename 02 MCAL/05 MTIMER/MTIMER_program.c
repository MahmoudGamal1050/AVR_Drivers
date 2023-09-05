/*
 *	MTIMER_program.c
 *  Description:	
 *  Created on : Aug 17, 2023
 *  Author     : Mahmoud Gamal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MTIMER_private.h"
#include "MTIMER_config.h"
#include "MTIMER_interface.h"
#include "../MDIO/MDIO_interface.h"
#include "../MGIE/MGIE_interface.h"
#include "../../HAL/HLCD/HLCD_interface.h"

/* Pointers to function to have callback functions addresses */
/* pointer to timer0 overflow mode callback pointer to function */
static void(*TIMER0_OverflowCallBack)(void) = NULL;
/* pointer to timer0 compare match callback pointer to function */
static void(*TIMER0_CompareMatchCallBack)(void) = NULL;

/* pointer to timer1 overflow callback pointer to function */
static void(*TIMER1_OverflowCallBack)(void) = NULL;
/* pointer to timer1 compare match for channel A callback pointer to function */
static void(*TIMER1_CompareMatchACallBack)(void) = NULL;
/* pointer to timer1 compare match for channel B callback pointer to function */
static void(*TIMER1_CompareMatchBCallBack)(void) = NULL;
/* pointer to timer1 input capture callback pointer to function */
static void(*TIMER1_CaptureEventCallBack)(void) = NULL;

/* pointer to timer2 overflow callback pointer to function */
static void(*TIMER2_OverflowCallBack)(void) = NULL;
/* pointer to timer2 compare match callback pointer to function */
static void(*TIMER2_CompareMatchCallBack)(void) = NULL;

static u16 ICU_timeOn;		/* Variable to save timeOn count for PWM calculation using ICU */
static u16 ICU_periodicTime;	/* Variable to save periodic count for PWM calculation using ICU */
//static u8 ICU_InterruptCounter =0 ;	/* variable to count number of interrupts for ICU */
/* Private callback function for ICU interrupt */
//static void ICU1_voidInterrupt(void);

void MTIMER_voidInit(void)
{
	/* If timer0 is configured as enable */
	#if	TIMER0_CONTROL == ENABLE
		TCNT0 = 0;		/* Start counting from 0 */
		/* Select the mode by writing to WGM01 and WGM00 of TCCR0 register */
		TCCR0 = TIMER0_MODE<<WGM01;
	#endif

		/* If timer1 is configured as enable */
	#if	TIMER1_CONTROL == ENABLE
		TCNT1 =0;			/* Start counting from 0 */
		/* Select the mode by writing to WGM11 and WGM10 of TCCR1A register */
		TCCR1A |= TIMER1_MODE & 0x03 ;
		/* Select the mode by writing to WGM13 and WGM12 of TCCR1B register */
		TCCR1B |= TIMER1_MODE & 0x18 ;


	#endif

	#if	TIMER2_CONTROL == ENABLE

	#endif

}

void MTIMER_voidStart(u8 copy_u8TimerId)
{
	/* Start counting for the required timer */
	switch(copy_u8TimerId)
	{
		case TIMER0 :
			/* Write prescalar to TCCR0 to start timer0 */
			TCCR0 = (TCCR0&0xF8) | TIMER0_PRESCALER;
			break;
		case TIMER1 :
			/* Write prescalar to TCCR1B to start timer1 */
			TCCR1B = (TCCR1B&0xF8) | TIMER1_PRESCALER;
			break;
		case TIMER2 :
			break;

	}
}

void MTIMER_voidStop(u8 copy_u8TimerId)
{
	/* Stop counting for the required timer */
	switch(copy_u8TimerId)
	{
		case TIMER0 :
			/* Write prescalar 0 to TCCR0 to stop timer0 */
			TCCR0 = (TCCR0&0xF8) | 0x00;
			break;
		case TIMER1 :
			/* Write prescalar 0 to TCCR1B to stop timer1 */
			TCCR1B = (TCCR1B&0xF8) | 0x00;
			break;
		case TIMER2 :
			break;

	}


}
u16 MTIMER_u16Read(u8 copy_u8TimerId)
{
	u16 Local_u16Count;		/* Variable to return timer current count */
	switch(copy_u8TimerId)
	{
		case TIMER0 :
			/* Assign TCNT0(timer0 counter register) to return count */
			Local_u16Count =(u8)TCNT0 ;
			break;
		case TIMER1 :
			/* Assign TCNT1(timer1 counter register) to return count */
			Local_u16Count =TCNT1 ;
			break;
		case TIMER2 :
			break;

	}
	/* return the timer count */
	return Local_u16Count;

}

void MTIMER_voidPreload(u8 copy_u8TimerId, u16 copy_u16PreloadValue)
{
	/* Determine required timer */
	switch(copy_u8TimerId)
	{
		case TIMER0 :
			/* Assign preload value to timer0 count register to start counting from this value */
			TCNT0 = (u8)copy_u16PreloadValue;
			break;
		case TIMER1 :
			/* Assign preload value to timer1 count register to start counting from this value */
			TCNT1 = copy_u16PreloadValue;
			break;
		case TIMER2 :
			break;

	}
}

void MTIMER_voidSetCompareValue(u8 copy_u8TimerId, u16 copy_u16LoadValue)
{
	/* Determine required timer (or channel in case timer1) */
	switch(copy_u8TimerId)
	{
		case TIMER0 :
			/* Assign compare value to timer0 output compare register */
			OCR0 = (u8)copy_u16LoadValue;;
			break;
		case TIMER1 :
			/* Assign compare value to timer1 output compare registers A and B */
			OCR1A = copy_u16LoadValue;;
			OCR1B = copy_u16LoadValue;;
			break;
		case TIMER2 :
			break;
		case TIMER1_OCR1A :
			/* Assign compare value to timer1 output compare registers A */
			OCR1A = copy_u16LoadValue;;
			break;
		case TIMER1_OCR1B :
			/* Assign compare value to timer1 output compare registers B */
			OCR1B = copy_u16LoadValue;;
			break;

	}
}

void MTIMER_voidSetCallBack(void(*ptr)(void), u8 copy_u8ISR_ID )
{
	/* Determine required callback depending on ISR ID */
	switch(copy_u8ISR_ID)
	{
		case TIMER0_OVF_INTERRUPT :
			/* Set call back for timer0 overflow interrupt */
			TIMER0_OverflowCallBack = ptr;
			break;
		case TIMER0_COMP_INTERRUPT :
			/* Set call back for timer0 compare match interrupt */
			TIMER0_CompareMatchCallBack = ptr;
			break;
		case TIMER1_OVF_INTERRUPT :
			/* Set call back for timer1 overflow interrupt */
			TIMER1_OverflowCallBack = ptr;
			break;
		case TIMER1_COMPA_INTERRUPT :
			/* Set call back for timer1 compare match A interrupt */
			TIMER1_CompareMatchACallBack = ptr;
			break;
		case TIMER1_COMPB_INTERRUPT :
			/* Set call back for timer1 compare match B interrupt */
			TIMER1_CompareMatchBCallBack = ptr;
			break;
		case TIMER1_CAPT_INTERRUPT :
			/* Set call back for timer1 input capture interrupt */
			TIMER1_CaptureEventCallBack = ptr;
			break;
		case TIMER2_OVF_INTERRUPT :
			/* Set call back for timer2 overflow interrupt */
			TIMER2_OverflowCallBack = ptr;
			break;
		case TIMER2_COMP_INTERRUPT :
			/* Set call back for timer2 compare match interrupt */
			TIMER2_CompareMatchCallBack = ptr;
			break;

		default :
			break;

	}

}

void MTIMER_voidInterruptEnable(u8 copy_u8ISR_ID)
{
	/* Determine required interrupt to enable */
	switch(copy_u8ISR_ID)
	{
		case TIMER0_OVF_INTERRUPT :
			SET_BIT(TIMSK, TOIE0);	/* Enable timer0 overflow mode interrupt */
			break;
		case TIMER0_COMP_INTERRUPT :
			SET_BIT(TIMSK, OCIE0);	/*  Enable timer0 Output Compare Match interrupt  */
			break;
		case TIMER1_OVF_INTERRUPT :
			SET_BIT(TIMSK, TOIE1);	/* Enable timer1 overflow mode interrupt */
			break;
		case TIMER1_COMPA_INTERRUPT :
			SET_BIT(TIMSK, OCIE1A);	/* Enable timer1 Output Compare A Match interrupt  */
			break;
		case TIMER1_COMPB_INTERRUPT :
			SET_BIT(TIMSK, OCIE1B);	/* Enable timer1 Output Compare B Match interrupt  */
			break;
		case TIMER1_CAPT_INTERRUPT :
			SET_BIT(TIMSK, TICIE1);	/* 	enable timer1 Input Capture interrupt  */
			break;
		case TIMER2_OVF_INTERRUPT :
			break;
		case TIMER2_COMP_INTERRUPT :
			break;

		default :
			break;

	}


}
void MTIMER_voidInterruptDisable(u8 copy_u8ISR_ID)
{
	switch(copy_u8ISR_ID)
	{
		case TIMER0_OVF_INTERRUPT :
			CLR_BIT(TIMSK, TOIE0);	/* Disable timer0 overflow mode interrupt */
			break;
		case TIMER0_COMP_INTERRUPT :
			CLR_BIT(TIMSK, OCIE0);	/*  Disable timer0 Output Compare Match interrupt  */
			break;
		case TIMER1_OVF_INTERRUPT :
			CLR_BIT(TIMSK, TOIE1);	/* Disable timer1 overflow mode interrupt */
			break;
		case TIMER1_COMPA_INTERRUPT :
			CLR_BIT(TIMSK, OCIE1A);	/* Disable timer1 Output Compare A Match interrupt  */
			break;
		case TIMER1_COMPB_INTERRUPT :
			CLR_BIT(TIMSK, OCIE1B);	/* Disable timer1 Output Compare B Match interrupt  */
			break;
		case TIMER1_CAPT_INTERRUPT :
			CLR_BIT(TIMSK, TICIE1);	/* 	Disable timer1 Input Capture interrupt  */
			break;
		case TIMER2_OVF_INTERRUPT :
			break;
		case TIMER2_COMP_INTERRUPT :
			break;

		default :
			break;

	}


}

u16 TIMER1_u16GetICR1(void)
{
	/* Return timer1 input capture register current value */
	u16 Local_u16Ret = ICR1;
	return Local_u16Ret;
}
void MTIMER_voidGenerateNonPWMSignal(u8 copy_u8TimerId)
{
	/* Determine required channel to generate non PWM */
	switch(copy_u8TimerId)
	{
		case TIMER0 :
			/* Generate non PWM on timer0 OC0 Pin */
			TCCR0 = (TCCR0&0xCF) | (TIMER0_COMPARE_OUTPUT_MODE<<COM00);
			break;
		case TIMER1 :
			/* Generate non PWM on timer1  OC1A and OC1B Pins */
			TCCR1A = (TCCR1A&0x3F) | (TIMER1_COMPARE_OUTPUT_MODE_A<<COM1A0);
			TCCR1A = (TCCR1A&0xCF) | (TIMER1_COMPARE_OUTPUT_MODE_B<<COM1B0);
			break;

		case TIMER1_OCR1A :
			/* Generate non PWM on timer1  OC1A Pin */
			TCCR1A = (TCCR1A&0x3F) | (TIMER1_COMPARE_OUTPUT_MODE_A<<COM1A0);
			break;
		case TIMER1_OCR1B :
			/* Generate non PWM on timer1  OC1B Pin */
			TCCR1A = (TCCR1A&0xCF) | (TIMER1_COMPARE_OUTPUT_MODE_B<<COM1B0);
			break;

		case TIMER2 :
			break;

	}


}
void MTIMER_voidGenerateFastPWMSignal(u8 copy_u8TimerId)
{
	/* Determine required channel to generate fast PWM */
	switch(copy_u8TimerId)
	{
		case TIMER0 :
			/* Generate fast PWM on timer0 OC0 Pin */
			TCCR0 = (TCCR0&0xCF) | (TIMER0_COMPARE_OUTPUT_MODE<<COM00);
			break;
		case TIMER1 :
			/* Generate fast PWM on timer1  OC1A and OC1B Pins */
			TCCR1A = (TCCR1A&0x3F) | (TIMER1_COMPARE_OUTPUT_MODE_A<<COM1A0);
			TCCR1A = (TCCR1A&0xCF) | (TIMER1_COMPARE_OUTPUT_MODE_B<<COM1B0);
			break;

		case TIMER1_OCR1A :
			/* Generate fast PWM on timer1  OC1A Pin */
			TCCR1A = (TCCR1A&0x3F) | (TIMER1_COMPARE_OUTPUT_MODE_A<<COM1A0);
			break;
		case TIMER1_OCR1B :
			/* Generate fast PWM on timer1  OC1B Pin */
			TCCR1A = (TCCR1A&0xCF) | (TIMER1_COMPARE_OUTPUT_MODE_B<<COM1B0);
			break;

		case TIMER2 :
			break;

	}

}
void MTIMER_voidGeneratePhaseCorrectPWMSignal(u8 copy_u8TimerId)
{
	/* Determine required channel to generate phase correct PWM */
	switch(copy_u8TimerId)
	{
		case TIMER0 :
			/* Generate phase correct PWM on timer0 OC0 Pin */
			TCCR0 = (TCCR0&0xCF) | (TIMER0_COMPARE_OUTPUT_MODE<<COM00);
			break;
		case TIMER1 :
			/* Generate phase correct PWM on timer1  OC1A and OC1B Pins */
			TCCR1A = (TCCR1A&0x3F) | (TIMER1_COMPARE_OUTPUT_MODE_A<<COM1A0);
			TCCR1A = (TCCR1A&0xCF) | (TIMER1_COMPARE_OUTPUT_MODE_B<<COM1B0);
			break;

		case TIMER1_OCR1A :
			/* Generate phase correct PWM on timer1  OC1A Pin */
			TCCR1A = (TCCR1A&0x3F) | (TIMER1_COMPARE_OUTPUT_MODE_A<<COM1A0);
			break;
		case TIMER1_OCR1B :
			/* Generate phase correct PWM on timer1  OC1B Pin */
			TCCR1A = (TCCR1A&0xCF) | (TIMER1_COMPARE_OUTPUT_MODE_B<<COM1B0);
			break;

		case TIMER2 :
			break;

	}

}

void MTIMER1_voidSetICR1(u16 copy_u16LoadValue)
{
	ICR1 = copy_u16LoadValue;
}

u16 MTIMER1_u16GetICR1(void)
{

	return ICR1;
}

void MTIMER1_voidSetICUTrigger(u8 copu_u8Edge)
{
	/* Assign edge to pin ICES1 in TCCR1B register */
	TCCR1B = (TCCR1B & 0xBF ) | (copu_u8Edge<<ICES1);

}

/* Implementation of ICU using polling to get more accurate results */
void MTIMER1_voidGetICUFreqDutyCycle(u32 *copy_u8Frequency, u8 *copy_u8DutyCycle)
{
	/* Set ICU trigger as rising edge */
	TCCR1B = (TCCR1B & 0xBF ) | (ICU_RISING_EDGE<<ICES1);
	/* Wait for rising edge */
	while ((TIFR&(1<<ICF1)) == 0);

	/* Start timer1 when rising ridge arrives */
	MTIMER_voidStart(TIMER1);
	TIFR = (1<<ICF1);		/* clear input capture flag */
	/* Set ICU trigger as falling edge */
	TCCR1B = (TCCR1B & 0xBF ) | (ICU_FALLING_EDGE<<ICES1);
	/* Wait for falling edge */
	while ((TIFR&(1<<ICF1)) == 0);
	/* Get Ton when falling edge arrives */
	ICU_timeOn=ICR1;

	TIFR = (1<<ICF1);		/* clear capture flag */
	/* Set ICU trigger as rising edge */
	TCCR1B = (TCCR1B & 0xBF ) | (ICU_RISING_EDGE<<ICES1);
	/* Wait for next rising edge */
	while ((TIFR&(1<<ICF1)) == 0);
	/* Get periodic time */
	ICU_periodicTime = ICR1;
	/* Stop the timer */
	MTIMER_voidStop(TIMER1);
	/* Calculate duty cycle then assign it to the pointer */
	*copy_u8DutyCycle = ICU_timeOn*100/ICU_periodicTime;
	/* Calculate frequency then assign it to the pointer */
	*copy_u8Frequency = 8000/ICU_periodicTime;

}
/* Implementation of ICU using interrupt */
//void MTIMER1_voidGetICUFreqDutyCycle(u32 *copy_u8Frequency, u8 *copy_u8DutyCycle)
//{
//	/* Set input capture trigger as rising edge */
//	MTIMER1_voidSetICUTrigger(ICU_RISING_EDGE);
//	/* Set input capture call back function   */
//	MTIMER_voidSetCallBack(ICU1_voidInterrupt, TIMER1_CAPT_INTERRUPT);
//	/* Enable input capture interrupt */
//	MTIMER_voidInterruptEnable(TIMER1_CAPT_INTERRUPT);
//	MGIE_voidEnable();		/* Enable global interrupt */
//
//	while(ICU_InterruptCounter<=3);		/* Wait until timeOn and periodicTime are calculated */
//
//	*copy_u8DutyCycle = ICU_timeOn*100/ICU_periodicTime;	/* Calculate duty cycle then assign it to the pointer */
//	*copy_u8Frequency = 8000/ICU_periodicTime;			/* Calculate frequency then assign it to the pointer */
//
//}
//
//static void ICU1_voidInterrupt(void)
//{
//	ICU_InterruptCounter++;	/* Increment the interrupt counter */
//	if(ICU_InterruptCounter == 1)
//	{
//		/* Start the timer at first rising edge */
//		MTIMER_voidStart(TIMER1);
//		/* Change ICU trigger to falling edge */
//		MTIMER1_voidSetICUTrigger(ICU_FALLING_EDGE);
//
//	}
//	else if(ICU_InterruptCounter == 2)
//	{
//		/* Get timeOn value */
//		ICU_timeOn = MTIMER1_u16GetICR1();
//		/* Change ICU trigger to rising edge */
//		MTIMER1_voidSetICUTrigger(ICU_RISING_EDGE);
//	}
//	else if(ICU_InterruptCounter == 3)
//	{
//		/* Get periodicTime value */
//		ICU_periodicTime = MTIMER1_u16GetICR1();
//
//		/* Stop the timer */
//		MTIMER_voidStop(TIMER1);
//		/* Disable ICU interrupt */
//		MTIMER_voidInterruptDisable(TIMER1_CAPT_INTERRUPT);
//		ICU_InterruptCounter++;
//
//	}
//
//}


void MTIMER_voidSetInterval(u8 copy_u8SystemTicks, void(*ptr)(void))
{

}

ISR(__vector_11)
{
	TIMER0_OverflowCallBack();
}

ISR(__vector_10)
{
	TIMER0_CompareMatchCallBack();
}


ISR(__vector_9)
{
	TIMER1_OverflowCallBack();
}

ISR(__vector_8)
{
	TIMER1_CompareMatchBCallBack();
}

ISR(__vector_7)
{
	TIMER1_CompareMatchACallBack();
}

ISR(__vector_6)
{
	TIMER1_CaptureEventCallBack();
}

ISR(__vector_5)
{
	TIMER2_OverflowCallBack();
}

ISR(__vector_4)
{
	TIMER2_CompareMatchCallBack();
}
