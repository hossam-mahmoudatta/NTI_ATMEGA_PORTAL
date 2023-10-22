 /******************************************************************************
 *
 * Module: GPIO (General Purpose I/O)
 *
 * File Name: GPIO.h
 *
 * Description: Header file for the AVR GPIO Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "LED_CONFIG.h"

/*******************************************************************************
 *                             							 Functions Prototypes                       	    			      *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
LED_Error_t LED_voidInit(u8 copy_u8portID, u8 copy_u8pinID);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
LED_Error_t LED_voidOn(u8 copy_u8portID, u8 copy_u8pinID);


/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
LED_Error_t LED_voidOff(u8 copy_u8portID, u8 copy_u8pinID);

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
LED_Error_t LED_voidToggle(u8 copy_u8portID, u8 copy_u8pinID);

#endif /* LED_INTERFACE_H_ */
