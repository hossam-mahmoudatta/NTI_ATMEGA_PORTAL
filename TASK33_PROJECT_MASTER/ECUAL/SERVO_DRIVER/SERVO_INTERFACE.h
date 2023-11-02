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

#include "SERVO_CONFIG.h"

/*******************************************************************************
 *                             							 Functions Prototypes            					                  *
 *******************************************************************************/


// Initializes the 7 Segment Display Driver
void SERVO_voidInit(void);

// Displays a value on the 7 Segment Display
void SERVO_voidAdjustAngle(void);

u16 mapServo(u16 copy_u16ADCValue);


#endif /* SEVEN-SEGMENT_H_ */
