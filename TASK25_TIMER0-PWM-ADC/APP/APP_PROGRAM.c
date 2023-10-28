/******************************************************************************
 *
 * Application
 *
 * File Name: APP_Program.c
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
extern u8 Mapping = 0;

void SYSTEM_INITIALIZATION(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("Testing PWM");


	// Initializing ADC Module
	ADC_voidInit();
	ADC_voidStartConversionISR(CHANNEL_1);

	GLOBINT_voidSetEnableFlag();

	// Initializing Timer0 Module
	TIMER0_INITIALIZATION();
	TIMER0_START();

}

void functionISR(void) {
		ADC_Result = ADC_DATA_REG;
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("ADC: ");
		LCD_voidSetCursor(1, 5);
		LCD_voidIntgerToString(ADC_Result);

		Mapping = DutyCycle_ADC_Mapping(ADC_Result);
		TIMER0_voidSetDutyCycle_FASTPWM(Mapping);
		LCD_voidSetCursor(2, 0);
		LCD_voidDisplayString("Duty %: ");
		LCD_voidSetCursor(2, 8);
		LCD_voidIntgerToString(Mapping);
		_delay_ms(250);
		LCD_voidSetCursor(1, 7);
		LCD_voidSetCursor(2, 11);
		LCD_voidDisplayString(" ");
}

void executeISR(void) {
	// Starts ADC Conversion
	ADCSRA_REG->ADSC = START_CONVERSION;
	ADC_CallBackFunction(&functionISR);
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
