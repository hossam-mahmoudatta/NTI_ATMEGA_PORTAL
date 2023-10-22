 /******************************************************************************
 *
 * Module: Seven Segment Display
 *
 * File Name: SEGMENT.h
 *
 * Description: Header file for the AVR Seven Segment Display Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef SEGMENT_INTERFACE_H_
#define SEGMENT_INTERFACE_H_


#include "SEGMENT_CONFIG.h"

/*******************************************************************************
 *                             							 Functions Prototypes            					                  *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
SEGMENT_Error_t SEGMENT_voidInit(u8 copy_u8portID);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
SEGMENT_Error_t SEGMENT_voidDisplay(u8 copy_u8portID, u8 copy_u8pinValue);

#endif /* SEVEN-SEGMENT_H_ */
