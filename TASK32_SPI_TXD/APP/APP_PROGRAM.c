/******************************************************************************
 *
 * Application
 *
 * File Name: APP_Program.c
 *
 * Description: Application file for testing UART with Strings
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/


/*******************************************************************************
 *                              					 Application Libraries                      					  *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					 Application Declarations                      					  *
 *******************************************************************************/
u8 data = '5';
u8 KeyData = 0;
u8 *str = "7oda#";

void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("SPI TRANSMIT");

	// Initializing Keypad
	KEYPAD_voidInit();

	// Initializing SPI Module Master
	SPI_voidInitialization_Master();
	_delay_ms(1000);
}

void executeMain_TXD(void) {
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Sending..");
	SPI_u8SendByte_Polling(20);
	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("Sent: ");
	LCD_voidSetCursor(2, 6);
	LCD_voidSendData(data);
	//SPI_voidSendString_Polling(str);
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Done!");
}


/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
