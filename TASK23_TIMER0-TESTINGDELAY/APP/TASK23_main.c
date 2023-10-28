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
 ************************
 *******************************************************************************/

int main(void)
{
	SYSTEM_INITIALIZATION();
	ADC_CallBackFunction(&ISR_INSIDE);

	while (1)
	{

	}
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
