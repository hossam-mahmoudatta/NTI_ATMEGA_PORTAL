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

//Local Variables
u8 SPI_Reading = 0;
u8 DFR_Previous_Angle = Door_Close;
u8 DFL_Previous_Angle = Door_Close;

void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("SLAVE1 RECEIVE");

	// Initializing SPI Module Slave
	_delay_ms(50);
	SPI_voidInitialization_Slave();

	// Initializing UART Module Slave
	//UART_Initialization();

	// Initializing the Global Interrupt Enable
	GLOBINT_voidSetEnableFlag();

	// Initializing Timer1
	TIMER1_Initialization();

	// Initializing ADC
	ADC_voidInit();

}

void executeMain_SLAVE1(void) {
	if(SPI_Reading == 't') // RIGHT FRONT DOOR
	{
		DFR_Previous_Angle = SERVO_CarDoor(FR_Door, DFR_Previous_Angle, SERVO_DATA_PORT, SERVO_DATA_PIN1);
		SPI_Reading=0;
	}
	else if(SPI_Reading == 'r') //LEFT FRONT DOOR
	{
		DFL_Previous_Angle = SERVO_CarDoor(FL_Door, DFL_Previous_Angle, SERVO_DATA_PORT, SERVO_DATA_PIN2);
		SPI_Reading=0;
	}
}

void SPI_SLAVE1_Receive(void) {
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Receiving..");
	SPI_Reading = SPI_u8ReceiveByte_ISR();
	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("RxD: ");
	LCD_voidSetCursor(2, 5);
	LCD_voidSendData(SPI_Reading);
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Done!");
}

void executeISR(void)
{
	SPI_CallBackFunction(SPI_SLAVE1_Receive);
}
/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
