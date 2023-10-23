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

void systemInit(void) {
	//LED_voidInit(PORT_A, LED_PORTA_KIT_YELLOW);
	//LED_voidInit(PORT_A, LED_PORTA_KIT_GREEN);
	//LCD_voidInit();
	//KEYPAD_voidInit();
	//SEGMENT_voidInit(PORT_B);

	LED_voidInit(PORT_B, LED_PORTB_KIT_RED);
	EXT_INTERRUPT_Enable_voidINTx(EXT_INT0, INT_Function);
	EXT_INTERRUPT_Sense_voidINTx(EXT_INT0, EXT_INTERRUPT_Falling_Edge);
	GLOBAL_INTERRUPT_voidEnable();

	GPIO_voidSetPinDirection(PORT_C, PIN_2, PIN_OUTPUT);
	GPIO_voidSetPinDirection(PORT_D, PIN_3, PIN_INPUT);
}

void INT_Function(void) {
	LED_voidToggle(PORT_B, LED_PORTB_KIT_RED);
	_delay_ms(30);
}


	//LED_voidToggle(PORT_B, LED_PORTB_KIT_RED);


void binaryLEDS(u8 copy_u8pinValue) {
	switch(copy_u8pinValue) {
		case 0:
			GPIO_voidSetPinValue(PORT_B, LED_PORTB_KIT_RED, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_GREEN, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_BLUE, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_YELLOW, LOGIC_LOW);
			break;
		case 1:
			GPIO_voidSetPinValue(PORT_B, LED_PORTB_KIT_RED, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_GREEN, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_BLUE, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_YELLOW, LOGIC_LOW);
			break;
		case 2:
			GPIO_voidSetPinValue(PORT_B, LED_PORTB_KIT_RED, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_GREEN, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_BLUE, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_YELLOW, LOGIC_LOW);
			break;
		case 3:
			GPIO_voidSetPinValue(PORT_B, LED_PORTB_KIT_RED, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_GREEN, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_BLUE, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_YELLOW, LOGIC_LOW);
			break;
		case 4:
			GPIO_voidSetPinValue(PORT_B, LED_PORTB_KIT_RED, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_GREEN, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_BLUE, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_YELLOW, LOGIC_LOW);
			break;
		case 5:
			GPIO_voidSetPinValue(PORT_B, LED_PORTB_KIT_RED, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_GREEN, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_BLUE, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_YELLOW, LOGIC_LOW);
			break;
		case 6:
			GPIO_voidSetPinValue(PORT_B, LED_PORTB_KIT_RED, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_GREEN, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_BLUE, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_YELLOW, LOGIC_LOW);
			break;
		case 7:
			GPIO_voidSetPinValue(PORT_B, LED_PORTB_KIT_RED, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_GREEN, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_BLUE, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_YELLOW, LOGIC_LOW);
			break;
		case 8:
			GPIO_voidSetPinValue(PORT_B, LED_PORTB_KIT_RED, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_GREEN, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_BLUE, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_YELLOW, LOGIC_HIGH);
			break;
		case 9:
			GPIO_voidSetPinValue(PORT_B, LED_PORTB_KIT_RED, LOGIC_HIGH);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_GREEN, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_BLUE, LOGIC_LOW);
			GPIO_voidSetPinValue(PORT_A, LED_PORTA_KIT_YELLOW, LOGIC_HIGH);
			break;
	}
}


void TrafficLights(void) {
	u8 i = 1;
	LED_voidOn(PORT_B, LED_PORTB_KIT_RED);
	for(i = 1 ; i < 4 ; i++)
	{
		SEGMENT_voidDisplay(PORT_B, i);
		_delay_ms(800);
	}
	LED_voidOff(PORT_B, LED_PORTB_KIT_RED);

	LED_voidOn(PORT_A, LED_PORTA_KIT_YELLOW);
	for(i = 1 ; i < 4 ; i++)
	{
		SEGMENT_voidDisplay(PORT_B, i);
		_delay_ms(800);
	}
	LED_voidOff(PORT_A, LED_PORTA_KIT_YELLOW);

	LED_voidOn(PORT_A, LED_PORTA_KIT_GREEN);
	for(i = 1 ; i < 4 ; i++)
	{
		SEGMENT_voidDisplay(PORT_B, i);
		_delay_ms(800);
	}
	LED_voidOff(PORT_A, LED_PORTA_KIT_GREEN);
}

void displayKEYPADLCD(void) {
	u8 keyValue = KEYPAD_u8getPressedKey();
	LCD_voidDisplayCharacter(keyValue);
	LCD_voidMoveCursor(0,0);
}











/*
void binaryLEDS(u8 copy_u8pinValue) {
    PORTA_REG =		((copy_u8pinValue & 0x10) << 2) |		// PA6
            					((copy_u8pinValue & 0x08) << 1) |	// PA5
								((copy_u8pinValue & 0x04) << 2);	// PA4

    PORTB_REG = 		(copy_u8pinValue & 0x01) << 7;	// PB7
}
*/
