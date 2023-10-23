/******************************************************************************
 *
 * Module: GPIO (General Purpose I/O)
 *
 * File Name: GPIO_INTERFACE.h
 * UPDATED ON: OCTOBER 2023
 * Description: Header file for the AVR GPIO Driver TO INCLUDE THE PROTOTYPES
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "GPIO_CONFIG.h"

/*******************************************************************************
 *                              						Functions Prototypes                           						  *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will return an error.
 */
GPIO_Error_t GPIO_voidSetPinDirection(u8 copy_u8portID, u8 copy_u8pinID, u8 copy_u8pinDIR);


/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will return an error.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
GPIO_Error_t GPIO_voidSetPinValue(u8 copy_u8portID, u8 copy_u8pinID, u8 copy_u8pinValue);


/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return an error.
 */
u8 GPIO_u8GetPinValue(u8 copy_u8portID, u8 copy_u8pinID);


/*
 * Description :
 * Toggles a certain pin when requested.
 * If the input port number or pin number are not correct, The function will return an error.
 */
GPIO_Error_t GPIO_voidTogglePin(u8 copy_u8portID, u8 copy_u8pinID);


/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 */
GPIO_Error_t GPIO_voidSetPortDirection(u8 copy_u8portID, u8 copy_u8portDIR);


/*
 * Description :
 * Write the value on the required port.
 */
GPIO_Error_t GPIO_voidSetPortValue(u8 copy_u8portID, u8 copy_u8portValue);


/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
u8 GPIO_u8GetPortValue(u8 copy_u8portID);


#endif /* GPIO_INTERFACE_H_ */
