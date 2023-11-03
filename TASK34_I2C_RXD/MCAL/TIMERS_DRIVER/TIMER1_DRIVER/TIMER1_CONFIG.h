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

#define TIMER1_ISR_ENABLE				0
#define TIMER1_SET			1
#define TIMER1_NOTSET			0

#define TIMER1_SIZE		256

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
#define TIMER1_PRESCALER		TIMER1_PRESCALER_8


#endif /* TIMER_H_ */
