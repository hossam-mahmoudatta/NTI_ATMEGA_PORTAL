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
u8 Temperature = 0;

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

	// Initializing Timer1
	TIMER1_Initialization();

	// Initializing ADC
	ADC_voidInit();



}

void executeMain_SLAVE1(void) {
	Temperature = ADC_u16ReadTemperature();
			spi_reading=SPI_SendReceive(temp); // temp sensor
			if(spi_reading!=0)
			{
				DIO_TogglePin(PINA1);
				//delay(10);
				//spi_reading=0;
			}
			if(spi_reading=='z') // door1
			{
			    D1_Previous_Angle= Car_Door_Command(Door_1, D1_Previous_Angle,PINC0);
				spi_reading=0;
			}
			else if(spi_reading=='x')//door2
			{
				D2_Previous_Angle= Car_Door_Command(Door_2, D2_Previous_Angle,PINC1);
				spi_reading=0;
			}
			else if(spi_reading=='c')// temp sensor
			{
				spi_reading=0;
				spi_reading=SPI_SendReceive(temp);
				spi_reading=0;
			}
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
