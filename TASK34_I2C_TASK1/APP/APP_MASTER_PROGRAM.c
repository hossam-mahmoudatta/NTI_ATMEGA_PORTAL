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
	LCD_voidDisplayString("I2C TRANSMIT");

	// Initializing SPI Module Master
	I2C_voidMasterInit(I2C_SLAVE1_ADDRESS);
}

void executeMain_TXD(void) {
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Sending..");

	I2C_voidSendStartCondition();
	I2C_voidSendSlaveAddressWrite(I2C_SLAVE1_ADDRESS);
	I2C_voidSendMasterDataByte(data);
	_delay_ms(100);
	I2C_voidSendStopCondition();

	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("TxD: ");
	LCD_voidSetCursor(2, 5);
	LCD_voidSendData(data);

	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Done!");
}



/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
