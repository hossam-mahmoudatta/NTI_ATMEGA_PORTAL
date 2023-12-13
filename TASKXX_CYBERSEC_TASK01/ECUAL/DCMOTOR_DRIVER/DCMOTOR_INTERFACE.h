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
void DCMOTOR_voidStart(MOTOR_DIR motorDirection);

// Stops the DC Motor
void DCMOTOR_voidStop(void);

// Controls the DC Motor
void DCMOTOR_voidControlSpeed(u8 copy_u8Duty);


#endif /* DCMOTOR_INTERFACE_H_ */
