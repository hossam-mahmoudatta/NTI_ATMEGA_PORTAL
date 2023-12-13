/******************************************************************************
 *
 * Module: Seven Segment Display
 *
 * File Name: SEGMENT_PROGRAM.C
 *
 * Description: Source file for the AVR Seven Segment Display Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "SEGMENT_INTERFACE.h"

/*******************************************************************************
 *                              						Functions Declarations                     	      				  *
 *******************************************************************************/

// Initializes the 7 Segment Display Driver
SEGMENT_Error_t SEGMENT_voidInit(u8 copy_u8portID) {
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	u8 SEGMENT_Driver_Checker = 0;

	if((copy_u8portID >= NUM_OF_PORTS)) {
		SEGMENT_Driver_Checker = SEGMENT_WRONG_PORT_NUMBER;
	}
	else {
		/* These pins are for the COMs */
		/* I will configure whether I will use all the coms or not */
#if (DIGITS_USED == 4)
		GPIO_voidSetPinDirection(COM_4_PORT, COM_4, PIN_OUTPUT);
		GPIO_voidSetPinDirection(COM_3_PORT, COM_3, PIN_OUTPUT);
		GPIO_voidSetPinDirection(COM_2_PORT, COM_2, PIN_OUTPUT);
		GPIO_voidSetPinDirection(COM_1_PORT, COM_1, PIN_OUTPUT);
#elif (DIGITS_USED == 3)
		GPIO_voidSetPinDirection(COM_3_PORT, COM_3, PIN_OUTPUT);
		GPIO_voidSetPinDirection(COM_2_PORT, COM_2, PIN_OUTPUT);
		GPIO_voidSetPinDirection(COM_1_PORT, COM_1, PIN_OUTPUT);
#elif (DIGITS_USED == 2)
		GPIO_voidSetPinDirection(COM_2_PORT, COM_2, PIN_OUTPUT);
		GPIO_voidSetPinDirection(COM_1_PORT, COM_1, PIN_OUTPUT);
#elif (DIGITS_USED == 1)
		GPIO_voidSetPinDirection(COM_1_PORT, COM_1, PIN_OUTPUT);
#else
		GPIO_voidSetPinDirection(COM_4_PORT, COM_4, PIN_OUTPUT);
		GPIO_voidSetPinDirection(COM_3_PORT, COM_3, PIN_OUTPUT);
		GPIO_voidSetPinDirection(COM_2_PORT, COM_2, PIN_OUTPUT);
		GPIO_voidSetPinDirection(COM_1_PORT, COM_1, PIN_OUTPUT);
#endif

		/* These pins are for the BCD on the FARES Kit */
		GPIO_voidSetPinDirection(copy_u8portID, BCD_1, PIN_OUTPUT);
		GPIO_voidSetPinDirection(copy_u8portID, BCD_2, PIN_OUTPUT);
		GPIO_voidSetPinDirection(copy_u8portID, BCD_4, PIN_OUTPUT);
		GPIO_voidSetPinDirection(copy_u8portID, BCD_8, PIN_OUTPUT);

		SEGMENT_Driver_Checker = SEGMENT_OK;
	}
	return SEGMENT_Driver_Checker;
}


// Displays a value on the 7 Segment Display
SEGMENT_Error_t SEGMENT_voidDisplay(u8 copy_u8portID, u8 copy_u8pinValue) {
	u8 SEGMENT_Driver_Checker = 0;

	if((copy_u8portID >= NUM_OF_PORTS)) {
		SEGMENT_Driver_Checker = SEGMENT_WRONG_PORT_NUMBER;
	}
	else if((copy_u8pinValue < 0 && copy_u8pinValue > 9)) {
		SEGMENT_Driver_Checker = SEGMENT_WRONG_VALUE;
	}
	else {
		switch(copy_u8pinValue) {
			case 0:
				GPIO_voidSetPinValue(copy_u8portID, BCD_1, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 1:
				GPIO_voidSetPinValue(copy_u8portID, BCD_1, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 2:
				GPIO_voidSetPinValue(copy_u8portID, BCD_1, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_2, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 3:
				GPIO_voidSetPinValue(copy_u8portID, BCD_1, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_2, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 4:
				GPIO_voidSetPinValue(copy_u8portID, BCD_1, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_4, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 5:
				GPIO_voidSetPinValue(copy_u8portID, BCD_1, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_4, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 6:
				GPIO_voidSetPinValue(copy_u8portID, BCD_1, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_2, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_4, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 7:
				GPIO_voidSetPinValue(copy_u8portID, BCD_1, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_2, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_4, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_8, LOGIC_LOW);
				break;
			case 8:
				GPIO_voidSetPinValue(copy_u8portID, BCD_1, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_8, LOGIC_HIGH);
				break;
			case 9:
				GPIO_voidSetPinValue(copy_u8portID, BCD_1, LOGIC_HIGH);
				GPIO_voidSetPinValue(copy_u8portID, BCD_2, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_4, LOGIC_LOW);
				GPIO_voidSetPinValue(copy_u8portID, BCD_8, LOGIC_HIGH);
				break;
		}
		SEGMENT_Driver_Checker = SEGMENT_OK;
	}
	return SEGMENT_Driver_Checker;
}

