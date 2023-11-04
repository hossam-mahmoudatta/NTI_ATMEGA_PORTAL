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

#ifndef SERVO_CONFIG_H_
#define SERVO_CONFIG_H_

#include <util/delay.h>
#include "../../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"
#include "../../MCAL/ADC_DRIVER/ADC_INTERFACE.h"
#include "../../MCAL/TIMERS_DRIVER/TIMER1_DRIVER/TIMER1_INTERFACE.h"
#include "../LCD_DRIVER/LCD_INTERFACE.h"

/*******************************************************************************
 *                                							Macro Definitions                            			     	  		*
 *******************************************************************************/

// Defines the SERVO DATA PORT & PIN based on TIMER1A
#define SERVO_DATA_PORT		PORT_D
#define SERVO_DATA_PIN1		PIN_4
#define SERVO_DATA_PIN2		PIN_5
#define SERVO_OP_RANGE		20000


/*******************************************************************************
 *                               							Types Declaration                     							  *
 *******************************************************************************/

typedef enum {
	Door_Close = 0,
	Door_Open =180
} DOOR_STATUS;

typedef enum {
	FR_Door = 0,
	FL_Door = 1,
	RL_Door = 2,
	RR_Door = 3
} DOOR_NO;


#endif /* SERVO_CONFIG_H_ */
