/*
 * Timer0_config.h
 *
 *  Created on: May 20, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_

    // [   0 -> stop timer , 1 , 8 , 64 , 256 , 1024 ]
#define TIMER0_PRESCALER         8

#define TIMER0_MODE             TIMER0_OVF

#define TIMER0_INTERRUPT_MODE   TIMER0_INTERRUPT

#define TIMER0_OC0_OUT          OC0_DISCONNECTED

#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
