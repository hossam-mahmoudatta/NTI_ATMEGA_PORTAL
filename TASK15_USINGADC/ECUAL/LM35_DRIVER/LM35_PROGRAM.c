 /******************************************************************************
 *
 * Module: LM35 Sensor
 *
 * File Name: LM35_PROGRAM.c
 *
 * Description: Source file for the LM35 Sensor Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "LM35_INTERFACE.h"
#include <util/delay.h>

//olatile u16 glob_ADCResult = 0;

/*******************************************************************************
 *                              						Functions Declarations	                     	   		  		   *
 *******************************************************************************/

// Initializes and enables the ADC Module to start functionality
u8 LM35_u8getTemperature(void) {
	u8 temperatureValue = 0;

	// Read ADC Channel that the LM35 is configured to
	ADC_u16readChannel(LM35_CHANNEL_ID);

	// Add a small Delay for the global ADC result is set with Interrupt
	_delay_ms(5);

	// Calculate the temperature for the ADC
	temperatureValue = (((u32)glob_ADCResult * LM35_MAX_TEMP * ADC_REF_VOLT) / (ADC_MAX_VAL * LM35_MAX_VOLT));

	return temperatureValue;
}

