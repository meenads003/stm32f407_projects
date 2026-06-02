################################################################################
# Automatically-generated file. Do not edit!
<<<<<<< HEAD
# Toolchain: GNU Tools for STM32 (14.3.rel1)
=======
# Toolchain: GNU Tools for STM32 (13.3.rel1)
>>>>>>> bb8892156c7bb4bbe45216243724f2ce6edd6c68
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
<<<<<<< HEAD
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
=======
-include Startup/subdir.mk
-include Src/subdir.mk
>>>>>>> bb8892156c7bb4bbe45216243724f2ce6edd6c68
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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


<<<<<<< HEAD
BUILD_ARTIFACT_NAME := 1.Blinkled
=======
BUILD_ARTIFACT_NAME := 24_UART_Driver
>>>>>>> bb8892156c7bb4bbe45216243724f2ce6edd6c68
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
<<<<<<< HEAD
1.Blinkled.elf \

MAP_FILES += \
1.Blinkled.map \
=======
24_UART_Driver.elf \

MAP_FILES += \
24_UART_Driver.map \
>>>>>>> bb8892156c7bb4bbe45216243724f2ce6edd6c68

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
<<<<<<< HEAD
1.Blinkled.list \
=======
24_UART_Driver.list \
>>>>>>> bb8892156c7bb4bbe45216243724f2ce6edd6c68


# All Target
all: main-build

# Main-build Target
<<<<<<< HEAD
main-build: 1.Blinkled.elf secondary-outputs

# Tool invocations
1.Blinkled.elf 1.Blinkled.map: $(OBJS) $(USER_OBJS) C:\Users\Meena\ DS\OneDrive\ -\ BITSILICA\ Pvt.\ Ltd\Documents\My_new\1.Blinkled\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "1.Blinkled.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Meena DS\OneDrive - BITSILICA Pvt. Ltd\Documents\My_new\1.Blinkled\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="1.Blinkled.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
=======
main-build: 24_UART_Driver.elf secondary-outputs

# Tool invocations
24_UART_Driver.elf 24_UART_Driver.map: $(OBJS) $(USER_OBJS) C:\Users\Meena\ DS\STM32CubeIDE\workspace_1.19.0\24_UART_Driver\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "24_UART_Driver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Meena DS\STM32CubeIDE\workspace_1.19.0\24_UART_Driver\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="24_UART_Driver.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
>>>>>>> bb8892156c7bb4bbe45216243724f2ce6edd6c68
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

<<<<<<< HEAD
1.Blinkled.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "1.Blinkled.list"
=======
24_UART_Driver.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "24_UART_Driver.list"
>>>>>>> bb8892156c7bb4bbe45216243724f2ce6edd6c68
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
<<<<<<< HEAD
	-$(RM) 1.Blinkled.elf 1.Blinkled.list 1.Blinkled.map default.size.stdout
=======
	-$(RM) 24_UART_Driver.elf 24_UART_Driver.list 24_UART_Driver.map default.size.stdout
>>>>>>> bb8892156c7bb4bbe45216243724f2ce6edd6c68
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
