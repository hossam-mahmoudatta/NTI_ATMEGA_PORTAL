/*
 * PWM_priv.h
 *
 *  Created on: May 26, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_PWM_PWM_PRIV_H_
#define MCAL_PWM_PWM_PRIV_H_

#define TCCR0               *((u8*)0x53)
#define TCNT0               *((u8*)0x52)
#define OCR0                *((u8*)0x5C)
#define TIMSK               *((u8*)0x59)
#define TIFR                *((u8*)0x58)

#define TIMER0			87
#define TIMER1			8
#define TIMER2			7

#define FAST_PWM            65
#define PHASE_PWM           21

#define SET_CTC_CLR_TOP     23
#define CLR_CTC_SET_TOP     09

#endif /* MCAL_PWM_PWM_PRIV_H_ */
