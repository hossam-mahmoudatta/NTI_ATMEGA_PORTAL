################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/LED_DRIVER/LED.c 

OBJS += \
./ECUAL/LED_DRIVER/LED.o 

C_DEPS += \
./ECUAL/LED_DRIVER/LED.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/LED_DRIVER/%.o: ../ECUAL/LED_DRIVER/%.c ECUAL/LED_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


