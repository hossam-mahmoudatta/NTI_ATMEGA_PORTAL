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
u8 Mapping = 0;

void SYSTEM_INITIALIZATION(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("Testing PWM");

	// Initializing Interrupts
	EXTINT_voidSetSenseINTx(EXT_INT0, EXTINT_Falling_Edge);
	GLOBINT_voidSetEnableFlag();
	EXTINT_voidEnableINTx(EXT_INT0, functionISR);

	// Initializing Timer0 Module
	TIMER0_INITIALIZATION();
	TIMER0_START();

}

void functionISR(void) {
	Mapping += 5;
	if(Mapping != 100)
	{
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("Duty %: ");
		LCD_voidSetCursor(1, 8);
		LCD_voidIntgerToString(Mapping);

		TIMER0_voidSetDutyCycle_FASTPWM(Mapping);
	}
	else if(Mapping == 100)
	{
		Mapping = 0;
		LCD_voidSetCursor(1, 8);
		LCD_voidDisplayString("    ");
	}
}

/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
