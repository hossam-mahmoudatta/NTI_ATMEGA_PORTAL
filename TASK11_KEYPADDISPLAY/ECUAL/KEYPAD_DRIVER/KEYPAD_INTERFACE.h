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

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../MCAL/GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"


/*******************************************************************************
 *                                									Definitions                                  					  *
 *******************************************************************************/

#define KEYPAD_COL_NUM							4
#define KEYPAD_ROW_NUM							4

#define KEYPAD_COL_PORT							PORT_C
#define KEYPAD_FIRSTCOL_PIN						PIN_4

#define KEYPAD_ROW_PORT							PORT_C
#define KEYPAD_FIRSTROW_PIN						PIN_0

#define KEYPAD_BUTTON_PRESSED				LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED			LOGIC_HIGH

/*******************************************************************************
 *                              						Functions Prototypes                          						  *
 *******************************************************************************/

// Initializes the driver for the keypad with the option for 4x3 and 4x4 Keypads
void KEYPAD_Init(void);

// Checks which key was pressed
uint8 KEYPAD_getPressedKey(void);

#endif /* KEYPAD_H_ */
