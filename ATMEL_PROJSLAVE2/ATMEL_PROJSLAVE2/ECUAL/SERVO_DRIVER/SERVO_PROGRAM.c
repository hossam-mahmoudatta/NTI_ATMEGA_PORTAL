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
	//ADC_voidInit();
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


// Open Front Right Door
void SERVO_CarDoor_FR_Open(void)
{	
	TIMER1A_u16SetCompareMatch_FASTPWM(750);
}

// Close Front Right Door
void SERVO_CarDoor_FR_Close(void)
{
	TIMER1A_u16SetCompareMatch_FASTPWM(1499);
}

// Open Front Left Door
void SERVO_CarDoor_FL_Open(void)
{
	TIMER1B_u16SetCompareMatch_FASTPWM(750);
}

// Close Front Left Door
void SERVO_CarDoor_FL_Close(void)
{
	TIMER1B_u16SetCompareMatch_FASTPWM(1499);
}

// Open Rear Right Door
void SERVO_CarDoor_RR_Open(void)
{
	TIMER1A_u16SetCompareMatch_FASTPWM(750);
}

// Close Rear Right Door
void SERVO_CarDoor_RR_Close(void)
{
	TIMER1A_u16SetCompareMatch_FASTPWM(1499);
}

// Open Rear Left Door
void SERVO_CarDoor_RL_Open(void)
{
	TIMER1B_u16SetCompareMatch_FASTPWM(750);
}

// Close Rear Left Door
void SERVO_CarDoor_RL_Close(void)
{
	TIMER1B_u16SetCompareMatch_FASTPWM(1499);
}






