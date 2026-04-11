################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Temp/lcd_io_fsmc16_hal.c 

C_DEPS += \
./Core/Src/Temp/lcd_io_fsmc16_hal.d 

OBJS += \
./Core/Src/Temp/lcd_io_fsmc16_hal.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Temp/%.o Core/Src/Temp/%.su Core/Src/Temp/%.cyclo: ../Core/Src/Temp/%.c Core/Src/Temp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Core/Src/lvgl-master -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/cathy/STM32CubeIDE/workspace_1.17.0/G26 Display/Core/Src/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Temp

clean-Core-2f-Src-2f-Temp:
	-$(RM) ./Core/Src/Temp/lcd_io_fsmc16_hal.cyclo ./Core/Src/Temp/lcd_io_fsmc16_hal.d ./Core/Src/Temp/lcd_io_fsmc16_hal.o ./Core/Src/Temp/lcd_io_fsmc16_hal.su

.PHONY: clean-Core-2f-Src-2f-Temp

