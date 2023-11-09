/******************************************************************************
 *
 * Module: TIMER1
 *
 * File Name: TIMER1_INTERFACE.h
 *
 * Description: Header file for the TIMER1 Driver Function Prototypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#include "TIMER1_CONFIG.h"

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

void TIMER1_voidInitialization(void);

void TIMER1_voidStart(void);

void TIMER1_voidStop(void);

void TIMER1_voidSetPreload(u8 copy_u8preloadValue);

u16 TIMER1_u16GetTime(void);

u16 TIMER1A_u16SetCompareMatch_PWM(u16 copy_u16CMP);

void TIMER1A_voidSetCounterTopValue_PWM(u16 copy_u16ICRValue);

u16 TIMER1A_u16SetDutyCycle_PWM(u8 copy_u8Duty);

u16 TIMER1B_u16SetDutyCycle_PWM(u8 copy_u8Duty);

void TIMER1A_voidSetDelay_ms_CTC(u16 copy_u16Delay);

void TIMER1B_voidSetDelay_ms_CTC(u16 copy_u16Delay);

void TIMER1_voidSetDelay_ms_OVF(u16 copy_u16Delay);


void TIMER1_CallBackFunction_CAPT(void (*Ptr_TIMER)(void));

void TIMER1_CallBackFunction_COMPAREA(void (*Ptr_TIMER)(void));

void TIMER1_CallBackFunction_COMPAREB(void (*Ptr_TIMER)(void));

void TIMER1_CallBackFunction_OVF(void (*Ptr_TIMER)(void));


#endif /* TIMER_INTERFACE_H_ */
