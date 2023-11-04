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

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "KEYPAD_CONFIG.h"

/*******************************************************************************
 *                              						Functions Prototypes                          						  *
 *******************************************************************************/

// Initializes the driver for the keypad with the option for 4x3 and 4x4 Keypads
void KEYPAD_voidInit(void);

// Checks which key was pressed
u8 KEYPAD_u8getPressedKey(void);

#endif /* KEYPAD_INTERFACE_H_ */
