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

#define ADMUX_REG		( *((volatile u8*) 0x27) )
#define ADCSRA_REG		( *((volatile u8*) 0x26) )
#define ADCH_REG			( *((volatile u8*) 0x25) )
#define ADCL_REG			( *((volatile u8*) 0x24) )
#define SFIOR_REG			( *((volatile u8*) 0x50) )

#endif /* MCAL_ADC_DRIVER_ADC_PRIVATE_H_ */
