 /******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXT_INTERRUPT.c
 *
 * Description: Source file for the AVR External Interrupt Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "GLOBAL_INTERRUPT_INTERFACE.h"


// Initialize External Interrupt
void GLOBAL_INTERRUPT_voidEnable(void) {
	SET_BIT(SREG_REG, SREG_I_BIT);
}

void GLOBAL_INTERRUPT_voidDisable(void) {
	CLR_BIT(SREG_REG, SREG_I_BIT);
}


