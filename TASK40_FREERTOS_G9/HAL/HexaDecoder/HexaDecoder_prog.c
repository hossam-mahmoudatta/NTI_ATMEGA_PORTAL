/*
 * HexaDecoder_prog.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../stdTypes.h"
#include "../../errorState.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "HexaDecoder_config.h"
#include "HexaDecoder_priv.h"

#if SSG_HW_CONFIG == SSG_PINS
static volatile const LOC_au8CommonCathodeValues []=
						{	0x3f,0x06,0x5B,0x4F,0x66,
							0x6D,0x7D,0x07,0x7F,0x6F,0x77,
							0x7C,0x39,0x5E,0x79,0x71
						};
#endif

ES_t HexaDec_enuInit(void)
{
    ES_t Local_enuErrorState = ES_NOK;

    #if HEX_DEC_A_PIN <= DIO_PIN_7 &&HEX_DEC_B_PIN <= DIO_PIN_7 &&HEX_DEC_C_PIN <= DIO_PIN_7 &&HEX_DEC_D_PIN <= DIO_PIN_7 && HEX_DEC_EN1_PIN <= DIO_PIN_7&& HEX_DEC_EN2_PIN <= DIO_PIN_7
        #if HEX_DEC_A_GRP <=DIO_GROUP_D && HEX_DEC_B_GRP <=DIO_GROUP_D && HEX_DEC_C_GRP <=DIO_GROUP_D && HEX_DEC_D_GRP <=DIO_GROUP_D && HEX_DEC_EN1_GRP <=DIO_GROUP_D && HEX_DEC_EN2_GRP <=DIO_GROUP_D   
            
            ES_t Local_aenuErrors [6] = {0};
            Local_aenuErrors[0]=DIO_enuSetPinDirection(HEX_DEC_A_GRP , HEX_DEC_A_PIN , DIO_OUTPUT);
            Local_aenuErrors[1]=DIO_enuSetPinDirection(HEX_DEC_B_GRP , HEX_DEC_B_PIN , DIO_OUTPUT);
            Local_aenuErrors[2]=DIO_enuSetPinDirection(HEX_DEC_C_GRP , HEX_DEC_C_PIN , DIO_OUTPUT);
            Local_aenuErrors[3]=DIO_enuSetPinDirection(HEX_DEC_D_GRP , HEX_DEC_D_PIN , DIO_OUTPUT);

            Local_aenuErrors[4]=DIO_enuSetPinDirection(HEX_DEC_EN1_GRP , HEX_DEC_EN1_PIN , DIO_OUTPUT);
            Local_aenuErrors[5]=DIO_enuSetPinDirection(HEX_DEC_EN2_GRP , HEX_DEC_EN2_PIN , DIO_OUTPUT);
            #if SSG_HW_CONFIG == SSG_PINS_ANODE || SSG_HW_CONFIG == SSG_PINS_ANODE 
                DIO_enuSetPinDirection(HEX_DEC_E_GRP , HEX_DEC_E_PIN , DIO_OUTPUT);
                DIO_enuSetPinDirection(HEX_DEC_F_GRP , HEX_DEC_F_PIN , DIO_OUTPUT);
                DIO_enuSetPinDirection(HEX_DEC_G_GRP , HEX_DEC_G_PIN , DIO_OUTPUT);
            #endif
            for (u8 i =0 ; i<6 ; i++)
            {
                if (Local_aenuErrors[i] != ES_OK)
                {
                    Local_enuErrorState = Local_aenuErrors[i];
                    break;
                }
            }
        #else
            #error hexa group config is out of range 
        #endif
    #else
        #error hexa pins config is out of range 
    #endif
    return Local_enuErrorState;
}

ES_t HexaDec_enuDisplayNum(u8 Copy_u8Num)
{
    ES_t Local_enuErrorState = ES_NOK;
#if SSG_HW_CONFIG == SSG_PINS_CATHODE || SSG_HW_CONFIG == SSG_PINS_ANODE
    if (Copy_u8Num <= 15)
    {
        #if SSG_HW_CONFIG == SSG_PINS_ANODE
            Copy_u8Num = ~ LOC_au8CommonCathodeValues[Copy_u8Num];
        #else
            Copy_u8Num = LOC_au8CommonCathodeValues[Copy_u8Num];
        #endif
        DIO_enuSetPinValue(HEX_DEC_A_GRP , HEX_DEC_A_PIN , ((Copy_u8Num >> 0) & 1));
        DIO_enuSetPinValue(HEX_DEC_B_GRP , HEX_DEC_B_PIN , ((Copy_u8Num >> 1) & 1));
        DIO_enuSetPinValue(HEX_DEC_C_GRP , HEX_DEC_C_PIN , ((Copy_u8Num >> 2) & 1));
        DIO_enuSetPinValue(HEX_DEC_D_GRP , HEX_DEC_D_PIN , ((Copy_u8Num >> 3) & 1));
        DIO_enuSetPinValue(HEX_DEC_E_GRP , HEX_DEC_E_PIN , ((Copy_u8Num >> 4) & 1));
        DIO_enuSetPinValue(HEX_DEC_F_GRP , HEX_DEC_F_PIN , ((Copy_u8Num >> 5) & 1));
        DIO_enuSetPinValue(HEX_DEC_G_GRP , HEX_DEC_G_PIN , ((Copy_u8Num >> 6) & 1));
    }
    else
    {
        Local_enuErrorState = ES_OUT_OF_RANGE;
    }
#else
    if (Copy_u8Num <= 9)
    {
        DIO_enuSetPinValue(HEX_DEC_A_GRP , HEX_DEC_A_PIN , ((Copy_u8Num>> 0 )& 1));
        DIO_enuSetPinValue(HEX_DEC_B_GRP , HEX_DEC_B_PIN , ((Copy_u8Num>> 1 )& 1));
        DIO_enuSetPinValue(HEX_DEC_C_GRP , HEX_DEC_C_PIN , ((Copy_u8Num>> 2 )& 1));
        DIO_enuSetPinValue(HEX_DEC_D_GRP , HEX_DEC_D_PIN , ((Copy_u8Num>> 3 )& 1));
    }
    else
    {
        Local_enuErrorState = ES_OUT_OF_RANGE;
    }
#endif
    return Local_enuErrorState;
}


ES_t HexaDec_enuEnableSSG(u8 Copy_u8SSGNum)
{
    ES_t Local_enuErrorState = ES_NOK;

    if (Copy_u8SSGNum == SSG_RIGHT)
    {
        Local_enuErrorState = DIO_enuSetPinValue(HEX_DEC_EN1_GRP , HEX_DEC_EN1_PIN , DIO_HIGH);
    }
    else if (Copy_u8SSGNum == SSG_LEFT)
    {
        Local_enuErrorState = DIO_enuSetPinValue(HEX_DEC_EN2_GRP , HEX_DEC_EN2_PIN , DIO_HIGH);
    }
    else
    {
        Local_enuErrorState = ES_OUT_OF_RANGE;
    }

    return Local_enuErrorState;
}


ES_t HexaDec_enuDisableSSG(u8 Copy_u8SSGNum)
{
    ES_t Local_enuErrorState = ES_NOK;

    if (Copy_u8SSGNum == SSG_RIGHT)
    {
        Local_enuErrorState = DIO_enuSetPinValue(HEX_DEC_EN1_GRP , HEX_DEC_EN1_PIN , DIO_LOW);
    }
    else if (Copy_u8SSGNum == SSG_LEFT)
    {
        Local_enuErrorState = DIO_enuSetPinValue(HEX_DEC_EN2_GRP , HEX_DEC_EN2_PIN , DIO_LOW);
    }
    else
    {
        Local_enuErrorState = ES_OUT_OF_RANGE;
    }
    
    return Local_enuErrorState;
}


ES_t HexaDec_enuStopDisplay(void)
{
    ES_t Local_enuErrorState = ES_NOK;

    DIO_enuSetPinValue(HEX_DEC_EN1_GRP , HEX_DEC_EN1_PIN , DIO_LOW);
    DIO_enuSetPinValue(HEX_DEC_EN2_GRP , HEX_DEC_EN2_PIN , DIO_LOW);

    return Local_enuErrorState;
}

