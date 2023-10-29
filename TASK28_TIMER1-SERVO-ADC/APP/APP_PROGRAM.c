/******************************************************************************
 *
 * Application
 *
 * File Name: APP_Program.c
 *
 * Description: Application file for testing ADC with Interrupts
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/


/*******************************************************************************
 *                              					 Application Libraries                      					  *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					 Application Declarations                      					  *
 *******************************************************************************/

//u16 ADC_Result = 0;
//u8 Mapping = 0;
//u16 angleValue = 0;
//u16 CMP_Value = 0;

void System_Initialization(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("Servo Motor");
	LCD_voidSetCursor(1, 0);
	LCD_voidDisplayString("Angle: ");
	GPIO_voidSetPinDirection(PORT_D, PIN_5, PIN_OUTPUT);

	SERVO_voidInit();

//	// Initializing ADC Module
//	ADC_voidInit();
//
//	// Initializing Timer0 Module
//	TIMER1_Initialization();
//	TIMER1A_SetTop_FASTPWM(2000);

}

void executeMain(void) {
	SERVO_voidAdjustAngle();
}
//void adjustServo(void){
//	ADC_Result = ADC_voidStartConversionPolling(CHANNEL_1);
//	angleValue = mapServo(ADC_Result);
//	CMP_Value = TIMER1A_SetCOMPAREMATCH_FASTPWM(angleValue);
//	LCD_voidSetCursor(1, 7);
//	LCD_voidIntgerToString(CMP_Value);
//
//}






/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
