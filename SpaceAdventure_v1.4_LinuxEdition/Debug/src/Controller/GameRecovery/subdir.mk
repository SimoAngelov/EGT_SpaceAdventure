################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Controller/GameRecovery/GameRecovery.cpp 

OBJS += \
./src/Controller/GameRecovery/GameRecovery.o 

CPP_DEPS += \
./src/Controller/GameRecovery/GameRecovery.d 


# Each subdirectory must supply rules for building sources it contributes
src/Controller/GameRecovery/%.o: ../src/Controller/GameRecovery/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


