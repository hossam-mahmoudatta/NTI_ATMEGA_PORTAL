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
u8 data=0;
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
}

void executeMain_TXD(void) {
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Sending..");
	//SPI_u8SendByte_Polling(20);
	//SPI_voidSendString_Polling(str);
	_delay_ms(1000);
	while(1)
	{
		SPI_u8SendReceiveByte_Polling('1');
		_delay_ms(250);
	}
	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("Done!");


//	KeyData = KEYPAD_u8getPressedKey();
//	while(KeyData == 0xff)
//	{
//		KeyData = KEYPAD_u8getPressedKey();
//	}
//	if(KeyData == '7') {
//		LCD_voidSetCursor(1, 0);
//		LCD_voidDisplayString("7Sending..");
//		//UART_voidSendByte_Polling('h');
//		UART_voidSendString((u8*)"Hossam#");
//		LCD_voidClearScreen();
//		LCD_voidSetCursor(1, 0);
//		LCD_voidDisplayString("Done!");
//	}
//	else if(KeyData == '8') {
//		LCD_voidSetCursor(1, 0);
//		LCD_voidDisplayString("8Sending..");
//		//UART_voidSendByte_Polling('O');
//		UART_voidSendString((u8*)"Mahmoud#");
//		LCD_voidClearScreen();
//		LCD_voidSetCursor(1, 0);
//		LCD_voidDisplayString("Done!");
//	}
//	else if(KeyData == '9') {
//		LCD_voidSetCursor(1, 0);
//		LCD_voidDisplayString("9Sending..");
//		//UART_voidSendByte_Polling('X');
//		UART_voidSendString((u8*)"Atta#");
//		LCD_voidClearScreen();
//		LCD_voidSetCursor(1, 0);
//		LCD_voidDisplayString("Done!");
//	}
}


/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
