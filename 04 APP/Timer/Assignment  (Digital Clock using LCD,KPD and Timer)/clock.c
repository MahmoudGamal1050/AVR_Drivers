/*
 *	main.c
 *  Description:	
 *  Created on : Aug 16, 2023
 *  Author     : Mahmoud Gamal
 *  Description: Clock Assignment.
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MGIE/MGIE_interface.h"
#include "MCAL/MTIMER/MTIMER_interface.h"
#include "HAL/HLCD/HLCD_interface.h"
#include "HAL/HKPD/HKPD_interface.h"

/* Global variables to save time */
u8 Global_u8Hours,Global_u8Minutes,Global_u8Seconds;
/* Variable to get keypad pressed key */
u8 Global_u8Key;		

/* Clock reset preprocessor function definition */
#define CLOCK_RESET \
		do\
		{\
			HLCD_voidClearScreen();\
			HLCD_voidWriteString("  00 : 00 : 00");\
			HLCD_voidSetPosition(1, 3);\
			HLCD_voidWriteString("Time Reset  ");\
			Global_u8Seconds=0;\
			Global_u8Minutes=0;\
			Global_u8Hours=0;\
		}while(0);

/* CallBack function for timer1 interrupt every 1s */
void WATCH_voidOneSecondInterrupt(void);
/* Function to display seconds */
void WATCH_voidDisplaySeconds(void);
/* Function to display minutes */
void WATCH_voidDisplayMinutes(void);
/* Function to display hours */
void WATCH_voidDisplayHours(void);
/* Function to adjust time through keypad */
void WATCH_voidSetTime(void);

int main(void)
{
	/* Initialize keypad */
	HKPD_voidInit();
	/* Initialize LCD */
	HLCD_voidInit();
	/* Initialize timer1 in CTC OCR1A mode */
	MTIMER_voidInit();
	/* F_CPU = 8MHZ, prescalar = 1024 -> tick time = 1024/8M = 128us
	 * To count to 1s -> number of ticks = 1s/128us = 7812
	 * Set compare value of OCR1A to clear timer when reaching 7812(1 second)
	 */
	MTIMER_voidSetCompareValue(TIMER1_OCR1A,7812 );
	/* Set callBack function for timer1 compare match A*/
	MTIMER_voidSetCallBack(WATCH_voidOneSecondInterrupt, TIMER1_COMPA_INTERRUPT);
	/* Enable timer1 compare match A */
	MTIMER_voidInterruptEnable(TIMER1_COMPA_INTERRUPT);
	MGIE_voidEnable();		/* Enable global interrupt */
	/* Write to LCD */
	HLCD_voidWriteString("  00 : 00 : 00");
	HLCD_voidSetPosition(1, 3);
	HLCD_voidWriteString("Clock Paused ");

    while (1)
    {
    	/* Check if a key is pressed */
    	Global_u8Key = HKPD_u8GetPressedKey();
    	if(Global_u8Key!=0)
    	{
    		switch(Global_u8Key)
    		{
    		case 'A' :
				/* Start the clock */
    			MTIMER_voidStart(TIMER1);		/* Start the timer */
    			HLCD_voidSetPosition(1, 3);
    			HLCD_voidWriteString("Clock Working");
    			break;
    		case 'B' :
				/* Stop the clock */
    			MTIMER_voidStop(TIMER1);	/* Stop the timer */
    			HLCD_voidSetPosition(1, 3);
    			HLCD_voidWriteString("Clock Paused ");
    			break;

    		case 'C' :
				/* Reset the clock */
    			MTIMER_voidStop(TIMER1);
    			CLOCK_RESET;
    			break;

    		case 'D' :
				/* Adjust timer */
    			MTIMER_voidStop(TIMER1);
    			WATCH_voidSetTime();
    			break;
    		}

    	}
    }
}

void WATCH_voidOneSecondInterrupt(void)
{
	Global_u8Seconds++;	/* Increment one second */
	WATCH_voidDisplaySeconds();	/* Display seconds on LCD */
	WATCH_voidDisplayMinutes(); /* Display minutes on LCD */
	WATCH_voidDisplayHours();	/* Display hours on LCD */
}

void WATCH_voidDisplaySeconds(void)
{

	if(Global_u8Seconds==60)
	{
		Global_u8Seconds =0;/* Reset seconds when reaching 60 */
		Global_u8Minutes++;	/* Increment minutes */
	}
	/* Move cursor */
	HLCD_voidSetPosition(0, 12);
	/* Write 0 to 2nd digit in case seconds < 10 */
	if (Global_u8Seconds<10)
	{
		HLCD_voidWriteData('0');
	}
	/* Write seconds to LCD */
	HLCD_voidWriteNumber(Global_u8Seconds);

}
void WATCH_voidDisplayMinutes(void)
{
	if(Global_u8Minutes==60)
	{
		Global_u8Minutes =0;	/* Reset minutes when reaching 60 */
		Global_u8Hours++;	/* Increment hours */
	}
	/* Move cursor */
	HLCD_voidSetPosition(0, 7);
	/* Write 0 to 2nd digit in case minutes < 10 */
	if (Global_u8Minutes<10)
	{
		HLCD_voidWriteData('0');
	}
	/* Write minutes to LCD */
	HLCD_voidWriteNumber(Global_u8Minutes);

}
void WATCH_voidDisplayHours(void)
{
	/* Reset hours when reaching 24 */
	if(Global_u8Hours==24)
	{
		Global_u8Hours =0;
	}
	/* Move cursor */
	HLCD_voidSetPosition(0, 2);
	/* Write 0 to 2nd digit in case hours < 10 */
	if (Global_u8Hours<10)
	{
		HLCD_voidWriteData('0');
	}
	/* Write hours to LCD */
	HLCD_voidWriteNumber(Global_u8Hours);
}

void WATCH_voidSetTime(void)
{

	u8 Local_u8RetFlag=0;	/* Flag to break the loop after adjusting time */
	u8 Local_u8TimeFlag=0; 	/* Flag to select between adjusting hours, minutes or hours */
	HLCD_voidSetPosition(1, 3);	/* Move cursor */
	HLCD_voidWriteString("Set Hours    "); /* Write to LCD */
	/* Loop to adjust time */
	while(Local_u8RetFlag==0)
	{
		/* Check if a key is pressed */
		Global_u8Key =HKPD_u8GetPressedKey();
		if(Global_u8Key!=0 && Local_u8TimeFlag==0)
		{
			/* Adjust hours */
			switch(Global_u8Key)
			{
			/* Increment hours when # is pressed */
			case '#' :
				Global_u8Hours++;
				WATCH_voidDisplayHours();	/* Display updated hours to LCD */
				break;
				/* Decrement hours when * is pressed */
			case '*' :
				/* When reaching underflow hours should stay at 0 */
				if(Global_u8Hours==0)
				{
					Global_u8Hours=1;
				}
				Global_u8Hours--;
				WATCH_voidDisplayHours(); /* Display updated hours to LCD */
				break;

			case 'D' :
				/* Go to adjust minutes */
				Local_u8TimeFlag=1;
				HLCD_voidSetPosition(1, 3);	/* Move cursor */
				HLCD_voidWriteString("Set Minutes"); /* Write to LCD */
				break;

			}
		}

		else if(Global_u8Key!=0 && Local_u8TimeFlag==1)
		{
			/* Adjust minutes */
			switch(Global_u8Key)
			{
			/* Increment minutes when # is pressed */
			case '#' :
				Global_u8Minutes++;
				WATCH_voidDisplayMinutes();
				break;
			/* Decrement minutes when * is pressed */
			case '*' :
				if(Global_u8Minutes==0)
				{
					Global_u8Minutes=1;
				}
				Global_u8Minutes--;
				WATCH_voidDisplayMinutes();	/* Display updated minutes to LCD */
				break;

			case 'D' :
				/* Go to adjust seconds */
				Local_u8TimeFlag=2;
				HLCD_voidSetPosition(1, 3);
				HLCD_voidWriteString("Set Seconds");
				break;

			}
		}

		else if(Global_u8Key!=0 && Local_u8TimeFlag==2)
		{
			/* Adjust seconds */
			switch(Global_u8Key)
			{
			/* Increment seconds when # is pressed */
			case '#' :
				Global_u8Seconds++;
				WATCH_voidDisplaySeconds();
				break;
			/* Decrement seconds when * is pressed */
			case '*' :
				if(Global_u8Seconds==0)
				{
					Global_u8Seconds=1;
				}
				Global_u8Seconds--;
				WATCH_voidDisplaySeconds(); /* Display updated seconds to LCD */
				break;

			case 'D' :
				/* Break the loop so that the clock starts again */
				Local_u8RetFlag=1;
				break;


			}
		}
	}

	HLCD_voidSetPosition(1, 3);
	HLCD_voidWriteString("Clock Working");
	MTIMER_voidStart(TIMER1);	/* Start the clock after adjusting time */

}
