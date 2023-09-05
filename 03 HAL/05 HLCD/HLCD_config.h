/*
 *	HLCD_config.h
 *  Description:	
 *  Created on : Aug 10, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef HAL_HLCD_HLCD_CONFIG_H_
#define HAL_HLCD_HLCD_CONFIG_H_
/* Choose LCD mode :
 * 		_8_BIT_MODE
 * 		_4_BIT_MODE
 */
#define LCD_MODE _4_BIT_MODE
/* Choose LCD Port */
#define LCD_DATA_PORT	DIO_PORTA

/* Choose LCD data pins for 8_bit_mode */
#if LCD_MODE == _8_BIT_MODE
#define LCD_D0       PC0
#define LCD_D1       PC1
#define LCD_D2       PC2
#define LCD_D3       PC3
#define LCD_D4       PC4
#define LCD_D5       PC5
#define LCD_D6       PC6
#define LCD_D7       PC7

/* Choose LCD data pins for 4_bit_mode */
#elif LCD_MODE ==  _4_BIT_MODE
#define LCD_D4       PA0
#define LCD_D5       PA1
#define LCD_D6       PA2
#define LCD_D7       PA3

#endif

/* Choose LCD control pins */

#define LCD_RS		PA6
#define LCD_RW		PA5
#define LCD_EN		PA4


#endif /* HAL_HLCD_HLCD_CONFIG_H_ */
