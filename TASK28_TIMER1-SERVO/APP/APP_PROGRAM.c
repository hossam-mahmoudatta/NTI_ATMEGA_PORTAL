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

u16 ADC_Result = 0;
u8 Mapping = 0;

void SYSTEM_INITIALIZATION(void) {
	// Initializing LCD Module
	LCD_voidInit();
	LCD_voidSetCursor(0, 0);
	LCD_voidDisplayString("Servo Motor");
	GPIO_voidSetPinDirection(PORT_D, PIN_5, PIN_OUTPUT);

	ADC_voidInit();

	// Initializing Timer0 Module
	TIMER1_Initialization();

}

void adjustServo(void){
	ADC_Result = ADC_voidStartConversionPolling();

}

u16 mapServo(u16 copy_u16ADCValue){
	u16 servoAngle = (u16)(copy_u16ADCValue * 255) / 100;
	return servoAngle;

}




/*******************************************************************************
 *                              					 					END                      											  *
 *******************************************************************************/
