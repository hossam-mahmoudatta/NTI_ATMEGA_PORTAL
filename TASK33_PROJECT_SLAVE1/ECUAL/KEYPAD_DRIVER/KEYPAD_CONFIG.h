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

/* Initializing the number of rows and columns in the given keypad */
#define KPD_COL_NUM					(u8)(4)
#define KPD_ROW_NUM					(u8)(4)

/* Assigning the pins to the rows and columns depending on the keypad.
 * 	This achieves portability
 */
#define KPD_COL0_PORT				PORT_D
#define KPD_COL0_PIN					PIN_7

#define KPD_COL1_PORT				PORT_D
#define KPD_COL1_PIN						PIN_6

#define KPD_COL2_PORT				PORT_D
#define KPD_COL2_PIN					PIN_5

#define KPD_COL3_PORT				PORT_D
#define KPD_COL3_PIN					PIN_3

#define KPD_ROW0_PORT				PORT_C
#define KPD_ROW0_PIN					PIN_5

#define KPD_ROW1_PORT				PORT_C
#define KPD_ROW1_PIN					PIN_4

#define KPD_ROW2_PORT				PORT_C
#define KPD_ROW2_PIN					PIN_3

#define KPD_ROW3_PORT				PORT_C
#define KPD_ROW3_PIN					PIN_2


#define KPD_BTN_PRESSED			LOGIC_LOW
#define KPD_BTN_RELEASED			LOGIC_HIGH


#define KPD_ARR_COL_PORT 		{	KPD_COL0_PORT,	\
																KPD_COL1_PORT,	\
																KPD_COL2_PORT,	\
																KPD_COL3_PORT	}

#define KPD_ARR_COL_PIN 			{	KPD_COL0_PIN,	\
																KPD_COL1_PIN,	\
																KPD_COL2_PIN,	\
																KPD_COL3_PIN	}

#define KPD_ARR_ROW_PORT 		{	KPD_ROW0_PORT,	\
																KPD_ROW1_PORT,	\
																KPD_ROW2_PORT,	\
																KPD_ROW3_PORT	}

#define KPD_ARR_ROW_PIN 			{	KPD_ROW0_PIN,	\
																KPD_ROW1_PIN,	\
																KPD_ROW2_PIN,	\
																KPD_ROW3_PIN	}

#define KPD_ARR_VALUES 			{	{'7', '8', '9', '/'},	\
																{'4', '5', '6', '*'},	\
																{'1', '2', '3', '-'},	\
																{'C', '0', '=', '+'}	}


#endif /* KEYPAD_CONFIG_H_ */
