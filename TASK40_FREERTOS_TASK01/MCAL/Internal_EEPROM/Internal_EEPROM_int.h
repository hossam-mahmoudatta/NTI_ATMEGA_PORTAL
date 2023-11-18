/*
 * Internal_EEPROM_int.h
 *
 *  Created on: Jun 10, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_INTERNAL_EEPROM_INTERNAL_EEPROM_INT_H_
#define MCAL_INTERNAL_EEPROM_INTERNAL_EEPROM_INT_H_

void EEPROM_vidWriteByte(u16 Copy_u16Address, u8 Copy_u8Data);

u8 EEPROM_u8ReadByte(u16 Copy_u16Address);

#endif /* MCAL_INTERNAL_EEPROM_INTERNAL_EEPROM_INT_H_ */
