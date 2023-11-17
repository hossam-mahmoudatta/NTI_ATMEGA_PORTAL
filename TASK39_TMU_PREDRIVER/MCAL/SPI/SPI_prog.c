/*
 * SPI_prog.c
 *
 *  Created on: Oct 29, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../LIB/stdTypes.h"

#include "SPI_config.h"
#include "SPI_priv.h"

void SPI_vidInit(void)
{
#if SPI_MODE == MASTER
	SPCR |=(1<<4);
#elif SPI_MODE == SLAVE
	SPCR &=~(1<<4);
#else 
#error SPI mode configuration is invalid
#endif

	SPCR &=~(3<<0);
	SPSR &=~(1<<0);
#if SPI_CLOCK_PRESCALER == PRES_2
	SPSR |= (1<<0);
	SPCR &=~(3<<0);
#elif SPI_CLOCK_PRESCALER == PRES_4
	SPSR &=~(1<<0);
	SPCR &=~(3<<0);
#elif SPI_CLOCK_PRESCALER == PRES_8
	SPSR |= (1<<0);
	SPCR |= (1<<0);
#elif SPI_CLOCK_PRESCALER == PRES_16
	SPSR &=~(1<<0);
	SPCR |= (1<<0);
#elif SPI_CLOCK_PRESCALER == PRES_32
	SPSR |= (1<<0);
	SPCR |= (2<<0);
#elif SPI_CLOCK_PRESCALER == PRES_64
	SPSR &=~(1<<0);
	SPCR |= (2<<0);
#elif SPI_CLOCK_PRESCALER == PRES_128
	SPSR &=~(1<<0);
	SPCR |= (3<<0);
#else 
#error SPI Prescaler configuration is invalid
#endif

#if SPI_CLOCK_POLARITY == RISING
	SPCR &=~(1<<3);
#elif SPI_CLOCK_POLARITY == FALLING
	SPCR |= (1<<3);
#else 
#error SPI Clock Polarity configuration is invalid
#endif

#if SPI_CLOCK_PHASE == SAMPLE_SETUP
	SPCR &=~(1<<2);
#elif SPI_CLOCK_PHASE == SETUP_SAMPLE
	SPCR |= (1<<2);
#else 
#error SPI Clock Phase configuration is invalid
#endif

#if SPI_DATA_ORDER == MSB
	SPCR &=~(1<<5);
#elif SPI_DATA_ORDER == LSB
	SPCR |= (1<<5);
#else 
#error SPI Data Order configuration is invalid
#endif

	SPCR |=(1<<6);
}

u8 SPI_u8Transcieve(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while(! ((SPSR>>7)&1));
	return SPDR;
}
