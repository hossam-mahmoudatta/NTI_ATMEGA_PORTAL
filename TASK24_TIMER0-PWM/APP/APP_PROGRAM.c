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

void SYSTEM_INITIALIZATION(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("Testing PWM");

	// Initializing Timer0 Module
	TIMER0_INITIALIZATION();
//	//TIMER0_voidSetDutyCycle_FASTPWM(30);
//	//u8 OCRVVALUE = TIMER0_voidSetDutyCycle_FASTPWM(30);
//	LCD_voidSetCursor(1, 0);
//	LCD_voidIntgerToString(OCRVVALUE);
}


/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
