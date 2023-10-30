################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/LM35_DRIVER/LM35_PROGRAM.c 

OBJS += \
./ECUAL/LM35_DRIVER/LM35_PROGRAM.o 

C_DEPS += \
./ECUAL/LM35_DRIVER/LM35_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/LM35_DRIVER/%.o: ../ECUAL/LM35_DRIVER/%.c ECUAL/LM35_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


