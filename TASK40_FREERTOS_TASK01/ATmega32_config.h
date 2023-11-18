/*
 * ATmega32_config.h
 *
 *  Created on: Nov 16, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef ATMEGA32_CONFIG_H_
#define ATMEGA32_CONFIG_H_

#define atmega32ENABLE_APP_POV                          1
#define atmega32ENABLE_APP_LIGHT                        1
#define atmega32ENABLE_APP_UPDATE                       1

#define atmega32ENABLE_HAL_COMMUNICATION                0
#define atmega32ENABLE_HAL_EEPROM                       0
#define atmega32ENABLE_HAL_HEXADECODER                  1
#define atmega32ENABLE_HAL_ICU                          0
#define atmega32ENABLE_HAL_KEYPAD                       0
#define atmega32ENABLE_HAL_L293D                        0
#define atmega32ENABLE_HAL_PARSING                      0
#define atmega32ENABLE_HAL_STEPPER                      0
#define atmega32ENABLE_HAL_SWITCH                       1

#define atmega32ENABLE_MCAL_ADC                         0
#define atmega32ENABLE_MCAL_DIO                         1
#define atmega32ENABLE_MCAL_EXTI                        0
#define atmega32ENABLE_MCAL_GIE                         0
#define atmega32ENABLE_MCAL_IIC                         0
#define atmega32ENABLE_MCAL_EEPROM                      0
#define atmega32ENABLE_MCAL_PWM                         0
#define atmega32ENABLE_MCAL_SPI                         0
#define atmega32ENABLE_MCAL_TIMER0                      0
#define atmega32ENABLE_MCAL_UART                        1
#define atmega32ENABLE_MCAL_WDT                         0

#endif /* ATMEGA32_CONFIG_H_ */
