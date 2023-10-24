/******************************************************************************
 *
 * Application
 *
 * File Name: TASK3_main.c
 *
 * Description: Application file for testing the gpio driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/


/*******************************************************************************
 *                              					 Application Libraries                      					  *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					 Application Libraries                      					  *
 *******************************************************************************/

void System_Initialization(void) {
	LCD_voidInit();
	LCD_voidDisplayString("Welcome to the Bouncing Star !", 0, 0);
	_delay_ms(3000);
	LCD_voidClearScreen();
}

void dancingStar(void) {
	u8 Line = 0;
	u8 Column = 0;
	u8 Flag = 0;

	LCD_voidSetCursor(Line, Column);
	LCD_voidSendData('X');
	_delay_ms(400);
	LCD_voidSetCursor(Line, Column);
	LCD_voidSendData(' ');

	if(Flag == 0) {
		Line++;
		if(Line > 2) {
			Flag = 1;
		}
	}
	else {
		Line--;
		if(Line < 1) {
			Flag = 0;
		}
	}

	if(Column > 19) {
		Column = 0;
		Line = 0;
	}
}

