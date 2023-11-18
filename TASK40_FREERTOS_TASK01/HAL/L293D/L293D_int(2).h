/*
 * L293D_int.h
 *
 *  Created on: May 6, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_L293D_L293D_INT_H_
#define HAL_L293D_L293D_INT_H_

ES_t L293D_enuInit(void);

ES_t L293D_enuSetDirection(u8 Copy_u8MotorId , u8 Copy_u8Direction);

ES_t L293D_enuSetSpeed(u8 Copy_u8MotorId , u8 Copy_u8SpeedPercentage);

#define L293D_COUNTER_CW        98
#define L293D_CW                65

#define L293D_MOTOR_A           12
#define L293D_MOTOR_B           75

#endif /* HAL_L293D_L293D_INT_H_ */
