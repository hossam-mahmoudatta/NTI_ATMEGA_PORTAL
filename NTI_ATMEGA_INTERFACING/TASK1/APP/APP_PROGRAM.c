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


/*
void binaryLEDS(u8 copy_u8pinValue) {
    PORTA_REG =		((copy_u8pinValue & 0x10) << 2) |		// PA6
            					((copy_u8pinValue & 0x08) << 1) |	// PA5
								((copy_u8pinValue & 0x04) << 2);	// PA4

    PORTB_REG = 		(copy_u8pinValue & 0x01) << 7;	// PB7
}
*/
