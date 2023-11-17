/*
 * IIC_priv.h
 *
 *  Created on: Sep 30, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef IIC_PRIV_H_
#define IIC_PRIV_H_

#define IIC_MASTER		0
#define IIC_SLAVE		95

#define TWAR		*((u8*)0x22)
#define TWBR		*((u8*)0x20)
#define TWCR		*((u8*)0x56)
#define TWDR		*((u8*)0x23)
#define TWSR		*((u8*)0x21)

#define BITRATE(IIC_SPEED)		((F_CPU-16ul*IIC_SPEED)/(2ul*IIC_SPEED*IIC_PRES))

#endif /* IIC_PRIV_H_ */
