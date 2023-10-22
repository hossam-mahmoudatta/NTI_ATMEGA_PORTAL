/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.c
 *
 * Description: Source file for the AVR KEYPAD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h>
#include "KEYPAD_INTERFACE.h"

#ifndef STD_KEYPAD
	#if (KEYPAD_COL_NUM == 3)
	/*
	 * Function responsible for mapping the switch number in the keypad to
	 * its corresponding functional number in the proteus for 4x3 keypad
	 */
		static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number);
	#elif (KEYPAD_COL_NUM == 4)
	/*
	 * Function responsible for mapping the switch number in the keypad to
	 * its corresponding functional number in the proteus for 4x4 keypad
	 */
		static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number);
	#endif
#endif /* STD_KEYPAD */


void KEYPAD_Init(void) {
	/* Setup PORT and PINS for for KEYPAD Rows*/
	GPIO_setupPinDirection(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN + 1, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN + 2, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN + 3, PIN_INPUT);

	/* Setup PORT and PINS for for KEYPAD Columns*/
	GPIO_setupPinDirection(KEYPAD_COL_PORT, KEYPAD_FIRSTCOL_PIN, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT, KEYPAD_FIRSTCOL_PIN + 1, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT, KEYPAD_FIRSTCOL_PIN + 2, PIN_INPUT);

	#if(KEYPAD_COL_NUM == 4)
		GPIO_setupPinDirection(KEYPAD_COL_PORT, KEYPAD_FIRSTCOL_PIN + 3, PIN_INPUT);
	#endif
}


uint8 KEYPAD_getPressedKey(void) {
	uint8 row, col;
	while(1) {
		for (row = 0 ; row < KEYPAD_ROW_NUM ; row++) {
			// I set the pin by '1' for the row, and will iterate
			GPIO_setupPinDirection(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN + row, PIN_OUTPUT);
			/* Set/Clear the row output pin */
			GPIO_writePin(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN + row, KEYPAD_BUTTON_PRESSED);
			//_delay_ms(8);
			for (col = 0 ; col < KEYPAD_COL_NUM ; col++) {
				/* Check if the switch is pressed in this column */
				if(GPIO_readPin(KEYPAD_COL_PORT,KEYPAD_FIRSTCOL_PIN + col) == KEYPAD_BUTTON_PRESSED) {
					#if (KEYPAD_COL_NUM == 3)
						#ifdef STD_KEYPAD
							return ( (row * KEYPAD_COL_NUM) + col + 1);
						#else
							return KEYPAD_4x3_adjustKeyNumber( (row * KEYPAD_COL_NUM) + col + 1);
						#endif
					#elif (KEYPAD_COL_NUM == 4)
						#ifdef STD_KEYPAD
							return ( (row * KEYPAD_COL_NUM) + col + 1);
						#else
							return KEYPAD_4x4_adjustKeyNumber( (row * KEYPAD_COL_NUM) + col + 1);
						#endif
					#endif
				}
			}
			GPIO_setupPinDirection(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN + row, PIN_INPUT);
		}
	}
}

// Whats the use for this #idndef STD Keypad stuff?
#ifndef STD_KEYPAD
	#if (KEYPAD_COL_NUM == 3)
	 // Update the keypad pressed button value with the correct one in keypad 4x3 shape
		static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number) {
			uint8 keypad_button = 0;
			switch(button_number) {
				case 10: keypad_button = '*'; // ASCII Code of *
						 break;
				case 11: keypad_button = 0;
						 break;
				case 12: keypad_button = '#'; // ASCII Code of #
						 break;
				default: keypad_button = button_number;
						break;
			}
			return keypad_button;
		}

	#elif (KEYPAD_COL_NUM == 4)
		// Update the keypad pressed button value with the correct one in keypad 4x4 shape
		static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number) {
			uint8 keypad_button = 0;
			switch(button_number) {
				case 1: keypad_button = 7;
						break;
				case 2: keypad_button = 8;
						break;
				case 3: keypad_button = 9;
						break;
				case 4: keypad_button = '%'; // ASCII Code of %
						break;
				case 5: keypad_button = 4;
						break;
				case 6: keypad_button = 5;
						break;
				case 7: keypad_button = 6;
						break;
				case 8: keypad_button = '*'; /* ASCII Code of '*' */
						break;
				case 9: keypad_button = 1;
						break;
				case 10: keypad_button = 2;
						break;
				case 11: keypad_button = 3;
						break;
				case 12: keypad_button = '-'; /* ASCII Code of '-' */
						break;
				case 13: keypad_button = 13;  /* ASCII of Enter */
						break;
				case 14: keypad_button = 0;
						break;
				case 15: keypad_button = '='; /* ASCII Code of '=' */
						break;
				case 16: keypad_button = '+'; /* ASCII Code of '+' */
						break;
				default: keypad_button = button_number;
						break;
			}
			return keypad_button;
		}
	#endif

#endif /* STD_KEYPAD */
