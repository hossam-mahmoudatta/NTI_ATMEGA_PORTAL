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

#include "SERVO_INTERFACE.h"

/*******************************************************************************
 *                              						Functions Declarations                     	      				  *
 *******************************************************************************/
u8 	Mapping 		= 0;
u16 ADC_Result 	= 0;
u16 AngleValue 	= 0;
u16 CMP_Value 	= 0;


// Initializes the 7 Segment Display Driver
void SERVO_voidInit(void) {
	TIMER1_voidInitialization();
	TIMER1_voidSetTop_FASTPWM(SERVO_OP_RANGE);
	ADC_voidInit();
}


// Adjusts the angle for the servo motor
void SERVO_voidAdjustAngle(u8 copy_u8Angle) {
	if(copy_u8Angle > 180)
	{
		copy_u8Angle = 180;
	}
	OCR1B_REG = ((copy_u8Angle * (u32)1000) / (u32) 180) + 999;
}


// Mapping Servo with ADC
u16 mapServo(u16 copy_u16ADCValue){
	u16 servoAngle = (u16)(copy_u16ADCValue * 255) / 100;
	return servoAngle;
}

DOOR_STATUS SERVO_CarDoor(DOOR_NO doorNum, DOOR_STATUS doorAngle, u8 portNumber, u8 pinNumber)
{
	GPIO_voidSetPinDirection(portNumber, pinNumber, PIN_OUTPUT);
	if(doorAngle == Door_Close)
	{
		GPIO_voidSetPinValue(portNumber, pinNumber, LOGIC_HIGH);
		//_delay_ms(10);
		SERVO_voidAdjustAngle(Door_Open);
		doorAngle = Door_Open;
		_delay_ms(50);
		GPIO_voidSetPinValue(portNumber, pinNumber, LOGIC_LOW);
	}
	else if(doorAngle == Door_Open)
	{
		GPIO_voidSetPinValue(portNumber, pinNumber, LOGIC_HIGH);
		//_delay_ms(10);
		SERVO_voidAdjustAngle(Door_Close);
		doorAngle = Door_Close;
		_delay_ms(50);
		GPIO_voidSetPinValue(portNumber, pinNumber, LOGIC_LOW);
	}
	return doorAngle;
}





