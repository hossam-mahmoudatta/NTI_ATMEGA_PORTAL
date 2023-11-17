/*
 * ADC_prog.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"


#include "ADC_config.h"
#include "ADC_priv.h"

static void (*LOC_pfunISRFun)(void*) = NULL;
static void *LOC_pvidParameter = NULL;


ES_t ADC_enuInit(void)
{
    ADCSRA &= (0xF8);
    #if ADC_PRESCALER >= ADC_PRES_2 && ADC_PRESCALER <= ADC_PRES_128
        ADCSRA |= ADC_PRESCALER;
    #else   
        #error ADC prescaler configuration is invalid
    #endif

    #if ADC_ADJUSTMENT == ADC_LEFT_ADJ
        ADMUX |= (1<<5);
    #elif ADC_ADJUSTMENT == ADC_RIGHT_ADJ
        ADMUX &=~(1<<5);
    #else
        #error ADC Adjusment configuration is invalid
    #endif

    ADMUX &= (0x3F); // ADMUX &= ~(0xC0); // ADMUX &= ~(3<<6);
    #if ADC_V_REFERENCE == ADC_V_AREF
        ADMUX &= (0x3F);
    #elif ADC_V_REFERENCE == ADC_V_AVCC
        ADMUX |= (1<<6);
    #elif ADC_V_REFERENCE == ADC_V_INTERNAL
        ADMUX |= (3<<6);
    #else
        #error ADC voltage reference configuration is invalid
    #endif

    ADMUX &= (0xE0); //ADMUX &= ~(0x1F);
    #if ADC_INIT_CHANNEL >= 0 && ADC_INIT_CHANNEL <= 31
        ADMUX |= ADC_INIT_CHANNEL;
    #else
        #error ADC init channel number is invalid
    #endif

    #if ADC_INTERRUPT_MODE == ADC_INTERRUPT
        ADCSRA |= (1<<3);
    #elif ADC_INTERRUPT_MODE == ADC_POLLING
        ADCSRA &=~(1<<3);
    #else
        #error ADC interrupt mode configuration is invalid
    #endif

    #if ADC_TRIGGER_SOURCE == ADC_SINGLE_CONV 
        ADCSRA &=~(1<<5);
    #elif (ADC_TRIGGER_SOURCE >= ADC_FREE_RUNNING_CONV && ADC_TRIGGER_SOURCE <= 17)
        ADCSRA &=~(1<<5);

        SFIOR &= (0x1F);
        SFIOR |= ((ADC_TRIGGER_SOURCE-10) << 5);

        ADCSRA |= (1<<5);
    #else
        #error ADC auto trigger mode configuration is invalid
    #endif

    ADCSRA |= (1<<7);

    return ES_OK;
}

ES_t ADC_enuReadPolling(u8 Copy_u8Channel , u16 * Copy_pu16ADCRead)
{
    //clear flag
    ADCSRA |= (1<<4);
    //start conv
    ADCSRA |= (1<<6);

    if (Copy_u8Channel <= 31)
    {
        ADMUX &= (0xE0); //ADMUX &= ~(0x1F);
        ADMUX |= Copy_u8Channel;

        while (((ADCSRA >> 4)& 1) == FALSE);

        #if ADC_ADJUSTMENT == ADC_LEFT_ADJ
            *Copy_pu16ADCRead = (ADCL >> 6);
            *Copy_pu16ADCRead |= ((u16)ADCH << 2);
        #elif ADC_ADJUSTMENT == ADC_RIGHT_ADJ
            *Copy_pu16ADCRead = ADCL;
            *Copy_pu16ADCRead |= ((u16)ADCH << 8);
        #endif
        //clear flag
        ADCSRA |= (1<<4);
    }    
    return ES_OK;
}

ES_t ADC_enuStartConversion(void)
{
    ADCSRA |= (1<<6);
    return ES_OK;
}

ES_t ADC_enuSetADCChannel(u8 Copy_u8Channel)
{
    if (Copy_u8Channel <= 31)
    {
        ADMUX &= (0xE0); //ADMUX &= ~(0x1F);
        ADMUX |= Copy_u8Channel;
    }
    return ES_OK;
}

ES_t ADC_enuRead(u16 * Copy_pu16ADCRead)
{
    if (Copy_pu16ADCRead != NULL)
    {
        #if ADC_ADJUSTMENT == ADC_LEFT_ADJ
            *Copy_pu16ADCRead = (ADCL >> 6);
            *Copy_pu16ADCRead |= ((u16)ADCH << 2);
            #warning ADC_enuRead is not working speedly in LEFT ADJ
        #elif ADC_ADJUSTMENT == ADC_RIGHT_ADJ
            *Copy_pu16ADCRead = ADCL;
            *Copy_pu16ADCRead |= ((u16)ADCH << 8);
        #endif
    }
    return ES_OK;
}

ES_t ADC_enuReadHigh(u8 * Copy_pu8ADCRead)
{
    if (Copy_pu8ADCRead != NULL)
    {
        #if ADC_ADJUSTMENT == ADC_LEFT_ADJ
            *Copy_pu8ADCRead = ADCH ;
        #elif ADC_ADJUSTMENT == ADC_RIGHT_ADJ
            *Copy_pu8ADCRead = (ADCL>>2);
            *Copy_pu8ADCRead |= (ADCH << 6);
            #warning ADC_enuReadHigh is not working speedly in RIGHT ADJ
        #endif
    }
    return ES_OK;
}

ES_t ADC_enuSetTriggerSource(u8 Copy_u8TriggerSource)
{
    if (Copy_u8TriggerSource >= ADC_FREE_RUNNING_CONV && Copy_u8TriggerSource <= 17)
    {
        ADCSRA &=~(1<<5);

        SFIOR &= (0x1F);
        SFIOR |= ((Copy_u8TriggerSource-10) << 5);

        ADCSRA |= (1<<5);
    }
    return ES_OK;
}

ES_t ADC_enuClearTriggerSource(void)
{
    ADCSRA &=~(1<<5);
    return ES_OK;
}

ES_t ADC_enuSetCallBack(void (*Copy_pfunAppFun)(void*), void * Copy_pvidParameter)
{
    if (Copy_pfunAppFun != NULL)
    {
        LOC_pfunISRFun = Copy_pfunAppFun;
        LOC_pvidParameter = Copy_pvidParameter;
    }
    return ES_OK;
}

ES_t ADC_enuEnableInterrupt(void)
{
    ADCSRA |= (1<<3);
    return ES_OK;
}
ES_t ADC_enuDisableInterrupt(void)
{
    ADCSRA &=~(1<<3);
    return ES_OK;
}

ES_t ADC_enuEnable(void)
{
    ADCSRA |= (1<<7);
    return ES_OK;
}
ES_t ADC_enuDisable(void)
{
    ADCSRA &=~(1<<7);
    return ES_OK;
}


void __vector_16 (void)__attribute__((signal));
void __vector_16 (void)
{
    if (LOC_pfunISRFun != NULL)
    {
        LOC_pfunISRFun (LOC_pvidParameter);
    }
}
