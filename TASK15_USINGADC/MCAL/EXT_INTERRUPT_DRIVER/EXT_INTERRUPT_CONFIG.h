/******************************************************************************
 *
 * Module: External Interrupts
 *
 * File Name: EXT_INTERRUPT_CONFIG.h
 *
 * Description: Header file for the AVR EXTERNAL INTERRUPT Driver Config
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef EXT_INTERRUPT_CONFIG_H_
#define EXT_INTERRUPT_CONFIG_H_

/*******************************************************************************
 *                              							Macro Definitions						                       		   *
 *******************************************************************************/

// Defining the ISCxx Bits 0-3 in INT0, INT1 for the MCUCR
#define EXTINT_Low_Level					0
#define EXTINT_Logical_Change		1
#define EXTINT_Falling_Edge				2
#define EXTINT_Rising_Edge				3

// Defining the ISC2 Bit6 in INT2 for the MCUCSR
#define EXTINT_INT2_Falling_Edge	0
#define EXTINT_INT2_Rising_Edge		1

// Numbering the INTx
#define EXT_INT0		1
#define EXT_INT1		2
#define EXT_INT2		3

// Masking Pins to the Registers
#define MCUCR_ISC11		PIN_3
#define MCUCR_ISC10		PIN_2

#define MCUCR_ISC01		PIN_1
#define MCUCR_ISC00	PIN_0

#define MCUCSR_ISC2	PIN_6

#define GICR_INT0			PIN_6
#define GICR_INT1			PIN_7
#define GICR_INT2			PIN_5

#define EXTINT_INT0_MODE						EXTINT_Rising_Edge
#define EXTINT_INT1_MODE						EXTINT_Falling_Edge
#define EXTINT_INT2_MODE						EXTINT_INT2_Falling_Edge


#endif /* EXT_INTERRUPTS_CONFIG_H_ */
