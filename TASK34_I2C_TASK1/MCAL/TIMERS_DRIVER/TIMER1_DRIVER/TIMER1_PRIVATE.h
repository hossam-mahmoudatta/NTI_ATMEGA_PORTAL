 /******************************************************************************
 *
 * Module: TIMER1
 *
 * File Name: TIMER_PRIVATE1.h
 *
 * Description: Header file for the TIMER Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/
#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#include "../TIMER_GENERAL_PRIVATE.h"

/*******************************************************************************
 *                              							Timer1 Registers					                   				     *
 *******************************************************************************/

// Timer1A, Timer1B Registers
typedef struct {
	u8 WGM1x: 		2;	// Waveform Generation Mode WGM11 & WGM10
	u8 FOC1B: 		1;	// Force Output Compare: Is only active when operating a non-PWM Mode.
	u8 FOC1A: 		1;	// Force Output Compare: Is only active when operating a non-PWM Mode.
	u8 COM1Bx: 	2;	// Specifies the Compare Output OC1B mode.
	u8 COM1Ax: 	2;	// Specifies the Compare Output OC1A mode.
} TCCR1A;
#define TCCR1A_REG 	((volatile TCCR1A*) 0x4F)

typedef struct {
	u8 CS1x: 			3;	// Prescaler Clock Select
	u8 WGM1x: 		2;	// Waveform Generation Mode WGM13 & WGM12
	u8		 	 : 		1;	// Reserved Bit
	u8 ICES1: 		1;	// Input Capture Edge Select
	u8 ICNC1: 		1;	// Input Capture Noise Canceler
} TCCR1B;
#define TCCR1B_REG 	((volatile TCCR1B*) 0x4E)

#define TCNT1H_REG 	(*(volatile u8*) 0x4D) // Counter
#define TCNT1L_REG 	(*(volatile u8*) 0x4C) // Counter
#define TCNT1_REG 	(*(volatile u16*) 0x4C) // Counter

#define OCR1AH_REG 	(*(volatile u8*) 0x4B) // Output Compare Register High Byte
#define OCR1AL_REG 	(*(volatile u8*) 0x4A) // Output Compare Register Low Byte
#define OCR1A_REG 	(*(volatile u16*) 0x4A) // Output Compare Register the Two Bytes

#define OCR1BH_REG 	(*(volatile u8*) 0x49) // Output Compare Register High Byte
#define OCR1BL_REG 	(*(volatile u8*) 0x48) // Output Compare Register Low Byte
#define OCR1B_REG 	(*(volatile u16*) 0x48) // Output Compare Register the Two Bytes

#define ICR1H_REG 	(*(volatile u8*) 0x47) // Input Capture Register High Byte
#define ICR1L_REG 	(*(volatile u8*) 0x46) // Input Capture Register Low Byte
#define ICR1_REG 	(*(volatile u16*) 0x46) // Input Capture Register Low Byte


#endif /* TIMER1_PRIVATE_H_ */
