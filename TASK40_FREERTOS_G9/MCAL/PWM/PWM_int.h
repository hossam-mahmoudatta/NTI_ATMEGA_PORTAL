/*
 * PWM_int.h
 *
 *  Created on: May 26, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_PWM_PWM_INT_H_
#define MCAL_PWM_PWM_INT_H_

void 
 PWM_vidInit(void);

void PWM_vidSetDutyNFreq(u8 Copy_u8DutyCycle , u16 Copy_u16Frequency);

void PWM_vidStopPWM(void);

#endif /* MCAL_PWM_PWM_INT_H_ */
