 /******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: GLOBAL_INTERRUPT_PROGRAM.c
 *
 * Description: Source file for the AVR Global Interrupt Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "GLOBAL_INTERRUPT_INTERFACE.h"

/*******************************************************************************
 *                              						Functions Declarations                     	      				  *
 *******************************************************************************/

// Enables the Global Interrupt Enable Flag in the Status Register
void GLOBINT_voidSetEnableFlag(void) {
	SET_BIT(SREG_REG, SREG_I_BIT);
}

// Disables the Global Interrupt Disable Flag in the Status Register
void GLOBINT_voidSetDisableFlag(void) {
	CLR_BIT(SREG_REG, SREG_I_BIT);
}


