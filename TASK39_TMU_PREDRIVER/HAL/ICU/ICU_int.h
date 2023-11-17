/*
 * ICU_int.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_ICU_ICU_INT_H_
#define HAL_ICU_ICU_INT_H_

void ICU_vidInit(void);

void ICU_vidCalculatePWMParams(void);

void ICU_vidStartCapture(void);

u8 ICU_u8GetDutyCycle(void);

u32 ICU_u32GetFrequency(void);

void ICU_vidEnableReadingUltraSonic(void);

#endif /* HAL_ICU_ICU_INT_H_ */
