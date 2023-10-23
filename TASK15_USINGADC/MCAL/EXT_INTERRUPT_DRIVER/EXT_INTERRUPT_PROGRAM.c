/******************************************************************************
 *
 * Module: External Interrupts
 *
 * File Name: EXT_INTERRUPT_PROGRAM.c
 *
 * Description: Source file for the AVR EXTERNAL INTERRUPT driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "EXT_INTERRUPT_INTERFACE.h"

/*******************************************************************************
 *                              						Function Declarations					                       		   *
 *******************************************************************************/

//These are the callBack functions for INT0 & INT1 & INT2
void (*CallBackPtr_INT0) (void);
void (*CallBackPtr_INT1) (void);
void (*CallBackPtr_INT2) (void);


// Initialize INT0 & INT1 & INT2 Sense Control System
void EXTINT_voidSetSenseINTx(u8 copyINTx, u8 CopySense) {
	switch(copyINTx) {
	case EXT_INT0:
		if(CopySense == EXTINT_Low_Level) {
			CLR_BIT(MCUCR_REG, MCUCR_ISC01);
			CLR_BIT(MCUCR_REG, MCUCR_ISC00);
		}
		else if(CopySense == EXTINT_Logical_Change) {
			CLR_BIT(MCUCR_REG, MCUCR_ISC01);
			SET_BIT(MCUCR_REG, MCUCR_ISC00);
		}
		else if(CopySense == EXTINT_Falling_Edge) {
			SET_BIT(MCUCR_REG, MCUCR_ISC01);
			CLR_BIT(MCUCR_REG, MCUCR_ISC00);
		}
		else if(CopySense == EXTINT_Rising_Edge) {
			SET_BIT(MCUCR_REG, MCUCR_ISC01);
			SET_BIT(MCUCR_REG, MCUCR_ISC00);
		}
		break;
	case EXT_INT1:
		if(CopySense == EXTINT_Low_Level) {
			CLR_BIT(MCUCR_REG, MCUCR_ISC11);
			CLR_BIT(MCUCR_REG, MCUCR_ISC10);
		}
		else if(CopySense == EXTINT_Logical_Change) {
			CLR_BIT(MCUCR_REG, MCUCR_ISC11);
			SET_BIT(MCUCR_REG, MCUCR_ISC10);
		}
		else if(CopySense == EXTINT_Falling_Edge) {
			SET_BIT(MCUCR_REG, MCUCR_ISC11);
			CLR_BIT(MCUCR_REG, MCUCR_ISC10);
		}
		else if(CopySense == EXTINT_Rising_Edge) {
			SET_BIT(MCUCR_REG, MCUCR_ISC11);
			SET_BIT(MCUCR_REG, MCUCR_ISC10);
		}
		break;
	case EXT_INT2:
		if(CopySense == EXTINT_INT2_Falling_Edge) {
			CLR_BIT(MCUCSR_REG, MCUCSR_ISC2);
		}
		else if(CopySense == EXTINT_INT2_Rising_Edge) {
			SET_BIT(MCUCSR_REG, MCUCSR_ISC2);
		}
		break;
	}
}


// Enable External Interrupt INT0 & INT1 & INT2 and pass a function to ISR
void EXTINT_voidEnableINTx(u8 copyINTx, void (*copy_PtrtoFunc) (void)) {
	switch(copyINTx) {
	case EXT_INT0:
		SET_BIT(GICR_REG, GICR_INT0);
		CallBackPtr_INT0 = copy_PtrtoFunc;
		break;
	case EXT_INT1:
		SET_BIT(GICR_REG, GICR_INT1);
		CallBackPtr_INT1 = copy_PtrtoFunc;
		break;
	case EXT_INT2:
		SET_BIT(GICR_REG, GICR_INT2);
		CallBackPtr_INT2 = copy_PtrtoFunc;
		break;
	default:
		SET_BIT(GICR_REG, GICR_INT0);
		CallBackPtr_INT0 = copy_PtrtoFunc;
		break;
	}
}


// Disable External Interrupt INT0 & INT1 & INT2
void EXTINT_voidDisableINTx(u8 copyINTx) {
	switch(copyINTx) {
	case EXT_INT0:
		CLR_BIT(GICR_REG, GICR_INT0);
		break;
	case EXT_INT1:
		CLR_BIT(GICR_REG, GICR_INT1);
		break;
	case EXT_INT2:
		CLR_BIT(GICR_REG, GICR_INT2);
		break;
	default:
		CLR_BIT(GICR_REG, GICR_INT0);
		break;
	}
}


// Disables Compiler Optimizations & verifies callback not empty
void __vector_1(void) __attribute__((signal, used));
void __vector_1(void) {
	if(CallBackPtr_INT0 != NULL) {
		CallBackPtr_INT0();
	}
}

void __vector_2(void) __attribute__((signal, used));
void __vector_2(void) {
	if(CallBackPtr_INT1 != NULL) {
		CallBackPtr_INT1();
	}
}

void __vector_3(void) __attribute__((signal, used));
void __vector_3(void) {
	if(CallBackPtr_INT2 != NULL) {
		CallBackPtr_INT2();
	}
}


/*
  * is to tell the compiler that I will use this function
  * but not now, so don't optimize and delete it.
  * And to make sure that The callback function actually has
  * an address to another function, not empty and pointed to null.
  */
