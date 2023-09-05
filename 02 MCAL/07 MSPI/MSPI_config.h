/*
 *	MSPI_config.h
 *  Description:	
 *  Created on : Aug 21, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MSPI_MSPI_CONFIG_H_
#define MCAL_MSPI_MSPI_CONFIG_H_


/* Select SPI Data Order option:
*            LSB
*            MSB
*/
#define DARA_ORDER     LSB


/* Select SPI Clock Polarity Option:
*            RISING_FALLING
*            FALLING_RISING
*/
#define CLOCK_POLARITY     RISING_FALLING


/* Select SPI Clock Phase Option:
*            SAMPLE_SETUP
*            SETUP_SAMPLE
*/
#define CLOCK_PHASE     SAMPLE_SETUP

/* Select SPI Clock Rate Option:
*            NORMAL_SPEED_DIV_4
*            NORMAL_SPEED_DIV_16
*            NORMAL_SPEED_DIV_64
*            NORMAL_SPEED_DIV_128
*            DOUBLE_SPEED_DIV_2
*            DOUBLE_SPEED_DIV_8
*            DOUBLE_SPEED_DIV_32
*            DOUBLE_SPEED_DIV_64
*/
#define CLOCK_RATE    NORMAL_SPEED_DIV_4


#endif /* MCAL_MSPI_MSPI_CONFIG_H_ */
