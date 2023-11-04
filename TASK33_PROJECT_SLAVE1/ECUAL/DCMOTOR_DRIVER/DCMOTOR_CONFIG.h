 /******************************************************************************
 *
 * Module: Servo Motor
 *
 * File Name: Servo_CONFIG.h
 *
 * Description: Header file for the Servo Motor Driver Macro Definitions
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef DCMOTOR_CONFIG_H_
#define DCMOTOR_CONFIG_H_

#include <util/delay.h>
#include "../../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"
#include "../../MCAL/ADC_DRIVER/ADC_INTERFACE.h"
#include "../../MCAL/TIMERS_DRIVER/TIMER1_DRIVER/TIMER1_INTERFACE.h"
//#include "../LCD_DRIVER/LCD_INTERFACE.h"

/*******************************************************************************
 *                                							Macro Definitions                            			     	  		*
 *******************************************************************************/

// Defines the SERVO DATA PORT & PIN based on TIMER1A
#define SERVO_DATA_PORT		PORT_D
#define SERVO_DATA_PIN			PIN_5
#define SERVO_OP_RANGE		20000


/*******************************************************************************
 *                               							Types Declaration                     							  *
 *******************************************************************************/

#define MOTOR_PORT PORT_C

#define FRONT_MOTORS_FWD  PIN_0
#define FRONT_MOTORS_BWD  PIN_1
#define FRONT_MOTORS_CTRL  PIN_2

#define REAR_MOTORS_FWD  PIN_3
#define REAR_MOTORS_BWD  PIN_4
#define REAR_MOTORS_CTRL  PIN_5


#define MOTOR_STATE

#define MOTOR_MAX_SPEED  100


typedef enum {
	FR_MOTOR = 0,
	FL_MOTOR,
	RL_MOTOR,
	RR_MOTOR,
	TOTAL_MOTOR
} MOTOR_NAME;

#endif /* DCMOTOR_CONFIG_H_ */
