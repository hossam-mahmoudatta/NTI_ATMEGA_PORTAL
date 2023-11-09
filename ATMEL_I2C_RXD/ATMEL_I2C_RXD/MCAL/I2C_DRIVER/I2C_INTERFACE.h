 /******************************************************************************
 *
 * Module: I2C (Inter Integrated Circuit)
 *
 * File Name: I2C.h
 *
 * Description: Header file for the AVR I2C Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "I2C_CONFIG.h"

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the SPI Module to start functionality
void I2C_voidMasterInit(void);

// Initializes and enables the SPI Module to start functionality
void I2C_voidSlaveInit(u8 copy_u8Address);

// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidSendStartCondition(void);

// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidSendRepeatedStart(void);

// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidMasterSendSlaveAddressWrite(u8 copy_u8Address);

// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidMasterSendSlaveAddressRead(u8 copy_u8Address);

// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidMasterSendDataByte(u8 copy_u8DataByte);

// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidMasterReceiveDataByte(u8 *copy_u8DataByte);

u8 I2C_u8SlaveReceiveDataByte(void);

// Responsible for the SPI to receive an array of bytes, a string
void I2C_voidSendStopCondition(void);

// Responsible for the SPI to receive an array of bytes, a string
void I2C_voidSendByte(u8 copy_u8Data);

// Responsible for the SPI to receive an array of bytes, a string
u8 I2C_u8ReadByteWithACK(void);

// Responsible for the SPI to receive an array of bytes, a string
u8 I2C_u8ReadByteWithNACK(void);

// Responsible for the SPI to receive an array of bytes, a string
u8 I2C_u8GetStatus(void);

#endif /* I2C_INTERFACE_H_ */
