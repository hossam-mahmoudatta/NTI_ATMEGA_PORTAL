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

#include "../../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"
#include "LCD_CONFIG.h"
#include <util/delay.h>

/*******************************************************************************
 *                              						Functions Prototypes                  					  *
 *******************************************************************************/

// Initializes and enables the LCD Module to start functionality
void LCD_vidInit(void);


 // Sends a command to the LCD
void LCD_vidSendCommand(u8_t copy_u8Command);


 // Displays a character on the LCD
void LCD_vidDisplayCharacter(u8_t copy_u8data);


// Displays a string on the LCD
void LCD_vidDisplayString(cu8_t *str, u8_t copy_u8row, u8_t copy_u8_col);


// Chooses where the cursor would stand on the LCD to type from it
void LCD_vidMoveCursor(u8_t copy_u8row, u8_t copy_u8_col);


// Displays a string on the LCD at a chosen cursor and row
void LCD_vidDisplayStringRowColumn(u8_t copy_u8row,
		u8_t copy_u8_col,
		cu8_t *copy_cu8Str);


// LCD only understands ASCII, so this converts Int to a string
void LCD_vidIntgerToString(u32_t copy_u32data, u8_t copy_u8row, u8_t copy_u8_col);


// Clears the LCD from any garbage
void LCD_vidClearScreen(void);


#endif /* LCD_INTERFACE_H_ */
