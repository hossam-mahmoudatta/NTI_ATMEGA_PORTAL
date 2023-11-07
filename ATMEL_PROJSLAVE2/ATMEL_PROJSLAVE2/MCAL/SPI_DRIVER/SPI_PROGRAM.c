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

	//GPIO_voidSetPinValue(PORT_B, SS, LOGIC_HIGH);

	/*Set master node*/
	SET_BIT(SPCR_REG,SPCR_MSTR);
	
	/*clock speed: system frequency divided by 16*/
	SET_BIT(SPCR_REG,SPCR_SPR0);
	CLR_BIT(SPCR_REG,SPCR_SPR1);

	/*SPI enable*/
	SET_BIT(SPCR_REG,SPCR_SPE);

#if (SPI_ISR_ENABLE)
	SET_BIT(SPCR_REG,SPCR_SPIE);
#endif
}

// Initializes and enables the Slave mode for the SPI Module to start functionality
void SPI_voidInitialization_Slave(void) {
	GPIO_voidSetPinDirection(PORT_B, SS, PIN_INPUT);
	GPIO_voidSetPinDirection(PORT_B, MOSI, PIN_INPUT);
	GPIO_voidSetPinDirection(PORT_B, MISO, PIN_OUTPUT);
	GPIO_voidSetPinDirection(PORT_B, SCK, PIN_INPUT);

	GPIO_voidSetPinValue(PORT_B, SS, LOGIC_LOW);

	/*Set master node*/
	CLR_BIT(SPCR_REG,SPCR_MSTR);	
	
	/*clock speed: system frequency divided by 16*/
	SET_BIT(SPCR_REG,SPCR_SPR0);
	CLR_BIT(SPCR_REG,SPCR_SPR1);

	/*SPI enable*/
	SET_BIT(SPCR_REG,SPCR_SPE);

#if (SPI_ISR_ENABLE)
	SET_BIT(SPCR_REG,SPCR_SPIE);
#endif
}


// Responsible for the SPI to send & receive a byte
u8 SPI_u8SendReceiveByte_Polling(u8 copy_u8Data) {
	SPDR_REG = copy_u8Data;
	while((GET_BIT(SPSR_REG,SPSR_SPIF)) == 0)
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
	while((GET_BIT(SPSR_REG,SPSR_SPIF) == 0))
	{
		// Polling (Busy Wait)
		/* Waiting for the flag is set, it is set when data transmission
		 * flag is set, Master will set SS to low to generate clock on SCK pin
		 */
	}
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
	while((GET_BIT(SPSR_REG,SPSR_SPIF) == 0))
	{
		// Polling (Busy Wait)
		/* Waiting for the flag is set, it is set when data transmission
		 * flag is set, Master will set SS to low to generate clock on SCK pin
		 */
	}
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
		i++; // why the incremented above?
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
