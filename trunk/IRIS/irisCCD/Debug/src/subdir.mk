################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/irisCCDGUIEventLoop.cpp \
../src/irisCCDGUIMain.cpp \
../src/irisCCDGUISaveDataToDisk.cpp \
../src/irisCCDHelperFunctions.cpp \
../src/irisCCDImpl.cpp \
../src/irisCCDImplInit.cpp \
../src/irisCCDTestClient.cpp \
../src/irisCCDThreadImpl.cpp \
../src/irisCCDThreadInit.cpp 

OBJS += \
./src/irisCCDGUIEventLoop.o \
./src/irisCCDGUIMain.o \
./src/irisCCDGUISaveDataToDisk.o \
./src/irisCCDHelperFunctions.o \
./src/irisCCDImpl.o \
./src/irisCCDImplInit.o \
./src/irisCCDTestClient.o \
./src/irisCCDThreadImpl.o \
./src/irisCCDThreadInit.o 

CPP_DEPS += \
./src/irisCCDGUIEventLoop.d \
./src/irisCCDGUIMain.d \
./src/irisCCDGUISaveDataToDisk.d \
./src/irisCCDHelperFunctions.d \
./src/irisCCDImpl.d \
./src/irisCCDImplInit.d \
./src/irisCCDTestClient.d \
./src/irisCCDThreadImpl.d \
./src/irisCCDThreadInit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


