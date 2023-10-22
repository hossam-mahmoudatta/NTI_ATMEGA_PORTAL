/******************************************************************************
 *
 * Application
 *
 * File Name: TASK3_main.c
 *
 * Description: Application file for testing the gpio driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					Application Execution                              			  *
 *******************************************************************************/

int main(void) {
	LED_voidInit(PORT_B, LED_PORTB_KIT_RED);
	LED_voidInit(PORT_A, LED_PORTA_KIT_YELLOW);
	LED_voidInit(PORT_A, LED_PORTA_KIT_BLUE);
	LED_voidInit(PORT_A, LED_PORTA_KIT_GREEN);

	SEGMENT_voidInit(PORT_B);

	u8 i = 0;

	while (1)
	{
		for(i = 0 ; i < 10 ; i++)
		{
			SEGMENT_voidDisplay(PORT_B, i);
			binaryLEDS(i);

			_delay_ms(1000);

		}
	}
}

