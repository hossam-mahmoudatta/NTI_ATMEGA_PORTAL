/*
 * Stepper_prog.c
 *
 *  Created on: Oct 23, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_HAL_STEPPER != 0


#include "../../stdTypes.h"
#include "../../errorState.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Stepper_config.h"
#include "Stepper_priv.h"

#include <util/delay.h>

ES_t Stepper_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection(BLUE_PORT, BLUE_PIN , DIO_OUTPUT);
	DIO_enuSetPinDirection(PINK_PORT, PINK_PIN , DIO_OUTPUT);
	DIO_enuSetPinDirection(YELLOW_PORT, YELLOW_PIN , DIO_OUTPUT);
	DIO_enuSetPinDirection(ORANGE_PORT, ORANGE_PIN , DIO_OUTPUT);

	DIO_enuSetPinValue(BLUE_PORT, BLUE_PIN 	   , DIO_HIGH);
	DIO_enuSetPinValue(PINK_PORT, PINK_PIN     , DIO_HIGH);
	DIO_enuSetPinValue(YELLOW_PORT, YELLOW_PIN , DIO_HIGH);
	DIO_enuSetPinValue(ORANGE_PORT, ORANGE_PIN , DIO_HIGH);

	return Local_enuErrorState;
}

ES_t Stepper_enuMoveOneCycle(u8 Copy_u8Direction)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8Direction == CLOCKWISE)
	{
		u16 Local_u16Iter;
		u8 Local_u8State = 0x0f;
		for (Local_u16Iter = 0; Local_u16Iter < 2048 ; Local_u16Iter ++)
		{
			Local_u8State &= ~(1 << (Local_u16Iter%4));

			DIO_enuSetPinValue(BLUE_PORT  , BLUE_PIN   , ((Local_u8State>>0)&1) );
			DIO_enuSetPinValue(PINK_PORT  , PINK_PIN   , ((Local_u8State>>1)&1) );
			DIO_enuSetPinValue(YELLOW_PORT, YELLOW_PIN , ((Local_u8State>>2)&1) );
			DIO_enuSetPinValue(ORANGE_PORT, ORANGE_PIN , ((Local_u8State>>3)&1) );

			Local_u8State = 0x0f;
			_delay_ms(3);
		}
	}

	return Local_enuErrorState;
}

ES_t Stepper_enuMoveAngle(u8 Copy_u8Direction , u16 Copy_u16Angle)
{
	ES_t Local_enuErrorState = ES_NOK;

	u16 Local_u16Steps =  ( (Copy_u16Angle * 2048ul) / 360ul );

	u16 Local_u16Iter;
	u8 Local_u8State = 0x0f;
	for (Local_u16Iter = 0; Local_u16Iter <Local_u16Steps ; Local_u16Iter ++)
	{
		Local_u8State &= ~(1 << (Local_u16Iter%4));

		DIO_enuSetPinValue(BLUE_PORT, BLUE_PIN 	   , ((Local_u8State>>0)&1) );
		DIO_enuSetPinValue(PINK_PORT, PINK_PIN     , ((Local_u8State>>1)&1) );
		DIO_enuSetPinValue(YELLOW_PORT, YELLOW_PIN , ((Local_u8State>>2)&1) );
		DIO_enuSetPinValue(ORANGE_PORT, ORANGE_PIN , ((Local_u8State>>3)&1) );

		Local_u8State = 0x0f;
		_delay_ms(2);
	}

	return Local_enuErrorState;
}
#endif