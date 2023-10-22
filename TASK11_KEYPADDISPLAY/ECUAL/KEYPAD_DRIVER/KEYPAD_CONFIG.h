 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.h
 *
 * Description: Header file for the AVR KEYPAD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "../../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"
#include <util/delay.h>


/*******************************************************************************
 *                                									Definitions                                  					  *
 *******************************************************************************/

#define KEYPAD_COL_NUM							(u8)(4)
#define KEYPAD_ROW_NUM							(u8)(4)

#define KEYPAD_COL0_PORT						PORT_D
#define KEYPAD_COL0_PIN							PIN_7

#define KEYPAD_COL1_PORT						PORT_D
#define KEYPAD_COL1_PIN							PIN_6

#define KEYPAD_COL2_PORT						PORT_D
#define KEYPAD_COL2_PIN							PIN_5

#define KEYPAD_COL3_PORT						PORT_D
#define KEYPAD_COL3_PIN							PIN_3

#define KEYPAD_ROW0_PORT						PORT_C
#define KEYPAD_ROW0_PIN							PIN_5

#define KEYPAD_ROW1_PORT						PORT_C
#define KEYPAD_ROW1_PIN							PIN_4

#define KEYPAD_ROW2_PORT						PORT_C
#define KEYPAD_ROW2_PIN							PIN_3

#define KEYPAD_ROW3_PORT						PORT_C
#define KEYPAD_ROW3_PIN							PIN_2


#define KEYPAD_BUTTON_PRESSED				LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED			LOGIC_HIGH


#define KEYPAD_ARR_COL_PORT 	{	KEYPAD_COL0_PORT, KEYPAD_COL1_PORT, KEYPAD_COL2_PORT, KEYPAD_COL3_PORT	}
#define KEYPAD_ARR_COL_PIN 		{	KEYPAD_COL0_PIN, KEYPAD_COL1_PIN, KEYPAD_COL2_PIN, KEYPAD_COL3_PIN	}
#define KEYPAD_ARR_ROW_PORT 	{	KEYPAD_ROW0_PORT, KEYPAD_ROW1_PORT, KEYPAD_ROW2_PORT, KEYPAD_ROW3_PORT	}
#define KEYPAD_ARR_ROW_PIN 		{	KEYPAD_ROW0_PIN, KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN	}

#define KEYPAD_ARR_VALUES 		{	{'7', '8', '9', '/'},	\
															{'4', '5', '6', '*'},	\
															{'1', '2', '3', '-'},	\
															{'C', '0', '=', '+'}	}


#endif /* KEYPAD_CONFIG_H_ */
