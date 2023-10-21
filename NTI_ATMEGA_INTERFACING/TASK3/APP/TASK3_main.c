/******************************************************************************
 *
 * Application
 *
 * File Name: TASK3_main.c
 *
 * Description: Application file for testing the gpio driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/


/*******************************************************************************
 *                              					 Application Libraries                      					  *
 *******************************************************************************/

#include <util/delay.h>
//#include <avr/io.h>
//#include <avr/interrupt.h>

/*******************************************************************************
 *                              						  MCAL Drivers                           				  *
 *******************************************************************************/

//#include "../MCAL/ADC_DRIVER/ADC.h"
//#include "../MCAL/I2C_DRIVER/I2C.h"
//#include "../MCAL/ICU_DRIVER/ICU.h"
//#include "../MCAL/SPI_DRIVER/SPI.h"
//#include "../MCAL/EXT_INTERRUPT_DRIVER/EXT_INTERRUPT.h"

#include "../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h" // I will need this driver for this ECU Driver

/*******************************************************************************
 *                              						  ECUAL Drivers                           				  *
 *******************************************************************************/

#include "../ECUAL/LED_DRIVER/LED_INTERFACE.h" // I will need this driver for this ECU Driver
#include "../ECUAL/SEVEN-SEGMENT_DRIVER/SEGMENT_INTERFACE.h"

//#include "../ECUAL/EEPROM_DRIVER/EEPROM.h"
//#include "../ECUAL/LM35_DRIVER/LM35.h"
//#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"

//#include "../ECUAL/BUZZER_DRIVER/BUZZER.h"
//#include "../ECUAL/KEYPAD_DRIVER/KEYPAD.h" // I will need this driver for this ECU Driver
//#include "../ECUAL/LCD_DRIVER/LCD.h" // I will need this driver for this ECU Driver


/*******************************************************************************
 *                              					Application Execution                              			  *
 *******************************************************************************/

int main(void) {
	LED_voidInit(PORT_B, LED_PORTB_KIT_RED);
	LED_voidInit(PORT_A, LED_PORTA_KIT_YELLOW);
	LED_voidInit(PORT_A, LED_PORTA_KIT_BLUE);
	LED_voidInit(PORT_A, LED_PORTA_KIT_GREEN);

	SEGMENT_voidInit(PORT_B);

	u8 i = 0;

	while (1)
	{
		for(i = 0 ; i < 10 ; i++)
		{
			SEGMENT_voidDisplay(PORT_B, i);
			_delay_ms(1000);
			LED_voidOn(PORT_B, LED_PORTB_KIT_RED);
			_delay_ms(1000);
			LED_voidOff(PORT_B, LED_PORTB_KIT_RED);
			_delay_ms(1000);
		}
	}
}

