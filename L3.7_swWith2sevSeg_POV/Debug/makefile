################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
lab3.7_swWith2sevSeg_POV.lss \

FLASH_IMAGE += \
lab3.7_swWith2sevSeg_POV.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: lab3.7_swWith2sevSeg_POV.elf secondary-outputs

# Tool invocations
lab3.7_swWith2sevSeg_POV.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lab3.7_swWith2sevSeg_POV.map -mmcu=atmega32 -o "lab3.7_swWith2sevSeg_POV.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lab3.7_swWith2sevSeg_POV.lss: lab3.7_swWith2sevSeg_POV.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lab3.7_swWith2sevSeg_POV.elf  >"lab3.7_swWith2sevSeg_POV.lss"
	@echo 'Finished building: $@'
	@echo ' '

lab3.7_swWith2sevSeg_POV.hex: lab3.7_swWith2sevSeg_POV.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex lab3.7_swWith2sevSeg_POV.elf  "lab3.7_swWith2sevSeg_POV.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lab3.7_swWith2sevSeg_POV.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 lab3.7_swWith2sevSeg_POV.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) lab3.7_swWith2sevSeg_POV.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
