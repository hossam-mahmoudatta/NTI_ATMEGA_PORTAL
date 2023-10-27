/******************************************************************************
 *
 * Application
 *
 * File Name: TASK19_main.c
 *
 * Description: Application file for testing the ADC with Interrupt
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					Application Execution                              			  *
 ************************
 *******************************************************************************/

int main(void) {
	SYSTEM_INITIALIZATION();
	TIMER0_CallBackFunction_OVF(&function_ISR);

	while (1)
	{

	}
}
