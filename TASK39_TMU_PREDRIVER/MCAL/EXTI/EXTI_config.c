/*
 * EXTI_config.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Ahmed El-Gaafrawy
 */
//public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

//lower

//my own
#include "EXTI_config.h"
#include "EXTI_priv.h"

u8 EXTI_u8EXTIPinNum = EXTI_NUM_PINS;

EXTI_t EXTI_astrEXTIConfig [ EXTI_NUM_PINS ]=
    {
        {EXTI_INT0 , EXTI_RISING , EXTI_POLLING_MODE},
        {EXTI_INT2 , EXTI_RISING , EXTI_POLLING_MODE},
        {EXTI_INT1 , EXTI_RISING , EXTI_POLLING_MODE},
    };
