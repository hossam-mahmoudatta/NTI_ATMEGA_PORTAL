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

void TIMER1_INITIALIZATION(void);

void TIMER1_voidSTART(void);

void TIMER1_voidSTOP(void);

void TIMER1_voidSetPreload(u8 copy_u8preloadValue);

u16 TIMER1_u16getTime(void);

EN_TIMER_Error_t TIMER_Init(uint32_t prescaler);

EN_TIMER_Error_t TIMER_DelaySet(uint32_t prescaler, float timeDelay);

void TIMER_CheckStatus(uint8_t pinNumber, uint8_t portNumber);

void TIMER_Start(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

uint8_t TIMER_Read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

#endif /* TIMER_H_ */
