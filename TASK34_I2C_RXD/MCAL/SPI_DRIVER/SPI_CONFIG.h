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

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "SPI_PRIVATE.h"

/*******************************************************************************
 *                              					MACRO DEFINITIONS				                   	   *
 *******************************************************************************/

// A better naming for the SPI Connection pins
#define SS 		PIN_4		// Slave Select
#define MOSI 	PIN_5		// Master O/P Slave I/P
#define MISO 	PIN_6		// Master I/P Slave O/P
#define SCK 		PIN_7		// Clock

#define SPI_DEF_DATA_VAL 0xFF // The default data value in the SPDR

#define SPI_ISR_ENABLE		1

typedef enum {
	SPI_NORMAL_CLK_4 		= 0b00,
	SPI_NORMAL_CLK_16 	= 0b01,
	SPI_NORMAL_CLK_64 	= 0b10,
	SPI_NORMAL_CLK_128 	= 0b11,
}	SPI_CLOCKRATE;
#define SPI_CLOCK_RATE		SPI_NORMAL_CLK_4

typedef enum {
	SPI_SAMPLE	= 0,
	SPI_SETUP 	= 1,
}	SPI_CPHA;
#define SPI_CPHA_SELCT	SPI_SAMPLE

typedef enum {
	SPI_RISING			= 0,
	SPI_FALLING 	= 1,
}	SPI_CPOL;
#define SPI_CPOL_SELCT	SPI_RISING

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/


#endif /* SPI_CONFIG_H_ */
