/*
 * interrupt.h
 *
 * Created: 8/20/2022 10:34:02 PM
 *  Author: Administrator
 */ 

/************************************************************************/
/*                External Interrupts Functions Prototypes              */
/************************************************************************/

#ifndef EXT_INTERRUPT_INTERFACE_H_
#define EXT_INTERRUPT_INTERFACE_H_

#include "EXT_INTERRUPT_CONFIG.h"
#include "EXT_INTERRUPT_PRIVATE.h"

// Initialize External Interrupt
void EXT_INTERRUPT_Sense_voidINTx(u8 copyINTx, u8 CopySense);

void EXT_INTERRUPT_Enable_voidINTx(u8 copyINTx, void (*copy_PtrtoFunc) (void));

void EXT_INTERRUPT_Disable_voidINTx(u8 copyINTx);

#endif /* EXT_INTERRUPT_H_ */
