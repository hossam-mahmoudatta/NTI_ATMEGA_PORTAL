 /******************************************************************************
 *
 * Module: SPI (Serial Peripheral Interface)
 *
 * File Name: SPI.h
 *
 * Description: Header file for the AVR SPI Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_CONFIG.h"

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the SPI Master Module to start functionality
void SPI_voidInitialization_Master(void);

// Initializes and enables the SPI Slave Module to start functionality
void SPI_voidInitialization_Slave(void);

// Responsible for the SPI to send & receive a byte
u8 SPI_u8SendReceiveByte_Polling(u8 copy_u8Data);

void SPI_u8SendByte_Polling(u8 copy_u8Data);

u8 SPI_u8ReceiveByte_Polling(void);

// Responsible for the SPI to send an array of bytes, a string
void SPI_voidSendString_Polling(const u8 *str);

// Responsible for the SPI to receive an array of bytes, a string
void SPI_voidReceiveString(u8 *str);

#endif /* SPI_INTERFACE_H_ */
