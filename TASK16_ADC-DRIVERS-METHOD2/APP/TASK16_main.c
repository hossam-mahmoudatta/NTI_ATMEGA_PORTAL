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
	systemInit();
	//u16 Result = 0;
	while (1)
	{
		readResistorADC();

//		Result = ADC_voidStartConversionPolling(CHANNEL_1);
//		LCD_voidIntgerToString(Result, 1, 0);
//		_delay_ms(500);
	}
}
