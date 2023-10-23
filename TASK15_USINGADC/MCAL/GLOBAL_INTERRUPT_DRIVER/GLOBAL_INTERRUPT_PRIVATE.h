/*
 * EXT_INTERRUPTS_PRIVATE.h
 *
 * Created: 8/21/2022 12:40:29 AM
 *  Author: Administrator
 */ 

/************************************************************************/
/*                    External Interrupts Registers                     */
/************************************************************************/

#ifndef GLOBAL_INTERRUPT_PRIVATE_H_
#define GLOBAL_INTERRUPT_PRIVATE_H_

#include "../GPIO_DRIVER/GPIO_INTERFACE.h"

// External Interrupts
#define SREG_REG    	(*( (volatile u8*) 0x5F) )


#endif /* GLOBAL_INTERRUPT_PRIVATE_H_ */
