################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Drivers/Fonts/font12.c \
../Core/Src/Drivers/Fonts/font16.c \
../Core/Src/Drivers/Fonts/font20.c \
../Core/Src/Drivers/Fonts/font24.c \
../Core/Src/Drivers/Fonts/font8.c 

C_DEPS += \
./Core/Src/Drivers/Fonts/font12.d \
./Core/Src/Drivers/Fonts/font16.d \
./Core/Src/Drivers/Fonts/font20.d \
./Core/Src/Drivers/Fonts/font24.d \
./Core/Src/Drivers/Fonts/font8.d 

OBJS += \
./Core/Src/Drivers/Fonts/font12.o \
./Core/Src/Drivers/Fonts/font16.o \
./Core/Src/Drivers/Fonts/font20.o \
./Core/Src/Drivers/Fonts/font24.o \
./Core/Src/Drivers/Fonts/font8.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Drivers/Fonts/%.o Core/Src/Drivers/Fonts/%.su Core/Src/Drivers/Fonts/%.cyclo: ../Core/Src/Drivers/Fonts/%.c Core/Src/Drivers/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Core/Src/lvgl-master -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/cathy/STM32CubeIDE/workspace_1.17.0/G26 Display/Core/Src/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Drivers-2f-Fonts

clean-Core-2f-Src-2f-Drivers-2f-Fonts:
	-$(RM) ./Core/Src/Drivers/Fonts/font12.cyclo ./Core/Src/Drivers/Fonts/font12.d ./Core/Src/Drivers/Fonts/font12.o ./Core/Src/Drivers/Fonts/font12.su ./Core/Src/Drivers/Fonts/font16.cyclo ./Core/Src/Drivers/Fonts/font16.d ./Core/Src/Drivers/Fonts/font16.o ./Core/Src/Drivers/Fonts/font16.su ./Core/Src/Drivers/Fonts/font20.cyclo ./Core/Src/Drivers/Fonts/font20.d ./Core/Src/Drivers/Fonts/font20.o ./Core/Src/Drivers/Fonts/font20.su ./Core/Src/Drivers/Fonts/font24.cyclo ./Core/Src/Drivers/Fonts/font24.d ./Core/Src/Drivers/Fonts/font24.o ./Core/Src/Drivers/Fonts/font24.su ./Core/Src/Drivers/Fonts/font8.cyclo ./Core/Src/Drivers/Fonts/font8.d ./Core/Src/Drivers/Fonts/font8.o ./Core/Src/Drivers/Fonts/font8.su

.PHONY: clean-Core-2f-Src-2f-Drivers-2f-Fonts

