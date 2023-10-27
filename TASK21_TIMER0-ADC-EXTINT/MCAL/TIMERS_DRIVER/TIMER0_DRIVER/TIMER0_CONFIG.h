 /******************************************************************************
 *
 * Module: TIMER0
 *
 * File Name: TIMER0_CONFIG.h
 *
 * Description: Header file for the TIMER0 Driver MACRO DEFINITIONS
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#include "TIMER0_PRIVATE.h"

/*******************************************************************************
 *                              							Macro Definitions						                       		   *
 *******************************************************************************/


#define NUMBITS 8 // no. of bits in the Timer Register
#define SIZEBITS pow(2, NUMBITS) // Total size of the register

#define	NORMAL_MODE		1
#define	PWM_MODE				0
#define	CTC_MODE				0
#define	FASTPWM_MODE		0

#define ISR_ENABLE				1

typedef enum {
	NO_TIME		 			= 0b000,
	NO_PRESCALER		= 0b001,
	TIMER0_PRESCALER_8			= 0b010,
	TIMER0_PRESCALER_64 		= 0b011,
	TIMER0_PRESCALER_256 	= 0b100,
	TIMER0_PRESCALER_1024 	= 0b101,
	TIMER0_EXT_CLK_FALLING = 0b110,
	TIMER0_EXT_CLK_RISING 	= 0b111
} TIMER0_CLOCK;
#define PRESCALER	TIMER0_PRESCALER_8

typedef enum {
	NORMAL_NO_OC0		 		= 0b000,
	NORMAL_TOGGLE_0C0	= 0b001,
	NORMAL_CLEAR_0C0		= 0b010,
	NORMAL_SET_0C0 			= 0b011,
} TIMER0_COM_NORMAL;
#define TIMER0_COM_NORMAL_MODE			NORMAL_TOGGLE_0C0

typedef enum {
	FASTPWM_NO_OC0		 		= 0b000,
	FASTPWM_RESV					= 0b001,
	FASTPWM_CLEAR_0C0		= 0b010,
	FASTPWM_SET_0C0 			= 0b011,
} TIMER0_COM_FASTPWM;
#define TIMER0_COM_FASTPWM_MODE			FASTPWM_NO_OC0

typedef enum {
	PHASEPWM_NO_OC0		 		= 0b000,
	PHASEPWM_RESV					= 0b001,
	PHASEPWM_CLEAR_0C0		= 0b010,
	PHASEPWM_SET_0C0 			= 0b011,
} TIMER0_COM_PHASEPWM;
#define TIMER0_COM_PHASEPWM_MODE			PHASEPWM_NO_OC0


#endif /* TIMER_CONFIG_H_ */
