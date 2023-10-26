/******************************************************************************
 *
 * Application
 *
 * File Name: TASK17_main.c
 *
 * Description: Application file for testing ADC with Interrupts
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/


/*******************************************************************************
 *                              					 Application Libraries                      					  *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					 Application Declarations                      					  *
 *******************************************************************************/

u16 ADC_Result = 0;

void systemInit(void) {
	LCD_voidInit();
	ADC_voidInit();
	GPIO_voidSetPinDirection(PORT_A, PIN_1, PIN_INPUT);
	LCD_voidDisplayString("Resistor Value: ");
	GLOBINT_voidSetEnableFlag();

}

void readResistorADC_ISR(void) {
	ADC_Result = ADC_DATA_REG;
	LCD_voidIntgerToString(ADC_Result);
	_delay_ms(250);
	LCD_voidDisplayString("    ");
}

void executeISR(void) {
	ADC_voidStartConversionISR(CHANNEL_1);
	ADC_CallBackFunction(&readResistorADC_ISR);
}
