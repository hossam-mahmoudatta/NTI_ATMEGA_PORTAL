/******************************************************************************
 *
 * Module: GPIO (General Purpose I/O)
 *
 * File Name: GPIO.h
 * uPDATED ON: MAY 6TH
 * Description: Header file for the AVR GPIO Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"
#include "GPIO_PRIVATE.h"
#include "GPIO_CONFIG.h"


/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will return an error.
 */
void GPIO_vidSetPinDirection(u8_t copy_u8portID, u8_t copy_u8pinID, u8_t copy_u8pinDIR);


/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will return an error.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_vidSetPinValue(u8_t copy_u8portID, u8_t copy_u8pinID, u8_t copy_u8pinValue);


/*
 * Description :
 * Toggles a certain pin when requested.
 * If the input port number or pin number are not correct, The function will return an error.
 */
void GPIO_vidTogglePin(u8_t copy_u8portID, u8_t copy_u8pinID);


/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return an error.
 */
u8_t GPIO_u8GetPinValue(u8_t copy_u8portID, u8_t copy_u8pinID);


/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_vidSetPortDirection(u8_t copy_u8portID, u8_t copy_u8portDIR);


/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_vidSetPortValue(u8_t copy_u8portID, u8_t copy_u8portValue);


/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
u8_t GPIO_u8GetPortValue(u8_t copy_u8portID);


#endif /* GPIO_INTERFACE_H_ */
