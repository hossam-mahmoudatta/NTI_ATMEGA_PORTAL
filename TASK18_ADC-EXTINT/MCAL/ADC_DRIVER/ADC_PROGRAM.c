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
	// Sets REFS1:0 to '01'
	ADMUX_REG->REFS = AVCC;
	ADMUX_REG->ADLAR = RIGHT_ADJUST;

	// Enables ADC & Choose Prescaler of 128
	ADCSRA_REG->ADEN = ADEN_ENABLE;
	ADCSRA_REG->ADPS = PRESCALER_128;
	ADCSRA_REG->ADATE = ENABLE_TRIGGER;
	SFIOR_REG->ADTS = EXT_INTERRUPT;


//#if(TRIGGER_STATUS == ENABLE_TRIGGER)
//	SFIOR_REG->ADTS = TRIGGER_SETTING;
//#elif(TRIGGER_STATUS == DISABLE_TRIGGER)
//	SFIOR_REG->ADTS = FREE_RUNNING;
//#endif

	/* ADCSRA Register Bits Description:
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
	ADCSRA_REG->ADIE = ENABLE_INTERRUPT;

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
