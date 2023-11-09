/******************************************************************************
 *
 * Module: EEPROM
 *
 * File Name: EEPROM.h
 *
 * Description: Header file for the AVR EEPROM driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/
#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include "../../MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"

#define ERROR 		0
#define SUCCESS 	1

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

u8 EEPROM_u8WriteByte(u16 copy_u16Address, u8 copy_u8Data);


u8 EEPROM_u8ReadByte(u16 copy_u16Address, u8 *copy_u8Data);


#endif /* EEPROM_INTERFACE_H_ */
