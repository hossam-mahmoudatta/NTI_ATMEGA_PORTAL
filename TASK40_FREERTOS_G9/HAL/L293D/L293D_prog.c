/*
 * L293D_prog.c
 *
 *  Created on: May 6, 2023
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../ATmega32_config.h"
#if atmega32ENABLE_HAL_L293D != 0



#include "../../stdTypes.h"
#include "../../errorState.h"

#include "../../MCAL/DIO/DIO_int.h"
//#include "../../MCAL/Timer/Timer_int.h"

#include "L293D_config.h"
#include "L293D_priv.h"

ES_t L293D_enuInit(void)
{
    DIO_enuSetPinDirection(L293D_EN1_GRP,L293D_EN1_PIN, DIO_OUTPUT);
    DIO_enuSetPinDirection(L293D_EN2_GRP,L293D_EN2_PIN, DIO_OUTPUT);

    DIO_enuSetPinDirection(L293D_IN1_GRP,L293D_IN1_PIN, DIO_OUTPUT);
    DIO_enuSetPinDirection(L293D_IN2_GRP,L293D_IN2_PIN, DIO_OUTPUT);
    DIO_enuSetPinDirection(L293D_IN3_GRP,L293D_IN3_PIN, DIO_OUTPUT);
    DIO_enuSetPinDirection(L293D_IN4_GRP,L293D_IN4_PIN, DIO_OUTPUT);

    // pwm_init for en1, en2

    return ES_OK;
}

ES_t L293D_enuSetDirection(u8 Copy_u8MotorId , u8 Copy_u8Direction)
{
    if (Copy_u8Direction == L293D_CW)
    {
        if (Copy_u8MotorId==L293D_MOTOR_A)
        {
            DIO_enuSetPinValue(L293D_IN1_GRP, L293D_IN1_PIN, DIO_HIGH);
            DIO_enuSetPinValue(L293D_IN2_GRP, L293D_IN2_PIN, DIO_LOW);
        }
        else if(Copy_u8MotorId == L293D_MOTOR_B)
        {
            DIO_enuSetPinValue(L293D_IN3_GRP, L293D_IN1_PIN, DIO_HIGH);
            DIO_enuSetPinValue(L293D_IN4_GRP, L293D_IN2_PIN, DIO_LOW);
        }
    }
    else if (Copy_u8Direction == L293D_COUNTER_CW)
    {
        if (Copy_u8MotorId==L293D_MOTOR_A)
        {
            DIO_enuSetPinValue(L293D_IN1_GRP, L293D_IN1_PIN, DIO_LOW);
            DIO_enuSetPinValue(L293D_IN2_GRP, L293D_IN2_PIN, DIO_HIGH);
        }
        else if(Copy_u8MotorId == L293D_MOTOR_B)
        {
            DIO_enuSetPinValue(L293D_IN3_GRP, L293D_IN1_PIN, DIO_LOW);
            DIO_enuSetPinValue(L293D_IN4_GRP, L293D_IN2_PIN, DIO_HIGH);
        }
    }
    return ES_OK;
}

ES_t L293D_enuSetSpeed(u8 Copy_u8MotorId , u8 Copy_u8SpeedPercentage)
{
    if (Copy_u8MotorId==L293D_MOTOR_A)
    {
        if (Copy_u8SpeedPercentage == 0)
        {
            DIO_enuSetPinValue(L293D_EN1_GRP, L293D_EN1_PIN, DIO_LOW);
        }
        else if (Copy_u8SpeedPercentage == 100)
        {
            DIO_enuSetPinValue(L293D_EN1_GRP, L293D_EN1_PIN, DIO_HIGH);
        }
        else if (Copy_u8SpeedPercentage >0 && Copy_u8SpeedPercentage <100)
        {
            //Timer PWM 
        }
    }
    else if(Copy_u8MotorId == L293D_MOTOR_B)
    {
        if (Copy_u8SpeedPercentage == 0)
        {
            DIO_enuSetPinValue(L293D_EN2_GRP, L293D_EN2_PIN, DIO_LOW);
        }
        else if (Copy_u8SpeedPercentage == 100)
        {
            DIO_enuSetPinValue(L293D_EN2_GRP, L293D_EN2_PIN, DIO_HIGH);
        }
        else if (Copy_u8SpeedPercentage >0 && Copy_u8SpeedPercentage <100)
        {
            //Timer PWM 
        }
    }
    return ES_OK;
}

#endif