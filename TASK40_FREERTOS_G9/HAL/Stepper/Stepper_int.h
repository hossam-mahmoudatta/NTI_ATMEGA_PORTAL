/*
 * Stepper_int.h
 *
 *  Created on: Oct 23, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_STEPPER_STEPPER_INT_H_
#define HAL_STEPPER_STEPPER_INT_H_

ES_t Stepper_enuInit(void);

ES_t Stepper_enuMoveOneCycle(u8 Copy_u8Direction);

ES_t Stepper_enuMoveAngle(u8 Copy_u8Direction , u16 Copy_u16Angle);

#define STEPPER_CLOCKWISE				27
#define STEPPER_COUNTERCLOCKWISE		19

#endif /* HAL_STEPPER_STEPPER_INT_H_ */
