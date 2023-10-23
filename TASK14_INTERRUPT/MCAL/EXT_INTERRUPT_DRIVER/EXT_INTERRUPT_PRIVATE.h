/*
 * EXT_INTERRUPTS_PRIVATE.h
 *
 * Created: 8/21/2022 12:40:29 AM
 *  Author: Administrator
 */ 

/************************************************************************/
/*                    External Interrupts Registers                     */
/************************************************************************/

#ifndef EXT_INTERRUPT_PRIVATE_H_
#define EXT_INTERRUPT_PRIVATE_H_

#include "../GPIO_DRIVER/GPIO_INTERFACE.h"

// External Interrupts
#define MCUCR_REG   	(*( (volatile u8*) 0x55) )
#define MCUCSR_REG  (*( (volatile u8*) 0x54) )
#define GICR_REG    		(*( (volatile u8*) 0x5B) )
#define GIFR_REG    		(*( (volatile u8*) 0x5A) )

#endif /* EXT_INTERRUPTS_PRIVATE_H_ */
