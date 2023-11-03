 /******************************************************************************
 *
 * Module: I2C (Inter Integrated Circuit)
 *
 * File Name: I2C_CONFIG.h
 *
 * Description: Header file for the AVR I2C Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

#include "I2C_PRIVATE.h"

/*******************************************************************************
 *                              						 Predecessor Macros                           					  *
 *******************************************************************************/

// A better naming for the I2C Connection pins
#define SCL_PORT					PORT_C
#define SDA_PORT 					PORT_C
#define SCL_PIN						PIN_0
#define SDA_PIN 						PIN_1

#define I2C_SLAVE1_ADDRESS 		0x02	// Slave Address = 0b00000010
#define I2C_INITIALSTATUS 				0xF8	// Masking to eliminate 1st 3 bits & get last 5 bits 0b11111000

// I2C Status Bits in the TWSR Register, found in tables 74 & 75 in the Data sheet
// Status Codes for Master Transmitter Mode
#define I2C_START         						0x08 	// Start has been sent
#define I2C_REP_START     				0x10 	// Repeated start
#define I2C_MSTR_TXD_SLA_W_ACK 			0x18 	// Master transmit ( slave address + Write request ) to slave + ACK received from slave.
#define I2C_MSTR_TXD_SLA_W_NACK 		0x20 	// Master transmit ( slave address + Write request ) to slave + Not ACK received from slave.
#define I2C_MSTR_TXD_DATA_ACK				0x28 	// Master transmit data + ACK has been received from Slave.
#define I2C_MSTR_TXD_DATA_NACK   		0x30 	// Master transmit data + Not ACK has been received from Slave.
#define I2C_ARBIT_LOST   				0x38 	// Arbitration lost in (Slave + Write) or Data bytes

// Status Codes for Master Receiver Mode
#define I2C_MSTR_RXD_SLA_R_ACK  			0x40 	// Master transmit ( slave address + Read request ) to slave + ACK received from slave.
#define I2C_MSTR_RXD_SLA_R_NACK  		0x48 	// Master transmit ( slave address + Read request ) to slave + Not ACK received from slave.
#define I2C_MSTR_RXD_DATA_ACK   			0x50 	// Master received data + received ACK from slave.
#define I2C_MSTR_RXD_DATA_NACK 			0x58 	// Master received data + received Not ACK from slave.

// Status Codes for Slave Transmitter Mode
#define I2C_SLAV_TXD_SLA_R_ACK  			0xA8 	// Slave transmit ( slave address + Read request ) to slave + ACK received from slave.
#define I2C_SLAV_TXD_DATA_ACK				0xB8 	// Slave transmit data +  ACK received.

// Status Codes for Slave Receiver Mode
#define I2C_SLAV_RXD_SLA_W_ACK  			0x60 	// Master transmit ( slave address + Read request ) to slave + ACK received from slave.
#define I2C_SLAV_RXD_DATA_R_NACK  		0x80 	// Master transmit ( slave address + Read request ) to slave + Not ACK received from slave.

/*******************************************************************************
 *                              						 	Enum Declarations                         						  *
 *******************************************************************************/

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
}I2C_ErrorStatus;

typedef enum {
	I2C_ADDRESS_1 = 0x50,
	I2C_ADDRESS_2 = 0xA0,
    // Add more address values as needed
}	I2C_Address;

typedef enum {
	I2C_BAUDRATE_100K = 100000,
	I2C_BAUDRATE_400K = 400000,
    // Add more baud rate values as needed
}	I2C_BaudRate;

typedef struct {
	I2C_Address address;
	I2C_BaudRate bitRate;
}	I2C_ConfigType;


#endif /* I2C_CONFIG_H_ */
