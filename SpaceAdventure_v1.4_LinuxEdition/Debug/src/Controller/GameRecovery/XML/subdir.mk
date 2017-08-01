################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Controller/GameRecovery/XML/pugixml.cpp 

OBJS += \
./src/Controller/GameRecovery/XML/pugixml.o 

CPP_DEPS += \
./src/Controller/GameRecovery/XML/pugixml.d 


# Each subdirectory must supply rules for building sources it contributes
src/Controller/GameRecovery/XML/%.o: ../src/Controller/GameRecovery/XML/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


