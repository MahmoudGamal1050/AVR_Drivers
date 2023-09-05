/*
 *	HSSD_program.c
 *  Description:	
 *  Created on : Aug 6, 2023
 *  Author     : Mahmoud Gamal
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "HSSD_config.h"
#include "HSSD_interface.h"
#include "HSSD_private.h"

#include "../../MCAL/MDIO/MDIO_interface.h"

/* Array with 7-segment numbers combinations */
u8 SSD_Nums[10] = 
{
	0x3F, 0x06,
	0x5B, 0x4F, 
	0x66, 0x6D, 
	0x7D, 0x07, 
	0x7F, 0x6F
};
void HSSD_voidInit(void)
{
	/* Set 7-segment pins as output */
	MDIO_voidSetPinDirection(SSD_A, DIO_OUTPUT);
	MDIO_voidSetPinDirection(SSD_B, DIO_OUTPUT);
	MDIO_voidSetPinDirection(SSD_C, DIO_OUTPUT);
	MDIO_voidSetPinDirection(SSD_D, DIO_OUTPUT);
	MDIO_voidSetPinDirection(SSD_E, DIO_OUTPUT);
	MDIO_voidSetPinDirection(SSD_F, DIO_OUTPUT);
	MDIO_voidSetPinDirection(SSD_G, DIO_OUTPUT);

}
void HSSD_voidWrite(u8 copy_u8Num)
{
	u8 local_u8FirstDigit = copy_u8Num%10;

	#if (SSD_COMMON == SSD_CATHODE)
		MDIO_voidSetPinValue(SSD_A, GET_BIT(SSD_Nums[local_u8FirstDigit],0));
		MDIO_voidSetPinValue(SSD_B, GET_BIT(SSD_Nums[local_u8FirstDigit],1));
		MDIO_voidSetPinValue(SSD_C, GET_BIT(SSD_Nums[local_u8FirstDigit],2));
		MDIO_voidSetPinValue(SSD_D, GET_BIT(SSD_Nums[local_u8FirstDigit],3));
		MDIO_voidSetPinValue(SSD_E, GET_BIT(SSD_Nums[local_u8FirstDigit],4));
		MDIO_voidSetPinValue(SSD_F, GET_BIT(SSD_Nums[local_u8FirstDigit],5));
		MDIO_voidSetPinValue(SSD_G, GET_BIT(SSD_Nums[local_u8FirstDigit],6));

	#elif (SSD_COMMON == SSD_ANODE)
		MDIO_voidSetPinValue(SSD_A, !GET_BIT(SSD_Nums[local_u8FirstDigit],0));
		MDIO_voidSetPinValue(SSD_B, !GET_BIT(SSD_Nums[local_u8FirstDigit],1));
		MDIO_voidSetPinValue(SSD_C, !GET_BIT(SSD_Nums[local_u8FirstDigit],2));
		MDIO_voidSetPinValue(SSD_D, !GET_BIT(SSD_Nums[local_u8FirstDigit],3));
		MDIO_voidSetPinValue(SSD_E, !GET_BIT(SSD_Nums[local_u8FirstDigit],4));
		MDIO_voidSetPinValue(SSD_F, !GET_BIT(SSD_Nums[local_u8FirstDigit],5));
		MDIO_voidSetPinValue(SSD_G, !GET_BIT(SSD_Nums[local_u8FirstDigit],6));

	#endif




}


