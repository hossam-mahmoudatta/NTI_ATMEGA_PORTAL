################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GPIO_DRIVER/subdir.mk
-include MCAL/GLOBAL_INTERRUPT_DRIVER/subdir.mk
-include MCAL/EXT_INTERRUPT_DRIVER/subdir.mk
-include MCAL/ADC_DRIVER/subdir.mk
-include ECUAL/SEVEN-SEGMENT_DRIVER/subdir.mk
-include ECUAL/LM35_DRIVER/subdir.mk
-include ECUAL/LED_DRIVER/subdir.mk
-include ECUAL/LCD_DRIVER/subdir.mk
-include ECUAL/KEYPAD_DRIVER/subdir.mk
-include APP/subdir.mk
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


BUILD_ARTIFACT_NAME := TASK05_0-99
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
TASK05_0-99.lss \

FLASH_IMAGE += \
TASK05_0-99.hex \

EEPROM_IMAGE += \
TASK05_0-99.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: TASK05_0-99.elf secondary-outputs

# Tool invocations
TASK05_0-99.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TASK05_0-99.map -mmcu=atmega32 -o "TASK05_0-99.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TASK05_0-99.lss: TASK05_0-99.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TASK05_0-99.elf  >"TASK05_0-99.lss"
	@echo 'Finished building: $@'
	@echo ' '

TASK05_0-99.hex: TASK05_0-99.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TASK05_0-99.elf  "TASK05_0-99.hex"
	@echo 'Finished building: $@'
	@echo ' '

TASK05_0-99.eep: TASK05_0-99.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex TASK05_0-99.elf  "TASK05_0-99.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TASK05_0-99.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TASK05_0-99.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TASK05_0-99.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
