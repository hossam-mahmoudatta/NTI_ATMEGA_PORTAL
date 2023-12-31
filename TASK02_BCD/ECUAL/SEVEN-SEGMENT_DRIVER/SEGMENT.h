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

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "../../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"


/*******************************************************************************
 *                                								 Definitions                            			           		  	  *
 *******************************************************************************/

// Defines the BCD DATA Pins based on the used Kit
#define BCD_1								PIN_0
#define BCD_2							PIN_1
#define BCD_4							PIN_2
#define BCD_8							PIN_4

// Defines the BCD COM Pins based on the used Kit
#define COM_4							PIN_6
#define COM_3							PIN_5
#define COM_2							PIN_2
#define COM_1							PIN_3

// Defines the BCD COM PORTs based on the used Kit
#define COM_4_PORT					PORT_B
#define COM_3_PORT					PORT_B
#define COM_2_PORT					PORT_A
#define COM_1_PORT					PORT_A

/*******************************************************************************
 *                               							Types Declaration                     							  *
 *******************************************************************************/

typedef enum SEGMENT_Error_t {
	SEGMENT_OK,
	SEGMENT_WRONG_VALUE,
	SEGMENT_WRONG_PORT_NUMBER
} SEGMENT_Error_t;


/*******************************************************************************
 *                             							 Functions Prototypes            					                  *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
SEGMENT_Error_t SEGMENT_Init(u8_t copy_u8portID);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
SEGMENT_Error_t SEGMENT_DISPLAY(u8_t copy_u8portID, u8_t copy_u8pinValue);

#endif /* SEVEN-SEGMENT_H_ */
