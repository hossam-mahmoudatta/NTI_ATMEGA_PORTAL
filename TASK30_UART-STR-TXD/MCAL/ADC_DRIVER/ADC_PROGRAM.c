 /******************************************************************************
 *
 * Module: ADC (Analog to Digital Converter)
 *
 * File Name: ADC_PROGRAM.c
 *
 * Description: Source file for the AVR ADC Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "ADC_INTERFACE.h"

/*******************************************************************************
 *                              							Global Variables				                   	   		  		   *
 *******************************************************************************/

	//extern volatile u16 glob_ADCResult = 0;

void (*CallBackPtr_ADC) (void);

/*******************************************************************************
 *                              						Functions Declarations	                     	   		  		   *
 *******************************************************************************/

// Initializes and enables the ADC Module to start functionality
void ADC_voidInit(void) {
	/* ADMUX Register Bits Description:
	 * 7:6, 	REFS1:0 = 01 to choose AVCC = 5v as reference voltage
	 * 5, 	ADLAR   = 0 right adjusted
	 * 4:0, 	MUX4:0  = 00000 to choose channel 0 as initializationd
	 */

	// Sets REFS1:0 to '01'
	ADMUX_REG->REFS = AVCC;
	ADMUX_REG->ADLAR = RIGHT_ADJUST;

	// Enables ADC & Choose Prescaler of 128
	ADCSRA_REG->ADEN = ADEN_ENABLE;
	ADCSRA_REG->ADPS = PRESCALER_128;
	ADCSRA_REG->ADATE = DISABLE_TRIGGER;
	SFIOR_REG->ADTS = FREE_RUNNING;

	/* ADCSRA Register Bits Description:
	 * 7,	ADEN = 1 Enable ADC
	 * 6,	ADSC = 1 Start Conversion
	 * 5,	ADATE = 0 Disable Auto Trigger
	 * 4,	ADIF = 1 Enable ADC Interrupt Flag
	 * 3,	ADIE = 1 Enable ADC Interrupt
	 * 2:0, ADPS2:0 = 111 to choose
	 * ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz
	 * --> ADC must operate in range 50-200Khz
	 */
}


// Start ADC Conversion using Polling
u16 ADC_voidStartConversionPolling(u8 copy_u8channelSelect) {
	// Insert Channel Number in ADMUX Procedure
	ADMUX_REG->MUX = copy_u8channelSelect;

	// Starts ADC Conversion
	ADCSRA_REG->ADSC = START_CONVERSION;

	// Busy wait (Polling) untill ADIF = 1
	while ( ADCSRA_REG->ADIF == FLAG_NOTSET );

	// Set Interrupt Flag by 1 by clearing it
	ADCSRA_REG->ADIF = FLAG_SET;

	// Read Data from ADCL Bits 0 -> 9
	return ADC_DATA_REG;
}

// Start ADC Conversion using Interrupts
void ADC_voidStartConversionISR(u8 copy_u8channelSelect) {
	ADMUX_REG->MUX = copy_u8channelSelect;

	// Starts ADC Conversion
	ADCSRA_REG->ADSC = START_CONVERSION;

	// Enables the Interrupt
	ADCSRA_REG->ADIE = ENABLE_INT;

}

/*
 * Description :
 * Call Back function to use in ISR *
 */
void ADC_CallBackFunction(void (*Ptr_ADC)(void))
{
	CallBackPtr_ADC = Ptr_ADC;
}


void __vector_16(void) __attribute__((signal, used));
void __vector_16(void) {
	if(CallBackPtr_ADC != NULL) {
		CallBackPtr_ADC();
	}
}
