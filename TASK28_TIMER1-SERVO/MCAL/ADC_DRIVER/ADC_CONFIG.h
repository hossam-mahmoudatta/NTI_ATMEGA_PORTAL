 /******************************************************************************
 *
 * Module: ADC (Analog to Digital Converter)
 *
 * File Name: ADC_CONFIG.h
 *
 * Description: Header file for the AVR ADC Driver Macro Definitions
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*******************************************************************************
 *                              							Macro Definitions						                       		   *
 *******************************************************************************/

#define ADC_MAX_VAL 		1023
#define ADC_REF_VOLT		5

/*******************************************************************************
 *                              							Enum Definitions						                       		   *
 *******************************************************************************/

typedef enum {
	CHANNEL_0 = 0b000,
	CHANNEL_1 = 0b001,
	CHANNEL_2 = 0b010,
	CHANNEL_3 = 0b011,
	CHANNEL_4 = 0b100,
	CHANNEL_5 = 0b101,
	CHANNEL_6 = 0b110,
	CHANNEL_7 = 0b111
} ADC_CHANNEL;

typedef enum {
	RIGHT_ADJUST,
	LEFT_ADJUST
} ADC_ADLAR;

typedef enum {
	AREF = 0b00,
	AVCC = 0b01,
	REFS_RESERVED = 0b10,
	INTERNAL_VOLT = 0b11
} ADC_REFS;

typedef enum {
	ADEN_DISABLE,
	ADEN_ENABLE
} ADC_ENABLE;

typedef enum {
	STOP_CONVERSION,
	START_CONVERSION
} ADC_CONVERSION;

typedef enum {
	DISABLE_TRIGGER,
	ENABLE_TRIGGER
}ADC_TRIGGER;

typedef enum {
	FLAG_NOTSET,
	FLAG_SET
}ADC_FLAG;

typedef enum {
	DISABLE_INT,
	ENABLE_INT
}ADC_INTERRUPT;

typedef enum {
	PRESCALER_0 = 0b000,
	PRESCALER_2 = 0b001,
	PRESCALER_4 = 0b010,
	PRESCALER_8 = 0b011,
	PRESCALER_16 = 0b100,
	PRESCALER_32 = 0b101,
	PRESCALER_64 = 0b110,
	PRESCALER_128 = 0b111
} ADC_PRESCALER;


typedef enum {
	FREE_RUNNING = 0b000,
	ANALOG_COMPARATOR = 0b001,
	EXT_INTERRUPT = 0b010,
	TIMER0_COMPARE = 0b011,
	TIMER0_OVERFLOW = 0b100,
	TIMER1_COMPARE = 0b101,
	TIMER1_OVERFLOW = 0b110,
	TIMER1_CAPTURE = 0b111
} ADC_TRIGGER_SOURCE;


#endif /* ADC_CONFIG_H_ */
