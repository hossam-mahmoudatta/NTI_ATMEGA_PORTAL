/******************************************************************************
 *
 * Application
 *
 * File Name: TASK4_main.c
 *
 * Description: Application file for testing the gpio driverg
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					Application Execution                              			  *
 *******************************************************************************/

int main(void) {
	System_Initialization();
	u8 Row = 0;
	u8 Column = 0;
	u8 Flag = 0;

	while (1)
	{

	}
}

//		dancingStar(Flag, Row, Column);
//		LCD_voidSetCursor(Line, Column);
//		LCD_voidSendData('X');
//		_delay_ms(400);
//		LCD_voidSetCursor(Line, Column);
//		LCD_voidSendData(' ');
//
//		if(Flag == 0) {
//			Line++;
//			if(Line > 2) {
//				Flag = 1;
//			}
//		}
//		else {
//			Line--;
//			if(Line < 1) {
//				Flag = 0;
//			}
//		}
//
//		if(Column > 19) {
//			Column = 0;
//			Line = 0;
//		}
//	}
