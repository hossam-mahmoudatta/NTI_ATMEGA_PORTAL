/*
 * light_config.h
 *
 *  Created on: Oct 7, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef APP_TRAFFIC_LIGHT_CONFIG_H_
#define APP_TRAFFIC_LIGHT_CONFIG_H_


#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../TMU/TMU_int.h"


#define GREEN_LED           	DIO_GROUP_A , 	DIO_PIN_0
#define YELLOW_LED			DIO_GROUP_A , 	DIO_PIN_1
#define RED_LED             	DIO_GROUP_A , 	DIO_PIN_2

#endif /* APP_TRAFFIC_LIGHT_CONFIG_H_ */
