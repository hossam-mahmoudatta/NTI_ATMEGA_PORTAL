/*
 * Internal_EEPROM.c
 *
 *  Created on: Jun 10, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_MCAL_EEPROM != 0



#include "../../stdTypes.h"
#include "../../errorState.h"


#include "Internal_EEPROM_priv.h"

void EEPROM_vidWriteByte(u16 Copy_u16Address, u8 Copy_u8Data)
{
	/* Wait for completion of previous write */
	while(((EECR>>EEWE)&1) == 1);

	/* Set up address and data registers */
	EEARH = (Copy_u16Address>>8)& 3;
	EEARL = (u8)Copy_u16Address;
	EEDR = Copy_u8Data;
	/* Write logical one to EEMWE */
	// EECR |= (1<<EEMWE);
	asm("SBI 0x1C , 2");
	/* Start eeprom write by setting EEWE */
	// EECR |= (1<<EEWE);
	asm("SBI 0x1C , 1");

}

u8 EEPROM_u8ReadByte(u16 Copy_u16Address)
{
	/* Wait for completion of previous write */
	while(((EECR>>EEWE)&1) == 1);

	/* Set up address and data registers */
	EEARH = (Copy_u16Address>>8)& 3;
	EEARL = (u8)Copy_u16Address;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}

#endif