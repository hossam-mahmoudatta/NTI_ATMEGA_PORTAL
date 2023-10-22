 /******************************************************************************
 *
 * Module: LCD Display
 *
 * File Name: LCD.c
 *
 * Description: Source file for the AVR LCD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/



#include "LCD_INTERFACE.h"


// Initializes and enables the LCD Module to start functionality
void LCD_voidInit(void) {
	// Initialize RS Pin
	GPIO_voidSetPinDirection(LCD_INIT_PORT, LCD_RS, PIN_OUTPUT);

	// Initialize Enable Pin
	GPIO_voidSetPinDirection(LCD_INIT_PORT, LCD_ENABLE, PIN_OUTPUT);

	// LCD Power On Internal Delay is 15 mS
	_delay_ms(20);

	// Setup the port and pins for the data pins inside the LCD
	if (LCD_BIT_MODE == LCD_8_BIT) {
		GPIO_voidSetPortDirection(LCD_DATA_PORT, PORT_OUTPUT);

		LCD_voidSendCommand(LCD_TWO_LINE_EIGHT_BIT);
	}
	else {
		GPIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATAPIN_D4, PIN_OUTPUT);
		GPIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATAPIN_D5, PIN_OUTPUT);
		GPIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATAPIN_D6, PIN_OUTPUT);
		GPIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATAPIN_D7, PIN_OUTPUT);

		LCD_voidSendCommand(LCD_TWO_LINE_FOUR_BIT);
		LCD_voidSendCommand(LCD_TWO_LINE_FOUR_BIT_INIT1);
		LCD_voidSendCommand(LCD_TWO_LINE_FOUR_BIT_INIT2);
	}

	LCD_voidSendCommand(LCD_CURSOR_OFF);
	LCD_voidSendCommand(LCD_CLEAR_DISPLAY);

//	LCD_voidSendCommand(0x20);
//	LCD_voidSendCommand(0x20);
//	LCD_voidSendCommand(0x80);
//
//	_delay_ms(2);
//
//	LCD_voidSendCommand(0x00);
//	_delay_ms(2);
//	LCD_voidSendCommand(0xC0);
//
//	_delay_ms(2);
//
//	LCD_voidSendCommand(0x00);
//	_delay_ms(2);
//	LCD_voidSendCommand(0x10);
//
//	_delay_ms(2);

//	LCD_vidSendCommand(0x00);
//	LCD_vidSendCommand(0x60);

// Initializing Sending Commands
//LCD_vidSendCommand(LCD_TWO_LINE_FOUR_BIT);
}


// Sends a command to the LCD
void LCD_voidSendCommand(u8 copy_u8Command) {

	// Set RS Pin to '0'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_RS, LOGIC_LOW);
	_delay_ms(1);

	// Set Enable Pin to '1'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(2);

	if (LCD_BIT_MODE == LCD_8_BIT) {
		GPIO_voidSetPortValue(LCD_DATA_PORT, copy_u8Command);
		_delay_ms(2);

		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(2);
	}
	else {
		// Inserts the command in the assigned PORT to be sent to the LCD
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8Command, 4));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8Command, 5));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8Command, 6));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8Command, 7));
		_delay_ms(2);

		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(2);

		// Set Enable Pin to '1'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
		_delay_ms(2);

		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8Command, 0));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8Command, 1));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8Command, 2));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8Command, 3));
		_delay_ms(2);

		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(2);
	}
}


// Displays a character on the LCD
void LCD_voidDisplayCharacter(u8 copy_u8data) {

	// Set RS Pin to '1'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_RS, LOGIC_HIGH);
	_delay_ms(1);

	// Set Enable Pin to '1'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(2);

	if (LCD_BIT_MODE == LCD_8_BIT) {
		GPIO_voidSetPortValue(LCD_DATA_PORT, copy_u8data);
		_delay_ms(2);

		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(2);
	}
	else {
		// Inserts the command in the assigned PORT to be sent to the LCD
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8data, 4));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8data, 5));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8data, 6));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8data, 7));
		_delay_ms(2);

		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(2);

		// Set Enable Pin to '1'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
		_delay_ms(2);

		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8data, 0));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8data, 1));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8data, 2));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8data, 3));
		_delay_ms(2);

		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(2);
	}
}


// Displays a string on the LCD
void LCD_voidDisplayString(cu8 *str, u8 copy_u8row, u8 copy_u8_col) {
	u8 i = 0;
	LCD_voidMoveCursor(copy_u8row, copy_u8_col);

	while(str[i] != '\0') {
		LCD_voidDisplayCharacter(str[i]);
		i++;
		copy_u8_col++;
		if (copy_u8_col >= LCD_MAXCOL_SIZE) {
			copy_u8_col = 0;
			copy_u8row++;
			if (copy_u8row >= LCD_MAXROW_SIZE) {
				copy_u8row = 0;
				LCD_voidMoveCursor(copy_u8row, copy_u8_col);
			}
		}
	}
	/*
	for (int i = 0 ; i < strlen(str) ; i++) {
		LCD_displayCharacters(str[i]);
	}*/
}


// Chooses where the cursor would stand on the LCD to type from it
void LCD_voidMoveCursor(u8 copy_u8row, u8 copy_u8_col) {

	// Calculate the required address in the LCD DDRAM checking
	// The location of the cursor originally on which line
	//if(copy_u8row < LCD_MAXROW_SIZE && copy_u8_col < LCD_MAXCOL_SIZE) {
		switch(copy_u8row) {
			case 0:
				LCD_voidSendCommand(0x80 + copy_u8_col);
					break;
			case 1:
				LCD_voidSendCommand(0xC0 + copy_u8_col);
					break;
			case 2:
				LCD_voidSendCommand(0x94 + copy_u8_col);
					break;
			case 3:
				LCD_voidSendCommand(0xd4 + copy_u8_col);
					break;
			default:
				LCD_voidDisplayString("default", 0, 0);
				break;
		}
}


// LCD only understands ASCII, so this converts Int to a string
void LCD_voidIntgerToString(u32 copy_u32data, u8 copy_u8row, u8 copy_u8_col) {
	// A string to hold the ASCII values
	cu8 buffer[16];

	// Converts data to its ASCII
	itoa(copy_u32data, buffer, 10);

	// Display string with the results in the buffer
	LCD_voidDisplayString(buffer, copy_u8row, copy_u8_col);
}

// Clears the LCD from any garbage
void LCD_voidClearScreen(void) {
	// Clears the LCD Display
	LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
}

















//// Displays a string on the LCD at a chosen cursor and row
//void LCD_voidDisplayStringRowColumn(u8 copy_u8row,
//		u8 copy_u8_col,
//		cu8 *copy_cu8Str) {
//	// Go to to the required LCD position
//	LCD_voidMoveCursor(copy_u8row, copy_u8_col);
//
//	// Display the string from the cursor
//	LCD_voidDisplayString(*copy_cu8Str, copy_u8row, copy_u8_col);
//}
