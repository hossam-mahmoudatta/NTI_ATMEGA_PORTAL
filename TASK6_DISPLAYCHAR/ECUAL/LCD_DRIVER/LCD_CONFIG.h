 /******************************************************************************
 *
 * Module: LCD Display
 *
 * File Name: LCD_INTERFACE.h
 *
 * Description: Header file for the AVR LCD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*******************************************************************************
 *                                								Definitions                                  		      *
 *******************************************************************************/

#define LCD_DATA_PORT							PORT_B
#define LCD_DATAPIN_D4						PIN_0
#define LCD_DATAPIN_D5						PIN_1
#define LCD_DATAPIN_D6						PIN_2
#define LCD_DATAPIN_D7						PIN_4

#define LCD_INIT_PORT								PORT_A
#define LCD_RS										PIN_3
#define LCD_ENABLE								PIN_2

#define LCD_CLEAR_DISPLAY					0x01
#define LCD_TWO_LINE_FOUR_BIT			0x28
#define LCD_TWO_LINE_EIGHT_BIT			0x38
#define LCD_CURSOR_OFF          				0x0C
#define LCD_CURSOR_ON          				0x0E
#define LCD_CURSOR_BLINKING          		0x0F
#define LCD_CURSOR_LOCATION        		0x80

#define LCD_ROW_MAXSIZE        				4
#define LCD_COL_MAXSIZE        				20

#endif /* LCD_CONFIG_H_ */
