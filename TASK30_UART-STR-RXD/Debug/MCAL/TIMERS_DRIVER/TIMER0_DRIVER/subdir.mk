################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMERS_DRIVER/TIMER0_DRIVER/TIMER0_PROGRAM.c 

OBJS += \
./MCAL/TIMERS_DRIVER/TIMER0_DRIVER/TIMER0_PROGRAM.o 

C_DEPS += \
./MCAL/TIMERS_DRIVER/TIMER0_DRIVER/TIMER0_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMERS_DRIVER/TIMER0_DRIVER/%.o: ../MCAL/TIMERS_DRIVER/TIMER0_DRIVER/%.c MCAL/TIMERS_DRIVER/TIMER0_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


