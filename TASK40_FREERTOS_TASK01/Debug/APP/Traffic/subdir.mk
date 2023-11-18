################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Traffic/Update_prog.c \
../APP/Traffic/light_prog.c 

OBJS += \
./APP/Traffic/Update_prog.o \
./APP/Traffic/light_prog.o 

C_DEPS += \
./APP/Traffic/Update_prog.d \
./APP/Traffic/light_prog.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Traffic/%.o: ../APP/Traffic/%.c APP/Traffic/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


