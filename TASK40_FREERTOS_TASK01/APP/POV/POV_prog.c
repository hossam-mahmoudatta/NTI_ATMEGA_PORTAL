/*
 * POV_prog.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_APP_POV != 0

#include "../../stdTypes.h"
#include "../../errorState.h"

#include "../../HAL/HexaDecoder/HexaDecoder_int.h"

#include <util/delay.h>


typedef enum
{
    POV_WRITE_FIRST,
    POV_DELAY_FIRST,
    POV_WRITE_SECOND,
    POV_DELAY_SECOND,
    POV_STOP_DISPLAY,
}POVState_t;


static POVState_t LOC_enuPOVStateMachine = POV_WRITE_FIRST; 
static u8 LOC_u8DisplayedNumber =0;

ES_t POV_enuInit(void)
{
   return HexaDec_enuInit();
}

void POV_vidDisplayTask(void)
{
    switch (LOC_enuPOVStateMachine)
    {
    case POV_WRITE_FIRST:
        HexaDec_enuDisableSSG(SSG_RIGHT);
        HexaDec_enuDisableSSG(SSG_LEFT);

        HexaDec_enuDisplayNum(LOC_u8DisplayedNumber % 10);
        HexaDec_enuEnableSSG(SSG_RIGHT);
        LOC_enuPOVStateMachine = POV_DELAY_FIRST;
        break;

    case POV_DELAY_FIRST:
        LOC_enuPOVStateMachine = POV_WRITE_SECOND;
        break;

    case POV_WRITE_SECOND:
        HexaDec_enuDisableSSG(SSG_RIGHT);

        HexaDec_enuDisplayNum(LOC_u8DisplayedNumber / 10);
        HexaDec_enuEnableSSG(SSG_LEFT);
        LOC_enuPOVStateMachine = POV_DELAY_SECOND;
        break;

    case POV_DELAY_SECOND:
        LOC_enuPOVStateMachine = POV_WRITE_FIRST;
        break;
    case POV_STOP_DISPLAY:
        HexaDec_enuDisableSSG(SSG_RIGHT);
        HexaDec_enuDisableSSG(SSG_LEFT);
        break;
    default:
        break;
    }
}

void POV_vidSetDisplayedNumber(u8 Copy_u8Number)
{
    LOC_u8DisplayedNumber = Copy_u8Number;
}

void POV_vidStopDisplay(void)
{
    LOC_enuPOVStateMachine = POV_STOP_DISPLAY;
}

void POV_vidResumeDisplay(void)
{
    LOC_enuPOVStateMachine = POV_WRITE_FIRST;
}


ES_t POV_enuDisplayNum(u8 Copy_u8Num)
{
    ES_t Local_enuErrorState = ES_NOK;

    if (Copy_u8Num <= 99)
    {
        HexaDec_enuDisableSSG(SSG_RIGHT);
        HexaDec_enuDisableSSG(SSG_LEFT);

        HexaDec_enuDisplayNum(Copy_u8Num % 10);
        HexaDec_enuEnableSSG(SSG_RIGHT);
        _delay_ms(10);

        HexaDec_enuDisableSSG(SSG_RIGHT);
        HexaDec_enuDisplayNum(Copy_u8Num / 10);
        HexaDec_enuEnableSSG(SSG_LEFT);
        _delay_ms(10);

        HexaDec_enuDisableSSG(SSG_LEFT);
    }
    else
    {
        Local_enuErrorState = ES_OUT_OF_RANGE;
    }
    return Local_enuErrorState;
}
#endif