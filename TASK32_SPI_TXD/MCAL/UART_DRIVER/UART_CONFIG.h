 /******************************************************************************
 *
 * Module: USART (Universal Synchronous Asynchronous Receiver Transmitter)
 *
 * File Name: USART.h
 *
 * Description: Header file for the AVR USART Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#include "UART_PRIVATE.h"

/*******************************************************************************
 *                              					MACRO DEFINITIONS				                   	   *
 *******************************************************************************/

#define UART_PORT					PORT_D
#define UART_RXD						PIN_0
#define UART_TXD						PIN_1

#define UART_ISR_ENABLE 		0

#define UART_5_BITSIZE			0
#define UART_6_BITSIZE			1
#define UART_7_BITSIZE			2
#define UART_8_BITSIZE			3
#define UART_9_BITSIZE			7
#define UART_BITSIZE	UART_8_BITSIZE

#define UBRR_16MHz_9600		103
#define UBRR_8MHz_9600			51
#define UBRR_1MHz_9600			6
#define UBRR_VALUE					UBRR_1MHz_9600

typedef enum {
    UART_NORMAL_SPEED,
	UART_2X_SPEED,
} 	UART_SPEED;
#define UART_SPEED		UART_NORMAL_SPEED

typedef enum {
    UART_PARITY_DISABLED,
    UART_PARITY_EVEN = 2,
    UART_PARITY_ODD = 3,
} 	UART_Parity;
#define UART_ParityMode	UART_PARITY_DISABLED

typedef enum {
    UART_STOP_1_BIT,
    UART_STOP_2_BIT
} 	UART_StopBit;
#define UART_StopSize		UART_STOP_1_BIT

typedef enum {
	UART_BAUDRATE_2400 = 2400,
	UART_BAUDRATE_4800 = 4800,
	UART_BAUDRATE_9600 = 9600,
	UART_BAUDRATE_14400 = 14400,
}	UART_BaudRate;
#define UART_BaudrateSize		UART_BAUDRATE_9600


#endif /* UART_CONFIG_H_ */
