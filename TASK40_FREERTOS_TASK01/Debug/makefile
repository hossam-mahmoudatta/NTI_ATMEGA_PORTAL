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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := TASK40_FREERTOS_TASK01
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
TASK40_FREERTOS_TASK01.lss \

FLASH_IMAGE += \
TASK40_FREERTOS_TASK01.hex \

EEPROM_IMAGE += \
TASK40_FREERTOS_TASK01.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: TASK40_FREERTOS_TASK01.elf secondary-outputs

# Tool invocations
TASK40_FREERTOS_TASK01.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TASK40_FREERTOS_TASK01.map -mmcu=atmega32 -o "TASK40_FREERTOS_TASK01.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TASK40_FREERTOS_TASK01.lss: TASK40_FREERTOS_TASK01.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TASK40_FREERTOS_TASK01.elf  >"TASK40_FREERTOS_TASK01.lss"
	@echo 'Finished building: $@'
	@echo ' '

TASK40_FREERTOS_TASK01.hex: TASK40_FREERTOS_TASK01.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TASK40_FREERTOS_TASK01.elf  "TASK40_FREERTOS_TASK01.hex"
	@echo 'Finished building: $@'
	@echo ' '

TASK40_FREERTOS_TASK01.eep: TASK40_FREERTOS_TASK01.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex TASK40_FREERTOS_TASK01.elf  "TASK40_FREERTOS_TASK01.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TASK40_FREERTOS_TASK01.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TASK40_FREERTOS_TASK01.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TASK40_FREERTOS_TASK01.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
