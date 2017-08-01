################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/View/View1_Intro/View1_Intro.cpp 

OBJS += \
./src/View/View1_Intro/View1_Intro.o 

CPP_DEPS += \
./src/View/View1_Intro/View1_Intro.d 


# Each subdirectory must supply rules for building sources it contributes
src/View/View1_Intro/%.o: ../src/View/View1_Intro/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


