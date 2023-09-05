/*
 *	HEEPROM_program.c
 *  Description:	
 *  Created on : Sep 2, 2023
 *  Author     : Mahmoud Gamal
 */
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "HEEPROM_private.h"
#include "HEEPROM_config.h"
#include "HEEPROM_interface.h"
#include "../../MCAL/MDIO/MDIO_interface.h"
#include "../../MCAL/MI2C/MI2C_interface.h"


void HEEPROM_voidInit(void)
{
	/* Initialize this MC as I2C master */
	MI2C_voidInitMaster();

}
void HEEPROM_voidWriteByte(u8 Copy_u8Data, u16 Copy_u16Address)
{
	/* Send start condition */
	MI2C_voidStartCondition();
	/* Send the device address + write command, we need to get A8 A9 A10 address bits from the
	* memory location address and 0xA0 in the most significant 8-bits */
	MI2C_voidMasterSendSlaveAddressWrite((u8)(0x50 | ((Copy_u16Address & 0x0700)>>8)));
	/* Send EEPROM required address */
	MI2C_voidMasterSendData((u8)Copy_u16Address);
	/* Send data to EEPROM */
	MI2C_voidMasterSendData(Copy_u8Data);
	/* Send stop condition */
	MI2C_voidStopCondition();


}
u8 HEEPROM_u8ReadByte(u16 Copy_u16Address)
{
	/* Local variable to return data */
	u8 Local_u8RetData;
	/* Send start condition */
	MI2C_voidStartCondition();
	/* Send the device address + write command, we need to get A8 A9 A10 address bits from the
	 * memory location address and 0xA0 in the most significant 8-bits */
	MI2C_voidMasterSendSlaveAddressWrite((u8)(0x50 | ((Copy_u16Address & 0x0700)>>8)));
	/* Send EEPROM required address */
	MI2C_voidMasterSendData((u8)Copy_u16Address);
	/* Send repeated start condition */
	MI2C_voidRepeatedStartCondition();
	/* Send the device address + read command */
	MI2C_voidMasterSendSlaveAddressRead((u8)(0x50 | ((Copy_u16Address & 0x0700)>>8)));
	/* Get data from EEPROM */
	Local_u8RetData = MI2C_u8MasterReceiveData();
	/* Send stop condition */
	MI2C_voidStopCondition();
	/* Return data */
	return Local_u8RetData;
}
