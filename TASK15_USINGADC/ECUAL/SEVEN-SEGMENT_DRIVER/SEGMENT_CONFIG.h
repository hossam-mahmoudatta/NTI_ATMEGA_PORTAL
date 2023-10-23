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

#ifndef SEGMENT_CONFIG_H_
#define SEGMENT_CONFIG_H_

#include "../../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"

/*******************************************************************************
 *                                							Macro Definitions                            			     	  		*
 *******************************************************************************/

// Defines the BCD DATA Pins based on the used Kit
#define BCD_1							PIN_0
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

#define DIGITS_USED					2

/*******************************************************************************
 *                               							Types Declaration                     							  *
 *******************************************************************************/

typedef enum SEGMENT_Error_t {
	SEGMENT_OK,
	SEGMENT_WRONG_VALUE,
	SEGMENT_WRONG_PORT_NUMBER
} SEGMENT_Error_t;


#endif /* SEVEN-SEGMENT_H_ */
