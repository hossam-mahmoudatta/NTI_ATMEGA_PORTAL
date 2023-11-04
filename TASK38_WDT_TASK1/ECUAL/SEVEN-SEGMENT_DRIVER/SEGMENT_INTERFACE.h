 /******************************************************************************
 *
 * Module: Seven Segment Display
 *
 * File Name: SEGMENT_INTERFACE.h
 *
 * Description: Header file for the AVR Seven Segment Display Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef SEGMENT_INTERFACE_H_
#define SEGMENT_INTERFACE_H_

#include "SEGMENT_CONFIG.h"

/*******************************************************************************
 *                             							 Functions Prototypes            					                  *
 *******************************************************************************/

// Initializes the 7 Segment Display Driver
SEGMENT_Error_t SEGMENT_voidInit(u8 copy_u8portID);


// Displays a value on the 7 Segment Display
SEGMENT_Error_t SEGMENT_voidDisplay(u8 copy_u8portID, u8 copy_u8pinValue);


#endif /* SEVEN-SEGMENT_H_ */
