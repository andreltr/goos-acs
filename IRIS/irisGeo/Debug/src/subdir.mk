################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/irisGeoClient.cpp \
../src/irisGeoHelperFunctions.cpp \
../src/irisGeoImpl.cpp \
../src/irisGeoImplInit.cpp \
../src/irisGeoThreadImpl.cpp \
../src/irisGeoThreadInit.cpp 

OBJS += \
./src/irisGeoClient.o \
./src/irisGeoHelperFunctions.o \
./src/irisGeoImpl.o \
./src/irisGeoImplInit.o \
./src/irisGeoThreadImpl.o \
./src/irisGeoThreadInit.o 

CPP_DEPS += \
./src/irisGeoClient.d \
./src/irisGeoHelperFunctions.d \
./src/irisGeoImpl.d \
./src/irisGeoImplInit.d \
./src/irisGeoThreadImpl.d \
./src/irisGeoThreadInit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


