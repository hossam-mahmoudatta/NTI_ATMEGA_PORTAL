 /******************************************************************************
 *
 * Module: I2C (Inter Integrated Circuit)
 *
 * File Name: I2C_PRIVATE.h
 *
 * Description: Header file for the AVR I2C Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#include "../GPIO_DRIVER/GPIO_INTERFACE.h"

/*******************************************************************************
 *                              								SPI Registers					              			     	   *
 *******************************************************************************/

/* TWBR - TWI Bit Rate Register
  *  Bit 7..0 – TWBR: TWI Bit Rate Register
  */
#define TWBR_REG		(*((volatile u8*) 0x20))


// TWI Control Register –TWCR
typedef struct {
	u8 TWIE: 		1;		// Interrupt Enable
	u8          : 		1;		// Reserved
	u8 TWEN: 		1;		// Enable Bit
	u8 TWWC: 	1;		//  Write Collision Flag
	u8 TWSTO:	1;		// Stop Condition Bit
	u8 TWSTA: 	1;		// Start Condition Bit
	u8 TWEA: 		1;		// Enable Acknowledge Bit
	u8 TWINT: 		1;		// TWI Interrupt Flag
} TWCR;
#define TWCR_REG		((volatile TWCR*) 0x56)


// TWSR - TWI Status Register
typedef struct {
	u8 TWPS: 	2;		// TWI Prescaler Bits
	u8           : 	1;		// Res
	u8 TWS: 	5;		// TWI Status BITS
} TWSR;
#define TWSR_REG		(((volatile TWSR*) 0x21))

/* TWDR - TWI Data Register
  *  Bit 7..0 – TWDR: TWI Data Register
  */
#define TWDR_REG		(*((volatile u8*) 0x23))



/* TWAR - TWI (Slave) Address Register
  *  Bit 7..1 – TWA: TWI (Slave) Address Register
  *  Bit 0 – TWGCE: TWI General Call Recognition Enable Bit
  */
typedef struct {
	u8 TWGCE: 	1;		// TWI General Call Recognition Enable Bit
	u8 TWA: 	7;		// TWI (Slave) Address Register
} TWAR;
#define TWAR_REG		*((volatile u8*) 0x22)


#endif /* I2C_PRIVATE_H_ */
