################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adxl345.c \
../Src/corem4.c \
../Src/i2c.c \
../Src/main.c \
../Src/spi.c \
../Src/stm32f407xx_gpio.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/utility.c 

OBJS += \
./Src/adxl345.o \
./Src/corem4.o \
./Src/i2c.o \
./Src/main.o \
./Src/spi.o \
./Src/stm32f407xx_gpio.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/utility.o 

C_DEPS += \
./Src/adxl345.d \
./Src/corem4.d \
./Src/i2c.d \
./Src/main.d \
./Src/spi.d \
./Src/stm32f407xx_gpio.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/utility.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

