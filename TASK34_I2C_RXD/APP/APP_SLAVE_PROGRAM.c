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

#include "APP_SLAVE_INTERFACE.h"

/*******************************************************************************
 *                              					 Application Declarations                      					  *
 *******************************************************************************/
u8 ReceivedData;
//u8 KeyData = 0;

void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("I2C RECEIVE");

	// Initializing I2C SLAVE Module
	_delay_ms(250);
	I2C_voidSlaveInit(I2C_SLAVE1_ADDRESS);

}

void executeMain_RXD(void) {
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Receiving..");
	_delay_ms(100);
//	ReceivedData = I2C_voidReceiveSlaveDataByte();
	ReceivedData = I2C_u8ReadByteWithACK();

	LCD_voidSetCursor(2, 0);
	LCD_voidDisplayString("RxD: ");
	LCD_voidSetCursor(2, 5);
	LCD_voidSendData(ReceivedData);
	LCD_voidSetCursor(3, 0);
	LCD_voidDisplayString("Done!");
}



/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
