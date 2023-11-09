 /******************************************************************************
 *
 * Module: USART (Universal Synchronous Asynchronous Receiver Transmitter)
 *
 * File Name: USART.c
 *
 * Description: Source file for the AVR USART Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "UART_INTERFACE.h"

void (*CallBackPtr_UART_RXC) (void);
void (*CallBackPtr_UART_UDRE) (void);
void (*CallBackPtr_UART_TXC) (void);

/*******************************************************************************
 *                              				FUNCTION IMPLEMENTATIONS				                   	   *
 *******************************************************************************/

void UART_voidInitialization(void) {
/*
	// why uint32? to support the largest baud rate
	// to create a UART driver, I have 4 main parameters
	// Parity, Stop Bit, Data size, Baud Rate

	// All serial peripherals are very slow compared to the processor,
	// for ex. we will use the baudrate 9600, which is approx 9.6 KHz
	// while the processor is 16 MHz, so the risk is that while im looping on the data
	// the looping of the processor will eventually outrace the uart sending time,
	// so u might overwrite on bits inside the UART
	// so we must make polling functions and then set flags
	// to know if i received or sent the data successfully on the uart

	// UBRRL & UBRRH, BaudRate Registers
	// From the datasheet, I need to calculate the UBBR by using this equation:
	// UBBR = ( ((Fcpu) / (8 * Baud)) - 1 )
	// When will this eqn be in -Ve? if the Fcpu is less than '1'
	// What does the -Ve UBBR mean? it means i can't use this baud rate @ this Fcpu
	// The Fcpu must be atleast 8 times larger than the Baud Rate!!!
	// So if my Fcpu = 16Mhz & Baud = 9600, then the UBBR = 207.
*/
	GPIO_voidSetPinDirection(UART_PORT, UART_RXD, PIN_INPUT);
	GPIO_voidSetPinDirection(UART_PORT, UART_TXD, PIN_OUTPUT);
	UCSRA_REG->U2X = UART_SPEED;
	UCSRB_REG->TXEN = 1;
	UCSRB_REG->RXEN = 1;

	u8 UCSRC_Value = 0;
	SET_BIT(UCSRC_Value, UCSRC_URSEL);

	// Choose Character Size
#if (UART_BITSIZE == UART_5_BITSIZE)
	CLR_BIT(UCSRC_Value, UCSRC_UCSZ0);
	CLR_BIT(UCSRC_Value, UCSRC_UCSZ1);
	CLR_BIT(UCSRB_REG, UCSZ2);
#elif (UART_BITSIZE == UART_6_BITSIZE)
	SET_BIT(UCSRC_Value, UCSRC_UCSZ0);
#elif (UART_BITSIZE == UART_7_BITSIZE)
	SET_BIT(UCSRC_Value, UCSRC_UCSZ1);
#elif (UART_BITSIZE == UART_9_BITSIZE)
	SET_BIT(UCSRC_Value, UCSRC_UCSZ0);
	SET_BIT(UCSRC_Value, UCSRC_UCSZ1);
	SET_BIT(UCSRB_REG, UCSZ2);
#else
	SET_BIT(UCSRC_Value, UCSRC_UCSZ0);
	SET_BIT(UCSRC_Value, UCSRC_UCSZ1);
#endif
	UCSRC_REG = UCSRC_Value;

	// For F_CPU: 16 MHz & Baud: 9600, My UBRR: 103
	UBRRL_REG = (u8)(UBRR_VALUE);
	UBRRH_REG = (u8)(UBRR_VALUE >> 8);

	// UBBRH = 0;
	// UBBRL = 207;
	// (0000) (1100 1111) 12 bits, (0000) is for UBBRH, (1100 1111) if for UBBRL
//	UBRR_Value = (u16) ( ( (F_CPU) / (8 * UART_BaudrateSize * 8UL) ) - 1 );
//	UBRRH_REG = UBBR_Value >> 8;
//	// Because I want the 4 Zeroes in it
//
//	UBRRL_REG = UBBR_Value;
//	// Because I want the actual value


#if (UART_ISR_ENABLE == 1)
	UCSRB_REG->RXCIE = 1;
	UCSRB_REG->TXCIE = 1;
	UCSRB_REG->UDRIE = 1;
#endif

}


// Responsible for the USART to send a byte
void UART_voidSendByte_Polling(const u8 data) {
	while(UCSRA_REG->UDRE == 0);
	//UCSRA_REG->TXC = 1;

	UDR_REG = data;

	/*
	 * Put the required data in the UDR register and also clear the UDRE flag as
	 * the UDR register is not empty now
	 */

	/************************* Another Method *************************
	UDR = data;
	while( BIT_IS_CLR(UCSRA, TXC) ){

	} // Wait until the transmission is complete TXC = 1
	SET_BIT(UCSRA,TXC); // Clear the TXC flag
	// This is waiting for the flag to be set to '0' to know that I received data
	*******************************************************************/
}


// Responsible for the USART to receive a byte
u8 UART_voidReceiveByte_Polling(void) {
	// This is waiting for the flag to be set to '0' to know that I received data
	while(UCSRA_REG->RXC == 0);
	//UCSRA_REG->RXC = 1;

	return UDR_REG;		// When reading
}


// Responsible for the USART to send an array of bytes, a string
void UART_voidSendString(const u8 *str) {
	u8 i = 0;
	for(i = 0 ; str[i] ; i++)
	{
		UART_voidSendByte_Polling(str[i]);
	}
}


// Responsible for the USART to receive an array of bytes, a string
void UART_voidReceiveString(u8 *str) {
	u8 i = 0;
	str[0] = UART_voidReceiveByte_Polling();
	for(; str[i] != 0x0d ;)
	{
		i++;
		str[i] = UART_voidReceiveByte_Polling();
	}
	str[i] = 0;
}

void (*CallBackPtr_UART_RXC) (void);
void (*CallBackPtr_UART_UDRE) (void);
void (*CallBackPtr_UART_TXC) (void);

// UART RXC Callback Function
void UART_CallBackFunction_RXC(void (*Ptr_UART_RXC)(void))
{
	CallBackPtr_UART_RXC = Ptr_UART_RXC;
}

// UART UDRE Callback Function
void UART_CallBackFunction_UDRE(void (*Ptr_UART_UDRE)(void))
{
	CallBackPtr_UART_UDRE = Ptr_UART_UDRE;
}

// UART TXC Callback Function
void UART_CallBackFunction_TXC(void (*Ptr_UART_TXC)(void))
{
	CallBackPtr_UART_TXC = Ptr_UART_TXC;
}


// The ISR For the UART RXC Callback Function
void __vector_13(void) __attribute__((signal, used));
void __vector_13(void) {
	if(CallBackPtr_UART_RXC != NULL) {
		CallBackPtr_UART_RXC();
	}
}

// The ISR For the UART UDRE Callback Function
void __vector_14(void) __attribute__((signal, used));
void __vector_14(void) {
	if(CallBackPtr_UART_UDRE != NULL) {
		CallBackPtr_UART_UDRE();
	}
}

// The ISR For the UART TXC Callback Function
void __vector_15(void) __attribute__((signal, used));
void __vector_15(void) {
	if(CallBackPtr_UART_TXC != NULL) {
		CallBackPtr_UART_TXC();
	}
}

