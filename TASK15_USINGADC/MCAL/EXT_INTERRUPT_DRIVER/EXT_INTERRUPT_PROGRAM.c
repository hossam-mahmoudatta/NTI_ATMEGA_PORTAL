/*
 * EXT_INTERRUPTS.c
 *
 * Created: 8/21/2022 12:37:04 AM
 *  Author: Administrator
 */

/************************************************************************/
/*               External Interrupts Function Declarations              */
/************************************************************************/

#include "EXT_INTERRUPT_INTERFACE.h"

//The function that will be called in the EXT INT
void (*CallBackPtr_INT0) (void);
void (*CallBackPtr_INT1) (void);
void (*CallBackPtr_INT2) (void);


// Enable External Interrupt INT0 & INT1 & INT2
void EXT_INTERRUPT_Sense_voidINTx(u8 copyINTx, u8 CopySense) {
	switch(copyINTx) {
	case EXT_INT0:
		if(CopySense == EXT_INTERRUPT_Low_Level) {
			CLR_BIT(MCUCR_REG, MCUCR_ISC01);
			CLR_BIT(MCUCR_REG, MCUCR_ISC00);
		}
		else if(CopySense == EXT_INTERRUPT_Logical_Change) {
			CLR_BIT(MCUCR_REG, MCUCR_ISC01);
			SET_BIT(MCUCR_REG, MCUCR_ISC00);
		}
		else if(CopySense == EXT_INTERRUPT_Falling_Edge) {
			SET_BIT(MCUCR_REG, MCUCR_ISC01);
			CLR_BIT(MCUCR_REG, MCUCR_ISC00);
		}
		else if(CopySense == EXT_INTERRUPT_Rising_Edge) {
			SET_BIT(MCUCR_REG, MCUCR_ISC01);
			SET_BIT(MCUCR_REG, MCUCR_ISC00);
		}
		break;
	case EXT_INT1:
		if(CopySense == EXT_INTERRUPT_Low_Level) {
			CLR_BIT(MCUCR_REG, MCUCR_ISC11);
			CLR_BIT(MCUCR_REG, MCUCR_ISC10);
		}
		else if(CopySense == EXT_INTERRUPT_Logical_Change) {
			CLR_BIT(MCUCR_REG, MCUCR_ISC11);
			SET_BIT(MCUCR_REG, MCUCR_ISC10);
		}
		else if(CopySense == EXT_INTERRUPT_Falling_Edge) {
			SET_BIT(MCUCR_REG, MCUCR_ISC11);
			CLR_BIT(MCUCR_REG, MCUCR_ISC10);
		}
		else if(CopySense == EXT_INTERRUPT_Rising_Edge) {
			SET_BIT(MCUCR_REG, MCUCR_ISC11);
			SET_BIT(MCUCR_REG, MCUCR_ISC10);
		}
		break;
	case EXT_INT2:
		if(CopySense == EXT_INTERRUPT_INT2_Falling_Edge) {
			CLR_BIT(MCUCSR_REG, MCUCSR_ISC2);
		}
		else if(CopySense == EXT_INTERRUPT_INT2_Rising_Edge) {
			SET_BIT(MCUCSR_REG, MCUCSR_ISC2);
		}
		break;
	}
}

// Enable External Interrupt INT0 & INT1 & INT2
void EXT_INTERRUPT_Enable_voidINTx(u8 copyINTx, void (*copy_PtrtoFunc) (void)) {
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

// Enable External Interrupt INT0 & INT1 & INT2
void EXT_INTERRUPT_Disable_voidINTx(u8 copyINTx) {
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




// Previous prototype __attribute__((signal, used));
// is to tell the compiler that I will use this function
// but not now, so don't optimize and delete it.
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
