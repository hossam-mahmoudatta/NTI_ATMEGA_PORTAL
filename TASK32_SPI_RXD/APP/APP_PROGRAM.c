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

u8 receivedChar = 0;

void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("SPI RECEIVE");

	// Initializing Keypad
	//KEYPAD_voidInit();

	// Initializing SPI Module Slave
	SPI_voidInitialization_Slave();
	UART_Initialization();
	GPIO_voidSetPinDirection(PORT_D, PIN_0, PIN_INPUT);
	GPIO_voidSetPinDirection(PORT_D, PIN_1, PIN_OUTPUT);
	_delay_ms(1000);
}

void executeMain_RXD(void) {
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Receiving..");
	receivedChar = SPI_u8ReceiveByte_Polling();
	//SPI_voidReceiveString(str);
	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("Recv: ");
	LCD_voidSetCursor(2, 6);
	LCD_voidSendData(receivedChar);
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Done!");

	UART_voidSendByte_Polling(receivedChar + '0');

}


/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
