################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EEPROM/EEPROM_prog(1).c \
../HAL/EEPROM/EEPROM_prog.c 

OBJS += \
./HAL/EEPROM/EEPROM_prog(1).o \
./HAL/EEPROM/EEPROM_prog.o 

C_DEPS += \
./HAL/EEPROM/EEPROM_prog(1).d \
./HAL/EEPROM/EEPROM_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/EEPROM/EEPROM_prog(1).o: ../HAL/EEPROM/EEPROM_prog(1).c HAL/EEPROM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/EEPROM/EEPROM_prog(1).d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/EEPROM/%.o: ../HAL/EEPROM/%.c HAL/EEPROM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


