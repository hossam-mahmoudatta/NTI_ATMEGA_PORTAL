 /******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXT_INTERRUPT.h
 *
 * Description: Header file for the AVR External Interrupt Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef GLOBAL_INTERRUPT_H_
#define GLOBAL_INTERRUPT_H_

#include "GLOBAL_INTERRUPT_CONFIG.h"
#include "GLOBAL_INTERRUPT_PRIVATE.h"


/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

void GLOBAL_INTERRUPT_voidEnable(void);

void GLOBAL_INTERRUPT_voidDisable(void);


#endif /* EXT-INTERRUPT_H_ */


