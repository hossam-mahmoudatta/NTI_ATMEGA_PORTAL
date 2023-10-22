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
	LCD_voidDisplayString("My name is hossam and this is embedded systems course and this is a test", 0, 0);
	functionInits();

	while (1)
	{
		displayKEYPADLCD();
	}
}
