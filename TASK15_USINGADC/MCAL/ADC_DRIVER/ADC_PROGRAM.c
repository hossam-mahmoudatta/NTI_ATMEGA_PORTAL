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

	volatile u16 glob_ADCResult = 0;

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
	SET_BIT(ADMUX_REG, ADMUX_REFS0);

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

	// Enables ADC & Choose Prescaler of 128
	ADCSRA_REG |= (1 << ADCSRA_ADEN) | (1 << ADCSRA_ADPS2) | (1 << ADCSRA_ADPS1) | (1 << ADCSRA_ADPS0);
}


// Reads the content written to the selected channel of the ADC
void ADC_u16readChannel(u8 copy_u8channelSelect) {
	// Insert Channel Number in ADMUX Procedure
	// Initializes & clears first 5 bits to zero
	ADMUX_REG &= 0xE0;		// 0b1110 0000

	// Mask the Input Channel ID with Max Channel Numbers, which are 8 channels
	copy_u8channelSelect &= 0x07; // 0b0000 0111

	// Insert Channel no. into ADMUX Register
	ADMUX_REG |= copy_u8channelSelect;

	// Starts ADC Conversion
	SET_BIT(ADCSRA_REG, ADCSRA_ADSC);

#if (ADC_INT_MODE == ADC_POLLING)
	// Busy wait (Polling) untill ADIF = 1
	while ( BIT_IS_CLR(ADCSRA_REG, ADCSRA_ADIF) );

	// Set Interrupt Flag by 1 by clearing it
	ADCSRA_REG |= (1 << ADCSRA_ADIF);

	// Read Data from ADCL Bits 0 -> 9
	glob_ADCResult = ADCL_REG;
#else
	ADCSRA_REG |= (1 << ADCSRA_ADIE);
#endif

}

