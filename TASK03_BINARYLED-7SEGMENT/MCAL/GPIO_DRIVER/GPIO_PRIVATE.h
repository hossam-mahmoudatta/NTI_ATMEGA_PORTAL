/******************************************************************************
 *
 * Module: GPIO (General Purpose I/O)
 *
 * File Name: GPIO_CONFIG.h
 * uPDATED ON: MAY 6TH
 * Description: Header file for the AVR GPIO Driver TO INCLUDE THE INITIAL DEFINITIONS
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"

/************************************************************************/
/*                             				GPIO Registers                            				   */
/************************************************************************/


// PORTA Registers
#define PORTA_REG	(*(volatile u8*)0x3B)
#define DDRA_REG		(*(volatile u8*)0x3A)
#define PINA_REG		(*(volatile u8*)0x39)
// since this was a pure address, I had to cast it
// then dereference it so that i can access its pointed value.

// PORTB Registers
#define PORTB_REG	(*(volatile u8*)0x38)
#define DDRB_REG		(*(volatile u8*)0x37)
#define PINB_REG		(*(volatile u8*)0x36)

// PORTC Registers
#define PORTC_REG	(*(volatile u8*)0x35)
#define DDRC_REG		(*(volatile u8*)0x34)
#define PINC_REG		(*(volatile u8*)0x33)

// PORTD Registers
#define PORTD_REG	(*(volatile u8*)0x32)
#define DDRD_REG		(*(volatile u8*)0x31)
#define PIND_REG		(*(volatile u8*)0x30)

#endif /* GPIO_PRIVATE_H_ */
