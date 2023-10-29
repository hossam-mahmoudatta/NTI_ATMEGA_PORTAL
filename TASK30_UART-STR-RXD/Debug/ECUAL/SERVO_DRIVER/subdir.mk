################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/SERVO_DRIVER/SERVO_PROGRAM.c 

OBJS += \
./ECUAL/SERVO_DRIVER/SERVO_PROGRAM.o 

C_DEPS += \
./ECUAL/SERVO_DRIVER/SERVO_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/SERVO_DRIVER/%.o: ../ECUAL/SERVO_DRIVER/%.c ECUAL/SERVO_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


