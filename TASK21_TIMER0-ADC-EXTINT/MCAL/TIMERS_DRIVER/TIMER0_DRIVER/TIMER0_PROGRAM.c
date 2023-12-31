/******************************************************************************
 *
 * Module: ADC (Analog to Digital Converter)
 *
 * File Name: ADC_PROGRAM.c
 *
 * Description: Source file for the AVR ADC Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "TIMER0_INTERFACE.h"

/*******************************************************************************
 *                              							Global Variables				                   	   		  		   *
 *******************************************************************************/

void (*CallBackPtr_TIMER0_COMP) (void);
void (*CallBackPtr_TIMER0_OVF) (void);

/*******************************************************************************
 *                              						Functions Declarations	                     	   		  		   *
 *******************************************************************************/

void TIMER0_INITIALIZATION(void) {
	// Choose Timer Mode
	//TCCR0_REG = 0x00; // Normal Mode
	TCCR0_REG->FOC0 = 0;
#if (NORMAL_MODE)
	TCCR0_REG->WGM01 = 0;
	TCCR0_REG->WGM00 = 0;
#elif (PWM_MODE)
	TCCR0_REG->WGM01 = 0;
	TCCR0_REG->WGM00 = 1;
#elif (CTC_MODE)
	TCCR0_REG->WGM01 = 1;
	TCCR0_REG->WGM00 = 0;
#elif (FASTPWM_MODE)
	TCCR0_REG->WGM01 = 1;
	TCCR0_REG->WGM00 = 1;
#endif

#if (ISR_ENABLE)
	TIMSK_REG->TOIE0 = 1;
#endif
}


void TIMER0_START(void) {
	// Choose Timer PRESCALER
	TCCR0_REG->CS0x = TIMER0_PRESCALER_1024;
}


void TIMER0_STOP(void) {
	// Choose Timer PRESCALER
	TCCR0_REG->CS0x = NO_TIME;
}


void TIMER0_setPreload(u8 preloadValue) {
	// Choose Timer PRESCALER
	TCNT0_REG = preloadValue;
}


u8 TIMER0_getTime(void) {
	// Choose Timer PRESCALER
	return TCNT0_REG;
}


void TIMER0_CallBackFunction_COMP(void (*Ptr_TIMER)(void))
{
	CallBackPtr_TIMER0_COMP = Ptr_TIMER;
}

void TIMER0_CallBackFunction_OVF(void (*Ptr_TIMER)(void))
{
	CallBackPtr_TIMER0_OVF = Ptr_TIMER;
}


void __vector_10(void) __attribute__((signal, used));
void __vector_10(void) {
	if(CallBackPtr_TIMER0_COMP != NULL) {
		CallBackPtr_TIMER0_COMP();
	}
}

void __vector_11(void) __attribute__((signal, used));
void __vector_11(void) {
	if(CallBackPtr_TIMER0_OVF != NULL) {
		CallBackPtr_TIMER0_OVF();
	}
}

