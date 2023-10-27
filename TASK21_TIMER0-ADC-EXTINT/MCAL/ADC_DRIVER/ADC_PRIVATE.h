 /******************************************************************************
 *
 * Module: ADC (Analog to Digital Converter)
 *
 * File Name: ADC_PRIVATE.h
 *
 * Description: Header file for the AVR ADC Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef MCAL_ADC_DRIVER_ADC_PRIVATE_H_
#define MCAL_ADC_DRIVER_ADC_PRIVATE_H_

#include "../GPIO_DRIVER/GPIO_INTERFACE.h"

/*******************************************************************************
 *                              					External Interrupts Registers					                   	   *
 *******************************************************************************/

typedef struct {
	u8 MUX: 		5;		// ADC has 8 channels, choose ch0 = '00000'
	u8 ADLAR: 	1;	// Set it to '0' for Right Adjust Result
	u8 REFS: 		2;	// Select REFS1:0 to choose volt reference, choose '01' for AVCC
} ADMUX;
#define ADMUX_REG	 ((volatile ADMUX*) 0x27)

typedef struct {
	u8 ADPS: 3; // ADC Prescaler Config, choose the prescaler settings, set to '111' to be 128
	u8 ADIE: 1; // ADC Interrupt Enable, Enables the interrupt if set to 1
	u8 ADIF: 1;	// ADC Interrupt Flag, if we used interrupts with ADC, this is the flag we use
	u8 ADATE: 1;	// Auto Triggering, set it to '0', we won't use the automatic
	u8 ADSC: 1;		// Starts the conversion, bit is '1' when conversion and turns into '0' when complete
	u8 ADEN: 1;		// ADC Enable, set it to '1' to enable the ADC
} ADSCRA;
#define ADCSRA_REG		((volatile ADSCRA*) 0x26)

typedef struct {
	u8 : 5;
	u8 ADTS: 3;
} SFIOR;
#define SFIOR_REG			((volatile SFIOR*) 0x50)


#define ADCH_REG			( *((volatile u8*) 0x25) )
#define ADCL_REG			( *((volatile u8*) 0x24) )
#define ADC_DATA_REG	( *((volatile u16*) 0x24) )


#endif /* MCAL_ADC_DRIVER_ADC_PRIVATE_H_ */
