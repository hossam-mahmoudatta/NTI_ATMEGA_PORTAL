/*
 * ADC_priv.h
 *
 *  Created on: Sep 23, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

#define ADMUX           *((volatile u8*)0x27)
#define ADCSRA          *((volatile u8*)0x26)
#define ADCH            *((volatile u8*)0x25)
#define ADCL            *((volatile u8*)0x24)
#define SFIOR           *((volatile u8*)0x50)



#define ADC_PRES_2          1
#define ADC_PRES_4          2
#define ADC_PRES_8          3
#define ADC_PRES_16         4
#define ADC_PRES_32         5
#define ADC_PRES_64         6
#define ADC_PRES_128        7

#define ADC_LEFT_ADJ            98
#define ADC_RIGHT_ADJ           45

#define ADC_INTERRUPT              65
#define ADC_POLLING                43

#define ADC_V_AREF                21
#define ADC_V_AVCC                53
#define ADC_V_INTERNAL            74

#define ADC_SINGLE_CONV                 70
#define ADC_FREE_RUNNING_CONV           10
#define ADC_ANALOG_COMP_TRIGGER         11
#define ADC_EXTI0_TRIGGER               12
#define ADC_TIM0_COMP_TRIGGER           13
#define ADC_TIM0_OVF_TRIGGER            14



#endif /* MCAL_ADC_ADC_PRIV_H_ */
