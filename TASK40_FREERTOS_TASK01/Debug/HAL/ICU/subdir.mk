################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/ICU/ICU_prog(1).c \
../HAL/ICU/ICU_prog(2).c \
../HAL/ICU/ICU_prog.c 

OBJS += \
./HAL/ICU/ICU_prog(1).o \
./HAL/ICU/ICU_prog(2).o \
./HAL/ICU/ICU_prog.o 

C_DEPS += \
./HAL/ICU/ICU_prog(1).d \
./HAL/ICU/ICU_prog(2).d \
./HAL/ICU/ICU_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/ICU/ICU_prog(1).o: ../HAL/ICU/ICU_prog(1).c HAL/ICU/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/ICU/ICU_prog(1).d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/ICU/ICU_prog(2).o: ../HAL/ICU/ICU_prog(2).c HAL/ICU/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/ICU/ICU_prog(2).d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/ICU/%.o: ../HAL/ICU/%.c HAL/ICU/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


