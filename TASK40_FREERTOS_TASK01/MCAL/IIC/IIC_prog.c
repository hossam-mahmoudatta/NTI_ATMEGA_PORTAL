/*
 * IIC_prog.c
 *
 *  Created on: Sep 30, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_MCAL_IIC != 0


#include "../../stdTypes.h"
#include "../../errorState.h"

#include "IIC_priv.h"
#include "IIC_config.h"

ES_t IIC_enuInit(void)
{
	ES_t Local_u8ErrorState = ES_NOK;

#if IIC_MODE == IIC_MASTER


	#if IIC_PRES == 1ul
		TWSR &= ~(3<<0);
	#endif

	TWBR= (u8)BITRATE(IIC_CLOCK_SPEED);

	//TWAR &=~ (1<<0);
	TWAR = (IIC_NODE_ADDRESS<<1) | IIC_RECOG_GENERAL_CALL;
	//ack bit
	TWCR |=(1<<6);

	//enable IIC
	TWCR |=(1<<2);

#elif IIC_MODE == IIC_SLAVE
	TWAR &=~ (1<<0);
	TWAR = (IIC_NODE_ADDRESS<<1) | IIC_RECOG_GENERAL_CALL;
	//clear flag
	TWCR |=(1<<7);
	//enable IIC
	TWCR |=(1<<2);
#endif

	return Local_u8ErrorState;
}

ES_t IIC_enuStartCondition(void)
{
	ES_t Local_u8ErrorState = ES_NOK;

	TWCR |=(1<<5);
	//clear flag
	TWCR |=(1<<7);
	while(! ((TWCR>>7)&1) );

	if ((TWSR & 0xF8) == 0x08)
		Local_u8ErrorState = ES_OK;

	return Local_u8ErrorState;
}

ES_t IIC_enuRepeatedStartCondition(void)
{
	ES_t Local_u8ErrorState = ES_NOK;

	TWCR |=(1<<5);
	//clear flag
	TWCR |=(1<<7);
	while(! ((TWCR>>7)&1) );

	if ((TWSR & 0xF8) == 0x10)
		Local_u8ErrorState = ES_OK;

	return Local_u8ErrorState;
}

ES_t IIC_enuStopCondition(void)
{
	ES_t Local_u8ErrorState = ES_NOK;

	//clear flag
	TWCR |=(1<<4);
	TWCR |=(1<<7);

	return Local_u8ErrorState;
}
ES_t IIC_enuWriteSlaveAddress(u8 Copy_u8SlaveAddress , u8 Copy_u8Operation)
{
	ES_t Local_u8ErrorState = ES_NOK;

	TWDR = ( (Copy_u8SlaveAddress<<1) | Copy_u8Operation );


	//clear start condition
	TWCR &=~(1<<5);
	//clear flag
	TWCR |=(1<<7);
	while(! ((TWCR>>7)&1) );

	if ((TWSR & 0xF8) == 0x18 && Copy_u8Operation == 0)
		Local_u8ErrorState = ES_OK;

	else if ((TWSR & 0xF8) == 0x40 && Copy_u8Operation == 1)
		Local_u8ErrorState = ES_OK;

	return Local_u8ErrorState;
}

ES_t IIC_enuWriteData(u8 Copy_u8Data)
{
	ES_t Local_u8ErrorState = ES_NOK;

	TWDR = Copy_u8Data;

	//clear flag
	TWCR |=(1<<7);
	while(! ((TWCR>>7)&1) );

	if ((TWSR & 0xF8) == 0x28 || (TWSR & 0xF8) == 0xB8)
		Local_u8ErrorState = ES_OK;

	return Local_u8ErrorState;
}

ES_t IIC_enuCheckMyAddress(void)
{
	ES_t Local_u8ErrorState = ES_NOK;

	//enable acknowledge
	TWCR |= (1<<6);
	//clear flag
	TWCR |=(1<<7);
	while(! ((TWCR>>7)&1) );
	if ((TWSR & 0xF8) == 0x60)
		Local_u8ErrorState = ES_OK;

	else if ((TWSR & 0xF8) == 0xA8)
		Local_u8ErrorState = ES_OK;

	return Local_u8ErrorState;
}

ES_t IIC_enuReadData(u8 * Copy_pu8Data)
{
	ES_t Local_u8ErrorState = ES_NOK;

	//clear flag
	TWCR |=(1<<7);

	while(! ((TWCR>>7)&1) );

	if ((TWSR & 0xF8) == 0x50 || (TWSR & 0xF8) == 0x58)
	{
		*Copy_pu8Data = TWDR;
		Local_u8ErrorState = ES_OK;
	}
	else if ((TWSR & 0xF8) == 0x80)
	{
		*Copy_pu8Data = TWDR;
		Local_u8ErrorState = ES_OK;
	}
	return Local_u8ErrorState;
}
#endif