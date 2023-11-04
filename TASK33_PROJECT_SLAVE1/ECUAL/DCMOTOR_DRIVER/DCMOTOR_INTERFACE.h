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

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#include "DCMOTOR_CONFIG.h"

/*******************************************************************************
 *                             							 Functions Prototypes            					                  *
 *******************************************************************************/


// Initializes the DC Motor Driver
void DCMOTOR_voidInit(void);

// Starts the DC Motor
void DCMOTOR_voidStart(MOTOR_NAME motorName);

// Stops the DC Motor
void DCMOTOR_voidStop(MOTOR_NAME motorName);

// Adjusts the angle for the servo motor
void SERVO_voidAdjustAngle(u8 copy_u8Angle);

// Mapping Servo with ADC
u16 mapServo(u16 copy_u16ADCValue);

// Setting the Car door to open or close
DOOR_STATUS SERVO_CarDoor(DOOR_NO doorNum, DOOR_STATUS doorAngle, u8 portNumber, u8 pinNumber);



#endif /* DCMOTOR_INTERFACE_H_ */
