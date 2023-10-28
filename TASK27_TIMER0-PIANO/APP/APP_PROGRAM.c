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
	LCD_voidDisplayString("Piano");

	// Initializing Keypad Module
	KEYPAD_voidInit();

	// Initializing Timer0 Module
	TIMER0_INITIALIZATION();

}


void Piano(void) {
	u8 keydata = KEYPAD_u8getPressedKey();

	while(keydata==0xff)
	{
		keydata = KEYPAD_u8getPressedKey();
	}
	if(keydata == '7') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("1");
		TCCR0_REG->CS0x = TIMER0_PRESCALER_8;
		TIMER0_voidSetDutyCycle_FASTPWM(6);

	}
	else if(keydata == '8') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("2");
		TCCR0_REG->CS0x = TIMER0_PRESCALER_8;
		TIMER0_voidSetDutyCycle_FASTPWM(12);
	}
	else if(keydata == '9') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("3");
		TCCR0_REG->CS0x = TIMER0_PRESCALER_8;
		TIMER0_voidSetDutyCycle_FASTPWM(18);
	}
	else if(keydata == '/') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("4");
		TCCR0_REG->CS0x = TIMER0_PRESCALER_64;
		TIMER0_voidSetDutyCycle_FASTPWM(24);
	}
	else if(keydata == '4') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("5");
		TCCR0_REG->CS0x = TIMER0_PRESCALER_64;
		TIMER0_voidSetDutyCycle_FASTPWM(30);
	}
	else if(keydata == '5') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("6");
		TCCR0_REG->CS0x = TIMER0_PRESCALER_64;
		TIMER0_voidSetDutyCycle_FASTPWM(36);
	}
	else if(keydata == '6') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("7");
		TCCR0_REG->CS0x = TIMER0_PRESCALER_64;
		TIMER0_voidSetDutyCycle_FASTPWM(42);
	}
	else if(keydata == '*') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("8");
		TCCR0_REG->CS0x = TIMER0_PRESCALER_256;
		TIMER0_voidSetDutyCycle_FASTPWM(48);
	}
	else if(keydata == '1') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("9");
		TCCR0_REG->CS0x = TIMER0_PRESCALER_256;
		TIMER0_voidSetDutyCycle_FASTPWM(54);
	}
	else if(keydata == '2') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("10");
		TCCR0_REG->CS0x = TIMER0_PRESCALER_256;
		TIMER0_voidSetDutyCycle_FASTPWM(60);
	}
	else if(keydata == '3') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("111");
		TIMER0_voidSetDutyCycle_FASTPWM(66);
	}
	else if(keydata == '-') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("12");
		TIMER0_voidSetDutyCycle_FASTPWM(72);
	}
	else if(keydata == 'C') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("13");
		TIMER0_voidSetDutyCycle_FASTPWM(78);
	}
	else if(keydata == '0') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("14");
		TIMER0_voidSetDutyCycle_FASTPWM(84);
	}
	else if(keydata == '=') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("15");
		TIMER0_voidSetDutyCycle_FASTPWM(90);
	}
	else if(keydata == '+') {
		LCD_voidSetCursor(1, 0);
		LCD_voidDisplayString("16");
		TIMER0_voidSetDutyCycle_FASTPWM(98);
	}
}


/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
