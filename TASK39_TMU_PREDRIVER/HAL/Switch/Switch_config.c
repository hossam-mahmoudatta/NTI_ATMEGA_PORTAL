/*
 * Switch_config.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Switch_config.h"
#include "Switch_priv.h"


u8 Switch_u8MaxSwitchNum = SWITCH_MAX_NUM;

Switch_t Switch_astrSwitchConfig [ SWITCH_MAX_NUM ] =
            {
                {DIO_GROUP_B , DIO_PIN_0 , DIO_PULL_UP}, //sw0
                {DIO_GROUP_B , DIO_PIN_1 , DIO_PULL_UP}, //sw1
                {DIO_GROUP_B , DIO_PIN_2 , DIO_FLOAT}  	//sw2
            };

