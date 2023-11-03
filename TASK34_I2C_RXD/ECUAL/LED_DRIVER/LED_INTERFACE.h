/******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED_INTERFACE.h
 *
 * Description: Header file for the LED Driver Prototypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "LED_CONFIG.h"

/*******************************************************************************
 *                             							 Functions Prototypes                       	    			      *
 *******************************************************************************/

// Initializes the LED Driver
LED_Error_t LED_voidInit(u8 copy_u8portID, u8 copy_u8pinID);

// Turns on a LED
LED_Error_t LED_voidOn(u8 copy_u8portID, u8 copy_u8pinID);

// Turns off a LED
LED_Error_t LED_voidOff(u8 copy_u8portID, u8 copy_u8pinID);

// Toggles a LED
LED_Error_t LED_voidToggle(u8 copy_u8portID, u8 copy_u8pinID);

#endif /* LED_INTERFACE_H_ */
