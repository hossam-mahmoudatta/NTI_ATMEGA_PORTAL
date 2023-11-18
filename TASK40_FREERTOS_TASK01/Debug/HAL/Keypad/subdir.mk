################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad/Keypad_prog(1).c \
../HAL/Keypad/Keypad_prog.c 

OBJS += \
./HAL/Keypad/Keypad_prog(1).o \
./HAL/Keypad/Keypad_prog.o 

C_DEPS += \
./HAL/Keypad/Keypad_prog(1).d \
./HAL/Keypad/Keypad_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad/Keypad_prog(1).o: ../HAL/Keypad/Keypad_prog(1).c HAL/Keypad/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/Keypad/Keypad_prog(1).d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/Keypad/%.o: ../HAL/Keypad/%.c HAL/Keypad/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


