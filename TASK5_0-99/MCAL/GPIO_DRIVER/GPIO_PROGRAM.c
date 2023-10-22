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

//#include "avr/io.h" /* To use the IO Ports Registers */

#include "GPIO_INTERFACE.h"

/*******************************************************************************
 *                              					Functions Declarations                     	      		   *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
GPIO_Error_t GPIO_voidSetPinDirection(u8 copy_u8portID, u8 copy_u8pinID, u8 copy_u8pinDIR) {
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	u8 GPIO_Driver_Checker = 0;

	if((copy_u8pinID >= NUM_OF_PINS_PER_PORT)) {
		// Checks if the entered pin number is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_PIN_NUMBER;
	}
	else if((copy_u8portID >= NUM_OF_PORTS)) {
		// Checks if the entered port number is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else if((copy_u8pinDIR != PIN_INPUT) && (copy_u8pinDIR != PIN_OUTPUT)) {
		// Checks if the entered direction is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_DIRECTION;
	}
	else {
		// Setup the pin direction as required
		switch(copy_u8portID) {
			case PORT_A:
				if(copy_u8pinDIR == PIN_OUTPUT) {
					SET_BIT(DDRA_REG, copy_u8pinID);
				}
				else {
					CLR_BIT(DDRA_REG, copy_u8pinID);
				}
				break;
			case PORT_B:
				if(copy_u8pinDIR == PIN_OUTPUT) {
					SET_BIT(DDRB_REG, copy_u8pinID);
				}
				else {
					CLR_BIT(DDRB_REG, copy_u8pinID);
				}
				break;
			case PORT_C:
				if(copy_u8pinDIR == PIN_OUTPUT) {
					SET_BIT(DDRC_REG, copy_u8pinID);
				}
				else {
					CLR_BIT(DDRC_REG, copy_u8pinID);
				}
				break;
			case PORT_D:
				if(copy_u8pinDIR == PIN_OUTPUT) {
					SET_BIT(DDRD_REG, copy_u8pinID);
				}
				else {
					CLR_BIT(DDRD_REG, copy_u8pinID);
				}
				break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return GPIO_Driver_Checker;
}


/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
GPIO_Error_t GPIO_voidSetPinValue(u8 copy_u8portID, u8 copy_u8pinID, u8 copy_u8pinValue)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	u8 GPIO_Driver_Checker = 0;

	if((copy_u8pinID >= NUM_OF_PINS_PER_PORT)) {
		// Checks if the entered pin number is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_PIN_NUMBER;
	}
	else if((copy_u8portID >= NUM_OF_PORTS)) {
		// Checks if the entered port number is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else if((copy_u8pinValue != LOGIC_HIGH) && (copy_u8pinValue != LOGIC_LOW)) {
		// Checks if the entered direction is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_DIRECTION;
	}
	else {
		switch(copy_u8portID)
		{
			case PORT_A:
				if(copy_u8pinValue == LOGIC_HIGH) {
					SET_BIT(PORTA_REG ,copy_u8pinID);
				}
				else {
					CLR_BIT(PORTA_REG,copy_u8pinID);
				}
				break;
			case PORT_B:
				if(copy_u8pinValue == LOGIC_HIGH) {
					SET_BIT(PORTB_REG ,copy_u8pinID);
				}
				else {
					CLR_BIT(PORTB_REG,copy_u8pinID);
				}
				break;
			case PORT_C:
				if(copy_u8pinValue == LOGIC_HIGH) {
					SET_BIT(PORTC_REG ,copy_u8pinID);
				}
				else {
					CLR_BIT(PORTC_REG,copy_u8pinID);
				}
				break;
			case PORT_D:
				if(copy_u8pinValue == LOGIC_HIGH) {
					SET_BIT(PORTD_REG ,copy_u8pinID);
				}
				else {
					CLR_BIT(PORTD_REG,copy_u8pinID);
				}
				break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return GPIO_Driver_Checker;
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return an error.
 */
u8 GPIO_u8GetPinValue(u8 copy_u8portID, u8 copy_u8pinID) {
	u8 GPIO_Driver_Checker = 0;
	u8 pin_value = LOGIC_LOW;

	if((copy_u8pinID >= NUM_OF_PINS_PER_PORT)) {
		// Checks if the entered pin number is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_PIN_NUMBER;
	}
	else if((copy_u8portID >= NUM_OF_PORTS)) {
		// Checks if the entered port number is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else {
		/* Read the pin value as required */
		switch(copy_u8portID) {
			case PORT_A:
				// Checks if the bit equals '1' or not
				if(BIT_IS_SET(PINA_REG, copy_u8pinID)) {
					pin_value = LOGIC_HIGH;
				}
				else {
					pin_value = LOGIC_LOW;
				}
				break;
			case PORT_B:
				if(BIT_IS_SET(PINB_REG,copy_u8pinID)) {
					pin_value = LOGIC_HIGH;
				}
				else {
					pin_value = LOGIC_LOW;
				}
				break;
			case PORT_C:
				if(BIT_IS_SET(PINC_REG,copy_u8pinID)) {
					pin_value = LOGIC_HIGH;
				}
				else {
					pin_value = LOGIC_LOW;
				}
				break;
			case PORT_D:
				if(BIT_IS_SET(PIND_REG,copy_u8pinID)) {
					pin_value = LOGIC_HIGH;
				}
				else {
					pin_value = LOGIC_LOW;
				}
				break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return pin_value;
}


/*
 * Description :
 * Toggles a certain pin when requested.
 * If the input port number or pin number are not correct, The function will return an error.
 */
GPIO_Error_t GPIO_voidTogglePin(u8 copy_u8portID, u8 copy_u8pinID) {
	u8 GPIO_Driver_Checker = 0;

	if((copy_u8pinID >= NUM_OF_PINS_PER_PORT)) {
		// Checks if the entered pin number is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_PIN_NUMBER;
	}
	else if((copy_u8portID >= NUM_OF_PORTS)) {
		// Checks if the entered port number is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else {
		switch(copy_u8portID) {
			case PORT_A:
				TOG_BIT(PORTA_REG, copy_u8pinID);
				break;
			case PORT_B:
				TOG_BIT(PORTB_REG, copy_u8pinID);
				break;
			case PORT_C:
				TOG_BIT(PORTC_REG, copy_u8pinID);
				break;
			case PORT_D:
				TOG_BIT(PORTD_REG, copy_u8pinID);
				break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return GPIO_Driver_Checker;
}


/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
GPIO_Error_t GPIO_voidSetPortDirection(u8 copy_u8portID, u8 copy_u8portDIR) {
	u8 GPIO_Driver_Checker = 0;

	if((copy_u8portID >= NUM_OF_PORTS)) {
		// Checks if the entered port number is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else if((copy_u8portDIR != PORT_INPUT) && (copy_u8portDIR != PORT_OUTPUT)) {
		// Checks if the entered direction is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_DIRECTION;
	}
	else {
		/* Setup the port direction as required */
		switch(copy_u8portID) {
			case PORT_A:
				DDRA_REG = copy_u8portDIR;
				break;
			case PORT_B:
				DDRB_REG = copy_u8portDIR;
				break;
			case PORT_C:
				DDRC_REG = copy_u8portDIR;
				break;
			case PORT_D:
				DDRD_REG = copy_u8portDIR;
				break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return GPIO_Driver_Checker;
}


/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
GPIO_Error_t GPIO_voidSetPortValue(u8 copy_u8portID, u8 copy_u8portValue) {
	u8 GPIO_Driver_Checker = 0;

	if((copy_u8portID >= NUM_OF_PORTS)) {
		// Checks if the entered port number is invalid or not
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else {
		/* Setup the port direction as required */
		switch(copy_u8portID) {
			case PORT_A:
				PORTA_REG = copy_u8portValue;
				break;
			case PORT_B:
				PORTB_REG = copy_u8portValue;
				break;
			case PORT_C:
				PORTC_REG = copy_u8portValue;
				break;
			case PORT_D:
				PORTD_REG = copy_u8portValue;
				break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return GPIO_Driver_Checker;
}


/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
u8 GPIO_u8GetPortValue(u8 copy_u8portID) {
	u8 value = LOGIC_LOW;
	u8 GPIO_Driver_Checker = 0;

	if((copy_u8portID >= NUM_OF_PORTS)) {
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else {
		switch(copy_u8portID) {
			case PORT_A:
				// Why value equals PINA?
				value = PORTA_REG;
				break;
			case PORT_B:
				value = PORTB_REG;
				break;
			case PORT_C:
				value = PORTC_REG;
				break;
			case PORT_D:
				value = PORTD_REG;
				break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return value;
}
