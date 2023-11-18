/*
 * Switch_prog.c
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

extern u8 Switch_u8MaxSwitchNum;
extern Switch_t Switch_astrSwitchConfig [];

ES_t Switch_enuInit(void)
{
    ES_t Local_enuErrorState = ES_NOK;
    u8 Local_u8Iter = 0;
    for (Local_u8Iter = 0 ; Local_u8Iter < Switch_u8MaxSwitchNum ; Local_u8Iter++)
    {
        Local_enuErrorState = DIO_enuSetPinDirection(Switch_astrSwitchConfig[Local_u8Iter].swGrp ,
                        Switch_astrSwitchConfig[Local_u8Iter].swPin , DIO_INPUT);
        if (Local_enuErrorState != ES_OK)
        {
            break;
        }
        Local_enuErrorState = DIO_enuSetPinValue(Switch_astrSwitchConfig[Local_u8Iter].swGrp ,
                        Switch_astrSwitchConfig[Local_u8Iter].swPin , Switch_astrSwitchConfig[Local_u8Iter].swState);
        if (Local_enuErrorState != ES_OK)
        {
            break;
        }
    }

    return Local_enuErrorState ;
}

ES_t Switch_enuGetSwitchState(u8 Copy_u8SwitchID , u8 *Copy_pu8SwitchState)
{
    ES_t Local_enuErrorState = ES_NOK;
    
    if (Copy_pu8SwitchState != NULL)
    {
        if (Copy_u8SwitchID < Switch_u8MaxSwitchNum)
        {
            Local_enuErrorState = DIO_enuGetPinValue(Switch_astrSwitchConfig[Copy_u8SwitchID].swGrp ,
                    Switch_astrSwitchConfig[Copy_u8SwitchID].swPin , Copy_pu8SwitchState);
        
        }
        else
        {
            Local_enuErrorState = ES_OUT_OF_RANGE;
        }
    }
    else
    {
        Local_enuErrorState = ES_NULL_POINTER;
    }
    
    return Local_enuErrorState ;
}
#endif