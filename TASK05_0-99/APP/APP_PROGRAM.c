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
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("Welcome to the");
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Bouncing Star !");
	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("Hossam");
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Mahmoud !");
	_delay_ms(3000);
	LCD_voidClearScreen();
}

void dancingStar(u8 Flag, u8 Row, u8 Column) {
	LCD_voidSetCursor(Row, Column);
	LCD_voidSendData('X');
	_delay_ms(500);
	LCD_voidSetCursor(Row, Column);
	LCD_voidSendData(' ');

	Column++;
	if(Column > 15) {
		Column = 0;
		Row = 0;
	}


	if(Row < 4) {
		Row++;
		if(Row > 2) {
			Flag = 1;
		}
	}
	else {
		Row--;
		if(Row < 1) {
			Flag = 0;
		}
	}

}

