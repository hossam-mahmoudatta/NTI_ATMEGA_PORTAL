/*
 * UART_config.h
 *
 *  Created on: Sep 27, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

//				NORMAL  ,   DOUBLE
#define SPEED_MODE		DOUBLE

//				TRANSMITTER , RECIEVER, TRANSCIEVER
#define UART_MODE		TRANSCIEVER

//
#define BAUDRATE		9600ul

#define CLOCK_MODE		ASYCH

// 				FIVE , SIX ,
#define DATA_LEN		EIGHT

#define PARITY_STATE	NO_PARITY

#define STOP_STATE		ONE_STOP_BIT


#endif /* UART_CONFIG_H_ */
