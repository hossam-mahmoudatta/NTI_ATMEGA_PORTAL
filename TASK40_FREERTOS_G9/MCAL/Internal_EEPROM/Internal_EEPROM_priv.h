/*
 * Internal_EEPROM_priv.h
 *
 *  Created on: Jun 10, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_INTERNAL_EEPROM_INTERNAL_EEPROM_PRIV_H_
#define MCAL_INTERNAL_EEPROM_INTERNAL_EEPROM_PRIV_H_

#define EEARL		*((u8*)0x3E)
#define EEARH		*((u8*)0x3F)

#define EEDR		*((u8*)0x3D)

#define EECR		*((u8*)0x3C)

#define EEWE			1
#define EEMWE			2
#define EERE			0

#endif /* MCAL_INTERNAL_EEPROM_INTERNAL_EEPROM_PRIV_H_ */
