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

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include "../GPIO_DRIVER/GPIO_INTERFACE.h"

/*******************************************************************************
 *                              								SPI Registers					              			     	   *
 *******************************************************************************/

typedef struct {
	u8 SPRx: 	2;		// SPI Clock Rate Select
	u8 CPHA: 	1;		// Clock Phase
	u8 CPOL: 	1;		// Clock Polarity
	u8 MSTR: 	1;		// Master Slave Select
	u8 DORD:	1;		// Data Order
	u8 SPE: 		1;		// SPI Enable
	u8 SPIE: 		1;		// Interrupt Enable
} SPCR;
#define SPCR_REG		((volatile SPCR*) 0x2D)

typedef struct {
	u8 SPI2x: 	1;		// SPI Double Speed
	u8           : 	5;		// Reserved
	u8 WCOL: 	1;		// Write Collision Flag
	u8 SPIF: 		1;		// SPI Interrupt Flag
} SPSR;
#define SPSR_REG		((volatile SPSR*) 0x2E)

#define SPDR_REG		(*((volatile u8*) 0x2F))


#endif /* SPI_PRIVATE_H_ */
