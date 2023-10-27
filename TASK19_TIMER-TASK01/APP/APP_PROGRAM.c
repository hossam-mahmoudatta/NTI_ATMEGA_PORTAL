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
	//GPIO_voidSetPinDirection(PORT_A, PIN_1, PIN_INPUT);

void SYSTEM_INITIALIZATION(void) {
	LCD_voidInit();
	LED_voidInit(PORT_B, PIN_7);
	GPIO_voidSetPinDirection(PORT_B, PIN_7, PIN_OUTPUT);
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("Testing INT");
	GLOBINT_voidSetEnableFlag();
	TIMER0_INITIALIZATION();
	TIMER0_START();
	TIMER0_setPreload(49);
}

void function_ISR(void) {
	static u8 counter = 0;
	counter++;
	//LCD_voidSetCursor(1, 0);
	//LCD_voidIntgerToString(counter);
	if(counter == 4)
	{
		LED_voidToggle(PORT_B, PIN_7);
		//LCD_voidSetCursor(1, 0);
		//LCD_voidDisplayString("Toggled");
		TIMER0_setPreload(49);
		counter = 0;
	}
}

void executeISR(void) {
	TIMER0_CallBackFunction_OVF(&function_ISR);
}
