/*
 * LCD_config.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

/************************************************/
/********** EIGHT_BIT       FOUR_BIT ************/
/************************************************/
#define LCD_MODE                FOUR_BIT

/************************************************/
/*********** Control Pins Assignment ************/
/************************************************/
#define LCD_RS_GRP              DIO_GROUP_A
#define LCD_RS_PIN              DIO_PIN_3

#define LCD_RW_GRP              LCD_NOT_CONNECTED
#define LCD_RW_PIN              LCD_NOT_CONNECTED

#define LCD_EN_GRP              DIO_GROUP_A
#define LCD_EN_PIN              DIO_PIN_2

/************************************************/
/************* Data Pins Assignment *************/
/************************************************/
#define LCD_D7_GRP              DIO_GROUP_B
#define LCD_D7_PIN              DIO_PIN_4

#define LCD_D6_GRP              DIO_GROUP_B
#define LCD_D6_PIN              DIO_PIN_2

#define LCD_D5_GRP              DIO_GROUP_B
#define LCD_D5_PIN              DIO_PIN_1

#define LCD_D4_GRP              DIO_GROUP_B
#define LCD_D4_PIN              DIO_PIN_0

#define LCD_D3_GRP              DIO_GROUP_B
#define LCD_D3_PIN              DIO_PIN_5

#define LCD_D2_GRP              DIO_GROUP_B
#define LCD_D2_PIN              DIO_PIN_4

#define LCD_D1_GRP              DIO_GROUP_B
#define LCD_D1_PIN              DIO_PIN_7

#define LCD_D0_GRP              DIO_GROUP_B
#define LCD_D0_PIN              DIO_PIN_0

#endif /* HAL_LCD_LCD_CONFIG_H_ */
