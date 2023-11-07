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
volatile u8 SPI_Read = 0;
volatile u8 UART_Read = 0;
volatile u8 ADC_Read = 0;

volatile u8 UART_Flag = 0;


void System_Initialization(void) {
	// Initializing the Global Interrupt Enable
	//GLOBINT_voidSetEnableFlag();

	// Initializing UART Module
	UART_Initialization();
	
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("MASTER SPI");

	// Initializing SPI Module Master
	SPI_voidInitialization_Master();
	_delay_ms(100);

	// LCD Stamp
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("FR FL RL RR  CAR");
	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("DC DC DC DC  PRK");

	// SS Select Pins Initialization
	GPIO_voidSetPinDirection(PORT_C, PIN_0, PIN_INPUT);
	GPIO_voidSetPinDirection(PORT_C, PIN_1, PIN_INPUT);
	GPIO_voidSetPinValue(PORT_C, PIN_0, LOGIC_LOW);
	GPIO_voidSetPinValue(PORT_C, PIN_1, LOGIC_HIGH);

	// ADC Init
	ADC_voidInit();


}


void SPI_Slave_1_Select(void)
{
	GPIO_voidSetPinValue(PORT_C, PIN_0, LOGIC_LOW);
	GPIO_voidSetPinValue(PORT_C, PIN_1, LOGIC_HIGH);
}

void SPI_Slave_2_Select(void)
{
	GPIO_voidSetPinValue(PORT_C, PIN_1, LOGIC_LOW);
	GPIO_voidSetPinValue(PORT_C, PIN_0, LOGIC_HIGH);
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
 * 		x - reverse
 * 		d - right
 * 		a - left
 *
 * 	2 - Servo Motors
 * 		t - right front door
 * 		r - left front door
 * 		f - left rear door
 * 		g - right rear door
 *
 * 	3 - LM35 Temperature Sensor
 * 		reads the temp
 *
 * 4 - LDR Light Sensor (Next Release)
 * 		Turns the lights Automatically when dark
 */

void executeMain_MASTER(void) {
	UART_Read = UART_voidReceiveByte_ISR();
	//UART_Read = 't';
	switch(UART_Read)
	{
		// For Slave 1 Operations: Front Doors
		case 't':
			SPI_Slave_1_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 0);
			LCD_voidDisplayString("DO");

			UART_Flag = 0;
			_delay_ms(100);
		break;
		case 'r':
			SPI_Slave_1_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 0);
			LCD_voidDisplayString("DC");

			UART_Flag = 0;
			_delay_ms(100);
		break;
		case 'g':
			SPI_Slave_1_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 3);
			LCD_voidDisplayString("DO");

			UART_Flag = 0;
			_delay_ms(100);
		break;
		case 'f':
			SPI_Slave_1_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 3);
			LCD_voidDisplayString("DC");

			UART_Flag = 0;
			_delay_ms(100);
		break;


		// For Slave 2 Operations: Rear Doors
		case 'u':
			SPI_Slave_2_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 0);
			LCD_voidDisplayString("DO");

			UART_Flag = 0;
			_delay_ms(100);
		break;
		case 'y':
			SPI_Slave_2_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 0);
			LCD_voidDisplayString("DC");

			UART_Flag = 0;
			_delay_ms(100);
		break;
		case 'j':
			SPI_Slave_2_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 3);
			LCD_voidDisplayString("DO");

			UART_Flag = 0;
			_delay_ms(100);
		break;
		case 'h':
			SPI_Slave_2_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 3);
			LCD_voidDisplayString("DC");

			UART_Flag = 0;
			_delay_ms(100);
		break;


		// For Car Movement Operations
		case 'w':
			SPI_Slave_2_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 13);
			LCD_voidDisplayString("FWD");

			UART_Flag = 0;
			_delay_ms(100);
		break;
		case 's':
			SPI_Slave_2_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 13);
			LCD_voidDisplayString("PRK");

			UART_Flag = 0;
			_delay_ms(100);
		break;
		case 'x':
			SPI_Slave_2_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 13);
			LCD_voidDisplayString("REV");

			UART_Flag = 0;
			_delay_ms(100);
		break;

	}
	SPI_Read = 0;
	//UART_Read = 0;
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Temperature: ");
	LCD_voidSetCursor(3, 13);
	ADC_Read = ADC_u16ReadTemperature(CHANNEL_0);
	LCD_voidIntgerToString(ADC_Read);
}
	




void executeISR(void)
{
	UART_CallBackFunction_RXC(UARTReceiveFunction);
	//SPI_CallBackFunction(executeMain_MASTER);
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
