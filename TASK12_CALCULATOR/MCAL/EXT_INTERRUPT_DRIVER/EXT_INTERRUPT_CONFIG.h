/*
 * EXT_INTERRUPT_CONFIG.h
 *
 * Created: 8/21/2022 1:17:29 AM
 *  Author: Administrator
 */ 

/************************************************************************/
/*              External Interrupts Typedefs Configurations             */
/************************************************************************/

#ifndef EXT_INTERRUPT_CONFIG_H_
#define EXT_INTERRUPT_CONFIG_H_

// Defining the ISCXX Bits 0-3 in INT0, INT1 for the MCUCR
#define EXT_INTERRUPT_Low_Level					0
#define EXT_INTERRUPT_Logical_Change			1
#define EXT_INTERRUPT_Falling_Edge				2
#define EXT_INTERRUPT_Rising_Edge				3

// Defining the ISC2 Bit6 in INT2 for the MCUCSR
#define EXT_INTERRUPT_INT2_Falling_Edge		0
#define EXT_INTERRUPT_INT2_Rising_Edge		1


#define EXT_INT0		1
#define EXT_INT1		2
#define EXT_INT2		3

#define MCUCR_ISC11	PIN_3
#define MCUCR_ISC10	PIN_2

#define MCUCR_ISC01	PIN_1
#define MCUCR_ISC00	PIN_0

#define MCUCSR_ISC2	PIN_6

#define GICR_INT0		PIN_6
#define GICR_INT1		PIN_7
#define GICR_INT2		PIN_5


/* Configure range of commands to use for INTERRUPT 0 & 1 & 2 Mode
 *	Macros Available:
 *	
 *	EXT_INTERRUPT_Low_Level
 *	EXT_INTERRUPT_Logical_Change
 *	EXT_INTERRUPT_Falling_Edge
 *	EXT_INTERRUPT_Rising_Edge
 *
 *	EXT_INTERRUPT_INT2_Falling_Edge
 *	EXT_INTERRUPT_INT2_Rising_Edge
 *
 */
#define EXT_INTERRUPT_0_MODE						EXT_INTERRUPT_Rising_Edge
#define EXT_INTERRUPT_1_MODE						EXT_INTERRUPT_Falling_Edge

#define EXT_INTERRUPT_2_MODE						EXT_INTERRUPT_INT2_Falling_Edge



/* Configure range of commands to use for GICR INTERRUPT Initial State
 *	Macros Available:
 *	
 *	EXT_INTERRUPT_Disable_State
 *	EXT_INTERRUPT_Enable_State
 *
 */
#define EXT_INTERRUPT_INT0_INIT_STATE		EXT_INTERRUPT_Enable_State
#define EXT_INTERRUPT_INT1_INIT_STATE		EXT_INTERRUPT_Enable_State
#define EXT_INTERRUPT_INT2_INIT_STATE		EXT_INTERRUPT_Disable_State


#endif /* EXT_INTERRUPTS_CONFIG_H_ */
