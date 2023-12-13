/******************************************************************************
 *
 * Module: Seven Segment Display
 *
 * File Name: SEGMENT_PROGRAM.C
 *
 * Description: Source file for the AVR Seven Segment Display Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "DCMOTOR_INTERFACE.h"

/*******************************************************************************
 *                              						Functions Declarations                     	      				  *
 *******************************************************************************/

// Initializes the DC Motor Driver
void DCMOTOR_voidInit(void) {
	GPIO_voidSetPinDirection(MOTOR_PORT, FRONT_MOTORS_FWD, PIN_OUTPUT);
	GPIO_voidSetPinDirection(MOTOR_PORT, FRONT_MOTORS_BWD, PIN_OUTPUT);
	GPIO_voidSetPinDirection(MOTOR_PORT, FRONT_MOTORS_CTRL, PIN_OUTPUT);

	GPIO_voidSetPinDirection(MOTOR_PORT, REAR_MOTORS_FWD, PIN_OUTPUT);
	GPIO_voidSetPinDirection(MOTOR_PORT, REAR_MOTORS_BWD, PIN_OUTPUT);
	GPIO_voidSetPinDirection(MOTOR_PORT, REAR_MOTORS_CTRL, PIN_OUTPUT);
}


// Starts the DC Motor
void DCMOTOR_voidStart(MOTOR_DIR motorDirection) {
	switch(motorDirection)
	{
		case ACCELERATE:
			GPIO_voidSetPinValue(MOTOR_PORT, FRONT_MOTORS_FWD, LOGIC_HIGH);
			GPIO_voidSetPinValue(MOTOR_PORT, REAR_MOTORS_FWD, LOGIC_HIGH);
		break;
		case REVERSE:
			GPIO_voidSetPinValue(MOTOR_PORT, FRONT_MOTORS_BWD, LOGIC_HIGH);
			GPIO_voidSetPinValue(MOTOR_PORT, REAR_MOTORS_BWD, LOGIC_HIGH);
		break;
		case PARK:
			GPIO_voidSetPinValue(MOTOR_PORT, FRONT_MOTORS_FWD, LOGIC_LOW);
			GPIO_voidSetPinValue(MOTOR_PORT, REAR_MOTORS_FWD, LOGIC_LOW);
		break;
	}
}


// Stops the DC Motor
void DCMOTOR_voidStop(void) {
	GPIO_voidSetPinValue(MOTOR_PORT, FRONT_MOTORS_FWD, LOGIC_LOW);
	GPIO_voidSetPinValue(MOTOR_PORT, REAR_MOTORS_FWD, LOGIC_LOW);
}


// Stops the DC Motor
void DCMOTOR_voidControlSpeed(u8 copy_u8Duty) {
	u8 Speed = 0;
	Speed = TIMER1B_SetDutyCycle_FASTPWM(copy_u8Duty);
	GPIO_voidSetPinValue(MOTOR_PORT, FRONT_MOTORS_CTRL, Speed);
	GPIO_voidSetPinValue(MOTOR_PORT, REAR_MOTORS_CTRL, Speed);
}
