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

#include "APP_SLAVE1_INTERFACE.h"

/*******************************************************************************
 *                              					 Application Declarations                      					  *
 *******************************************************************************/

u8 receivedChar = 0;

void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("SLAVE1 RECEIVE");

	// Initializing SPI Module Slave
	_delay_ms(50);
	SPI_voidInitialization_Slave();

	// Initializing UART Module Slave
	UART_Initialization();

	// Initializing the Global Interrupt Enable
	GLOBINT_voidSetEnableFlag();

	TIMER1

}

void executeMain_SLAVE1(void) {
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Receiving..");
	receivedChar = SPI_u8ReceiveByte_ISR();
	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("RxD: ");
	LCD_voidSetCursor(2, 5);
	LCD_voidSendData(receivedChar);
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Done!");
//	UART_voidSendByte_Polling(receivedChar);
}

void SPI_SLAVE1_Receive(void) {
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Receiving..");
	receivedChar = SPI_u8ReceiveByte_ISR();
	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("RxD: ");
	LCD_voidSetCursor(2, 5);
	LCD_voidSendData(receivedChar);
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Done!");
//	UART_voidSendByte_Polling(receivedChar);
}

void executeISR(void)
{
	SPI_CallBackFunction(SPI_SLAVE1_Receive);
}
/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
