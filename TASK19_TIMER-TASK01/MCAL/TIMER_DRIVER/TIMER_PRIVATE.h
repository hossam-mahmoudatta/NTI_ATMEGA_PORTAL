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

#include <math.h>
#include "../GPIO_DRIVER/GPIO_INTERFACE.h"

/*******************************************************************************
 *                              							Timers Registers					                   				     *
 *******************************************************************************/

#define NUMBITS 8 // no. of bits in the Timer Register
#define SIZEBITS pow(2, NUMBITS) // Total size of the register

// Timer0 Registers
typedef struct {
	u8 CSx: 		3;	// Prescaler Clock Select
	u8 WGM01: 	1;	// Waveform Generation Mode
	u8 COMx: 	2;	// Specifies the Compare Output OC0 mode.
	u8 WGM00: 1;	// Waveform Generation Mode
	u8 FOC0: 	1; // Force Output Compare: Is only active when operating a non-PWM Mode.
} TCCR0;
#define TCCR0_REG 	(*(volatile TCCR0*) 0x53)

#define TCNT0_REG	(*(volatile u8*) 0x52)
#define OCR0_REG  	(*(volatile u8*) 0x5C)


// Timer1A, Timer1B Registers
typedef struct {
	u8 WGM1x: 		2;	// Waveform Generation Mode
	u8 FOC1B: 		1;	// Force Output Compare: Is only active when operating a non-PWM Mode.
	u8 FOC1A: 		1;	// Force Output Compare: Is only active when operating a non-PWM Mode.
	u8 COM1Bx: 	2;	// Specifies the Compare Output OC1B mode.
	u8 COM1Ax: 	2;	// Specifies the Compare Output OC1A mode.
} TCCR1A;
#define TCCR1A_REG 	(*(volatile TCCR1A*) 0x4F)

typedef struct {
	u8 CS1x: 			3;	// Prescaler Clock Select
	u8 WGM1x: 		2;	// Waveform Generation Mode
	u8		 	 : 		1;	// Reserved Bit
	u8 ICES1: 		1;	// Input Capture Edge Select
	u8 ICNC1: 		1;	// Input Capture Noise Canceler
} TCCR1B;
#define TCCR1B_REG 	(*(volatile TCCR1B*) 0x4E)

#define TCNT1H_REG 	(*(volatile u8*) 0x4D) // Counter
#define TCNT1L_REG 	(*(volatile u8*) 0x4C) // Counter
#define OCR1AH_REG 	(*(volatile u8*) 0x4B) // Output Compare Register High Byte
#define OCR1AL_REG 	(*(volatile u8*) 0x4A) // Output Compare Register Low Byte
#define OCR1BH_REG 	(*(volatile u8*) 0x49) // Output Compare Register High Byte
#define OCR1BL_REG 	(*(volatile u8*) 0x48) // Output Compare Register Low Byte




// General Timer Registers
#define TIMSK_REG  	(*(volatile u8*) 0x59)
#define TIFR_REG  		(*(volatile u8*) 0x58)



// Timer2 Registers
#define TCCR2 	(*(volatile u8*) 0x45)
#define TCNT2 		(*(volatile u8*) 0x44)

#endif /* TIMER_REGISTERS_H_ */
