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
 *                              					 			AVR Libraries                      									  *
 *******************************************************************************/

//#include <util/delay.h>
//#include <avr/io.h>
//#include <avr/interrupt.h>

/*******************************************************************************
 *                              						  MCAL Drivers                           				  *
 *******************************************************************************/

//#include "../MCAL/I2C_DRIVER/I2C.h"
//#include "../MCAL/ICU_DRIVER/ICU.h"
//#include "../MCAL/SPI_DRIVER/SPI.h"
#include "../MCAL/EXT_INTERRUPT_DRIVER/EXT_INTERRUPT_INTERFACE.h"
#include "../MCAL/ADC_DRIVER/ADC_INTERFACE.h"
#include "../MCAL/GLOBAL_INTERRUPT_DRIVER/GLOBAL_INTERRUPT_INTERFACE.h"
#include "../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"
#include "../MCAL/TIMERS_DRIVER/TIMER0_DRIVER/TIMER0_INTERFACE.h"

/*******************************************************************************
 *                              						  ECUAL Drivers                           				  *
 *******************************************************************************/

#include "../ECUAL/LCD_DRIVER/LCD_INTERFACE.h"
#include "../ECUAL/LED_DRIVER/LED_INTERFACE.h"

//#include "../ECUAL/SEVEN-SEGMENT_DRIVER/SEGMENT_INTERFACE.h"
//#include "../ECUAL/KEYPAD_DRIVER/KEYPAD_INTERFACE.h"
//#include "../ECUAL/EEPROM_DRIVER/EEPROM.h"
//#include "../ECUAL/LM35_DRIVER/LM35.h"
//#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"
//#include "../ECUAL/BUZZER_DRIVER/BUZZER.h"

/*******************************************************************************
 *                              					 Application Prototypes                      					  *
 *******************************************************************************/

void SYSTEM_INITIALIZATION(void);
void function_ISR(void);
void executeISR(void);
