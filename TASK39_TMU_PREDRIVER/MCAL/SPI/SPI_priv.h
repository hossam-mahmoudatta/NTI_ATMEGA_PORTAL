/*
 * SPI_priv.h
 *
 *  Created on: Oct 29, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define MASTER		            15
#define SLAVE		            19

#define MSB			            23
#define LSB			            27

#define RISING		            31
#define FALLING		            35

#define SETUP_SAMPLE            39
#define SAMPLE_SETUP            43

#define NORMAL		            47
#define DOUBLE		            51

#define PRES_2		            55
#define PRES_4		            59
#define PRES_8		            63
#define PRES_16		            67
#define PRES_32		            71
#define PRES_64		            75
#define PRES_128	            79


#define SPDR	*((volatile u8*) 0x2f)
#define SPSR	*((volatile u8*) 0x2e)
#define SPCR	*((volatile u8*) 0x2d)

#endif /* SPI_PRIV_H_ */
