/*
 * EXTI_prog.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_MCAL_EXTI != 0


//public
#include "../../stdTypes.h"
#include "../../errorState.h"

//lower

//my own
#include "EXTI_config.h"
#include "EXTI_priv.h"

// typedef char*   string;
// typedef void (*pvFUn)(void)      ;


extern u8 EXTI_u8EXTIPinNum;

extern EXTI_t EXTI_astrEXTIConfig [ ];

static void (*LOC_pfunISRFun[3])(void) = {NULL, NULL, NULL};
// static pvFUn ISR[3];

ES_t EXTI_enuInit(void)
{
    ES_t Local_enuErrorState = ES_NOK;

    u8 Local_u8Iter = 0;
    for (Local_u8Iter = 0 ; Local_u8Iter < EXTI_u8EXTIPinNum ; Local_u8Iter++)
    {
        enuSetIntMode   (EXTI_astrEXTIConfig[Local_u8Iter].intPin , EXTI_astrEXTIConfig[Local_u8Iter].intMode );
        enuSetSenseLevel(EXTI_astrEXTIConfig[Local_u8Iter].intPin , EXTI_astrEXTIConfig[Local_u8Iter].senseLevel );
    }

    return Local_enuErrorState;
}

ES_t EXTI_enuSetSenseLevel(u8 Copy_u8IntPin , u8 Copy_u8SenseLevel)
{
    ES_t Local_enuErrorState = ES_NOK;

    enuSetSenseLevel(Copy_u8IntPin , Copy_u8SenseLevel );

    return Local_enuErrorState;
}

ES_t EXTI_enuEnableInterrupt(u8 Copy_u8IntPin)
{
    ES_t Local_enuErrorState = ES_NOK;

    enuSetIntMode(Copy_u8IntPin, EXTI_INTERRUPT_MODE );

    return Local_enuErrorState;
}

ES_t EXTI_enuDisableInterrupt(u8 Copy_u8IntPin)
{
    ES_t Local_enuErrorState = ES_NOK;

    enuSetIntMode(Copy_u8IntPin, EXTI_POLLING_MODE );

    return Local_enuErrorState;
}

ES_t EXTI_enuSetCallBack(u8 Copy_u8IntPin , void(*Copy_pFunAppFun)(void))
{
    ES_t Local_enuErrorState = ES_NOK;

    if (Copy_pFunAppFun != NULL)
    {
        LOC_pfunISRFun[Copy_u8IntPin] = Copy_pFunAppFun;
    }
    else
    {
        Local_enuErrorState = ES_NULL_POINTER;
    }

    return Local_enuErrorState;
}


void __vector_1 (void)__attribute__((signal));
void __vector_2 (void)__attribute__((signal));
void __vector_3 (void)__attribute__((signal));
//INT0
void __vector_1 (void)
{
    if(LOC_pfunISRFun[EXTI_INT0] != NULL)
    {
        LOC_pfunISRFun[EXTI_INT0] ();
    }
}
//INT1
void __vector_2 (void)
{
    if(LOC_pfunISRFun[EXTI_INT1] != NULL)
    {
        LOC_pfunISRFun[EXTI_INT1] ();
    }
}
//INT2
void __vector_3 (void)
{
    if(LOC_pfunISRFun[EXTI_INT2] != NULL)
    {
        LOC_pfunISRFun[EXTI_INT2] ();
    }
    
}


static ES_t enuSetIntMode(u8 Copy_u8IntPin, u8 Copy_u8IntMode)
{
    switch (Copy_u8IntPin)
    {
        case EXTI_INT0:
            if (Copy_u8IntMode == EXTI_INTERRUPT_MODE)
            {
                GICR |= (1<<6);
            }
            else 
            {
                GICR &=~ (1<<6);
            }
            break;
            
        case EXTI_INT1:
            if (Copy_u8IntMode == EXTI_INTERRUPT_MODE)
            {
                GICR |= (1<<7);
            }
            else 
            {
                GICR &=~ (1<<7);
            }
            break;

        case EXTI_INT2:
            if (Copy_u8IntMode == EXTI_INTERRUPT_MODE)
            {
                GICR |= (1<<5);
            }
            else 
            {
                GICR &=~ (1<<6);
            }
            break;
    }
    return ES_OK;
}
static ES_t enuSetSenseLevel(u8 Copy_u8IntPin, u8 Copy_u8SenseLevel)
{
    switch (Copy_u8IntPin)
    {
        case EXTI_INT0:
            if (Copy_u8SenseLevel == EXTI_LOW_LEVEL)
            {
                MCUCR &= ~(3<<0);
            }
            else if (Copy_u8SenseLevel == EXTI_ANY_CHANGE)
            {
                MCUCR &= ~(3<<0);
                MCUCR |=  (1<<0);
            }
            else if (Copy_u8SenseLevel == EXTI_FALLING)
            {
                MCUCR &= ~(3<<0);
                MCUCR |=  (1<<1);
            }
            else if (Copy_u8SenseLevel == EXTI_RISING)
            {
                MCUCR |=  (3<<0);
            }
            else 
            {
            }
            break;
            
        case EXTI_INT1:
            if (Copy_u8SenseLevel == EXTI_LOW_LEVEL)
            {
                MCUCR &= ~(3<<2);
            }
            else if (Copy_u8SenseLevel == EXTI_ANY_CHANGE)
            {
                MCUCR &= ~(3<<2);
                MCUCR |=  (1<<2);
            }
            else if (Copy_u8SenseLevel == EXTI_FALLING)
            {
                MCUCR &= ~(3<<2);
                MCUCR |=  (1<<3);
            }
            else if (Copy_u8SenseLevel == EXTI_RISING)
            {
                MCUCR |=  (3<<2);
            }
            else 
            {
            }
            break;

        case EXTI_INT2:
            if (Copy_u8SenseLevel == EXTI_FALLING)
            {
                MCUCSR &= ~(1<<6);
            }
            else if (Copy_u8SenseLevel == EXTI_RISING)
            {
                MCUCSR |=  (1<<6);
            }
            else 
            {
            }
            break;
    }
    return ES_OK;
}
#endif