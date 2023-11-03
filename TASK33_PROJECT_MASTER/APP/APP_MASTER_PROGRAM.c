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

#include "APP_MASTER_INTERFACE.h"

/*******************************************************************************
 *                              					 Application Declarations                      					  *
 *******************************************************************************/
u8 data = 'E';
//u8 KeyData = 0;

void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("MASTER SPI");

	// Initializing Keypad
	KEYPAD_voidInit();

	// Initializing SPI Module Master
	SPI_voidInitialization_Master();

	// Initializing the Global Interrupt Enable
	GLOBINT_voidSetEnableFlag();
}

void executeMain_TXD(void) {
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Sending..");
	SPI_u8SendByte_Polling(data);
	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("TxD: ");
	LCD_voidSetCursor(2, 5);
	LCD_voidSendData(data);
//	LCD_voidSetCursor(2, 8);
//	LCD_voidSendData(KeyData);
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Done!");
}

void executeISR(void)
{
	SPI_CallBackFunction(executeMain_TXD);
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
