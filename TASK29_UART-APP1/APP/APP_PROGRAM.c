/******************************************************************************
 *
 * Application
 *
 * File Name: APP_Program.c
 *
 * Description: Application file for testing ADC with Interrupts
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

u8 KeyData = 0;

void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("UART TRANSMIT");

	// Initializing UART Pins
	UART_Initialization();
	GPIO_voidSetPinDirection(PORT_D, PIN_1, PIN_OUTPUT);
	GPIO_voidSetPinDirection(PORT_D, PIN_0, PIN_INPUT);

	// Initializing Keypad
	KEYPAD_voidInit();


}

void executeMain_TXD(void) {
	KeyData = KEYPAD_u8getPressedKey();
	while(KeyData == 0xff)
	{
		KeyData = KEYPAD_u8getPressedKey();
	}
	if(KeyData == '7') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("Sending..");
		UART_voidSendByte_Polling('h');
		//UART_voidSendString((u8*)"Hossam");
		LCD_voidClearScreen();
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("Done!");
	}
	else if(KeyData == '8') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("Sending..");
		UART_voidSendByte_Polling('O');
		//UART_voidSendString((u8*)"Mahmoud");
		LCD_voidClearScreen();
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("Done!");
	}
	else if(KeyData == '9') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("Sending..");
		UART_voidSendByte_Polling('X');
		//UART_voidSendString((u8*)"Atta");
		LCD_voidClearScreen();
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("Done!");
	}
}


/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
