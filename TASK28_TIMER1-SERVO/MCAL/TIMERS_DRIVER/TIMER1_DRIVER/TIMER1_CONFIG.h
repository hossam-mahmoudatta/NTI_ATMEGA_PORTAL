 /******************************************************************************
 *
 * Module: TIMER1
 *
 * File Name: TIMER1_CONFIG.h
 *
 * Description: Header file for the TIMER1 Driver MACRO DEFINITIONS
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#include "TIMER1_PRIVATE.h"

/*******************************************************************************
 *                              							Macro Definitions						                       		   *
 *******************************************************************************/

#define	TIMER1_NORMAL_MODE		0
#define	TIMER1_PHASEPWM_MODE	0
#define	TIMER1_CTC_MODE				0
#define	TIMER1_FASTPWM_MODE		1

#define TIMER1_ISR_ENABLE				1
#define TIMER1_SET			1
#define TIMER1_NOTSET			0

typedef enum {
	TIMER1_NO_TIME		 			= 0b000,
	TIMER1_NO_PRESCALER		= 0b001,
	TIMER1_PRESCALER_8		= 0b010,
	TIMER1_PRESCALER_64 		= 0b011,
	TIMER1_PRESCALER_256 	= 0b100,
	TIMER1_PRESCALER_1024 	= 0b101,
	TIMER1_EXT_CLK_FALLING = 0b110,
	TIMER1_EXT_CLK_RISING 	= 0b111
} TIMER1_CLOCK;
#define TIMER1_PRESCALER	TIMER1_PRESCALER_64

typedef enum {
	NORMAL_NO_OC0		 		= 0b000,
	NORMAL_TOGGLE_0C0	= 0b001,
	NORMAL_CLEAR_0C0		= 0b010,
	NORMAL_SET_0C0 			= 0b011,
} TIMER0_COM_NORMAL;
#define TIMER1_COM_CTC_MODE			NORMAL_TOGGLE_0C0

typedef enum {
	PHASEPWM_NO_OC0		 		= 0b000,
	PHASEPWM_RESV					= 0b001,
	PHASEPWM_CLEAR_0C0		= 0b010,
	PHASEPWM_SET_0C0 			= 0b011,
} TIMER0_COM_PHASEPWM;
#define TIMER0_COM_PHASEPWM_MODE			PHASEPWM_SET_0C0

typedef enum {
	FASTPWM_NO_OC0		 	= 0b000,
	FASTPWM_RESV				= 0b001,
	FASTPWM_NONINVERT		= 0b010,
	FASTPWM_INVERT			= 0b011,
} TIMER0_COM_FASTPWM;
#define TIMER0_COM_FASTPWM_MODE			FASTPWM_NONINVERT


EN_TIMER_Error_t TIMER_Init(uint32_t prescaler);

EN_TIMER_Error_t TIMER_DelaySet(uint32_t prescaler, float timeDelay);

void TIMER_CheckStatus(uint8_t pinNumber, uint8_t portNumber);

void TIMER_Start(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

uint8_t TIMER_Read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

#endif /* TIMER_H_ */
