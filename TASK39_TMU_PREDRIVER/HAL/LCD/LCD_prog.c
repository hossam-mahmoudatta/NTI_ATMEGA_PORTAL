/*
 * LCD_prog.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Ahmed El-Gaafrawy
 */
//Public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"


// lower
#include "../../MCAL/DIO/DIO_int.h"

//my own
#include "LCD_config.h"
#include "LCD_priv.h"

#include <util\delay.h>

ES_t LCD_enuInit(void)
{
    ES_t Local_enuErrorState = ES_NOK;

    _delay_ms(35);

    DIO_enuSetPinDirection(LCD_RS_GRP , LCD_RS_PIN , DIO_OUTPUT);
	#if LCD_RW_GRP != LCD_NOT_CONNECTED
    	DIO_enuSetPinDirection(LCD_RW_GRP , LCD_RW_PIN , DIO_OUTPUT);
	#endif
    DIO_enuSetPinDirection(LCD_EN_GRP , LCD_EN_PIN , DIO_OUTPUT);

    DIO_enuSetPinDirection(LCD_D7_GRP , LCD_D7_PIN , DIO_OUTPUT);
    DIO_enuSetPinDirection(LCD_D6_GRP , LCD_D6_PIN , DIO_OUTPUT);
    DIO_enuSetPinDirection(LCD_D5_GRP , LCD_D5_PIN , DIO_OUTPUT);
    DIO_enuSetPinDirection(LCD_D4_GRP , LCD_D4_PIN , DIO_OUTPUT);

    #if LCD_MODE == EIGHT_BIT 
        DIO_enuSetPinDirection(LCD_D3_GRP , LCD_D3_PIN , DIO_OUTPUT);
        DIO_enuSetPinDirection(LCD_D2_GRP , LCD_D2_PIN , DIO_OUTPUT);
        DIO_enuSetPinDirection(LCD_D1_GRP , LCD_D1_PIN , DIO_OUTPUT);
        DIO_enuSetPinDirection(LCD_D0_GRP , LCD_D0_PIN , DIO_OUTPUT);

        /******** Function Set Command ************/
        DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_LOW);
        enuWriteNLatch(0x38);
    #elif LCD_MODE == FOUR_BIT
        /******** Function Set Command ************/
        DIO_enuSetPinValue(LCD_D7_GRP, LCD_D7_PIN , 0);
        DIO_enuSetPinValue(LCD_D6_GRP, LCD_D6_PIN , 0);
        DIO_enuSetPinValue(LCD_D5_GRP, LCD_D5_PIN , 1);
        DIO_enuSetPinValue(LCD_D4_GRP, LCD_D4_PIN , 0);
       
        DIO_enuSetPinValue(LCD_EN_GRP, LCD_EN_PIN , DIO_HIGH);
        _delay_ms(1);
        DIO_enuSetPinValue(LCD_EN_GRP, LCD_EN_PIN , DIO_LOW);
        
        DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_LOW);
        enuWriteNLatch(0x28);
    #else
        #error LCD Mode config must be EIGHT_BIT or FOUR_BIT
    #endif
    /******** Display ON/OFF Control Command ************/
    DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_LOW);
    enuWriteNLatch(0x0F);
    
    /******** Clear Display Command ************/
    DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_LOW);
    enuWriteNLatch(0x01);

    /******** Entry Set Mode Command ************/
    DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_LOW);
    enuWriteNLatch(0x06);

    return Local_enuErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
    ES_t Local_enuErrorState = ES_NOK;

    DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_LOW);
    enuWriteNLatch(Copy_u8Command);

    return Local_enuErrorState;
}

ES_t LCD_enuSendData(u8 Copy_u8Data)
{
    ES_t Local_enuErrorState = ES_NOK;

    DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_HIGH);
    enuWriteNLatch(Copy_u8Data);

    return Local_enuErrorState;
}

ES_t LCD_enuSendString(const char *Copy_pcString)
{
    while (*Copy_pcString)
    {
        DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_HIGH);
        enuWriteNLatch(*Copy_pcString++);
    }
    return ES_OK;
}


ES_t LCD_enuGotoXY(u8 Copy_u8X , u8 Copy_u8Y)
{
    ES_t Local_enuErrorState = ES_NOK;

    if (((Copy_u8X >=1) && (Copy_u8X <=2)) && ((Copy_u8Y >=1) && (Copy_u8Y <=16)))
    {
        DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_LOW);
        enuWriteNLatch((0x80 + (0x40*(Copy_u8X -1))) + (Copy_u8Y -1) );
    }
    else
    {
        Local_enuErrorState = ES_OUT_OF_RANGE;
    }

    return Local_enuErrorState;
}

ES_t LCD_enuWriteIntegarNum(s32 Copy_s32Num)
{
    ES_t Local_enuErrorState = ES_NOK;

	s32 Local_s32Reverse=0;
	u8 Local_u8Remainder=0 , Local_u8NumDigit=0;

	if (Copy_s32Num ==0)
	{
		DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_HIGH);
		enuWriteNLatch('0');
		///Copy_s32Num *= -1 ;
	}

	if(Copy_s32Num <0)
	{
		DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_HIGH);
		enuWriteNLatch('-');
		Copy_s32Num *= -1 ;
	}
	while (Copy_s32Num)
	{
		Local_u8Remainder = Copy_s32Num % 10;
		Local_s32Reverse = Local_s32Reverse * 10 + Local_u8Remainder;
		Copy_s32Num /=10;
		Local_u8NumDigit ++;
	}

	while (Local_u8NumDigit)
	{
		Local_u8Remainder = Local_s32Reverse % 10;
		DIO_enuSetPinValue(LCD_RS_GRP , LCD_RS_PIN , DIO_HIGH);
		enuWriteNLatch(Local_u8Remainder + '0');
		Local_s32Reverse /= 10;
		Local_u8NumDigit --;
	}

	return Local_enuErrorState;
}


static ES_t enuWriteNLatch(u8 Copy_u8Byte)
{
	#if LCD_RW_GRP != LCD_NOT_CONNECTED
    	DIO_enuSetPinValue(LCD_RW_GRP , LCD_RW_PIN , DIO_LOW);
	#endif
    DIO_enuSetPinValue(LCD_EN_GRP , LCD_EN_PIN , DIO_LOW);

    #if  LCD_MODE == EIGHT_BIT

        DIO_enuSetPinValue(LCD_D7_GRP, LCD_D7_PIN , ((Copy_u8Byte>>7) & 1));
        DIO_enuSetPinValue(LCD_D6_GRP, LCD_D6_PIN , ((Copy_u8Byte>>6) & 1));
        DIO_enuSetPinValue(LCD_D5_GRP, LCD_D5_PIN , ((Copy_u8Byte>>5) & 1));
        DIO_enuSetPinValue(LCD_D4_GRP, LCD_D4_PIN , ((Copy_u8Byte>>4) & 1));
        
        DIO_enuSetPinValue(LCD_D3_GRP, LCD_D3_PIN , ((Copy_u8Byte>>3) & 1));
        DIO_enuSetPinValue(LCD_D2_GRP, LCD_D2_PIN , ((Copy_u8Byte>>2) & 1));
        DIO_enuSetPinValue(LCD_D1_GRP, LCD_D1_PIN , ((Copy_u8Byte>>1) & 1));
        DIO_enuSetPinValue(LCD_D0_GRP, LCD_D0_PIN , ((Copy_u8Byte>>0) & 1));
       
        DIO_enuSetPinValue(LCD_EN_GRP, LCD_EN_PIN , DIO_HIGH);
        _delay_ms(1);
        DIO_enuSetPinValue(LCD_EN_GRP, LCD_EN_PIN , DIO_LOW);

        // delay for waiting LCD to finish its cureent job
        _delay_ms(2);

    #elif LCD_MODE == FOUR_BIT
        DIO_enuSetPinValue(LCD_D7_GRP, LCD_D7_PIN , ((Copy_u8Byte>>7) & 1));
        DIO_enuSetPinValue(LCD_D6_GRP, LCD_D6_PIN , ((Copy_u8Byte>>6) & 1));
        DIO_enuSetPinValue(LCD_D5_GRP, LCD_D5_PIN , ((Copy_u8Byte>>5) & 1));
        DIO_enuSetPinValue(LCD_D4_GRP, LCD_D4_PIN , ((Copy_u8Byte>>4) & 1));
       
        DIO_enuSetPinValue(LCD_EN_GRP, LCD_EN_PIN , DIO_HIGH);
        _delay_ms(1);
        DIO_enuSetPinValue(LCD_EN_GRP, LCD_EN_PIN , DIO_LOW);
        
        DIO_enuSetPinValue(LCD_D7_GRP, LCD_D7_PIN , ((Copy_u8Byte>>3) & 1));
        DIO_enuSetPinValue(LCD_D6_GRP, LCD_D6_PIN , ((Copy_u8Byte>>2) & 1));
        DIO_enuSetPinValue(LCD_D5_GRP, LCD_D5_PIN , ((Copy_u8Byte>>1) & 1));
        DIO_enuSetPinValue(LCD_D4_GRP, LCD_D4_PIN , ((Copy_u8Byte>>0) & 1));
       
        DIO_enuSetPinValue(LCD_EN_GRP, LCD_EN_PIN , DIO_HIGH);
        _delay_ms(1);
        DIO_enuSetPinValue(LCD_EN_GRP, LCD_EN_PIN , DIO_LOW);

        // delay for waiting LCD to finish its cureent job
        _delay_ms(2);

    #else
        #error LCD Mode config must be EIGHT_BIT or FOUR_BIT
    #endif

    return ES_OK;
}
