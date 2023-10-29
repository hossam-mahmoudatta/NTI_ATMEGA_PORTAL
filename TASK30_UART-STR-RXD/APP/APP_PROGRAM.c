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
u8 CHARReceived = 0;

void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("UART RECEIVE");

	// Initializing UART Pins
	UART_Initialization();
	GPIO_voidSetPinDirection(PORT_D, PIN_1, PIN_OUTPUT);
	GPIO_voidSetPinDirection(PORT_D, PIN_0, PIN_INPUT);

	// Initializing Keypad
	//KEYPAD_voidInit();


}

void executeMain_RXD(void) {
	UART_voidReceiveByte_Polling();
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Receiving..");
	LCD_voidSetCursor(2, 0);
	LCD_voidSendData(UDR_REG);
	//LCD_voidDisplayString(stringReceived);
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Done!");

}


/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
