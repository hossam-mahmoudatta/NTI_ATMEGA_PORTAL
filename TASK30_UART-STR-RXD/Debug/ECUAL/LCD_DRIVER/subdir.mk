################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/LCD_DRIVER/LCD_PROGRAM.c 

OBJS += \
./ECUAL/LCD_DRIVER/LCD_PROGRAM.o 

C_DEPS += \
./ECUAL/LCD_DRIVER/LCD_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/LCD_DRIVER/%.o: ../ECUAL/LCD_DRIVER/%.c ECUAL/LCD_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


