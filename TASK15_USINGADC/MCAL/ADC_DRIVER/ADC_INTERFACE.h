 /******************************************************************************
 *
 * Module: ADC (Analog to Digital Converter)
 *
 * File Name: ADC_INTERFACE.h
 *
 * Description: Header file for the AVR ADC Driver Function Prototypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_CONFIG.h"
#include "ADC_PRIVATE.h"

#include "../GLOBAL_INTERRUPT_DRIVER/GLOBAL_INTERRUPT_INTERFACE.h"
#include "../EXT_INTERRUPT_DRIVER/EXT_INTERRUPT_INTERFACE.h"

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the ADC Module to start functionality
void ADC_voidInit(void);

 // Reads the content written to the selected channel of the ADC
void ADC_u16readChannel(u8 copy_u8channelSelect);


#endif /* ADC_INTERFACE_H_ */

