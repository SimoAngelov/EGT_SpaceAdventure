################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/View/View4_BonusGame/subdir.mk
-include src/View/View3_Slot/subdir.mk
-include src/View/View2_Paylines/subdir.mk
-include src/View/View1_Intro/subdir.mk
-include src/View/LifeCycle/subdir.mk
-include src/Model/subdir.mk
-include src/Globals/subdir.mk
-include src/Controller/IntroController/subdir.mk
-include src/Controller/GameRecovery/XML/subdir.mk
-include src/Controller/GameRecovery/subdir.mk
-include src/Controller/GameController/subdir.mk
-include src/Controller/BonusGameController/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Egt_SpaceAdventure

# Tool invocations
Egt_SpaceAdventure: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "Egt_SpaceAdventure" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) Egt_SpaceAdventure
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
