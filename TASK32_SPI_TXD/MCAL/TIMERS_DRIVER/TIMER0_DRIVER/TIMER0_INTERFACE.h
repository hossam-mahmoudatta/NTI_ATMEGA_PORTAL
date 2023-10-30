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

#include "TIMER0_CONFIG.h"

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

void TIMER0_INITIALIZATION(void);

void TIMER0_START(void);

void TIMER0_STOP(void);

void TIMER0_setPreload(u8 preloadValue);

u8 TIMER0_getTime(void);

u8 TIMER0_voidSetDutyCycle_FASTPWM(u8 copy_u8Duty);

u16 DutyCycle_ADC_Mapping(u16 copy_u16Data);

void TIMER0_setDelay_ms_CTC(u16 copy_u16Delay);

void TIMER0_setDelay_ms_OVF(u16 copy_u16Delay);

void TIMER0_CallBackFunction_COMP(void (*Ptr_TIMER)(void));

void TIMER0_CallBackFunction_OVF(void (*Ptr_TIMER)(void));

#endif /* TIMER_H_ */
