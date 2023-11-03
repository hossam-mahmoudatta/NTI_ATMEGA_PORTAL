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
u8 SPI_Read = 0;
u8 UART_Read = 0;

volatile u8 UART_Flag = 0;


void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("MASTER SPI");

	// Initializing SPI Module Master
	SPI_voidInitialization_Master();

	// Initializing the Global Interrupt Enable
	GLOBINT_voidSetEnableFlag();

	// Initializing UART Module
	UART_Initialization();
	UART_CallBackFunction_RXC(UARTReceiveFunction);

	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("  UART     SPI  ");




	// ISR Functions
	executeISR();
}


void UARTReceiveFunction(void)
{
	UART_Flag = 1;
}

/*
 * Car Electrical System
 * Parts Breakdown:
 * 1 - DC Motors
 * 		w - accelerate
 * 		s - brake
 * 		d - right
 * 		a - left
 *
 * 	2 - Servo Motors
 * 		t - right front door
 * 		r - left front door
 * 		g - right rear door
 * 		f - left rear door
 *
 * 	3 - LM35 Temperature Sensor
 * 		reads the temp
 *
 * 4 - LDR Light Sensor (Next Release)
 * 		Turns the lights Automatically when dark
 */

void executeMain_MASTER(void) {
	if(UART_Flag == 1)
	{
		UART_Read = UART_voidReceiveByte_ISR();

		if((UART_Read == 'w') || (UART_Read == 's') ||
				(UART_Read == 'a') || (UART_Read == 'd'))
				{
					SPI_Read = SPI_u8SendByte_Polling(UART_Read);

					LCD_voidSetCursor(2, 4);
					LCD_voidSendData(UART_Read);

					LCD_voidSetCursor(2, 12);
					LCD_voidSendData(SPI_Read);

					UART_Flag = 0;
					_delay_ms(100);
				}
		else if((UART_Read == 't') || (UART_Read == 'r') ||
				(UART_Read == 'g') || (UART_Read == 'f'))
				{
					SPI_Read = SPI_u8SendByte_Polling(UART_Read);

					LCD_voidSetCursor(2, 4);
					LCD_voidSendData(UART_Read);

					LCD_voidSetCursor(2, 12);
					LCD_voidSendData(SPI_Read);

					UART_Flag = 0;
					_delay_ms(100);
				}
		SPI_Read = 0;

	}

	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Sending..");
	//SPI_u8SendByte_Polling(data);
	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("TxD: ");
	LCD_voidSetCursor(2, 5);
	LCD_voidSendData(data);
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Done!");
}

void executeISR(void)
{
	UART_CallBackFunction_RXC(UARTReceiveFunction);

	SPI_CallBackFunction(executeMain_MASTER);
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
