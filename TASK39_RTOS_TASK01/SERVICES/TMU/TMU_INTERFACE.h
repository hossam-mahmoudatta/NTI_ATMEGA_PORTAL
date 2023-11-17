/*
 * TMU_int.h
 *
 *  Created on: Oct 7, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef TMU_TMU_INT_H_
#define TMU_TMU_INT_H_

void TMU_vidInit(void);

void TMU_vidCreateTask(void(*Copy_pfunAppFun)(void), u16 Copy_u16Periodicity , u8 Copy_u8Priority);

void TMU_vidStartScheduler(void);


#endif /* TMU_TMU_INT_H_ */
