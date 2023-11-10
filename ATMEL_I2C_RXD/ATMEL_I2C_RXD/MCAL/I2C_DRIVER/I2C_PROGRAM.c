 /******************************************************************************
 *
 * Module: I2C (Inter Integrated Circuit)
 *
 * File Name: I2C.h
 *
 * Description: Header file for the AVR I2C Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "I2C_INTERFACE.h"

/*******************************************************************************
 *                              					Module Implementation                              					  *
 *******************************************************************************/

// Initializes and enables the Master mode for the TWI Module to start functionality
void I2C_voidMasterInit(void) {
	/* For TWBR
	 * SCL Freq = (F_CPU) / (16 + 2 * TWBR * 4^TWPS)
	 * In the previous equation, I have two unknowns, the TWBR & TWPS
	 * Its the prescaler bits.. so what to choose?
	 * I know that the SCL is 400 KHz, & F_CPU is 8 MHz
	 * I can control TWPS & let it, TWPS = 0, so TWBR = 2
	 */

	TWBR_REG = 0x02; // Configuring with no Prescaler
	TWSR_REG->TWPS = 0; // Configuring no prescaler
	TWSR_REG->TWS = 0; // Initializing the the status by zero
	TWCR_REG->TWEA = 1;
}


// Initializes and enables the I2C Slave Module to start functionality
void I2C_voidSlaveInit(u8 copy_u8Address)
{
	TWAR_REG = copy_u8Address << 1; // Slave1 Address
	
	TWCR_REG->TWEN = 1;
	
	TWCR_REG->TWEA = 1;
		
}


// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidSendStartCondition(void) {
	// Again enabling the I2C Module, Set the Start Condition, Clearing the TWINT Flag
	/* But why I'm not using the normal set bit technique?
	 * Because I don't want to keep old data, & I want the information always set by me
	 */
	I2C_ErrorStatus LocalError = NoError;

	TWCR_REG->TWINT = 1;

	TWCR_REG->TWSTA = 1;

	TWCR_REG->TWEN = 1;

	while(TWCR_REG->TWINT == 0);
	// Busy Wait for TWINT set in TWCR Register to ensure that start bit is send successfully

	while(((TWSR_REG->TWS) << 3) != I2C_START)
	{
		LocalError = StartConditionErr;
	}

	return LocalError;
}

// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidSendRepeatedStart(void) {
	// Again enabling the I2C Module, Set the Start Condition, Clearing the TWINT Flag
	/* But why I'm not using the normal set bit technique?
	 * Because I don't want to keep old data, & I want the information always set by me
	 */
	I2C_ErrorStatus LocalError = NoError;

	TWCR_REG->TWINT = 1;

	TWCR_REG->TWSTA = 1;

	TWCR_REG->TWEN = 1;

	while(TWCR_REG->TWINT == 0);
	// Busy Wait for TWINT set in TWCR Register

	while(((TWSR_REG->TWS) << 3) != I2C_REP_START)
	{
		LocalError = RepeatedStartErr;
	}

	return LocalError;
}

// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidMasterSendSlaveAddressWrite(u8 copy_u8Address) {
	// Again enabling the I2C Module, Set the Start Condition, Clearing the TWINT Flag
	/* But why I'm not using the normal set bit technique?
	 * Because I don't want to keep old data, & I want the information always set by me
	 */
	I2C_ErrorStatus LocalError = NoError;

	// Puts the Slave address on the data bus
	TWDR_REG = copy_u8Address << 1;

	// Sets the 1st bit to zero to "write"
	CLR_BIT(TWDR_REG, 0);
	
	TWCR_REG->TWSTA = 0;

	TWCR_REG->TWINT = 1;

	TWCR_REG->TWEN = 1;

	while(TWCR_REG->TWINT == 0);
	// Busy Wait for TWINT set in TWCR Register
	// to ensure that start bit is send successfully

	while(((TWSR_REG->TWS) << 3) != I2C_MSTR_TXD_SLA_W_ACK)
	{
		LocalError = SlaveAddressWithWriteErr;
	}

	return LocalError;
}


// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidMasterSendSlaveAddressRead(u8 copy_u8Address) {
	// Again enabling the I2C Module, Set the Start Condition, Clearing the TWINT Flag
	/* But why I'm not using the normal set bit technique?
	 * Because I don't want to keep old data, & I want the information always set by me
	 */
	I2C_ErrorStatus LocalError = NoError;
	// Puts the Slave address on the data bus
	TWDR_REG = copy_u8Address << 1;

	// Sets the 1st bit to zero to write
	CLR_BIT(TWDR_REG, 0);

	TWCR_REG->TWINT = 1;

	TWCR_REG->TWEN = 1;

	while(TWCR_REG->TWINT == 0);
	// Busy Wait for TWINT set in TWCR Register
	// to ensure that start bit is send successfully

	while(((TWSR_REG->TWS) << 3) != I2C_MSTR_RXD_SLA_R_ACK)
	{
		LocalError = SlaveAddressWithReadErr;
	}

	return LocalError;
}


// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidMasterSendDataByte(u8 copy_u8DataByte) {
	// Again enabling the I2C Module, Set the Start Condition, Clearing the TWINT Flag
	/* But why I'm not using the normal set bit technique?
	 * Because I don't want to keep old data, & I want the information always set by me
	 */
	I2C_ErrorStatus LocalError = NoError;

	TWDR_REG = copy_u8DataByte;

	TWCR_REG->TWINT = 1;

	TWCR_REG->TWEN = 1;

	while(TWCR_REG->TWINT == 0);
	// Busy Wait for TWINT set in TWCR Register
	// to ensure that start bit is send successfully

	while(((TWSR_REG->TWS) << 3) != I2C_MSTR_TXD_DATA_ACK)
	{
		LocalError = MasterWriteByteErr;
	}

	return LocalError;
}


// Responsible for the SPI to send an array of bytes, a string
I2C_ErrorStatus I2C_voidMasterReceiveDataByte(u8 *copy_u8DataByte) {
	// Again enabling the I2C Module, Set the Start Condition, Clearing the TWINT Flag
	/* But why I'm not using the normal set bit technique?
	 * Because I don't want to keep old data, & I want the information always set by me
	 */
	I2C_ErrorStatus LocalError = NoError;
	TWCR_REG->TWINT = 1;

	while(TWCR_REG->TWINT == 0);
	// Busy Wait for TWINT set in TWCR Register
	// to ensure that start bit is send successfully

	while(((TWSR_REG->TWS) << 3) != I2C_MSTR_RXD_DATA_ACK)
	{
		LocalError = MasterReadByteErr;
	}

	*copy_u8DataByte = TWDR_REG;
	return LocalError;
}


// Responsible for the SPI to send an array of bytes, a string
u8 I2C_u8SlaveReceiveDataByte() {
	u8 Data;
	TWCR_REG->TWINT = 1;

	while(TWCR_REG->TWINT == 0);
	// Busy Wait for TWINT set in TWCR Register
	// to ensure that start bit is send successfully

	while( ((TWSR_REG->TWS) << 3) != I2C_SLAV_RXD_SLA_W_ACK);
	
	TWCR_REG->TWEA = 1;
	TWCR_REG->TWINT = 1;
	TWCR_REG->TWEN = 1;

	while(TWCR_REG->TWINT == 0);

	//if(((TWSR_REG->TWS) << 3) != I2C_SLAV_RXD_DATA_R_NACK);

	Data = TWDR_REG;

	return Data;
}


// Responsible for the SPI to receive an array of bytes, a string
void I2C_voidSendStopCondition(void) {
	TWCR_REG->TWSTO = 1;

	TWCR_REG->TWINT = 1;

	TWCR_REG->TWEN = 1;

	// Wait for the TWSTO to be cleared to ensure the stop condition transmitted
	//while(TWCR_REG->TWSTO == 0);
}

// Responsible for the SPI to receive an array of bytes, a string
void I2C_voidSendByte(u8 copy_u8Data) {
	TWCR_REG->TWEN = 1;
	TWCR_REG->TWINT = 1;

	TWDR_REG = copy_u8Data;

	while(TWCR_REG->TWINT == 0);

}

// Responsible for the SPI to receive an array of bytes, a string
u8 I2C_u8ReadByteWithACK(void) {
	TWCR_REG->TWEN = 1;
	TWCR_REG->TWINT = 1;
	TWCR_REG->TWEA = 1;

	while(TWCR_REG->TWINT == 0);

	return TWDR_REG;
}

// Responsible for the SPI to receive an array of bytes, a string
u8 I2C_u8ReadByteWithNACK(void) {
	TWCR_REG->TWEN = 1;
	TWCR_REG->TWINT = 1;

	while(TWCR_REG->TWINT == 0);

	return TWDR_REG;
}

// Responsible for the SPI to receive an array of bytes, a string
u8 I2C_u8GetStatus(void) {
	u8 I2CStatus;
	I2CStatus = ((TWSR_REG->TWS) << 3);
	return I2CStatus;
}
