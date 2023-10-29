 /******************************************************************************
 *
 * Module: LM35 Sensor
 *
 * File Name: LM35_CONFIG.h
 *
 * Description: Header file for the LM35 Sensor Driver Macro Definitions
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef LM35_CONFIG_H_
#define LM35_CONFIG_H_

#include "../../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"
#include "../../MCAL/ADC_DRIVER/ADC_INTERFACE.h"

/*******************************************************************************
 *                              							Macro Definitions						                       		   *
 *******************************************************************************/

#define LM35_CHANNEL_ID	2
#define LM35_MAX_VOLT		1.5
#define LM35_MAX_TEMP		150

#define LM35_PORT					PORT_A
#define LM35_PIN						PIN_1


#endif /* LM35_CONFIG_H_ */
