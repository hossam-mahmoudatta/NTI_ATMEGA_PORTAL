/******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED_PROGRAM.c
 *
 * Description: Source file for the LED Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "LED_INTERFACE.h"

/*******************************************************************************
 *                              						Functions Declarations                     	      				  *
 *******************************************************************************/

// Initializes the LED Driver
LED_Error_t LED_voidInit(u8 copy_u8portID, u8 copy_u8pinID) {
	u8 LED_Driver_Checker = 0;
	if((copy_u8pinID >= NUM_OF_PINS_PER_PORT)) {
		LED_Driver_Checker = LED_WRONG_PIN_NUMBER;
	}
	else if((copy_u8portID >= NUM_OF_PORTS)) {
		LED_Driver_Checker = LED_WRONG_PORT_NUMBER;
	}
	else {
		/* Setup the pin direction as required */
		GPIO_voidSetPinDirection(copy_u8portID, copy_u8pinID, PIN_OUTPUT);
		LED_Driver_Checker = LED_OK;
	}
	return LED_Driver_Checker;
}

// Turns on a LED
LED_Error_t LED_voidOn(u8 copy_u8portID, u8 copy_u8pinID) {
	u8 LED_Driver_Checker = 0;
		if((copy_u8pinID >= NUM_OF_PINS_PER_PORT)) {
			LED_Driver_Checker = LED_WRONG_PIN_NUMBER;
		}
		else if((copy_u8portID >= NUM_OF_PORTS)) {
			LED_Driver_Checker = LED_WRONG_PORT_NUMBER;
		}
		else {
			/* Setup the pin direction as required */
			#if (LED_MODE == LED_NEGATIVE_LOGIC)
				GPIO_voidSetPinValue(copy_u8portID, copy_u8pinID, LOGIC_LOW);
			#elif (LED_MODE == LED_POSITIVE_LOGIC)
				GPIO_voidSetPinValue(copy_u8portID, copy_u8pinID, LOGIC_HIGH);
			#endif
			LED_Driver_Checker = LED_OK;
		}
		return LED_Driver_Checker;
}

// Turns off a LED
LED_Error_t LED_voidOff(u8 copy_u8portID, u8 copy_u8pinID) {
	u8 LED_Driver_Checker = 0;
		if((copy_u8pinID >= NUM_OF_PINS_PER_PORT)) {
			LED_Driver_Checker = LED_WRONG_PIN_NUMBER;
		}
		else if((copy_u8portID >= NUM_OF_PORTS)) {
			LED_Driver_Checker = LED_WRONG_PORT_NUMBER;
		}
		else {
			/* Setup the pin direction as required */
			#if (LED_MODE == LED_NEGATIVE_LOGIC)
				GPIO_voidSetPinValue(copy_u8portID, copy_u8pinID, LOGIC_HIGH);
			#elif (LED_MODE == LED_POSITIVE_LOGIC)
				GPIO_voidSetPinValue(copy_u8portID, copy_u8pinID, LOGIC_LOW);
			#endif
			LED_Driver_Checker = LED_OK;
		}
		return LED_Driver_Checker;
}

// Toggles a LED
LED_Error_t LED_voidToggle(u8 copy_u8portID, u8 copy_u8pinID) {
	u8 LED_Driver_Checker = 0;
		if((copy_u8pinID >= NUM_OF_PINS_PER_PORT)) {
			LED_Driver_Checker = LED_WRONG_PIN_NUMBER;
		}
		else if((copy_u8portID >= NUM_OF_PORTS)) {
			LED_Driver_Checker = LED_WRONG_PORT_NUMBER;
		}
		else {
			/* Setup the pin direction as required */
			GPIO_voidTogglePin(copy_u8portID, copy_u8pinID);
			LED_Driver_Checker = LED_OK;
		}
		return LED_Driver_Checker;
}
