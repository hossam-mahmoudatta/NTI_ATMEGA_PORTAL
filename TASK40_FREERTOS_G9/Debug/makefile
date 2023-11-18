################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WDTimer/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/PWM/subdir.mk
-include MCAL/Internal_EEPROM/subdir.mk
-include MCAL/IIC/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Switch/subdir.mk
-include HAL/Stepper/subdir.mk
-include HAL/Parsing/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/L293D/subdir.mk
-include HAL/Keypad/subdir.mk
-include HAL/ICU/subdir.mk
-include HAL/HexaDecoder/subdir.mk
-include HAL/EEPROM/subdir.mk
-include HAL/Communication/subdir.mk
-include APP/Traffic/subdir.mk
-include APP/Project/subdir.mk
-include APP/POV/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
freeRTOS_NTI_G9.lss \

FLASH_IMAGE += \
freeRTOS_NTI_G9.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: freeRTOS_NTI_G9.elf secondary-outputs

# Tool invocations
freeRTOS_NTI_G9.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,freeRTOS_NTI_G9.map -mmcu=atmega32 -o "freeRTOS_NTI_G9.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

freeRTOS_NTI_G9.lss: freeRTOS_NTI_G9.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S freeRTOS_NTI_G9.elf  >"freeRTOS_NTI_G9.lss"
	@echo 'Finished building: $@'
	@echo ' '

freeRTOS_NTI_G9.hex: freeRTOS_NTI_G9.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex freeRTOS_NTI_G9.elf  "freeRTOS_NTI_G9.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: freeRTOS_NTI_G9.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 freeRTOS_NTI_G9.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) freeRTOS_NTI_G9.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
