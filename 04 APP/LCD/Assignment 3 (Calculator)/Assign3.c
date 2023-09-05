/*
 *	main.c
 *  Description:	
 *  Created on : Aug 9, 2023
 *  Author     : Mahmoud Gamal
 *  Description: LCD Assignment 3 ( Calculator )
 */
#include <util/delay.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "HAL/HKPD/HKPD_interface.h"
#include "HAL/HLCD/HLCD_interface.h"

#define CALC_RESET do{\
	state=0;\
	num1=0;\
	num2=0;\
	op=0;\
	sign1=1;\
	sign2=1;\
	resultFlag=0;\
	HLCD_voidClearScreen();\
	}while(0)
int main(void)
{
	HLCD_voidInit();	/* Initialize LCD */
	HKPD_voidInit();	/* Initialize Keypad */
	u8 key;				/* Variable to save pressed key */			
	s16 num1=0,num2=0;	/* 2 Variables to save inserted numbers */	
	u8 op=0;			/* Variable to save operation */
	u8 state=0;			/* Variable to determine which number is entered (1st or 2nd) */
	s8 sign1=1,sign2=1;	/* 2 Variables for numbers signs */
	u8 resultFlag=0;

	while(1)
	{
		/* Get pressed key */
		key =HKPD_u8GetPressedKey();
		/* Check if there is a pressed key */
		if(key!=0)
		{
			/* Reset LCD when a key is pressed after result is shown */
			if(resultFlag==1)
				{CALC_RESET;}
			/* Write the key to LCD */
			HLCD_voidWriteData(key);
			/* Check if the key is a number */
			if(key>='0' && key <='9')
			{
				/* First number */
				if(state==0)
				{
					/* Calculate the whole number */
					num1 =num1*10+(key-'0');
				}
				/* Second number */
				else if(state==1)
				{
					/* Calculate the whole number */
					num2 =num2*10+(key-'0');
				}

			}
			/* If the key is '+','-','*','/' */
			else if(key<'0')
			{
				switch(key)
				{

				/* Adding operation */
				case '+' :
					/* In case this is an operation not a sign  */
					if(num1&&!op)
						{
						op = '+';	/* Save operation */
						state=1;	/* Change state to get second operand */
						}
					break;
				case '-' :
					/* In case this is an operation not a sign  */
					if(num1&&!op)
					{
						op = '-';	/* Save operation */
						state=1;	/* Change state to get second operand */
					}
					/* First number sign is - */
					else if(num1==0)
						{sign1=-1;}
					/* Second number sign is - */
					else
					{
						sign2=-1;
						state=1;
					}
					break;
				/* Multiplying operation */
				case '*' :
					op = '*';     /* Save operation */
					state=1;     /* Change state to get second operand */
					break;
				/* Division operation */
				case '/' :
					op = '/';   /* Save operation */
					state=1;    /* Change state to get second operand */
					break;

				}

			}

			/*  If the key is '=' */
			else if(key =='=')
			{
				switch(op)
				{
				case '+' :
					/* If the result is negative */
					if((sign1*num1+sign2*num2)<0)
					{
						/* Write minus sign to LCD */
						HLCD_voidWriteData('-');
						/* Write the positive number to LCD */
						HLCD_voidWriteNumber((sign1*num1+sign2*num2)*-1);
					}

					else
					{
						/* Write the number to LCD */
						HLCD_voidWriteNumber(sign1*num1+sign2*num2);
					}
					break;
				case '-' :
					/* If the result is negative */
					if((sign1*num1-sign2*num2)<0)
					{
						/* Write minus sign to LCD */
						HLCD_voidWriteData('-');
						/* Write the positive number to LCD */
						HLCD_voidWriteNumber((sign1*num1-sign2*num2)*-1);
					}

					else
					{
						/* Write the number to LCD */
						HLCD_voidWriteNumber(sign1*num1-sign2*num2);
					}
					break;
				case '*' :
					/* If the result is negative */
					if((sign1*num1*sign2*num2)<0)
					{
						/* Write minus sign to LCD */
						HLCD_voidWriteData('-');
						/* Write the positive number to LCD */
						HLCD_voidWriteNumber((sign1*num1*sign2*num2)*-1);
					}

					else
					{
						/* Write the number to LCD */
						HLCD_voidWriteNumber(sign1*num1*sign2*num2);
					}
					break;
				case '/' :
					/* If the result is negative */
					if(((sign1*num1)/(sign2*num2))<0)
					{
						/* Write minus sign to LCD */
						HLCD_voidWriteData('-');
						/* Write the positive number to LCD */
						HLCD_voidWriteNumber(((sign1*num1)/(sign2*num2))*-1);
					}

					else
					{
						/* Write the number to LCD */
						HLCD_voidWriteNumber(((sign1*num1)/(sign2*num2)));
					}
					break;

				}
				resultFlag=1;


			}

			else if(key=='C')
			{
				CALC_RESET;
			}





		}

	}
}


