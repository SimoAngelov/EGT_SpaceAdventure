################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/View/View3_Slot/View3_Slot.cpp 

OBJS += \
./src/View/View3_Slot/View3_Slot.o 

CPP_DEPS += \
./src/View/View3_Slot/View3_Slot.d 


# Each subdirectory must supply rules for building sources it contributes
src/View/View3_Slot/%.o: ../src/View/View3_Slot/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


