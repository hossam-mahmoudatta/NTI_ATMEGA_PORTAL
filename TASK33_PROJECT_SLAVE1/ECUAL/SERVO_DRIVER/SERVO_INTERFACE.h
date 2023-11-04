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


// Initializes the Servo Motor Driver
void SERVO_voidInit(void);

// Adjusts the angle for the servo motor
void SERVO_voidAdjustAngle(u8 copy_u8Angle);

// Mapping Servo with ADC
u16 mapServo(u16 copy_u16ADCValue);

DOOR_STATUS SERVO_CarDoor(DOOR_NO doorNum, DOOR_STATUS doorAngle, u8 portNumber, u8 pinNumber);



#endif /* SEVEN-SEGMENT_H_ */
