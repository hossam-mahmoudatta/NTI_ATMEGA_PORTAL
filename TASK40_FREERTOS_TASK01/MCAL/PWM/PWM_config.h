/*
 * PWM_config.h
 *
 *  Created on: May 26, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_PWM_PWM_CONFIG_H_
#define MCAL_PWM_PWM_CONFIG_H_

#define PWM_CHANNEL			TIMER0

#define PWM_TYPE            FAST_PWM

#define TIMER0_PRESCALER         1024

#define TIMER0_OC0_OUT          CLR_CTC_SET_TOP

#endif /* MCAL_PWM_PWM_CONFIG_H_ */
