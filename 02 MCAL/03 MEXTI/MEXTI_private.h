/*
 *	MEXTI_private.h
 *  Description:	
 *  Created on : Aug 14, 2023
 *  Author     : Mahmoud Gamal
 */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

/******************************************************************
* Registers Addresses Definition    	      					  *
*******************************************************************/

/* MCU Control Register contains control bits for interrupt sense control for INT0 and INT1 */
#define MCUCR     *((volatile u8 *) 0x55)

/* MCUCR Register Pin Definition :
ISC01 ISC00          Description
0      0             The low level of INT0 generates an interrupt request.
0      1             Any logical change on INT0 generates an interrupt request.
1      0             The falling edge of INT0 generates an interrupt request.
1      1             The rising edge of INT0 generates an interrupt request
*/
#define ISC00     0
#define ISC01     1
/*
ISC11 ISC10          Description
0      0             The low level of INT1 generates an interrupt request.
0      1             Any logical change on INT1 generates an interrupt request.
1      0             The falling edge of INT1 generates an interrupt request.
1      1             The rising edge of INT1 generates an interrupt request
*/
#define ISC10     2
#define ISC11     3

/* MCU Control and Status Register : contains control bit for interrupt sense control for (INT2) */
#define MCUCSR    *((volatile u8 *) 0x54)
/* MCUCSR Register Pin Definition :
ISC2                 Description
0                    The falling edge of INT2 generates an interrupt request.
1                   The rising edge of INT2 generates an interrupt request
*/

#define ISC2      6

 /* Global interrupt control register : contain(enable bits for external interrupt) */
#define GICR      *((volatile u8 *) 0x5B)
/* GICR Register Pin Definition */
#define INT0      6	  /* INT1: External Interrupt Request 0 Enable (BIT 6) */
#define INT1      7	  /* INT1: External Interrupt Request 1 Enable (BIT 7) */
#define INT2      5	  /*INT1: External Interrupt Request 2 Enable (BIT 5) */


/*General Interrupt Flag register : contains the interrupt flags for all the ATmega32 external interrupts */
#define GIFR      *((volatile u8 *) 0x5A)
/* GIFR Register Pin Definition */
#define INTF0     6	 /*When an edge or logic change on the INT0 pin triggers an interrupt request, INTF0 becomes set (one) by hardware*/
#define INTF1     7  /*When an edge or logic change on the INT1 pin triggers an interrupt request, INTF1 becomes set (one) by hardware*/
#define INTF2     5	 /*When an event on the INT2 pin triggers an interrupt request, INTF2 becomes set (one) by hardware */


/* ISR function like macro */
#define ISR(vector)\
void vector (void) __attribute__((signal,used));\
void vector(void)

#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
