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

	funcInits();

	//LCD_voidDisplayCharacter('C');

	LCD_voidDisplayString("My name is hossam and this is embedded systems course and this is a test", 0, 0);

//	LCD_voidMoveCursor(0,0);
//	LCD_voidDisplayCharacter('A');
//	LCD_voidMoveCursor(1,0);
//	LCD_voidDisplayCharacter('B');
//	LCD_voidMoveCursor(2,0);
//	LCD_voidDisplayCharacter('C');
//	LCD_voidMoveCursor(3,0);
//	LCD_voidDisplayCharacter('D');


	while (1)
	{
		//TrafficLights();
	}
}
