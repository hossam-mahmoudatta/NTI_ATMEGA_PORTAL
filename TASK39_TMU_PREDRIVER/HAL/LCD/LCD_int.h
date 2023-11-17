/*
 * LCD_int.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

ES_t LCD_enuSendData(u8 Copy_u8Data);

ES_t LCD_enuSendString(const char *Copy_pcString);
// x 1 ,2  // y 1 -> 16
ES_t LCD_enuGotoXY(u8 Copy_u8X , u8 Copy_u8Y);

ES_t LCD_enuDrawSpecialChar(u8 * Copy_pu8Pattern , u8 Copy_u8PatternNum, u8 Copy_StartPattern , u8 Copy_u8X , u8 Copy_u8Y , u8 Copy_u8PrintDirection);

ES_t LCD_enuWriteIntegarNum(s32 Copy_s32Num);

ES_t LCD_enuWriteFloatNum(f32 Copy_f32Num);

#endif /* HAL_LCD_LCD_INT_H_ */
