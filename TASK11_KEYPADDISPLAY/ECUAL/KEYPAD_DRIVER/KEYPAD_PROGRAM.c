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

#include "KEYPAD_INTERFACE.h"

u8 KPD_ROW_PORT_VAL [] = KPD_ARR_ROW_PORT;
u8 KPD_ROW_PIN_VAL [] = KPD_ARR_ROW_PIN;

u8 KPD_COL_PORT_VAL [] = KPD_ARR_COL_PORT;
u8 KPD_COL_PIN_VAL [] = KPD_ARR_COL_PIN;

u8 KPD_DATA [KPD_ROW_NUM][KPD_COL_NUM] = KPD_ARR_VALUES;


void KEYPAD_voidInit(void) {
	/* Setup PORT and PINS for for KEYPAD Rows*/
	u8 counter1, counter2;

	for(counter1 = 0 ; counter1 < KPD_ROW_NUM ; counter1++) {
		GPIO_voidSetPinDirection(KPD_ROW_PORT_VAL[counter1], KPD_ROW_PIN_VAL[counter1], PIN_OUTPUT);
		GPIO_voidSetPinValue(KPD_ROW_PORT_VAL[counter1], KPD_ROW_PIN_VAL[counter1], LOGIC_HIGH);
	}
	for(counter2 = 0 ; counter2 < KPD_COL_NUM ; counter2++) {
		GPIO_voidSetPinDirection(KPD_COL_PORT_VAL[counter2], KPD_COL_PIN_VAL[counter2], PIN_INPUT);
	}
}


u8 KEYPAD_u8getPressedKey(void) {
	u8 row, col, dataValue = 0xff;
	//while(1) {
		for (row = 0 ; row < KPD_ROW_NUM ; row++) {

			// I set the pin by '1' for the row, and will iterate
			GPIO_voidSetPinDirection(KPD_ROW_PORT_VAL[row], KPD_ROW_PIN_VAL[row], PIN_OUTPUT);

			/* Set/Clear the row output pin */
			GPIO_voidSetPinValue(KPD_ROW_PORT_VAL[row], KPD_ROW_PIN_VAL[row], KPD_BTN_PRESSED);
			//_delay_ms(8);

			for (col = 0 ; col < KPD_COL_NUM ; col++) {
				/* Check if the switch is pressed in this column */
				if(GPIO_u8GetPinValue(KPD_COL_PORT_VAL[col], KPD_COL_PIN_VAL[col]) == KPD_BTN_PRESSED) {
					dataValue = KPD_DATA[row][col];
				}
			}
			GPIO_voidSetPinValue(KPD_ROW_PORT_VAL[row], KPD_ROW_PIN_VAL[row], KPD_BTN_RELEASED);
		//}
	}
	return dataValue;
}








//#ifndef STD_KEYPAD
//	#if (KPD_COL_NUM == 3)
//	/*
//	 * Function responsible for mapping the switch number in the keypad to
//	 * its corresponding functional number in the proteus for 4x3 keypad
//	 */
//		static u8 KEYPAD_4x3_adjustKeyNumber(u8 button_number);
//	#elif (KPD_ROW_NUM == 4)
//	/*
//	 * Function responsible for mapping the switch number in the keypad to
//	 * its corresponding functional number in the proteus for 4x4 keypad
//	 */
//		static u8 KEYPAD_4x4_adjustKeyNumber(u8 button_number);
//	#endif
//#endif /* STD_KEYPAD */

//// Whats the use for this #idndef STD Keypad stuff?
//#ifndef STD_KEYPAD
//	#if (KEYPAD_COL_NUM == 3)
//	 // Update the keypad pressed button value with the correct one in keypad 4x3 shape
//		static u8 KEYPAD_4x3_adjustKeyNumber(u8 button_number) {
//			u8 keypad_button = 0;
//			switch(button_number) {
//				case 10: keypad_button = '*'; // ASCII Code of *
//						 break;
//				case 11: keypad_button = 0;
//						 break;
//				case 12: keypad_button = '#'; // ASCII Code of #
//						 break;
//				default: keypad_button = button_number;
//						break;
//			}
//			return keypad_button;
//		}
//
//	#elif (KEYPAD_COL_NUM == 4)
//		// Update the keypad pressed button value with the correct one in keypad 4x4 shape
//		static u8 KEYPAD_4x4_adjustKeyNumber(u8 button_number) {
//			u8 keypad_button = 0;
//			switch(button_number) {
//				case 1: keypad_button = 7;
//						break;
//				case 2: keypad_button = 8;
//						break;
//				case 3: keypad_button = 9;
//						break;
//				case 4: keypad_button = '%'; // ASCII Code of %
//						break;
//				case 5: keypad_button = 4;
//						break;
//				case 6: keypad_button = 5;
//						break;
//				case 7: keypad_button = 6;
//						break;
//				case 8: keypad_button = '*'; /* ASCII Code of '*' */
//						break;
//				case 9: keypad_button = 1;
//						break;
//				case 10: keypad_button = 2;
//						break;
//				case 11: keypad_button = 3;
//						break;
//				case 12: keypad_button = '-'; /* ASCII Code of '-' */
//						break;
//				case 13: keypad_button = 13;  /* ASCII of Enter */
//						break;
//				case 14: keypad_button = 0;
//						break;
//				case 15: keypad_button = '='; /* ASCII Code of '=' */
//						break;
//				case 16: keypad_button = '+'; /* ASCII Code of '+' */
//						break;
//				default: keypad_button = button_number;
//						break;
//			}
//			return keypad_button;
//		}
//	#endif
//#endif /* STD_KEYPAD */

