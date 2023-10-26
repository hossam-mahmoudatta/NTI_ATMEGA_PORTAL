/******************************************************************************
 *
 * Application
 *
 * File Name: TASK17_main.c
 *
 * Description: Application file for testing the ADC with Interrupt
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
		executeISR();
	}
}
