 /******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: GLOBAL_INTERRUPT_PRIVATE.h
 *
 * Description: Header file for the AVR Global Interrupt Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef GLOBAL_INTERRUPT_PRIVATE_H_
#define GLOBAL_INTERRUPT_PRIVATE_H_

#include "../GPIO_DRIVER/GPIO_INTERFACE.h"

/*******************************************************************************
 *                              				External Interrupts Registers                     	      				  *
 *******************************************************************************/

#define SREG_REG    	(*( (volatile u8*) 0x5F) )


#endif /* GLOBAL_INTERRUPT_PRIVATE_H_ */
