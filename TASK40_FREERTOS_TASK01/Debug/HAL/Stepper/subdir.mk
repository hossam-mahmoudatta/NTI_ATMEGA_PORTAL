################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Stepper/Stepper_prog.c 

OBJS += \
./HAL/Stepper/Stepper_prog.o 

C_DEPS += \
./HAL/Stepper/Stepper_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Stepper/%.o: ../HAL/Stepper/%.c HAL/Stepper/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


