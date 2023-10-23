/******************************************************************************
 *
 * Application
 *
 * File Name: TASK13_main.c
 *
 * Description: Application file for testing the gpio driverg
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					Application Execution                              			  *
 *******************************************************************************/

int main(void) {
	systemInit();

	while (1)
	{
		keypadDisplayName();
	}
}
