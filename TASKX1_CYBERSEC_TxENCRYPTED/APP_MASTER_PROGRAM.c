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

u8 g_SecurityAccessCode[8];

int generateRandomNumber() {
    return rand() % 90000000 + 10000000; // Ensure the result is an 8-digit number
}

void System_Initialization(void) {
	PORT_voidInit();
	USART_voidInit();
	USART_u8SendStringSynchronous("System Started \r\n");

}

void executeMain_MASTER(void)
{
	// Start by receiving the Security Access from the Terminal
	for(int i = 0 ; i < 4 ; i++)
	{
		g_SecurityAccessCode[i] = USART_voidReceiveDataSynchronous();
	}
	USART_u8SendStringSynchronous("\r\n");
	g_SecurityAccessCode[0] += 4;
	g_SecurityAccessCode[1] += 0;

    // Seed the random number generator with a fixed value (e.g., 1)
    srand(1);

    int randomNumber = generateRandomNumber();

    //printf("Random 8-digit number: %08d\n", randomNumber);





    // Print on the Terminal
	for(int i = 0 ; i < 4 ; i++)
	{
		USART_voidSendDataSynchronous(g_SecurityAccessCode[i]);
	}
	USART_u8SendStringSynchronous("\r\n");
	USART_
}



/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
