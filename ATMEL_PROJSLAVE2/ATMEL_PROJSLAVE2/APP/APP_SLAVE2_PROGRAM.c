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

	// Initializing SPI Module Slave
	_delay_ms(50);
	SPI_voidInitialization_Slave();

	// Initializing UART Module Slave
	//UART_Initialization();

	// Initializing the Global Interrupt Enable
	GLOBINT_voidSetEnableFlag();

	// Initializing sERVO
	SERVO_voidInit();
	
	// sTARTING tIMER1
	TIMER1_voidStart();

	// Initializing DC Motors
	DCMOTOR_voidInit();
	
	GPIO_voidSetPinDirection(PORT_A, PIN_4, PIN_OUTPUT); // Waiting Lights
	GPIO_voidSetPinDirection(PORT_A, PIN_5, PIN_OUTPUT); // Headlights
	GPIO_voidSetPinDirection(PORT_A, PIN_6, PIN_OUTPUT); // Parking Lights
	
}


void executeMain_SLAVE2(void) {
	if(SPI_Reading == 'u') // RIGHT FRONT DOOR Open
	{
		SERVO_CarDoor_RR_Open();
		//SPI_Reading=0;
	}
	else if(SPI_Reading == 'y') //LEFT FRONT DOOR Close
	{
		SERVO_CarDoor_RR_Close();
		//SPI_Reading=0;
	}
	else if(SPI_Reading == 'j') // RIGHT FRONT DOOR Open
	{
		SERVO_CarDoor_RL_Open();
		//SPI_Reading=0;
	}
	else if(SPI_Reading == 'h') //LEFT FRONT DOOR Close
	{
		SERVO_CarDoor_RL_Close();
		//SPI_Reading=0;
	}
	
	// Motor Operations
	else if(SPI_Reading == 'w') // door1
	{
		DCMOTOR_voidStart(ACCELERATE);
		GPIO_voidSetPinValue(PORT_A, PIN_5, LOGIC_HIGH);
		GPIO_voidSetPinValue(PORT_A, PIN_6, LOGIC_LOW);
		GPIO_voidSetPinValue(PORT_A, PIN_4, LOGIC_LOW);
		//SPI_Reading=0;
	}
	else if(SPI_Reading == 'x')//door2
	{
		DCMOTOR_voidStart(REVERSE);
		//GPIO_voidSetPinValue(PORT_A, PIN_4, LOGIC_HIGH);
		GPIO_voidSetPinValue(PORT_A, PIN_6, LOGIC_LOW);
		GPIO_voidTogglePin(PORT_A, PIN_4);
		_delay_ms(600);
		//SPI_Reading=0;
	}
	else if(SPI_Reading == 's')//door2
	{
		DCMOTOR_voidStop();
		GPIO_voidSetPinValue(PORT_A, PIN_6, LOGIC_HIGH);
		GPIO_voidSetPinValue(PORT_A, PIN_5, LOGIC_LOW);
		//SPI_Reading=0;
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
