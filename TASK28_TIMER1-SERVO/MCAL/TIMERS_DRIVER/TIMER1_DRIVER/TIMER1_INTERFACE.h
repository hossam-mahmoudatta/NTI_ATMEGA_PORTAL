/******************************************************************************
 *
 * Module: ADC (Analog to Digital Converter)
 *
 * File Name: ADC_INTERFACE.h
 *
 * Description: Header file for the AVR ADC Driver Function Prototypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "TIMER1_CONFIG.h"

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

void TIMER1_Initialization(void);

void TIMER1_voidStart(void);

void TIMER1_voidStop(void);

void TIMER1_voidSetPreload(u8 copy_u8preloadValue);

u16 TIMER1_u16GetTime(void);

u16 TIMER1A_SetCOMPAREMATCH_FASTPWM(u16 copy_u16CMP);

void TIMER1A_SetTop_FASTPWM(void);

u16 TIMER1A_SetDutyCycle_FASTPWM(u8 copy_u8Duty);

u16 TIMER1B_SetDutyCycle_FASTPWM(u8 copy_u8Duty);

void TIMER1A_setDelay_ms_CTC(u16 copy_u16Delay);

void TIMER1B_setDelay_ms_CTC(u16 copy_u16Delay);

void TIMER1_setDelay_ms_OVF(u16 copy_u16Delay);

void TIMER1_CallBackFunction_CAPT(void (*Ptr_TIMER)(void));

void TIMER1_CallBackFunction_COMPA(void (*Ptr_TIMER)(void));

void TIMER1_CallBackFunction_COMPB(void (*Ptr_TIMER)(void));

void TIMER1_CallBackFunction_OVF(void (*Ptr_TIMER)(void));


#endif /* TIMER_H_ */
