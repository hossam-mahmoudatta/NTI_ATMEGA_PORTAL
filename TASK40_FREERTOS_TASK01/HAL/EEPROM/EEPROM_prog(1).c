/*
 * EEPROM_prog.c
 *
 *  Created on: Sep 30, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_HAL_EEPROM != 0


#include "../../stdTypes.h"
#include "../../errorState.h"

#include "../../MCAL/IIC/IIC_int.h"

#include "EEPROM_config.h"
#include "EEPROM_priv.h"

ES_t EEPROM_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = IIC_enuInit();

	return Local_enuErrorState;
}

ES_t EEPROM_enuWriteData(u16 Copy_u16Address, u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

#if EEPROM_TYPE == EIGHT_KBIT
	u8 Local_u8Address =( ( 0xA0 | (EEPROM_A2_STATE<<3) | ( ((Copy_u16Address>>8) &3) << 1) ) >>1 );
	u8 Local_ByteAddress = (u8)Copy_u16Address;
#endif

	if (ES_OK == IIC_enuStartCondition())
	{
		if (ES_OK == IIC_enuWriteSlaveAddress(Local_u8Address , 0))
		{
			if (ES_OK==IIC_enuWriteData(Local_ByteAddress))
			{
				if(ES_OK == IIC_enuWriteData(Copy_u8Data))
				{
					IIC_enuStopCondition();
					Local_enuErrorState = ES_OK;
				}
			}
		}
	}
	return Local_enuErrorState;
}

ES_t EEPROM_enuReadData(u16 Copy_u16Address, u8 * Copy_pu8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

#if EEPROM_TYPE == EIGHT_KBIT
	u8 Local_u8Address =( ( 0xA0 | (EEPROM_A2_STATE<<3) | ( ((Copy_u16Address>>8) &3) << 1) ) >>1 );
	u8 Local_ByteAddress = (u8)Copy_u16Address;
#endif

	if (ES_OK == IIC_enuStartCondition())
	{
		if (ES_OK == IIC_enuWriteSlaveAddress(Local_u8Address , 0))
		{
			if (ES_OK==IIC_enuWriteData(Local_ByteAddress))
			{
				if(ES_OK == IIC_enuRepeatedStartCondition())
				{
					if (ES_OK == IIC_enuWriteSlaveAddress(Local_u8Address , 1) )
					{
						if (ES_OK == IIC_enuReadData( Copy_pu8Data ))
						{
							IIC_enuStopCondition();
							Local_enuErrorState = ES_OK;
						}
					}
				}
			}
		}
	}

	return Local_enuErrorState;
}
#endif