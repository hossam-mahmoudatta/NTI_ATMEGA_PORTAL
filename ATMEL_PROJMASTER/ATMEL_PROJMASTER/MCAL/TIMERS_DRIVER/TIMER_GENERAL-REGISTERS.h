 /******************************************************************************
 *
 * Module: TIMERS
 *
 * File Name: TIMER_GENERAL-REGISTERS.h
 *
 * Description: Header file for the TIMER Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/
#ifndef TIMER_GENERAL_H_
#define TIMER_GENERAL_H_

#include <math.h>
#include "../GPIO_DRIVER/GPIO_INTERFACE.h"
#define F_CPU 8000000UL

/*******************************************************************************
 *                              							Timers Registers					                   				     *
 *******************************************************************************/

// TIMSK Register
typedef struct {
	u8 TOIE0: 		1;	// Prescaler Clock Select
	u8 OCIE0: 		1;	// Waveform Generation Mode
	u8 TOIE1: 		1;	// Specifies the Compare Output OC0 mode.
	u8 OCIE1B: 	1;	// Waveform Generation Mode
	u8 OCIE1A: 	1; // Force Output Compare: Is only active when operating a non-PWM Mode.
	u8 TICIE1: 		1; // Force Output Compare: Is only active when operating a non-PWM Mode.
	u8 TOIE2: 		1; // Force Output Compare: Is only active when operating a non-PWM Mode.
	u8 OCIE2: 		1; // Force Output Compare: Is only active when operating a non-PWM Mode.
} TIMSK;
#define TIMSK_REG 	((volatile TIMSK*) 0x59)


// TIFR Register
typedef struct {
	u8 TOV0: 		1;	// Prescaler Clock Select
	u8 OCF0: 		1;	// Waveform Generation Mode
	u8 TOV1: 		1;	// Specifies the Compare Output OC0 mode.
	u8 OCF1B: 	1;	// Waveform Generation Mode
	u8 OCF1A: 	1; // Force Output Compare: Is only active when operating a non-PWM Mode.
	u8 TICIE1: 		1; // Force Output Compare: Is only active when operating a non-PWM Mode.
	u8 TOV2: 		1; // Force Output Compare: Is only active when operating a non-PWM Mode.
	u8 OCF2: 		1; // Force Output Compare: Is only active when operating a non-PWM Mode.
} TIFR;
#define TIFR_REG 	((volatile TIFR*) 0x58)

#endif
