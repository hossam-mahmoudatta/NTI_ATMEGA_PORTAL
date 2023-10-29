/******************************************************************************
 *
 * Application
 *
 * File Name: TASK22_main.c
 *
 * Description: Application file for running 4 tasks simultaneously
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					Application Execution                              			  *
 *******************************************************************************/

int main(void)
{
	System_Initialization();
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("7 Sending..");
	//UART_voidSendByte_Polling('h');
	UART_voidSendString((u8*)"Hossam#");
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("              ");
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Done!");

	while (1)
	{

		//executeMain_TXD();
	}
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
