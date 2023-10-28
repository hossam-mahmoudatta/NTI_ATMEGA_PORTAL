 /******************************************************************************
 *
 * Module: TIMERS
 *
 * File Name: TIMER_PRIVATE.h
 *
 * Description: Header file for the TIMER Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/
#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#include "../TIMERS_DRIVER/TIMER_GENERAL-REGISTERS.h"

/*******************************************************************************
 *                              							Timers Registers					                   				     *
 *******************************************************************************/

// Timer2 Registers
typedef struct {
	u8 CS2x: 		3;	// Prescaler Clock Select
	u8 WGM21: 	1;	// Waveform Generation Mode
	u8 COM2x: 	2;	// Specifies the Compare Output OC0 mode.
	u8 WGM20: 1;	// Waveform Generation Mode
	u8 FOC2: 	1; // Force Output Compare: Is only active when operating a non-PWM Mode.
} TCCR0;
#define TCCR2_REG 	(*(volatile TCCR1A*) 0x45)

#define TCNT2_REG	(*(volatile u8*) 0x44)
#define OCR2_REG  	(*(volatile u8*) 0x43)


#endif /* TIMER_REGISTERS_H_ */
