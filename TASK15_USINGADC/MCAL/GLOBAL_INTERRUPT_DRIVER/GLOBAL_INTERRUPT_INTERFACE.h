 /******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: GLOBAL_INTERRUPT_INTERFACE.h
 *
 * Description: Header file for the AVR Global Interrupt Driver Protoypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef GLOBAL_INTERRUPT_INTERFACE_H_
#define GLOBAL_INTERRUPT_INTERFACE_H_

#include "GLOBAL_INTERRUPT_CONFIG.h"
#include "GLOBAL_INTERRUPT_PRIVATE.h"

/*******************************************************************************
 *                              						Functions Prototypes                           						  *
 *******************************************************************************/

// Enables the Global Interrupt Enable Flag in the Status Register
void GLOBINT_voidSetEnableFlag(void);

// Disables the Global Interrupt Disable Flag in the Status Register
void GLOBINT_voidSetDisableFlag(void);


#endif /* GLOBAL_INTERRUPT_INTERFACE_H_ */


