 /******************************************************************************
 *
 * Module: LCD Display
 *
 * File Name: LCD_INTERFACE.h
 *
 * Description: Header file for the AVR LCD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#include "LCD_CONFIG.h"


/*******************************************************************************
 *                              						Functions Prototypes                  					  *
 *******************************************************************************/

// Initializes and enables the LCD Module to start functionality
void LCD_voidInit(void);


 // Sends a command to the LCD
void LCD_voidSendCommand(u8 copy_u8Command);


 // Displays a character on the LCD
void LCD_voidDisplayCharacter(u8 copy_u8data);


// Displays a string on the LCD
void LCD_voidDisplayString(cu8 *str, u8 copy_u8row, u8 copy_u8_col);


// Chooses where the cursor would stand on the LCD to type from it
void LCD_voidMoveCursor(u8 copy_u8row, u8 copy_u8_col);


// LCD only understands ASCII, so this converts Int to a string
void LCD_voidIntgerToString(u32 copy_u32data, u8 copy_u8row, u8 copy_u8_col);


// Clears the LCD from any garbage
void LCD_voidClearScreen(void);


#endif /* LCD_INTERFACE_H_ */








//
//// Displays a string on the LCD at a chosen cursor and row
//void LCD_voidDisplayStringRowColumn(u8 copy_u8row,
//		u8 copy_u8_col,
//		cu8 *copy_cu8Str);
