################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/WDTimer/WDT_prog(1).c \
../MCAL/WDTimer/WDT_prog.c 

OBJS += \
./MCAL/WDTimer/WDT_prog(1).o \
./MCAL/WDTimer/WDT_prog.o 

C_DEPS += \
./MCAL/WDTimer/WDT_prog(1).d \
./MCAL/WDTimer/WDT_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/WDTimer/WDT_prog(1).o: ../MCAL/WDTimer/WDT_prog(1).c MCAL/WDTimer/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"MCAL/WDTimer/WDT_prog(1).d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MCAL/WDTimer/%.o: ../MCAL/WDTimer/%.c MCAL/WDTimer/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


