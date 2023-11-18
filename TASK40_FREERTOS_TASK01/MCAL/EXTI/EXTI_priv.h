/*
 * EXTI_priv.h
 *
 *  Created on: Sep 16, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

static ES_t enuSetSenseLevel(u8 Copy_u8IntPin, u8 Copy_u8SenseLevel);
static ES_t enuSetIntMode(u8 Copy_u8IntPin, u8 Copy_u8IntMode);


#define MCUCR                       *((volatile u8*)0x55)
#define MCUCSR                      *((volatile u8*)0x54)
#define GICR                        *((volatile u8*)0x5B)
#define GIFR                        *((volatile u8*)0x5A)


#define EXTI_LOW_LEVEL              65
#define EXTI_ANY_CHANGE             32
#define EXTI_FALLING                12
#define EXTI_RISING                 90

#define EXTI_INTERRUPT_MODE         74
#define EXTI_POLLING_MODE           69

#define EXTI_INT0                   0
#define EXTI_INT1                   1
#define EXTI_INT2                   2    

#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
