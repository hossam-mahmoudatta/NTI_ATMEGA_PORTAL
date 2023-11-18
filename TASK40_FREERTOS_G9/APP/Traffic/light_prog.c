/*
 * Traffic_prog.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_APP_LIGHT != 0

#include "../../stdTypes.h"
#include "../../errorState.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "Update_int.h"
#include "light_config.h"
#include "../POV/POV_int.h"

typedef enum
{
    LIGHT_GREEN,
    LIGHT_YELLOW,
    LIGHT_RED,
}LightState_t;

static LightState_t LOC_enuLightStateMachine = LIGHT_GREEN;
static LightState_t LOC_enuPrevLightStateMachine = LIGHT_GREEN;

static BOOL LOC_bOneTimeAccess = FALSE;
static u8 LOC_u8SystemTime = 0;
static u16 LOC_u16TimeQualifier = 0;


void Light_vidInit(void)
{
    DIO_enuSetPinDirection(GREEN_LED , DIO_OUTPUT);
    DIO_enuSetPinDirection(YELLOW_LED , DIO_OUTPUT);
    DIO_enuSetPinDirection(RED_LED , DIO_OUTPUT);
    
    DIO_enuSetPinValue(GREEN_LED , DIO_LOW);
    DIO_enuSetPinValue(YELLOW_LED , DIO_LOW);
    DIO_enuSetPinValue(RED_LED , DIO_LOW);

}

void Light_vidTrafficTask(void)
{
    switch (LOC_enuLightStateMachine)
    {
    case LIGHT_GREEN:
        if (LOC_bOneTimeAccess == FALSE)
        {
            DIO_enuSetPinValue(GREEN_LED , DIO_HIGH);
            DIO_enuSetPinValue(YELLOW_LED , DIO_LOW);
            DIO_enuSetPinValue(RED_LED , DIO_LOW);
            LOC_u8SystemTime = Update_u8GetTrafficTime();
            POV_vidSetDisplayedNumber(LOC_u8SystemTime);
            LOC_u16TimeQualifier = ((LOC_u8SystemTime - 3) * 4) - 1 ;

            LOC_bOneTimeAccess = TRUE;
        }
        else
        {
            LOC_u16TimeQualifier--;
            POV_vidSetDisplayedNumber((LOC_u16TimeQualifier+12+1+3)/4);
            if (LOC_u16TimeQualifier == 0)
            {
                LOC_bOneTimeAccess = FALSE;
                LOC_enuPrevLightStateMachine = LIGHT_GREEN;
                LOC_enuLightStateMachine = LIGHT_YELLOW;
                LOC_u16TimeQualifier = 11;
            }
        }
        break;
    case LIGHT_YELLOW:
        LOC_u16TimeQualifier--;
        
        DIO_enuTogglePinValue(YELLOW_LED);
        POV_vidSetDisplayedNumber((LOC_u16TimeQualifier+3)/4);

        if (LOC_u16TimeQualifier == 0 )
        {
            if (LOC_enuPrevLightStateMachine == LIGHT_GREEN)
            {
                LOC_enuLightStateMachine = LIGHT_RED;
            } 
            else if (LOC_enuPrevLightStateMachine == LIGHT_RED)
            {
                LOC_enuLightStateMachine = LIGHT_GREEN;
            } 
            else
            {}  
        }
        break;
    case LIGHT_RED:
        if (LOC_bOneTimeAccess == FALSE)
        {
            DIO_enuSetPinValue(GREEN_LED , DIO_LOW);
            DIO_enuSetPinValue(YELLOW_LED , DIO_LOW);
            DIO_enuSetPinValue(RED_LED , DIO_HIGH);
            LOC_u8SystemTime = Update_u8GetTrafficTime();
            POV_vidSetDisplayedNumber(LOC_u8SystemTime);

            LOC_u16TimeQualifier = ((LOC_u8SystemTime - 3) * 4) -1 ;

            LOC_bOneTimeAccess = TRUE;
        }
        else
        {
            LOC_u16TimeQualifier--;
            POV_vidSetDisplayedNumber((LOC_u16TimeQualifier+16)/4);
            if (LOC_u16TimeQualifier == 0)
            {
                LOC_bOneTimeAccess = FALSE;
                LOC_enuPrevLightStateMachine = LIGHT_RED;
                LOC_enuLightStateMachine = LIGHT_YELLOW;
                LOC_u16TimeQualifier = 12;
            }
        }
        break;
    default:
        break;
    }
}


#endif