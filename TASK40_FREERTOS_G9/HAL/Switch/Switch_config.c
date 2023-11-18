/*
 * Switch_config.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_HAL_SWITCH != 0


#include "../../stdTypes.h"
#include "../../errorState.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Switch_config.h"
#include "Switch_priv.h"

u8 Switch_u8MaxSwitchNum = SWITCH_MAX_NUM;

Switch_t Switch_astrSwitchConfig [ SWITCH_MAX_NUM ] =
            {
                {DIO_GROUP_D , DIO_PIN_7 , DIO_FLOAT}, //sw0
                {DIO_GROUP_D , DIO_PIN_6 , DIO_FLOAT}, //sw1
                {DIO_GROUP_A , DIO_PIN_3 , DIO_FLOAT}  //sw2
            };

#endif
