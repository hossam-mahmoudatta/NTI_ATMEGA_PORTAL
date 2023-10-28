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
	TIMER0_voidSetDutyCycle_FASTPWM(90);

	while (1)
	{
		//LED_voidOn(PORT_B, PIN_3);
		TIMER0_START();
	}
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
