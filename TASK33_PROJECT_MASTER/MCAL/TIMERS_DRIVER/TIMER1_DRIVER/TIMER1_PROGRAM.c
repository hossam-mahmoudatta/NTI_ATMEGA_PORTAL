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

#include "TIMER1_INTERFACE.h"

/*******************************************************************************
 *                              							Global Variables				                   	   		  		   *
 *******************************************************************************/

void (*CallBackPtr_TIMER1_CAPT) (void);
void (*CallBackPtr_TIMER1_COMPA) (void);
void (*CallBackPtr_TIMER1_COMPB) (void);
void (*CallBackPtr_TIMER1_OVF) (void);

/*******************************************************************************
 *                              						Functions Declarations	                     	   		  		   *
 *******************************************************************************/

void TIMER1_Initialization(void) {
	// Choose Timer Mode

#if (TIMER1_NORMAL_MODE)
	TCCR1A_REG->FOC1A 	= 1;
	TCCR1A_REG->FOC1B 	= 1;
	TCCR1A_REG->WGM1x 	= 0b00;
	TCCR1B_REG->WGM1x 	= 0b00;
	TCCR1A_REG->COM1Bx 	= 0b10; // Non Inverting Mode
	TCCR1A_REG->COM1Ax 	= 0b10; // Non Inverting Mode
#elif (TIMER1_CTC_MODE)
	TCCR1A_REG->FOC1A 	= 1;
	TCCR1A_REG->FOC1B 	= 1;
	TCCR1A_REG->WGM1x 	= 0b00;
	TCCR1B_REG->WGM1x 	= 0b01;
	TCCR1A_REG->COM1Bx 	= 0b10; // Non Inverting Mode
	TCCR1A_REG->COM1Ax 	= 0b10; // Non Inverting Mode
#elif (TIMER1_PHASEPWM_MODE)
	TCCR1A_REG->FOC1A = 0;
	TCCR1A_REG->FOC1B = 0;
	TCCR1A_REG->WGM1x = 0b01;
	TCCR1B_REG->WGM1x = 0b10;
	TCCR1A_REG->COM1Bx 	= 0b10; // Non Inverting Mode
	TCCR1A_REG->COM1Ax 	= 0b10; // Non Inverting Mode
#elif (TIMER1_FASTPWM_MODE)
	TCCR1A_REG->FOC1A 	= 0;
	TCCR1A_REG->FOC1B 	= 0;
	TCCR1A_REG->WGM1x 	= 0b10;
	TCCR1B_REG->WGM1x 	= 0b11;
	TCCR1A_REG->COM1Bx 	= 0b10; // Non Inverting Mode
	TCCR1A_REG->COM1Ax 	= 0b10; // Non Inverting Mode
#endif

	TCCR1B_REG->CS1x = TIMER1_PRESCALER;
	OCR1A_REG = 500;

#if (TIMER1_ISR_ENABLE)
	TIMSK_REG->TICIE1 = TIMER1_SET;
	TIMSK_REG->OCIE1A = TIMER1_SET;
	TIMSK_REG->OCIE1B = TIMER1_SET;
	TIMSK_REG->TOIE1 = TIMER1_SET;
#endif
}

void TIMER1_voidStart(void) {
	// Choose Timer PRESCALER
	//TCCR1B_REG->CS1x = TIMER1_PRESCALER;
}


void TIMER1_voidStop(void) {
	// Choose Timer PRESCALER
	TCCR1B_REG->CS1x = TIMER1_NO_TIME;
}


void TIMER1_voidSetPreload(u8 copy_u8preloadValue) {
	// Choose Timer PRESCALER
	TCNT1L_REG = copy_u8preloadValue;
}


u16 TIMER1_u16GetTime(void) {
	// Choose Timer PRESCALER
	return (u16)TCNT1L_REG;
}


u16 TIMER1A_SetCOMPAREMATCH_FASTPWM(u16 copy_u16CMP)
{
	 u16 Value = copy_u16CMP;
	 GPIO_voidSetPinDirection(PORT_D, PIN_5, PIN_OUTPUT);
	 OCR1AL_REG = copy_u16CMP;
	 return Value;
}

void TIMER1A_SetTop_FASTPWM(u16 copy_u16ICRValue)
{
	 ICR1L_REG = copy_u16ICRValue;
}

u16 TIMER1A_SetDutyCycle_FASTPWM(u8 copy_u8Duty)
{
	 u16 PWMValue = (u16)(copy_u8Duty * 255) / 100;
	 GPIO_voidSetPinDirection(PORT_D, PIN_5, PIN_OUTPUT);
	 OCR1AL_REG = PWMValue;
	 return PWMValue;
}

u16 TIMER1B_SetDutyCycle_FASTPWM(u8 copy_u8Duty)
{
	 u16 PWMValue = (u16)(copy_u8Duty * 255) / 100;
	 GPIO_voidSetPinDirection(PORT_D, PIN_4, PIN_OUTPUT);
	 OCR1BL_REG = PWMValue;
	 return PWMValue;
}

void TIMER1A_setDelay_ms_CTC(u16 copy_u16Delay)
{
	// Prepare Calculations to calculate OVERFLOWS
			float Tick_Time = 0.001;
			// This will set the Tick Time 1mS
			u16 compareValue = (Tick_Time * (float)F_CPU) / TIMER1_PRESCALER_64;
			TCNT1L_REG = compareValue;

			static u8 overFlowCounter = 0;

			while (overFlowCounter != copy_u16Delay) {
				// This condition is a Busy Wait
				while(TIFR_REG->OCF1A == TIMER1_NOTSET);

				// Clear the overflow flag
				TIFR_REG->OCF1A = TIMER1_SET;
				overFlowCounter++;
			}
			overFlowCounter = 0;
}

void TIMER1B_setDelay_ms_CTC(u16 copy_u16Delay)
{
	// Prepare Calculations to calculate OVERFLOWS
			float Tick_Time = 0.001;
			// This will set the Tick Time 1mS
			u16 compareValue = (Tick_Time * (float)F_CPU) / TIMER1_PRESCALER_64;
			TCNT1L_REG = compareValue;

			static u8 overFlowCounter = 0;

			while (overFlowCounter != copy_u16Delay) {
				// This condition is a Busy Wait
				while(TIFR_REG->OCF1B == TIMER1_NOTSET);

				// Clear the overflow flag
				TIFR_REG->OCF1B = TIMER1_SET;
				overFlowCounter++;
			}
			overFlowCounter = 0;
}

void TIMER1_setDelay_ms_OVF(u16 copy_u16Delay)
{
	// Prepare Calculations to calculate OVERFLOWS
			float Tick_Time = 0;
			Tick_Time = TIMER1_PRESCALER / (float)F_CPU;
			float Time_Overflow = Tick_Time * TIMER1_SIZE;
			float Number_Overflow = ceil((copy_u16Delay) / (Time_Overflow));

			static u8 overFlowCounter = 0;

			while (overFlowCounter != Number_Overflow) {
				// This condition is a Busy Wait
				while(TIFR_REG->TOV1 == TIMER1_NOTSET);

				// Clear the overflow flag
				TIFR_REG->TOV1 = TIMER1_SET;
				overFlowCounter++;
			}
			overFlowCounter = 0;
}

void TIMER1_CallBackFunction_CAPT(void (*Ptr_TIMER)(void))
{
	CallBackPtr_TIMER1_CAPT = Ptr_TIMER;
}

void TIMER1_CallBackFunction_COMPA(void (*Ptr_TIMER)(void))
{
	CallBackPtr_TIMER1_COMPA = Ptr_TIMER;
}

void TIMER1_CallBackFunction_COMPB(void (*Ptr_TIMER)(void))
{
	CallBackPtr_TIMER1_COMPB = Ptr_TIMER;
}

void TIMER1_CallBackFunction_OVF(void (*Ptr_TIMER)(void))
{
	CallBackPtr_TIMER1_OVF = Ptr_TIMER;
}


void __vector_6(void) __attribute__((signal, used));
void __vector_6(void) {
	if(CallBackPtr_TIMER1_CAPT != NULL) {
		CallBackPtr_TIMER1_CAPT();
	}
}

void __vector_7(void) __attribute__((signal, used));
void __vector_7(void) {
	if(CallBackPtr_TIMER1_COMPA != NULL) {
		CallBackPtr_TIMER1_COMPA();
	}
}

void __vector_8(void) __attribute__((signal, used));
void __vector_8(void) {
	if(CallBackPtr_TIMER1_COMPB != NULL) {
		CallBackPtr_TIMER1_COMPB();
	}
}

void __vector_9(void) __attribute__((signal, used));
void __vector_9(void) {
	if(CallBackPtr_TIMER1_OVF != NULL) {
		CallBackPtr_TIMER1_OVF();
	}
}
