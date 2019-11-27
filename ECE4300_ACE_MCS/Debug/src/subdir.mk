################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/ace.c \
../src/genkat_hash.c \
../src/hash.c 

CPP_SRCS += \
../src/chu_init.cpp \
../src/timer_core.cpp \
../src/uart_core.cpp 

OBJS += \
./src/ace.o \
./src/chu_init.o \
./src/genkat_hash.o \
./src/hash.o \
./src/timer_core.o \
./src/uart_core.o 

C_DEPS += \
./src/ace.d \
./src/genkat_hash.d \
./src/hash.d 

CPP_DEPS += \
./src/chu_init.d \
./src/timer_core.d \
./src/uart_core.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze g++ compiler'
	mb-g++ -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -I../../standalone_bsp_sampler/microblaze_I/include -mno-xl-reorder -mlittle-endian -mcpu=v11.0 -mxl-soft-mul -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze g++ compiler'
	mb-g++ -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -I../../standalone_bsp_sampler/microblaze_I/include -mno-xl-reorder -mlittle-endian -mcpu=v11.0 -mxl-soft-mul -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


