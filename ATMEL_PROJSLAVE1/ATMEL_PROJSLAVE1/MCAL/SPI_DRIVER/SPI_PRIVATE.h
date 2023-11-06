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


#define SPCR_SPR0	0		// SPI Clock Rate Select
#define SPCR_SPR1	1		// SPI Clock Rate Select
#define SPCR_CPHA 	2		// Clock Phase
#define SPCR_CPOL 	3		// Clock Polarity
#define SPCR_MSTR 	4		// Master Slave Select
#define SPCR_DORD	5		// Data Order
#define SPCR_SPE 	6		// SPI Enable
#define SPCR_SPIE 	7		// Interrupt Enable
#define SPCR_REG		*((volatile u8*) 0x2D)


#define SPSR_SPI2x 	0		// SPI Double Speed
#define SPSR_SPIF	7		// SPI Interrupt Flag
#define SPSR_REG		*((volatile u8*) 0x2E)

#define SPDR_REG		(*((volatile u8*) 0x2F))


#endif /* SPI_PRIVATE_H_ */
