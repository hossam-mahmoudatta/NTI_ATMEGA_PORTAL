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


/*******************************************************************************
 *                              					 Application Libraries                      					  *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					 Application Libraries                      					  *
 *******************************************************************************/

extern u16 ADC_Result = 0;

void systemInit(void) {
	LCD_voidInit();
	ADC_voidInit();
	GPIO_voidSetPinDirection(PORT_A, PIN_1, PIN_INPUT);

	LCD_voidDisplayString("Resistor Value: ", 0, 0);
	LCD_voidMoveCursor(1, 0);
}

void readResistorADC(void) {
	ADC_Result = ADC_voidStartConversionPolling(CHANNEL_1);
	LCD_voidIntgerToString(ADC_Result, 1, 0);
	_delay_ms(500);

}

