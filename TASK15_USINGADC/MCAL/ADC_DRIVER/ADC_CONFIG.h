 /******************************************************************************
 *
 * Module: ADC (Analog to Digital Converter)
 *
 * File Name: ADC_CONFIG.h
 *
 * Description: Header file for the AVR ADC Driver Macro Definitions
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*******************************************************************************
 *                              							Macro Definitions						                       		   *
 *******************************************************************************/

// Defines for the ADC Registers Bits
// Select REFS1:0 to choose volt reference, choose '01' for AVCC
#define ADMUX_REFS0		PIN_7
#define ADMUX_REFS1		PIN_6

// Set it to '0' for Right Adjust Result
#define ADMUX_ADLAR		PIN_5

// ADC has 8 channels, choose ch0 = '00000'
#define ADMUX_MUX4			PIN_4
#define ADMUX_MUX3			PIN_3
#define ADMUX_MUX2			PIN_2
#define ADMUX_MUX1			PIN_1
#define ADMUX_MUX0			PIN_0

// ADC Enable, set it to '1' to enable the ADC
#define ADCSRA_ADEN		PIN_7
// Starts the conversion, bit is '1' when conversion and turns into '0' when complete
#define ADCSRA_ADSC		PIN_6
// Auto Triggering, set it to '0', we won't use the automatic
#define ADCSRA_ADATE	PIN_5
// ADC Interrupt Flag, if we used interrupts with ADC, this is the flag we use
#define ADCSRA_ADIF		PIN_4
// ADC Interrupt Enable, Enables the interrupt if set to 1
#define ADCSRA_ADIE		PIN_3
// ADC Prescaler Config, choose the prescaler settings, set to '111' to be 128
#define ADCSRA_ADPS2		PIN_2
#define ADCSRA_ADPS1		PIN_1
#define ADCSRA_ADPS0	PIN_0

#define ADC_MAX_VAL 		1023
#define ADC_REF_VOLT		5

#define ADC_POLLING			1
#define ADC_INT					2
#define ADC_INT_MODE		ADC_INT


#endif /* ADC_CONFIG_H_ */
