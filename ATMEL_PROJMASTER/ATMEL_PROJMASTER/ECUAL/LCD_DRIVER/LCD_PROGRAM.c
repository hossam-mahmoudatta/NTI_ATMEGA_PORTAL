 /******************************************************************************
 *
 * Module: LCD Display
 *
 * File Name: LCD_PROGRAM.c
 *
 * Description: Source file for the AVR LCD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "LCD_INTERFACE.h"

/*******************************************************************************
 *                              						Functions Declarations                     	      				  *
 *******************************************************************************/

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


		LCD_voidSendCommand(LCD_2LINES_FOUR_BIT_INIT1);
		LCD_voidSendCommand(LCD_2LINES_FOUR_BIT_INIT2);
		LCD_voidSendCommand(LCD_2LINES_5x7_DOTS);
		//LCD_voidSendCommand(LCD_2LINES_FOUR_BIT);
		_delay_ms(2);
	}

	LCD_voidSendCommand(LCD_CURSOR_OFF);
	_delay_ms(2);
	LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
	_delay_ms(2);
	//LCD_voidSendCommand(LCD_ENTRY_MODE);

}


// Sends a command to the LCD
void LCD_voidSendCommand(u8 copy_u8Command) {
	// Set RS Pin to '0'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_RS, LOGIC_LOW);
	_delay_ms(1);
	// Set Enable Pin to '1'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(1);

#if (LCD_BIT_MODE == LCD_8_BIT)
		GPIO_voidSetPortValue(LCD_DATA_PORT, copy_u8Command);
		_delay_ms(2);

		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(2);
#else
		// Inserts the command in the assigned PORT to be sent to the LCD
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8Command, 4));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8Command, 5));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8Command, 6));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8Command, 7));

		_delay_ms(1);
		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(1);
		// Set Enable Pin to '1'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
		_delay_ms(1);

		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8Command, 0));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8Command, 1));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8Command, 2));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8Command, 3));

		_delay_ms(1);
		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(1);
#endif
}


// Displays a character on the LCD
void LCD_voidSendData(u8 copy_u8data) {
	// Set RS Pin to '1'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_RS, LOGIC_HIGH);
	_delay_ms(1);
	// Set Enable Pin to '1'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(1);

#if (LCD_BIT_MODE == LCD_8_BIT)
		GPIO_voidSetPortValue(LCD_DATA_PORT, copy_u8data);
		_delay_ms(2);

		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(2);
#else
		// Inserts the command in the assigned PORT to be sent to the LCD
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8data, 4));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8data, 5));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8data, 6));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8data, 7));

		_delay_ms(1);
		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(1);
		// Set Enable Pin to '1'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
		_delay_ms(1);

		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D4, GET_BIT(copy_u8data, 0));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D5, GET_BIT(copy_u8data, 1));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D6, GET_BIT(copy_u8data, 2));
		GPIO_voidSetPinValue(LCD_DATA_PORT, LCD_DATAPIN_D7, GET_BIT(copy_u8data, 3));

		_delay_ms(1);
		// Set Enable Pin to '0'
		GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
		_delay_ms(1);
#endif
}


// Displays a string on the LCD
void LCD_voidDisplayString(cu8 *str) {
	u8 i = 0;
	while(str[i] != '\0') {
		LCD_voidSendData(str[i]);
		i++;
	}
}


// Chooses where the cursor would stand on the LCD to type from it
void LCD_voidSetCursor(u8 copy_u8row, u8 copy_u8_col) {
	// Calculate the required address in the LCD DDRAM checking
	// The location of the cursor originally on which line
	u8 LCD_MEMORY_ADDRESS;
	switch(copy_u8row) {
		case LINE0:
			LCD_MEMORY_ADDRESS = copy_u8_col;
			break;
		case LINE1:
			LCD_MEMORY_ADDRESS = copy_u8_col + 0x40;
			break;
		case LINE2:
			LCD_MEMORY_ADDRESS = copy_u8_col + 0x10;
			break;
		case LINE3:
			LCD_MEMORY_ADDRESS = copy_u8_col + 0x50;
			break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_voidSendCommand(LCD_MEMORY_ADDRESS | LINE0_ADDRESS);
}


// LCD only understands ASCII, so this converts Int to a string
void LCD_voidIntgerToString(u32 copy_u32data) {
	// A string to hold the ASCII values
	cu8 buffer[16];

	// Converts data to its ASCII
	itoa(copy_u32data, buffer, 10);

	// Display string with the results in the buffer
	LCD_voidDisplayString(buffer);
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
