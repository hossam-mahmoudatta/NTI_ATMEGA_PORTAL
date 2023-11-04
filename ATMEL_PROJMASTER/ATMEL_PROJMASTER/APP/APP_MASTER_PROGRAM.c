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
u8 ADC_Read = 0;

volatile u8 UART_Flag = 0;


void System_Initialization(void) {
	// Initializing the Global Interrupt Enable
	GLOBINT_voidSetEnableFlag();

	// Initializing UART Module
	UART_Initialization();

	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("MASTER SPI");

	// Initializing SPI Module Master
	SPI_voidInitialization_Master();
	_delay_ms(100);

	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("  UART     SPI  ");

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
	if(UART_Flag == 1)
	{
		UART_Read = UART_voidReceiveByte_ISR();
		//UART_Read = 't';
		if((UART_Read == 'w') || (UART_Read == 's') ||
		(UART_Read == 'x') || (UART_Read == 'g') || (UART_Read == 'f') )
		{
			SPI_Slave_2_Select();

			SPI_Read = SPI_u8SendByte_Polling(UART_Read);
			LCD_voidSetCursor(2, 4);
			LCD_voidSendData(UART_Read);

			LCD_voidSetCursor(2, 12);
			LCD_voidSendData(SPI_Read);

			LCD_voidSetCursor(3, 0);
			LCD_voidDisplayString("SPI 2");

			//UART_Flag = 0;
			_delay_ms(100);
		}
		else if((UART_Read == 't') || (UART_Read == 'r'))
		{
			SPI_Slave_1_Select();
			SPI_Read = SPI_u8SendByte_Polling(UART_Read);

			LCD_voidSetCursor(2, 4);
			LCD_voidSendData(UART_Read);

			LCD_voidSetCursor(2, 12);
			LCD_voidSendData(SPI_Read);

			LCD_voidSetCursor(3, 0);
			LCD_voidDisplayString("SPI 1");

			//UART_Flag = 0;
			_delay_ms(100);
		}
		SPI_Read = 0;
	}

	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Temp: ");
	LCD_voidSetCursor(3, 6);
	ADC_Read = ADC_u16ReadTemperature(CHANNEL_0);
	LCD_voidIntgerToString(ADC_Read);
}

void executeISR(void)
{
	//UART_CallBackFunction_RXC(UARTReceiveFunction);
	//SPI_CallBackFunction(executeMain_MASTER);
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
