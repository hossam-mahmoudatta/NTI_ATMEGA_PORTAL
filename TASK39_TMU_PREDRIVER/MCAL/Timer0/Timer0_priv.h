/*
 * Timer0_priv.h
 *
 *  Created on: May 20, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_TIMER0_TIMER0_PRIV_H_
#define MCAL_TIMER0_TIMER0_PRIV_H_

#define TCCR0               *((u8*)0x53)
#define TCNT0               *((u8*)0x52)
#define OCR0                *((u8*)0x5C)
#define TIMSK               *((u8*)0x59)
#define TIFR                *((u8*)0x58)

#define TIMER0_OVF          98
#define TIMER0_CTC          45

#define TIMER0_INTERRUPT        32
#define TIMER0_POLLING          39

#define OC0_DISCONNECTED            21
#define OC0_TOGGLING                65
#define OC0_CLEARING                26
#define OC0_SETTING                 10


#endif /* MCAL_TIMER0_TIMER0_PRIV_H_ */
