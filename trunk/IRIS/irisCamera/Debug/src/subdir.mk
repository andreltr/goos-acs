################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/csbigcam.cpp \
../src/csbigimg.cpp \
../src/irisCamera.cpp \
../src/irisCameraFLI.cpp \
../src/irisCameraFactory.cpp \
../src/irisCameraIRIS.cpp \
../src/irisCameraSBIG.cpp \
../src/irisCameraST402.cpp \
../src/irisCameraSimulator.cpp \
../src/irisCameraSimulatorCreateStarData.cpp 

C_SRCS += \
../src/libfli-camera-parport.c \
../src/libfli-camera-usb.c \
../src/libfli-camera.c \
../src/libfli-debug.c \
../src/libfli-filter-focuser.c \
../src/libfli-mem.c \
../src/libfli-parport.c \
../src/libfli-serial.c \
../src/libfli-sys.c \
../src/libfli-usb-sys.c \
../src/libfli-usb.c \
../src/libfli.c 

OBJS += \
./src/csbigcam.o \
./src/csbigimg.o \
./src/irisCamera.o \
./src/irisCameraFLI.o \
./src/irisCameraFactory.o \
./src/irisCameraIRIS.o \
./src/irisCameraSBIG.o \
./src/irisCameraST402.o \
./src/irisCameraSimulator.o \
./src/irisCameraSimulatorCreateStarData.o \
./src/libfli-camera-parport.o \
./src/libfli-camera-usb.o \
./src/libfli-camera.o \
./src/libfli-debug.o \
./src/libfli-filter-focuser.o \
./src/libfli-mem.o \
./src/libfli-parport.o \
./src/libfli-serial.o \
./src/libfli-sys.o \
./src/libfli-usb-sys.o \
./src/libfli-usb.o \
./src/libfli.o 

C_DEPS += \
./src/libfli-camera-parport.d \
./src/libfli-camera-usb.d \
./src/libfli-camera.d \
./src/libfli-debug.d \
./src/libfli-filter-focuser.d \
./src/libfli-mem.d \
./src/libfli-parport.d \
./src/libfli-serial.d \
./src/libfli-sys.d \
./src/libfli-usb-sys.d \
./src/libfli-usb.d \
./src/libfli.d 

CPP_DEPS += \
./src/csbigcam.d \
./src/csbigimg.d \
./src/irisCamera.d \
./src/irisCameraFLI.d \
./src/irisCameraFactory.d \
./src/irisCameraIRIS.d \
./src/irisCameraSBIG.d \
./src/irisCameraST402.d \
./src/irisCameraSimulator.d \
./src/irisCameraSimulatorCreateStarData.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


