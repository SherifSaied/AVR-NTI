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
lab3.3_dipSw.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: lab3.3_dipSw.elf secondary-outputs

# Tool invocations
lab3.3_dipSw.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lab3.3_dipSw.map -mmcu=atmega32 -o "lab3.3_dipSw.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lab3.3_dipSw.lss: lab3.3_dipSw.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lab3.3_dipSw.elf  >"lab3.3_dipSw.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lab3.3_dipSw.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 lab3.3_dipSw.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) lab3.3_dipSw.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
