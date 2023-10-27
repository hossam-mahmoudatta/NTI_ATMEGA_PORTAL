/******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED_CONFIG.h
 *
 * Description: Header file for the LED Driver Macro Definitions
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#include "../../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"

/*******************************************************************************
*                                							Macro Definitions                     					      		  *
 *******************************************************************************/

#define LED_NEGATIVE_LOGIC				0
#define LED_POSITIVE_LOGIC				1

#define LED_MODE									LED_POSITIVE_LOGIC

#define LED_PORTB_KIT_RED					PIN_7
#define LED_PORTA_KIT_GREEN			PIN_4
#define LED_PORTA_KIT_BLUE				PIN_5
#define LED_PORTA_KIT_YELLOW			PIN_6

/*******************************************************************************
 *                               							Enum Declaration                 									  *
 *******************************************************************************/

typedef enum LED_Error_t {
	LED_OK,
	LED_WRONG_PIN_NUMBER,
	LED_WRONG_PORT_NUMBER
} LED_Error_t;


#endif /* LED_CONFIG_H_ */
