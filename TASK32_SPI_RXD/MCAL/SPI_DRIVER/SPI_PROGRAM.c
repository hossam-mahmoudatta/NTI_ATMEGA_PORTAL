 /******************************************************************************
 *
 * Module: SPI (Serial Peripheral Interface)
 *
 * File Name: SPI.h
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

/*******************************************************************************
 *                              				FUNCTION IMPLEMENTATIONS				                   	   *
 *******************************************************************************/

// Initializes and enables the Master mode for the SPI Module to start functionality
void SPI_voidInitialization_Master(void) {
	//GPIO_voidSetPinDirection(PORT_B, SS, PIN_INPUT);
	GPIO_voidSetPinDirection(PORT_B, MOSI, PIN_OUTPUT);
	GPIO_voidSetPinDirection(PORT_B, MISO, PIN_INPUT);
	GPIO_voidSetPinDirection(PORT_B, SCK, PIN_OUTPUT);


	//GPIO_voidSetPinValue(PORT_B, SS, LOGIC_HIGH);

	SPCR_REG->MSTR = 1;
	SPCR_REG->SPE = 1;
	SPCR_REG->SPRx = SPI_CLOCK_RATE;
	SPCR_REG->DORD = 1;


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
	SPCR_REG->SPRx = SPI_CLOCK_RATE;// Choosing the SCK rate, Fosc / 4
	SPCR_REG->DORD = 1;
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

void SPI_u8SendByte_Polling(u8 copy_u8Data) {
	SPDR_REG = copy_u8Data;
	while(SPSR_REG->SPIF == 0)
	{
		// Polling (Busy Wait)
		/* Waiting for the flag is set, it is set when data transmission
		 * flag is set, Master will set SS to low to generate clock on SCK pin
		 */
	}
}

u8 SPI_u8ReceiveByte_Polling(void) {
	while(SPSR_REG->SPIF == 0)
	{
		// Polling (Busy Wait)
		/* Waiting for the flag is set, it is set when data transmission
		 * flag is set, Master will set SS to low to generate clock on SCK pin
		 */
	}
	return SPDR_REG;
}

void SPI_voidSendString_Polling(const u8 *str) {
	u8 i = 0;
	u8 receivedData = 0;

	while (str[i] != '\0') {
		// receivedData contains the data from the other device
		receivedData = SPI_u8SendReceiveByte_Polling(str[i]);
		i++;
	}
}


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
