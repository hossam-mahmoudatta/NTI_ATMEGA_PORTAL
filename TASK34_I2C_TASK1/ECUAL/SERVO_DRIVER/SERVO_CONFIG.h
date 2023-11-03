 /******************************************************************************
 *
 * Module: Seven Segment Display
 *
 * File Name: SEGMENT_CONFIG.h
 *
 * Description: Header file for the 7 Segment Display Driver Macro Definitions
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef SERVO_CONFIG_H_
#define SERVO_CONFIG_H_

#include "../../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"
#include "../../MCAL/ADC_DRIVER/ADC_INTERFACE.h"
#include "../../MCAL/TIMERS_DRIVER/TIMER1_DRIVER/TIMER1_INTERFACE.h"
#include "../LCD_DRIVER/LCD_INTERFACE.h"

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




#endif /* SERVO_CONFIG_H_ */
