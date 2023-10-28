/******************************************************************************
 *
 * Application
 *
 * File Name: TASK22_main.c
 *
 * Description: Application file for running 4 tasks simultaneously
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					Application Execution                              			  *
 *******************************************************************************/

int main(void)
{
	SYSTEM_INITIALIZATION();

	while (1)
	{
		Piano();
		GPIO_voidSetPinValue(PORT_C, PIN_6, GPIO_u8GetPinValue(PORT_B, PIN_3));
	}
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
