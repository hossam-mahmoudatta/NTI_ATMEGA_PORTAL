 /******************************************************************************
 *
 * Module: TIMER1
 *
 * File Name: TIMER1_CONFIG.h
 *
 * Description: Header file for the TIMER1 Driver MACRO DEFINITIONS
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

void TIMER1_INITIALIZATION(void) {
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

	TCCR1B_REG->CS1x 		= TIMER1_PRESCALER;

#if (TIMER1_ISR_ENABLE)
	TIMSK_REG->TICIE1 = TIMER1_SET;
	TIMSK_REG->OCIE1A = TIMER1_SET;
	TIMSK_REG->OCIE1B = TIMER1_SET;
	TIMSK_REG->TOIE1 = TIMER1_SET;
#endif
}

void TIMER1_voidSTART(void) {
	// Choose Timer PRESCALER
	TCCR1B_REG->CS1x = TIMER1_PRESCALER;
}


void TIMER1_voidSTOP(void) {
	// Choose Timer PRESCALER
	TCCR1B_REG->CS1x = TIMER1_NO_TIME;
}


void TIMER1_voidSetPreload(u8 copy_u8preloadValue) {
	// Choose Timer PRESCALER
	(u16)TCNT1L_REG = copy_u8preloadValue;
}


u16 TIMER1_u16getTime(void) {
	// Choose Timer PRESCALER
	return (u16)TCNT1L_REG;
}

u8 TIMER1_voidSetDutyCycle_FASTPWM(u8 copy_u8Duty)
{
	 u8 pwmValue = (u16)(copy_u8Duty * 255) / 100;
	 GPIO_voidSetPinDirection(PORT_B, PIN_3, PIN_OUTPUT);
	 OCR0_REG = pwmValue;
	 return pwmValue;
}

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
			while ((TIFR & (1 << 0)) == 0);
		
			// Clear the overflow flag
			TIFR |= (1 << 0);
		
			overFlowCounter++;
		}
		overFlowCounter = 0;
		TCNT0 = 0x00;
		
		TIMER_VERIFER = TIMER_OK;
	}
	
	return TIMER_VERIFER;
	
	//             End of Algorithm 2            //
	
	
	/*	
	//                Algorithm 3                //
	//TCNT0 Register must be SIZEBITS - overflowAmount, to set delay
	//TCNT0 = SIZEBITS - overflowAmount;
	TCNT0 = 0xEB;
	// This function is a Busy Wait
	while ((TIFR & (1 << 0)) == 0);	
	
	TCCR0 = 0x00;
	
	// Clear the overflow flag
	TIFR |= (1 << 0);
	//             End of Algorithm 3            //
	*/

	
	/*
	//                Algorithm 1                //
	// This function is a Busy Wait
	while ((TIFR & (1 << 0)) == 0);	
	TCNT0 = 0x00;
	
	// Clear the overflow flag
	TIFR |= (1 << 0);
	
	overFlowCounter++;
	
	if (overFlowCounter >= overflowAmount) {
		
		overFlowCounter = 0;	
	}
	//             End of Algorithm 1            //
	*/
}

void TIMER_CheckStatus(uint8_t pinNumber, uint8_t portNumber);

void TIMER_Start(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

uint8_t TIMER_Read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);




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
