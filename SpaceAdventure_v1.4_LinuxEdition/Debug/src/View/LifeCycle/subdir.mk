################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/View/LifeCycle/LifeCycle.cpp 

OBJS += \
./src/View/LifeCycle/LifeCycle.o 

CPP_DEPS += \
./src/View/LifeCycle/LifeCycle.d 


# Each subdirectory must supply rules for building sources it contributes
src/View/LifeCycle/%.o: ../src/View/LifeCycle/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


