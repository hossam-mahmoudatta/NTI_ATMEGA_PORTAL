/*
 * DIO_priv.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_


#define DIO_CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0
#define DIO_CONC(b7,b6,b5,b4,b3,b2,b1,b0)         DIO_CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)

#define DDRA	*((volatile u8*)0x3A)
#define PORTA	*((volatile u8*)0x3B)
#define PINA	*((volatile u8*)0x39)

#define DDRB	*((volatile u8*)0x37)
#define PORTB	*((volatile u8*)0x38)
#define PINB	*((volatile u8*)0x36)

#define DDRC	*((volatile u8*)0x34)
#define PORTC	*((volatile u8*)0x35)
#define PINC	*((volatile u8*)0x33)

#define DDRD	*((volatile u8*)0x31)
#define PORTD	*((volatile u8*)0x32)
#define PIND	*((volatile u8*)0x30)

#define DIO_GROUP_A                 0      
#define DIO_GROUP_B                 1
#define DIO_GROUP_C                 2
#define DIO_GROUP_D                 3

#define DIO_PIN_0                   0
#define DIO_PIN_1                   1
#define DIO_PIN_2                   2
#define DIO_PIN_3                   3
#define DIO_PIN_4                   4
#define DIO_PIN_5                   5
#define DIO_PIN_6                   6
#define DIO_PIN_7                   7

#define DIO_LOW                     0
#define DIO_HIGH                    1      

#define DIO_FLOAT                   0
#define DIO_PULL_UP                 1      

#define DIO_INPUT                   0
#define DIO_OUTPUT                  1

#define DIO_MASK_BIT                1


#endif /* DIO_PRIV_H_ */
