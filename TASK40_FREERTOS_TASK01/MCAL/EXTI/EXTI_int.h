/*
 * EXTI_int.h
 *
 *  Created on: Sep 16, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

ES_t EXTI_enuInit(void);

ES_t EXTI_enuSetSenseLevel(u8 Copy_u8IntPin , u8 Copy_u8SenseLevel);

ES_t EXTI_enuEnableInterrupt(u8 Copy_u8IntPin);

ES_t EXTI_enuDisableInterrupt(u8 Copy_u8IntPin);

ES_t EXTI_enuSetCallBack(u8 Copy_u8IntPin , void(*Copy_pFunAppFun)(void));

#define EXTI_INT0                   0
#define EXTI_INT1                   1
#define EXTI_INT2                   2    

#define EXTI_LOW_LEVEL              65
#define EXTI_ANY_CHANGE             32
#define EXTI_FALLING                12
#define EXTI_RISING                 90

#endif /* MCAL_EXTI_EXTI_INT_H_ */
