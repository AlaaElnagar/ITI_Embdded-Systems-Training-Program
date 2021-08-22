################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/02-PORT/subdir.mk
-include MCAL/01_DIO/subdir.mk
-include HAL/01-CLCD/subdir.mk
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
PORT_Driver.lss \

FLASH_IMAGE += \
PORT_Driver.hex \

EEPROM_IMAGE += \
PORT_Driver.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: PORT_Driver.elf secondary-outputs

# Tool invocations
PORT_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PORT_Driver.map -mmcu=atmega32 -o "PORT_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PORT_Driver.lss: PORT_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PORT_Driver.elf  >"PORT_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

PORT_Driver.hex: PORT_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PORT_Driver.elf  "PORT_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

PORT_Driver.eep: PORT_Driver.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex PORT_Driver.elf  "PORT_Driver.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PORT_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 PORT_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PORT_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
