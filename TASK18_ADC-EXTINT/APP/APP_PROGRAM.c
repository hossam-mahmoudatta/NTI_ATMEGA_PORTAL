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

void SYSTEM_INITIALIZATION(void) {
	LCD_voidInit();
	ADC_voidInit();
	EXTINT_voidSetSenseINTx(EXT_INT0, EXTINT_Falling_Edge);
	EXTINT_voidEnableINTx(EXT_INT0, NULL);
	GPIO_voidSetPinDirection(PORT_A, PIN_1, PIN_INPUT);
	GPIO_voidSetPinDirection(PORT_D, PIN_2, PIN_INPUT);
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("Resistor Value: ");
	GLOBINT_voidSetEnableFlag();
	ADC_voidStartConversionISR(CHANNEL_1);

}

void readResistorADC_EXT_ISR(void) {
	ADC_Result = ADC_DATA_REG;
	LCD_voidSetCursor(1, 0);
	LCD_voidIntgerToString(ADC_Result);
	_delay_ms(250);
	LCD_voidSetCursor(1, 0);
	//LCD_voidDisplayString("    ");
}

void executeISR(void) {

	ADC_CallBackFunction(&readResistorADC_EXT_ISR);
}
