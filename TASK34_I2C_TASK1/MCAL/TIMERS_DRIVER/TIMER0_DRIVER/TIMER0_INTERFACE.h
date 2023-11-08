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
#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "TIMER0_CONFIG.h"

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

void TIMER0_voidInitialization(void);

void TIMER0_voidStart(void);

void TIMER0_voidStop(void);

void TIMER0_voidSetPreload(u8 copy_u8PreloadValue);

u8 TIMER0_u8GetTime(void);

u8 TIMER0_u8SetDutyCycle_PWM(u8 copy_u8DutyCycle);

void TIMER0_voidSetDelay_ms_CTC(u16 copy_u16Delay);

void TIMER0_voidSetDelay_ms_OVF(u16 copy_u16Delay);

u16 TIMER0_u16ADC_Mapping(u16 copy_u16Data);

void TIMER0_CallBackFunction_COMP(void (*Ptr_TIMER)(void));

void TIMER0_CallBackFunction_OVF(void (*Ptr_TIMER)(void));

#endif /* TIMER_INTERFACE_H_ */
