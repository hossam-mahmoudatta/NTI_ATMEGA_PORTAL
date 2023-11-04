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

#include "APP_SLAVE2_INTERFACE.h"

/*******************************************************************************
 *                              					 Application Declarations                      					  *
 *******************************************************************************/

u8 receivedChar = 0;

//Local Variables
u8 SPI_Reading = 0;
u8 DRL_Previous_Angle = Door_Close;
u8 DRR_Previous_Angle = Door_Close;

void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("SLAVE2 RECEIVE");

	// Initializing Keypad
	//KEYPAD_voidInit();

	// Initializing SPI Module Slave
	_delay_ms(50);
	SPI_voidInitialization_Slave();

	// Initializing UART Module Slave
	//UART_Initialization();

	// Initializing the Global Interrupt Enable
	GLOBINT_voidSetEnableFlag();

	// Initializing Timer1
	TIMER1_Initialization();

	// Initializing DC Motors
	DCMOTOR_voidInit();
}


void executeMain_SLAVE2(void) {
	if(SPI_Reading == 'w') // door1
	{
		DCMOTOR_voidStart(ACCELERATE);
		SPI_Reading=0;
	}
	else if(SPI_Reading == 'x')//door2
	{
		DCMOTOR_voidStart(REVERSE);
		SPI_Reading=0;
	}
	else if(SPI_Reading == 's')//door2
	{
		DCMOTOR_voidStop(ALL_MOTORS);
		SPI_Reading=0;
	}
	else if(SPI_Reading == 'f') // Left Rear DOOR
	{
		DRL_Previous_Angle = SERVO_CarDoor(RL_Door, DRL_Previous_Angle, SERVO_DATA_PORT, SERVO_DATA_PIN1);
		SPI_Reading=0;
	}
	else if(SPI_Reading == 'g') // Right Rear DOOR
	{
		DRR_Previous_Angle = SERVO_CarDoor(RR_Door, DRR_Previous_Angle, SERVO_DATA_PORT, SERVO_DATA_PIN2);
		SPI_Reading=0;
	}
}


void SPI_SLAVE2_Receive(void) {
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
	SPI_CallBackFunction(SPI_SLAVE2_Receive);
}
/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
