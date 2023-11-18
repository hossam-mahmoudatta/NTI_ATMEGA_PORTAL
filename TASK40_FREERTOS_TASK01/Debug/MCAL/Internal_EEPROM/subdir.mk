################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Internal_EEPROM/Internal_EEPROM.c 

OBJS += \
./MCAL/Internal_EEPROM/Internal_EEPROM.o 

C_DEPS += \
./MCAL/Internal_EEPROM/Internal_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Internal_EEPROM/%.o: ../MCAL/Internal_EEPROM/%.c MCAL/Internal_EEPROM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


