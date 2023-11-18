/*
 * Keypad_int.h
 *
 *  Created on: Sep 15, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

ES_t Keypad_enuInit(void);

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue);

#define KEYPAD_NOT_PRESSED          0xFF


#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
