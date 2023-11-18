/*
 * Keypad_prog.c
 *
 *  Created on: Sep 15, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_HAL_KEYPAD != 0


// public 
#include "../../stdTypes.h"
#include "../../errorState.h"


//lower 
#include "../../MCAL/DIO/DIO_int.h"

//my own
#include "Keypad_config.h"
#include "Keypad_priv.h"

#include <util/delay.h>

#if KEYPAD_ROW_NUM > 0 && KEYPAD_ROW_NUM <= 4 && KEYPAD_COL_NUM > 0 && KEYPAD_COL_NUM <= 4
#else
    #error keypad col & row is not valid 
#endif

ES_t Keypad_enuInit(void)
{
    u8 Local_au8RowGrp [4] = {R1_GRP,R2_GRP,R3_GRP,R4_GRP};
    u8 Local_au8RowPin [4] = {R1_PIN,R2_PIN,R3_PIN,R4_PIN};

    u8 Local_au8ColGrp [4] = {C1_GRP,C2_GRP,C3_GRP,C4_GRP};
    u8 Local_au8ColPin [4] = {C1_PIN,C2_PIN,C3_PIN,C4_PIN};
    u8 Local_u8Iter =0;

    for (Local_u8Iter = 0 ; Local_u8Iter <KEYPAD_ROW_NUM ; Local_u8Iter ++)
    {
        DIO_enuSetPinDirection(Local_au8RowGrp[Local_u8Iter], Local_au8RowPin[Local_u8Iter] , DIO_INPUT);
        DIO_enuSetPinValue(Local_au8RowGrp[Local_u8Iter], Local_au8RowPin[Local_u8Iter] , DIO_PULL_UP);
    }
    
    for (Local_u8Iter = 0 ; Local_u8Iter <KEYPAD_ROW_NUM ; Local_u8Iter ++)
    {
        DIO_enuSetPinDirection(Local_au8ColGrp[Local_u8Iter], Local_au8ColPin[Local_u8Iter] , DIO_OUTPUT);
        DIO_enuSetPinValue(Local_au8ColGrp[Local_u8Iter], Local_au8ColPin[Local_u8Iter] , DIO_HIGH);
    }
    return ES_OK;
}

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue)
{
    u8 Local_au8RowGrp [4] = {R1_GRP,R2_GRP,R3_GRP,R4_GRP};
    u8 Local_au8RowPin [4] = {R1_PIN,R2_PIN,R3_PIN,R4_PIN};

    u8 Local_au8ColGrp [4] = {C1_GRP,C2_GRP,C3_GRP,C4_GRP};
    u8 Local_au8ColPin [4] = {C1_PIN,C2_PIN,C3_PIN,C4_PIN};

    u8 Local_u8RowIter = 0 ;
    u8 Local_u8ColIter = 0 ;

    *Copy_pu8KeyValue = 0xFF ;
    u8 Local_u8PinValue = 0xFF ;
    BOOL Local_bBreakFlag = FALSE;

    for (Local_u8ColIter=0; Local_u8ColIter < KEYPAD_COL_NUM; Local_u8ColIter++)
    {
        DIO_enuSetPinValue(Local_au8ColGrp[Local_u8ColIter], Local_au8ColPin[Local_u8ColIter], DIO_LOW);

        for (Local_u8RowIter =0 ; Local_u8RowIter <KEYPAD_ROW_NUM ; Local_u8RowIter++)
        {
            DIO_enuGetPinValue(Local_au8RowGrp[Local_u8RowIter], Local_au8RowPin[Local_u8RowIter],&Local_u8PinValue);
            if (Local_u8PinValue == DIO_LOW)
            {
                _delay_ms(3);
                DIO_enuGetPinValue(Local_au8RowGrp[Local_u8RowIter], Local_au8RowPin[Local_u8RowIter],&Local_u8PinValue);
                if (Local_u8PinValue == DIO_LOW)
                {
                    // take action
                    u8 Local_au8KeyValues[KEYPAD_ROW_NUM][KEYPAD_COL_NUM] = KEYPAD_KEY_VALUES;
                    
                    *Copy_pu8KeyValue = Local_au8KeyValues[Local_u8RowIter][Local_u8ColIter];
                    while (Local_u8PinValue == DIO_LOW)
                        DIO_enuGetPinValue(Local_au8RowGrp[Local_u8RowIter], Local_au8RowPin[Local_u8RowIter],&Local_u8PinValue);
                    Local_bBreakFlag = TRUE;
                    break;
                }
            }
        }

        DIO_enuSetPinValue(Local_au8ColGrp[Local_u8ColIter], Local_au8ColPin[Local_u8ColIter], DIO_HIGH);
        if (Local_bBreakFlag == TRUE)
            break;
    }
    return ES_OK;
}




#endif