 /******************************************************************************
 *
 * Module: LM35 Sensor
 *
 * File Name: LM35_INTERFACE.h
 *
 * Description: Header file for the LM35 Sensor Driver Function Prototypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#include "LM35_CONFIG.h"

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the ADC Module to start functionality
u8 LM35_u8getTemperature(void);


#endif /* LM35_INTERFACE_H_ */

