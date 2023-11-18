/*
* Timer0_int.h
*
*  Created on: May 20, 2023
*      Author: Ahmed El-Gaafrawy
*/

#ifndef MCAL_TIMER0_TIMER0_INT_H_
#define MCAL_TIMER0_TIMER0_INT_H_

void Timer0_vidInit(void);

void Timer0_vidSetAschDelay(u32 Copy_u32MilliSecond , void (*Copy_pfunAppFun)(void));

void Timer0_vidSetSychDelay(u32 Copy_u32MilliSecond);

void Timer0_vidSetCompareCount(u8 Copy_u8CTCValue);

u8 Timer_u8GetTimerCounts(void);

void Timer_vidSetTimerCounts(u8 Copy_u8Counts);

void Timer_vidCallBack(void (*Copy_pfunCallBack)(void));

void Timer_vidEnableInterrupt(void);

void Timer_vidDisableInterrupt(void);

#endif /* MCAL_TIMER0_TIMER0_INT_H_ */
