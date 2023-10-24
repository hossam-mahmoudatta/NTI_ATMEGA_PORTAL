/******************************************************************************
 *
 * Module: External Interrupts
 *
 * File Name: EXT_INTERRUPT_INTERFACE.h
 *
 * Description: Header file for the AVR EXTERNAL INTERRUPT Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef EXT_INTERRUPT_INTERFACE_H_
#define EXT_INTERRUPT_INTERFACE_H_

#include "EXT_INTERRUPT_CONFIG.h"
#include "EXT_INTERRUPT_PRIVATE.h"

/*******************************************************************************
 *                              						Function Prototypes					               			    	   *
 *******************************************************************************/

// Initialize INT0 & INT1 & INT2 Sense Control System
void EXTINT_voidSetSenseINTx(u8 copyINTx, u8 CopySense);

// Enable External Interrupt INT0 & INT1 & INT2 and pass a function to ISR
void EXTINT_voidEnableINTx(u8 copyINTx, void (*copy_PtrtoFunc) (void));

// Disable External Interrupt INT0 & INT1 & INT2
void EXTINT_voidDisableINTx(u8 copyINTx);


#endif /* EXT_INTERRUPT_H_ */
