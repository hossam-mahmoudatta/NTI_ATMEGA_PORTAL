/******************************************************************************
 *
 * Module: Seven Segment Display
 *
 * File Name: SEGMENT.C
 *
 * Description: Source file for the AVR Seven Segment Display Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "SEGMENT.h"

//#include "avr/io.h" /* To use the IO Ports Registers */

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
SEGMENT_Error_t SEGMENT_Init(u8_t copy_u8portID) {
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	u8_t SEGMENT_Driver_Checker = NULL;

	if((copy_u8portID >= NUM_OF_PORTS)) {
		SEGMENT_Driver_Checker = SEGMENT_WRONG_PORT_NUMBER;
	}
	else {
		/* These pins are for the COMs */
		GPIO_vidSetPinDirection(COM_4_PORT, COM_4, PIN_OUTPUT);
		GPIO_vidSetPinDirection(COM_3_PORT, COM_3, PIN_OUTPUT);
		GPIO_vidSetPinDirection(COM_2_PORT, COM_2, PIN_OUTPUT);
		GPIO_vidSetPinDirection(COM_1_PORT, COM_1, PIN_OUTPUT);

		/* These pins are for the BCD on the FARES Kit */
		GPIO_vidSetPinDirection(copy_u8portID, BCD_1, PIN_OUTPUT);
		GPIO_vidSetPinDirection(copy_u8portID, BCD_2, PIN_OUTPUT);
		GPIO_vidSetPinDirection(copy_u8portID, BCD_4, PIN_OUTPUT);
		GPIO_vidSetPinDirection(copy_u8portID, BCD_8, PIN_OUTPUT);

		SEGMENT_Driver_Checker = SEGMENT_OK;
	}
	return SEGMENT_Driver_Checker;
}


/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
SEGMENT_Error_t SEGMENT_DISPLAY(u8_t copy_u8portID, u8_t copy_u8pinValue) {
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	u8_t SEGMENT_Driver_Checker = NULL;

	if((copy_u8portID >= NUM_OF_PORTS)) {
		SEGMENT_Driver_Checker = SEGMENT_WRONG_PORT_NUMBER;
	}
	else if((copy_u8pinValue < 0 && copy_u8pinValue > 9)) {
		SEGMENT_Driver_Checker = SEGMENT_WRONG_VALUE;
	}
	else {
		switch(copy_u8pinValue) {
			case 0:
				GPIO_vidSetPinValue(copy_u8portID, BCD_1, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 1:
				GPIO_vidSetPinValue(copy_u8portID, BCD_1, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 2:
				GPIO_vidSetPinValue(copy_u8portID, BCD_1, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_2, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 3:
				GPIO_vidSetPinValue(copy_u8portID, BCD_1, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_2, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 4:
				GPIO_vidSetPinValue(copy_u8portID, BCD_1, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_4, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 5:
				GPIO_vidSetPinValue(copy_u8portID, BCD_1, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_4, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 6:
				GPIO_vidSetPinValue(copy_u8portID, BCD_1, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_2, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_4, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 7:
				GPIO_vidSetPinValue(copy_u8portID, BCD_1, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_2, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_4, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 8:
				GPIO_vidSetPinValue(copy_u8portID, BCD_1, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_8, LOGIC_HIGH);
				break;
			case 9:
				GPIO_vidSetPinValue(copy_u8portID, BCD_1, LOGIC_HIGH);
				GPIO_vidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_vidSetPinValue(copy_u8portID, BCD_8, LOGIC_HIGH);
				break;
		}
		SEGMENT_Driver_Checker = SEGMENT_OK;
	}
	return SEGMENT_Driver_Checker;
}
