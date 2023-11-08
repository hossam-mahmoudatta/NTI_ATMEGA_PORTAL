 /******************************************************************************
 *
 * Module: TIMER0
 *
 * File Name: TIMER0_PRIVATE.h
 *
 * Description: Header file for the TIMER0 Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/
#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#include "../TIMER_GENERAL_PRIVATE.h"

/*******************************************************************************
 *                              							Timer0 Registers					                   				     *
 *******************************************************************************/

// Timer0 Registers
typedef struct {
	u8 CS0x: 		3;	// Prescaler Clock Select
	u8 WGM01: 	1;	// Waveform Generation Mode
	u8 COM0x: 	2;	// Specifies the Compare Output OC0 mode.
	u8 WGM00: 1;	// Waveform Generation Mode
	u8 FOC0: 	1; // Force Output Compare: Is only active when operating a non-PWM Mode.
} TCCR0;
#define TCCR0_REG 	((volatile TCCR0*) 0x53)

#define TCNT0_REG	(*(volatile u8*) 0x52)
#define OCR0_REG  	(*(volatile u8*) 0x5C)


#endif /* TIMER_REGISTERS_H_ */
