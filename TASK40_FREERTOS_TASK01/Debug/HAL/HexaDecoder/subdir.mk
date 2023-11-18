################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HexaDecoder/HexaDecoder_prog(1).c \
../HAL/HexaDecoder/HexaDecoder_prog.c 

OBJS += \
./HAL/HexaDecoder/HexaDecoder_prog(1).o \
./HAL/HexaDecoder/HexaDecoder_prog.o 

C_DEPS += \
./HAL/HexaDecoder/HexaDecoder_prog(1).d \
./HAL/HexaDecoder/HexaDecoder_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HexaDecoder/HexaDecoder_prog(1).o: ../HAL/HexaDecoder/HexaDecoder_prog(1).c HAL/HexaDecoder/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/HexaDecoder/HexaDecoder_prog(1).d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/HexaDecoder/%.o: ../HAL/HexaDecoder/%.c HAL/HexaDecoder/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


