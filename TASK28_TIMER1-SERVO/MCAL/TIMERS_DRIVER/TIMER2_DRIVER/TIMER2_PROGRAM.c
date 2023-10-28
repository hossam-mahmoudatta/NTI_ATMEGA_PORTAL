/*
 * timer.c
 *
 * Created: 8/19/2022 3:44:03 AM
 *  Author: Administrator
 */ 

#include "TIMER_CONFIG.h"

uint8_t TIMER_VERIFER = NULL;

EN_TIMER_Error_t TIMER_Init(uint32_t prescaler) {
	
	// Initializes the Timer0
	// Sets TCCR0 to 0
	// Assumption that the Timer is in Normal Mode
	// This function gets input of the prescaler
	
	// Choose Timer Mode
	TCCR0 = 0x00; // Normal Mode
	
	switch(prescaler) {
		
		case PRESCALER_NO:
			CLR_BIT(TCCR0, PIN_0);
			CLR_BIT(TCCR0, PIN_1);
			CLR_BIT(TCCR0, PIN_2);
			TIMER_VERIFER = TIMER_OK;
		break;
		
		case PRESCALER_1024:
			SET_BIT(TCCR0, PIN_0);
			CLR_BIT(TCCR0, PIN_1);
			SET_BIT(TCCR0, PIN_2);
			TIMER_VERIFER = TIMER_OK;
		break;
		
		case PRESCALER_256:
			CLR_BIT(TCCR0, PIN_0);
			CLR_BIT(TCCR0, PIN_1);
			SET_BIT(TCCR0, PIN_2);
			TIMER_VERIFER = TIMER_OK;
		break;
		
		case PRESCALER_64:
			SET_BIT(TCCR0, PIN_0);
			SET_BIT(TCCR0, PIN_1);
			CLR_BIT(TCCR0, PIN_2);
			TIMER_VERIFER = TIMER_OK;
		break;
		
		case PRESCALER_8:
			CLR_BIT(TCCR0, PIN_0);
			SET_BIT(TCCR0, PIN_1);
			CLR_BIT(TCCR0, PIN_2);
			TIMER_VERIFER = TIMER_OK;
		break;
		
		case PRESCALER_0:
			SET_BIT(TCCR0, PIN_0);
			CLR_BIT(TCCR0, PIN_1);
			CLR_BIT(TCCR0, PIN_2);
			TIMER_VERIFER = TIMER_OK;
		break;
			
		default:
			TIMER_VERIFER = TIMER_WRONG_PRESCALER;
		break;
	}
	return TIMER_VERIFER;
}

EN_TIMER_Error_t TIMER_DelaySet(uint32_t prescaler, float timeDelay) {
	
	// Sets the delay of Timer0
	// Checks if the Timer_Init returns 0, which means Timer is OK
	// Checks if the entered delay is valid
	// Calculates the overflow amount
	// Sets TCNT0 to 0
	// Sets overflow counter to 0
	// Compares overflow counter with overflow amount in a loop
	// Executes a busy wait function
	// Then clears the TIFR by setting it
	// Iterates Overflow Counter
	
	if ( TIMER_Init(prescaler) != TIMER_OK ) {
		TIMER_VERIFER = TIMER_WRONG_PRESCALER;
	}
	else if ( timeDelay == NULL ) {
		TIMER_VERIFER = TIMER_WRONG_DELAYVALUE;
	}
	else {
		// Prepare Calculations to calculate OVERFLOWS
		float Tick_Time = 0;
		Tick_Time = prescaler / (float)CPU_FREQ;
		float MaxDelay_Time = Tick_Time * SIZEBITS;
		float overflowAmount = floor((timeDelay) / (MaxDelay_Time));

		uint8_t overFlowCounter = 0;
	
		TCNT0 = 0x00;	
	
		//            Algorithm 2(WORKING!)          //
		while (overFlowCounter < overflowAmount) {
			// This function is a Busy Wait
			while ((TIFR_REG & (1 << 0)) == 0);
		
			// Clear the overflow flag
			TIFR_REG |= (1 << 0);
		
			overFlowCounter++;
		}
		overFlowCounter = 0;
		TCNT0_REG = 0x00;
		
		TIMER_VERIFER = TIMER_OK;
	}
	
	return TIMER_VERIFER;
}




// if CPU Frequency: 1 MHz, & Prescaler: 1024
// T_Tick = 1 ms
// T_Max Delay = 0.262 s
// No. Overflows = 20
// I did some calculations on an excel sheet
// to get the least number of overflows to achieve the delay of 5 seconds
// I will have to use the 1024 Prescaler, less than that will lead to higher
// number of overflows
