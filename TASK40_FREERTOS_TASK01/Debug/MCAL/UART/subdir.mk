################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/UART/UART_prog(1).c \
../MCAL/UART/UART_prog.c 

OBJS += \
./MCAL/UART/UART_prog(1).o \
./MCAL/UART/UART_prog.o 

C_DEPS += \
./MCAL/UART/UART_prog(1).d \
./MCAL/UART/UART_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/UART/UART_prog(1).o: ../MCAL/UART/UART_prog(1).c MCAL/UART/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"MCAL/UART/UART_prog(1).d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MCAL/UART/%.o: ../MCAL/UART/%.c MCAL/UART/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


