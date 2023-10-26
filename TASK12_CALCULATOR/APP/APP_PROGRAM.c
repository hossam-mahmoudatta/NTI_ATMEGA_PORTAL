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
	LCD_voidInit();
	KEYPAD_voidInit();

}

void keypadDisplayName(void) {
	u8 keydata = KEYPAD_u8getPressedKey();
	while(keydata==0xff)
	{
		keydata = KEYPAD_u8getPressedKey();
	}
	if(keydata == '7') {
		LCD_voidDisplayString("Hossam", 0, 0);
	}
	else if(keydata == '8') {
		LCD_voidDisplayString("Mahmoud", 1, 0);
	}
	else if(keydata == '9') {
		LCD_voidDisplayString("Atta", 2, 0);
	}
	else if(keydata == 'C') {
		LCD_voidClearScreen();
	}
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
