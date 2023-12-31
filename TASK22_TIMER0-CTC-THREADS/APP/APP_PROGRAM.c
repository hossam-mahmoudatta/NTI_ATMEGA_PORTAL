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

void SYSTEM_INITIALIZATION(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("Testing INT");

	//Initializing ADC Module
	ADC_voidInit();
	ADC_voidStartConversionISR(CHANNEL_1);

	// Initializing Enternal Interrupt Module
	EXTINT_voidSetSenseINTx(EXT_INT0, EXTINT_Falling_Edge);
	EXTINT_voidEnableINTx(EXT_INT0, TIMER0_START);
	GPIO_voidSetPinDirection(PORT_D, PIN_2, PIN_INPUT);
	GLOBINT_voidSetEnableFlag();

	// Initializing Timer0 Module
	TIMER0_INITIALIZATION();
	TIMER0_setPreload(49);
	TIMER0_CallBackFunction_OVF(NULL);
}


void Threads(void)
{
	u8 counter = 0;
	counter++;
	if(counter == 1) {
		LED_voidToggle(PORT_D, PIN_0);
	}
	else if(counter == 1) {
		LED_voidToggle(PORT_D, PIN_1);
	}
	else if(counter == 5) {
		LED_voidToggle(PORT_D, PIN_2);
	}
	else if(counter == 10) {
		LED_voidToggle(PORT_D, PIN_3);
	}

}


void ISR_INSIDE(void) {
	static u8 counter = 0;
	counter++;
	if(counter == 4)
	{
		ADC_Result = ADC_DATA_REG;
		LCD_voidSetCursor(1, 0);
		LCD_voidIntgerToString(ADC_Result);
		_delay_ms(250);
		LCD_voidSetCursor(1, 0);
		//LCD_voidDisplayString("    ");
		counter = 0;
	}
}


void ISR_EXECUTE(void) {
	ADC_CallBackFunction(&ISR_INSIDE);
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
