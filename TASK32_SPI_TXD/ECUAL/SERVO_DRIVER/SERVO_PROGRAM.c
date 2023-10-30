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
	TIMER1_Initialization();
	TIMER1A_SetTop_FASTPWM(SERVO_OP_RANGE);
	ADC_voidInit();
}

// Displays a value on the 7 Segment Display
void SERVO_voidAdjustAngle(void) {
	ADC_Result = ADC_voidStartConversionPolling(CHANNEL_1);
	AngleValue = mapServo(ADC_Result);
	CMP_Value = TIMER1A_SetCOMPAREMATCH_FASTPWM(AngleValue);
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Angle: ");
	LCD_voidSetCursor(1, 7);
	LCD_voidIntgerToString(CMP_Value);
}

u16 mapServo(u16 copy_u16ADCValue){
	u16 servoAngle = (u16)(copy_u16ADCValue * 255) / 100;
	return servoAngle;
}
