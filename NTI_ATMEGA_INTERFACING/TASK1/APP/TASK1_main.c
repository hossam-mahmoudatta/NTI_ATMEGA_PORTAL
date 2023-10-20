/******************************************************************************
 *
 * Application
 *
 * File Name: TASK1_main.c
 *
 * Description: Application file for testing the gpio driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/


/*******************************************************************************
 *                              					 Application Libraries                      					  *
 *******************************************************************************/

//#include <util/delay.h>
//#include <avr/io.h>
	#include <util/delay.h>
//#include <avr/interrupt.h>

/*******************************************************************************
 *                              						  Modules Drivers                           				  *
 *******************************************************************************/

//#include "../MCAL/ADC_DRIVER/ADC.h"
//#include "../MCAL/I2C_DRIVER/I2C.h"
//#include "../MCAL/ICU_DRIVER/ICU.h"
//#include "../MCAL/SPI_DRIVER/SPI.h"
//#include "../MCAL/EXT_INTERRUPT_DRIVER/EXT_INTERRUPT.h"

#include "../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h" // I will need this driver for this ECU Driver

/*******************************************************************************/

#include "../ECUAL/LED_DRIVER/LED.h" // I will need this driver for this ECU Driver
#include "../ECUAL/SEVEN-SEGMENT_DRIVER/SEGMENT.h"

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
	LED_Init(PORT_A, PIN_4);
	LED_Init(PORT_A, PIN_5);
	LED_Init(PORT_A, PIN_6);
	LED_Init(PORT_B, PIN_7);

	SEGMENT_Init(PORT_B);
	int i = 0;
	//u8_t value = 0;

	while (1)
	{
		for(i = 0 ; i < 10 ; i++) {
			SEGMENT_DISPLAY(PORT_B, i);
			_delay_ms(1000);

		}
	}
}


//		LED_On(PORT_A, PIN_4);
//		LED_On(PORT_A, PIN_5);
//		LED_On(PORT_A, PIN_6);
//		LED_On(PORT_B, PIN_7);
//		_delay_ms(1000);
//		LED_Off(PORT_A, PIN_4);
//		LED_Off(PORT_A, PIN_5);
//		LED_Off(PORT_A, PIN_6);
//		LED_Off(PORT_B, PIN_7);
//		_delay_ms(1000);

