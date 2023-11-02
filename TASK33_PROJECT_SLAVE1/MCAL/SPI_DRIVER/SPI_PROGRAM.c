 /******************************************************************************
 *
 * Module: SPI (Serial Peripheral Interface)
 *
 * File Name: SPI_PROGRAM.h
 *
 * Description: Source file for the AVR SPI Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "SPI_INTERFACE.h"

void (*CallBackPtr_SPI) (void);

/*******************************************************************************
 *                              				FUNCTION IMPLEMENTATIONS				                   	   *
 *******************************************************************************/

// Initializes and enables the Master mode for the SPI Module to start functionality
void SPI_voidInitialization_Master(void) {
	GPIO_voidSetPinDirection(PORT_B, SS, PIN_OUTPUT);
	GPIO_voidSetPinDirection(PORT_B, MOSI, PIN_OUTPUT);
	GPIO_voidSetPinDirection(PORT_B, MISO, PIN_INPUT);
	GPIO_voidSetPinDirection(PORT_B, SCK, PIN_OUTPUT);

	GPIO_voidSetPinValue(PORT_B, SS, LOGIC_HIGH);

	SPCR_REG->SPE = 1;
	SPCR_REG->MSTR = 1;
	SPCR_REG->SPRx = SPI_CLOCK_RATE;
	SPCR_REG->DORD = 0;
	SPSR_REG->SPI2x = 0;

#if (SPI_ISR_ENABLE)
	SPCR_REG->SPIE = 1;
#endif
}

// Initializes and enables the Slave mode for the SPI Module to start functionality
void SPI_voidInitialization_Slave(void) {
	GPIO_voidSetPinDirection(PORT_B, SS, PIN_INPUT);
	GPIO_voidSetPinDirection(PORT_B, MOSI, PIN_INPUT);
	GPIO_voidSetPinDirection(PORT_B, MISO, PIN_OUTPUT);
	GPIO_voidSetPinDirection(PORT_B, SCK, PIN_INPUT);

	GPIO_voidSetPinValue(PORT_B, SS, LOGIC_LOW);

	SPCR_REG->SPE = 1;// Enabling the SPI Module
	SPCR_REG->MSTR = 0;// Enabling the Master / Slave Mode; I will choose Master
	SPCR_REG->SPRx = SPI_CLOCK_RATE;
	SPCR_REG->DORD = 0;
	SPSR_REG->SPI2x = 0;

#if (SPI_ISR_ENABLE)
	SPCR_REG->SPIE = 1;
#endif
}


// Responsible for the SPI to send & receive a byte
u8 SPI_u8SendReceiveByte_Polling(u8 copy_u8Data) {
	SPDR_REG = copy_u8Data;
	while(SPSR_REG->SPIF == 0)
	{
		// Polling (Busy Wait)
		/* Waiting for the flag is set, it is set when data transmission
		 * flag is set, Master will set SS to low to generate clock on SCK pin
		 */
	}
	// after SPIF is set, then I return the data
	return SPDR_REG;
}

// Use the SPI to send a byte using Polling
u8 SPI_u8SendByte_Polling(u8 copy_u8Data) {
	u8 flushBuffer;
	SPDR_REG = copy_u8Data;
	while(SPSR_REG->SPIF == 0)
	{
		// Polling (Busy Wait)
		/* Waiting for the flag is set, it is set when data transmission
		 * flag is set, Master will set SS to low to generate clock on SCK pin
		 */
	}
	SPSR_REG->SPIF = 1;

	flushBuffer = SPDR_REG;
	return flushBuffer;
}

// Use the SPI to send a byte using Interrupt
void SPI_u8SendByte_ISR(u8 copy_u8Data) {
	SPDR_REG = copy_u8Data;
}

// Use the SPI to receive a byte using Polling
u8 SPI_u8ReceiveByte_Polling(void) {
	SPDR_REG = 0xFF;
	while(SPSR_REG->SPIF == 0)
	{
		// Polling (Busy Wait)
		/* Waiting for the flag is set, it is set when data transmission
		 * flag is set, Master will set SS to low to generate clock on SCK pin
		 */
	}
	SPSR_REG->SPIF = 1;
	return SPDR_REG;
}

// Use the SPI to receive a byte using Interrupt
u8 SPI_u8ReceiveByte_ISR(void) {
	u8 Data = 0;

	Data = SPDR_REG;
	return Data;
}

// Responsible for the SPI to send an array of bytes, a string
void SPI_voidSendString_Polling(const u8 *str) {
	u8 i = 0;
	u8 receivedData = 0;

	while (str[i] != '\0') {
		// receivedData contains the data from the other device
		receivedData = SPI_u8SendReceiveByte_Polling(str[i]);
		i++;
	}
}

// Responsible for the SPI to receive an array of bytes, a string
void SPI_voidReceiveString(u8 *str) {
	u8 i = 0;
	// Receives and stores the first byte
	str[i] = SPI_u8ReceiveByte_Polling();

	while (str[i] != '#') {
		i++; // why the incrementer above?
		str[i] =SPI_u8ReceiveByte_Polling() ;
	}
	str[i] = '\0'; // replacing the '#' with '\0'
}

// SPI Callback Function
void SPI_CallBackFunction(void (*Ptr_SPI)(void))
{
	CallBackPtr_SPI = Ptr_SPI;
}

// The ISR For the SPI CallBack Function
void __vector_12(void) __attribute__((signal, used));
void __vector_12(void) {
	if(CallBackPtr_SPI != NULL) {
		CallBackPtr_SPI();
	}
}
