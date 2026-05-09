################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/easyusbprintln/easyusbprintln.c 

C_DEPS += \
./Core/Src/easyusbprintln/easyusbprintln.d 

OBJS += \
./Core/Src/easyusbprintln/easyusbprintln.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/easyusbprintln/%.o Core/Src/easyusbprintln/%.su Core/Src/easyusbprintln/%.cyclo: ../Core/Src/easyusbprintln/%.c Core/Src/easyusbprintln/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Core/Src/lvgl-master -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/cathy/STM32CubeIDE/workspace_1.17.0/G26 Display/Core/Src/Drivers" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-easyusbprintln

clean-Core-2f-Src-2f-easyusbprintln:
	-$(RM) ./Core/Src/easyusbprintln/easyusbprintln.cyclo ./Core/Src/easyusbprintln/easyusbprintln.d ./Core/Src/easyusbprintln/easyusbprintln.o ./Core/Src/easyusbprintln/easyusbprintln.su

.PHONY: clean-Core-2f-Src-2f-easyusbprintln

