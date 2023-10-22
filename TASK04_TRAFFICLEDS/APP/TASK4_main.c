/******************************************************************************
 *
 * Application
 *
 * File Name: TASK4_main.c
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

	funcInits();

	while (1)
	{
		TrafficLights();
	}
}

