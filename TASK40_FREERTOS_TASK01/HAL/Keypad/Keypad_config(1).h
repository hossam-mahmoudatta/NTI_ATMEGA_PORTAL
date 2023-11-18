/*
 * Keypad_config.h
 *
 *  Created on: Sep 15, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

/******************************************/
/**** Column , Row Must not exceed 4x4 ****/
/******************************************/
#define KEYPAD_ROW_NUM              4
#define KEYPAD_COL_NUM              4

/******************************************/
/****  Column , Row Pin Configuration  ****/
/******************************************/
#define R1_GRP              DIO_GROUP_C
#define R1_PIN              DIO_PIN_2

#define R2_GRP              DIO_GROUP_C
#define R2_PIN              DIO_PIN_3

#define R3_GRP              DIO_GROUP_C
#define R3_PIN              DIO_PIN_4

#define R4_GRP              DIO_GROUP_C
#define R4_PIN              DIO_PIN_5



#define C1_GRP              DIO_GROUP_D
#define C1_PIN              DIO_PIN_1

#define C2_GRP              DIO_GROUP_D
#define C2_PIN              DIO_PIN_3

#define C3_GRP              DIO_GROUP_D
#define C3_PIN              DIO_PIN_2

#define C4_GRP              DIO_GROUP_D
#define C4_PIN              DIO_PIN_7

/******************************************/
/****           Key Values             ****/
/******************************************/

#define KEYPAD_KEY_VALUES           {\
                                        {'7','8','9','/'},\
                                        {'4','5','6','x'},\
                                        {'1','2','3','-'},\
                                        {'C','0','=','+'},\
                                    }

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
