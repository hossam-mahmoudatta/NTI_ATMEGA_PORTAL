/*
 * DIO_prog.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed El-Gaafrawy
 */
//Public libraries 
#include "../../LIB/stdTypes.h"
// #include "Bit_Math.h"
#include "../../LIB/errorState.h"

//Lower Layer interfaces

//my own libraries
#include "DIO_config.h"
#include "DIO_priv.h"


ES_t DIO_enuInit(void)
{
    ES_t Local_enuErrorState = ES_NOK;

//10111010
//    DDRA = DIO_CONC(DIO_PA7_DIR , DIO_PA6_DIR , DIO_PA5_DIR , DIO_PA4_DIR , DIO_PA3_DIR, DIO_PA2_DIR, DIO_PA1_DIR,DIO_PA0_DIR);

    return Local_enuErrorState;
}

ES_t DIO_enuSetPinDirection(u8 Copy_u8GroupID , u8 Copy_u8PinID , u8 Copy_u8Direction)
{
    ES_t Local_enuErrorState = ES_NOK;

    if ((Copy_u8GroupID <= DIO_GROUP_D) && (Copy_u8PinID <= DIO_PIN_7)
            && (Copy_u8Direction <= DIO_OUTPUT))
    {
        switch(Copy_u8GroupID)
        {
            case DIO_GROUP_A:
                DDRA &= ~(DIO_MASK_BIT << Copy_u8PinID);
                DDRA |=  (Copy_u8Direction << Copy_u8PinID);
            break;

            case DIO_GROUP_B:
                DDRB &= ~(DIO_MASK_BIT << Copy_u8PinID);
                DDRB |=  (Copy_u8Direction << Copy_u8PinID);
            break;

            case DIO_GROUP_C:
                DDRC &= ~(DIO_MASK_BIT << Copy_u8PinID);
                DDRC |=  (Copy_u8Direction << Copy_u8PinID);
            break;
            
            case DIO_GROUP_D:
                DDRD &= ~(DIO_MASK_BIT << Copy_u8PinID);
                DDRD |=  (Copy_u8Direction << Copy_u8PinID);
            break;

            default:
            break;
        }
        Local_enuErrorState = ES_OK;
    }
    else
    {
        Local_enuErrorState = ES_OUT_OF_RANGE;
    }

    return Local_enuErrorState;
}

ES_t DIO_enuSetPinValue(u8 Copy_u8GroupID , u8 Copy_u8PinID , u8 Copy_u8Value)
{
    ES_t Local_enuErrorState = ES_NOK;

        if ((Copy_u8GroupID <= DIO_GROUP_D) && (Copy_u8PinID <= DIO_PIN_7)
            && (Copy_u8Value <= DIO_HIGH))
    {
        switch(Copy_u8GroupID)
        {
            case DIO_GROUP_A:
                if(Copy_u8Value == DIO_HIGH)
                {
                    PORTA |=  (DIO_MASK_BIT << Copy_u8PinID);
//                	asm("sbi 0x1b, %I" "\n\t"
//							:"I" (Copy_u8PinID)
//							);
                }
                else
                {
                    PORTA &= ~(DIO_MASK_BIT << Copy_u8PinID);
                }
            break;

            case DIO_GROUP_B:
                PORTB = (Copy_u8Value == DIO_HIGH)? (PORTB | (DIO_MASK_BIT<<Copy_u8PinID)) : (PORTB &  (~(DIO_MASK_BIT<<Copy_u8PinID)));
            break;

            case DIO_GROUP_C:
                if(Copy_u8Value == DIO_HIGH)
                {
                    PORTC |=  (DIO_MASK_BIT << Copy_u8PinID);
                }
                else
                {
                    PORTC &= ~(DIO_MASK_BIT << Copy_u8PinID);
                }
                break;
            
            case DIO_GROUP_D:
                if(Copy_u8Value == DIO_HIGH)
                {
                    PORTD |=  (DIO_MASK_BIT << Copy_u8PinID);
                }
                else
                {
                    PORTD &= ~(DIO_MASK_BIT << Copy_u8PinID);
                }
                break;

            default:
            break;
        }
        Local_enuErrorState = ES_OK;
    }
    else
    {
        Local_enuErrorState = ES_OUT_OF_RANGE;
    }

    return Local_enuErrorState;
}

ES_t DIO_enuTogglePinValue(u8 Copy_u8GroupID , u8 Copy_u8PinID)
{
    ES_t Local_enuErrorState = ES_NOK;

    if ((Copy_u8GroupID <= DIO_GROUP_D) && (Copy_u8PinID <= DIO_PIN_7))
    {
        switch(Copy_u8GroupID)
        {
            case DIO_GROUP_A:
                PORTA ^= (DIO_MASK_BIT <<Copy_u8PinID);
            break;

            case DIO_GROUP_B:
                PORTB ^= (DIO_MASK_BIT <<Copy_u8PinID);
            break;

            case DIO_GROUP_C:
                PORTC ^= (DIO_MASK_BIT <<Copy_u8PinID);
            break;
            
            case DIO_GROUP_D:
                PORTD ^= (DIO_MASK_BIT <<Copy_u8PinID);
            break;

            default:
            break;
        }
        Local_enuErrorState = ES_OK;
    }
    else
    {
        Local_enuErrorState = ES_OUT_OF_RANGE;
    }

    return Local_enuErrorState;
}

ES_t DIO_enuGetPinValue(u8 Copy_u8GroupID , u8 Copy_u8PinID , u8 * Copy_pu8PinValue)
{
    ES_t Local_enuErrorState = ES_NOK;

    if (Copy_pu8PinValue != NULL)
    {
        if ((Copy_u8GroupID <= DIO_GROUP_D) && (Copy_u8PinID <= DIO_PIN_7))
        {
            switch(Copy_u8GroupID)
            {
                case DIO_GROUP_A:
                    *Copy_pu8PinValue = ((PINA >> Copy_u8PinID) & DIO_MASK_BIT);
                break;

                case DIO_GROUP_B:
                    *Copy_pu8PinValue = ((PINB >> Copy_u8PinID) & DIO_MASK_BIT);
                break;

                case DIO_GROUP_C:
                    *Copy_pu8PinValue = ((PINC >> Copy_u8PinID) & DIO_MASK_BIT);
                break;
                
                case DIO_GROUP_D:
                    *Copy_pu8PinValue = ((PIND >> Copy_u8PinID) & DIO_MASK_BIT);
                break;

                default:
                break;
            }
            Local_enuErrorState = ES_OK;
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

    return Local_enuErrorState;
}

