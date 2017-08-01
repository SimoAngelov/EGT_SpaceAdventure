################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Controller/BonusGameController/BonusGameController.cpp 

OBJS += \
./src/Controller/BonusGameController/BonusGameController.o 

CPP_DEPS += \
./src/Controller/BonusGameController/BonusGameController.d 


# Each subdirectory must supply rules for building sources it contributes
src/Controller/BonusGameController/%.o: ../src/Controller/BonusGameController/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


