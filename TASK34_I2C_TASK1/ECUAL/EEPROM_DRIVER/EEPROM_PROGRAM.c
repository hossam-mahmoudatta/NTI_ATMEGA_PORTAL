/******************************************************************************
 *
 * Module: EEPROM
 *
 * File Name: EEPROM.c
 *
 * Description: Source file for the AVR EEPROM driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "../../MCAL/I2C_DRIVER/I2C_INTERFACE.h"
#include "EEPROM_INTERFACE.h"

/*******************************************************************************
 *                              						Functions Declarations                         					  *
 *******************************************************************************/

u8 EEPROM_u8WriteByte(u16 copy_u16Address, u8 copy_u8Data){
	I2C_voidSendStartCondition();
	if (I2C_u8GetStatus() != I2C_START) {
	        return ERROR;
	}

	/*
	 * EEPROM address is 11 bits, the 3 MSB is the device address
	 * The other bits are the word address
	 * but the device address is again shifted to another 8 bit frame:
	 * the 4 MSB is 1010, then the Device Address, then R/W
	 */
	u8 EEPROM_ADDRESS_EQN = (u8) (0xA0 | ( (copy_u16Address & 0x0700) >> 7) );
	// 0xA0 = 1010, 0x0700 = 0b111 0000 000
	I2C_voidSendByte(EEPROM_ADDRESS_EQN);
	if (I2C_u8GetStatus() != I2C_MSTR_TXD_SLA_W_ACK) {
		return ERROR;
	}

	I2C_voidSendByte((u8) (copy_u16Address));
	if (I2C_u8GetStatus() != I2C_MSTR_TXD_DATA_ACK) {
		return ERROR;
	}

	I2C_voidSendByte(copy_u8Data);
	if (I2C_u8GetStatus() != I2C_MSTR_TXD_DATA_ACK) {
		return ERROR;
	}

	I2C_voidSendStopCondition();

	return SUCCESS;
}


u8 EEPROM_u8ReadByte(u16 copy_u16Address, u8 *copy_u8Data) {
	I2C_voidSendStartCondition();
	if (I2C_u8GetStatus() != I2C_START) {
			return ERROR;
	}

	/*
	 * EEPROM address is 11 bits, the 3 MSB is the device address
	 * The other bits are the word address
	 * but the device address is again shifted to another 8 bit frame:
	 * the 4 MSB is 1010, then the Device Address, then R/W
	 */
	u8 EEPROM_ADDRESS_EQN = (u8) (0xA0 | ( (copy_u16Address & 0x0700) >> 7) );
	// 0xA0 = 1010, 0x0700 = 0b111 0000 000
	I2C_voidSendByte(EEPROM_ADDRESS_EQN);
	if (I2C_u8GetStatus() != I2C_MSTR_TXD_SLA_W_ACK) {
		return ERROR;
	}

	I2C_voidSendByte((u8) (copy_u16Address));
	if (I2C_u8GetStatus() != I2C_MSTR_TXD_DATA_ACK) {
		return ERROR;
	}

	I2C_voidSendStartCondition();
	if (I2C_u8GetStatus() != I2C_REP_START) {
		return ERROR;
	}

	I2C_voidSendByte(EEPROM_ADDRESS_EQN | 1); // For Reading
	if (I2C_u8GetStatus() != I2C_MSTR_RXD_SLA_R_ACK) {
		return ERROR;
	}

	*copy_u8Data = I2C_u8ReadByteWithNACK();
	if (I2C_u8GetStatus() != I2C_MSTR_RXD_DATA_NACK) {
		return ERROR;
	}

	I2C_voidSendStopCondition();

	return SUCCESS;
}
