################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/View/View2_Paylines/View2_PayLines.cpp 

OBJS += \
./src/View/View2_Paylines/View2_PayLines.o 

CPP_DEPS += \
./src/View/View2_Paylines/View2_PayLines.d 


# Each subdirectory must supply rules for building sources it contributes
src/View/View2_Paylines/%.o: ../src/View/View2_Paylines/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


