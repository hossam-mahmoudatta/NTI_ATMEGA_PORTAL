 /******************************************************************************
 *
 * Module: ADC (Analog to Digital Converter)
 *
 * File Name: ADC.h
 *
 * Description: Header file for the AVR ADC Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "../GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"


/*******************************************************************************
 *                                								Definitions                                  					      *
 *******************************************************************************/

#define ADC_MAX_VALUE 								1023
#define ADC_REFERENCE_VOLT_VALUE 	5


/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the ADC Module to start functionality
void ADC_Init(void);


 // Reads the content written to the selected channel of the ADC
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */




/*************** ADMUX Register Definitions ***************/
/*
// Select REFS1:0 to choose volt reference, choose '01' for AVCC
#define ADMUX_REFS1											PIN_7
#define ADMUX_REFS0											PIN_6

// Set it to '0' for Right Adjust Result
#define ADMUX_ADLAR											PIN_5

// Analog Channel selection, ADC has 8 channels, choose ch0 = '00000'
#define ADMUX_MUX4											PIN_4
#define ADMUX_MUX3												PIN_3
#define ADMUX_MUX2												PIN_2
#define ADMUX_MUX1												PIN_1
#define ADMUX_MUX0											PIN_0
*/
/*************** ADCSRA Register Definitions ***************/
/*
// ADC Enable, set it to '1' to enable the ADC
#define ADCSRA_ADEN											PIN_7

// Starts the conversion, bit is '1' when conversion and turns into '0' when complete
#define ADCSRA_ADSC											PIN_6

// Auto Triggering, set it to '0', we won't use the automatic
#define ADCSRA_ADATE										PIN_5

// ADC Interrupt Flag, if we used interrupts with ADC, this is the flag we use
#define ADCSRA_ADIF												PIN_4

// ADC Interrupt Enable, Enables the interrupt if set to 1
#define ADCSRA_ADIE											PIN_3

// ADC Prescaler Config, choose the prescaler settings, set to '111' to be 128
#define ADCSRA_ADPS2										PIN_2
#define ADCSRA_ADPS1											PIN_1
#define ADCSRA_ADPS0										PIN_0
*/
