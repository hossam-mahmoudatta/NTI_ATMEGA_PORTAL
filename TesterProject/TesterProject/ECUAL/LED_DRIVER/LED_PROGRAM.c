/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "LED_INTERFACE.h"


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
LED_Error_t LED_voidInit(u8 copy_u8portID, u8 copy_u8pinID) {
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
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

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
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

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
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
