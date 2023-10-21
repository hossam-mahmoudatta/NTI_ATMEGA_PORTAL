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
void LCD_vidInit(void) {
	// LCD Power On Internal Delay is 15 mS
	_delay_ms(30);

	// Initialize RS Pin
	GPIO_vidSetPinDirection(LCD_INIT_PORT, LCD_RS, PIN_OUTPUT);

	// Initialize Enable Pin
	GPIO_vidSetPinDirection(LCD_INIT_PORT, LCD_ENABLE, PIN_OUTPUT);


	// Setup the port and pins for the data pins inside the LCD
	GPIO_vidSetPinDirection(LCD_DATA_PORT, LCD_DATAPIN_D4, PIN_OUTPUT);
	GPIO_vidSetPinDirection(LCD_DATA_PORT, LCD_DATAPIN_D5, PIN_OUTPUT);
	GPIO_vidSetPinDirection(LCD_DATA_PORT, LCD_DATAPIN_D6, PIN_OUTPUT);
	GPIO_vidSetPinDirection(LCD_DATA_PORT, LCD_DATAPIN_D7, PIN_OUTPUT);


	LCD_vidSendCommand(0x20);
	LCD_vidSendCommand(0x20);
	LCD_vidSendCommand(0x80);

	_delay_ms(2);

	LCD_vidSendCommand(0x00);
	LCD_vidSendCommand(0xC0);

	_delay_ms(2);

	LCD_vidSendCommand(0x00);
	LCD_vidSendCommand(0x10);

	_delay_ms(2);

//	LCD_vidSendCommand(0x00);
//	LCD_vidSendCommand(0x60);
//
//	_delay_ms(10);

	// Initializing Sending Commands
	//LCD_vidSendCommand(LCD_TWO_LINE_FOUR_BIT);
	//LCD_vidSendCommand(LCD_CURSOR_OFF);
	//LCD_vidSendCommand(LCD_CLEAR_DISPLAY);
}


// Sends a command to the LCD
void LCD_vidSendCommand(u8_t copy_u8Command) {

	// Set RS Pin to '0'
	GPIO_vidSetPinValue(LCD_INIT_PORT, LCD_RS, LOGIC_LOW);
	_delay_ms(1);

	// Inserts the command in the assigned PORT to be sent to the LCD
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8Command, 7));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8Command, 6));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8Command, 5));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8Command, 4));
	_delay_ms(2);

	// Set Enable Pin to '1'
	GPIO_vidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(2);

	// Set Enable Pin to '0'
	GPIO_vidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
	_delay_ms(2);

	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8Command, 3));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8Command, 2));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8Command, 1));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8Command, 0));

	// Set Enable Pin to '1'
	GPIO_vidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(2);

	// Set Enable Pin to '0'
	GPIO_vidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
	_delay_ms(2);
}


// Displays a character on the LCD
void LCD_vidDisplayCharacter(u8_t copy_u8data) {
	// Set RS Pin to '1'
	GPIO_vidSetPinValue(LCD_INIT_PORT, LCD_RS, LOGIC_HIGH);
	_delay_ms(2);

	// Inserts the data in the assigned PINS to be sent to the LCD
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8data, 7));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8data, 6));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8data, 5));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8data, 4));

	// Set Enable Pin to '1'
	GPIO_vidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(2);

	// Set Enable Pin to '0'
	GPIO_vidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
	_delay_ms(2);

	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8data, 3));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8data, 2));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8data, 1));
	GPIO_vidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8data, 0));

	// Set Enable Pin to '1'
	GPIO_vidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(2);

	// Set Enable Pin to '0'
	GPIO_vidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
	_delay_ms(2);
}


// Displays a string on the LCD
void LCD_vidDisplayString(cu8_t *str, u8_t copy_u8row, u8_t copy_u8_col) {
	u8_t i = 0;
	LCD_vidMoveCursor(copy_u8row, copy_u8_col);

	while(str[i] != '\0') {
		LCD_vidDisplayCharacter(str[i]);
		i++;
		copy_u8_col++;
		if (copy_u8_col >= LCD_COL_MAXSIZE) {
			copy_u8_col = 0;
			copy_u8row++;
			if (copy_u8row >= LCD_ROW_MAXSIZE) {
				copy_u8row = 0;
				LCD_vidMoveCursor(copy_u8row, copy_u8_col);
			}
		}
	}
	/*
	for (int i = 0 ; i < strlen(str) ; i++) {
		LCD_displayCharacters(str[i]);
	}*/
}


// Chooses where the cursor would stand on the LCD to type from it
void LCD_vidMoveCursor(u8_t copy_u8row, u8_t copy_u8_col) {

	// Calculate the required address in the LCD DDRAM checking
	// The location of the cursor originally on which line
	switch(copy_u8row) {
		case 0:
			LCD_vidSendCommand(copy_u8_col | 0x80);
				break;
		case 1:
			LCD_vidSendCommand(copy_u8_col + 0xc0);
				break;
		case 2:
			LCD_vidSendCommand(copy_u8_col + 0x94);
				break;
		case 3:
			LCD_vidSendCommand(copy_u8_col + 0xd4);
				break;
	}
	/* Move the LCD cursor to this specific address */
}


// Displays a string on the LCD at a chosen cursor and row
void LCD_vidDisplayStringRowColumn(u8_t copy_u8row,
		u8_t copy_u8_col,
		cu8_t *copy_cu8Str) {
	// Go to to the required LCD position
	LCD_vidMoveCursor(copy_u8row, copy_u8_col);

	// Display the string from the cursor
	LCD_vidDisplayString(*copy_cu8Str, copy_u8row, copy_u8_col);
}

// LCD only understands ASCII, so this converts Int to a string
void LCD_vidIntgerToString(u32_t copy_u32data, u8_t copy_u8row, u8_t copy_u8_col) {
	// A string to hold the ASCII values
	cu8_t buffer[16];

	// Converts data to its ASCII
	itoa(copy_u32data, buffer, 10);

	// Display string with the results in the buffer
	LCD_vidDisplayString(buffer, copy_u8row, copy_u8_col);
}

// Clears the LCD from any garbage
void LCD_vidClearScreen(void) {
	// Clears the LCD Display
	LCD_vidSendCommand(LCD_CLEAR_DISPLAY);
}

