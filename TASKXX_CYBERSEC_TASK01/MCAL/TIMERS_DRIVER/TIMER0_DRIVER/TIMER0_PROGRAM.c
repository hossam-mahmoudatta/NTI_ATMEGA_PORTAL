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
#if (TIMER0_NORMAL_MODE)
	TCCR0_REG->FOC0 = 0;
	TCCR0_REG->WGM01 = 0;
	TCCR0_REG->WGM00 = 0;
#elif (TIMER0_CTC_MODE)
	TCCR0_REG->FOC0 = 1;
	TCCR0_REG->WGM01 = 1;
	TCCR0_REG->WGM00 = 0;
	TCCR0_REG->COM0x = TIMER0_COM_CTC_MODE;
#elif (TIMER0_PHASEPWM_MODE)
	TCCR0_REG->FOC0 = 0;
	TCCR0_REG->WGM01 = 0;
	TCCR0_REG->WGM00 = 1;
	TCCR0_REG->COM0x = TIMER0_COM_PHASEPWM_MODE;
#elif (TIMER0_FASTPWM_MODE)
	TCCR0_REG->FOC0 	= 	0;
	TCCR0_REG->WGM01 = 1;
	TCCR0_REG->WGM00 = 1;
	TCCR0_REG->COM0x 	= TIMER0_COM_FASTPWM_MODE;
#endif

#if (ISR_ENABLE)
	TIMSK_REG->TOIE0 = 1;
#endif
}


void TIMER0_START(void) {
	// Choose Timer PRESCALER
	TCCR0_REG->CS0x = TIMER0_PRESCALER;
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


u8 TIMER0_voidSetDutyCycle_FASTPWM(u8 copy_u8Duty)
{
	 u8 pwmValue = (u16)(copy_u8Duty * 255) / 100;
	 GPIO_voidSetPinDirection(PORT_B, PIN_3, PIN_OUTPUT);
	 OCR0_REG = pwmValue;
	 return pwmValue;
}


u16 DutyCycle_ADC_Mapping(u16 copy_u16Data)
{
	u8 dutyCycleValue = ((u32)copy_u16Data * 100) / 1023;
	return  dutyCycleValue ;
}


void TIMER0_setDelay_ms_CTC(u16 copy_u16Delay)
{
	// Prepare Calculations to calculate OVERFLOWS
			float Tick_Time = 0.001;
			// This will set the Tick Time 1mS
			u8 compareValue = (Tick_Time * (float)F_CPU) / TIMER0_PRESCALER_64;
			TCNT0_REG = compareValue;

			static u8 overFlowCounter = 0;

			while (overFlowCounter != copy_u16Delay) {
				// This condition is a Busy Wait
				while(TIFR_REG->OCF0 == 0);

				// Clear the overflow flag
				TIFR_REG->OCF0 = 1;
				overFlowCounter++;
			}
			overFlowCounter = 0;
}

void TIMER0_setDelay_ms_CTC_ISR(u16 copy_u16Delay)
{
	// Prepare Calculations to calculate OVERFLOWS
			float Tick_Time = 0.001;
			// This will set the Tick Time 1mS
			u8 compareValue = (Tick_Time * (float)F_CPU) / TIMER0_PRESCALER;
			TCNT0_REG = compareValue;
}

void TIMER0_setDelay_ms_OVF(u16 copy_u16Delay)
{
	// Prepare Calculations to calculate OVERFLOWS
			float Tick_Time = 0;
			Tick_Time = TIMER0_PRESCALER / (float)F_CPU;
			float Time_Overflow = Tick_Time * TIMER0_SIZE;
			float Number_Overflow = ceil((copy_u16Delay) / (Time_Overflow));

			static u8 overFlowCounter = 0;

			while (overFlowCounter != Number_Overflow) {
				// This condition is a Busy Wait
				while(TIFR_REG->TOV0 == 0);

				// Clear the overflow flag
				TIFR_REG->TOV0 = 1;
				overFlowCounter++;
			}
			overFlowCounter = 0;
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

