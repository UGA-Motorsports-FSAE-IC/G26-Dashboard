################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/USB_DEVICE/Target/usbd_conf.c 

C_DEPS += \
./Core/Src/USB_DEVICE/Target/usbd_conf.d 

OBJS += \
./Core/Src/USB_DEVICE/Target/usbd_conf.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/USB_DEVICE/Target/%.o Core/Src/USB_DEVICE/Target/%.su Core/Src/USB_DEVICE/Target/%.cyclo: ../Core/Src/USB_DEVICE/Target/%.c Core/Src/USB_DEVICE/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Core/Src/lvgl-master -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/cathy/STM32CubeIDE/workspace_1.17.0/G26 Display/Core/Src/Drivers" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-USB_DEVICE-2f-Target

clean-Core-2f-Src-2f-USB_DEVICE-2f-Target:
	-$(RM) ./Core/Src/USB_DEVICE/Target/usbd_conf.cyclo ./Core/Src/USB_DEVICE/Target/usbd_conf.d ./Core/Src/USB_DEVICE/Target/usbd_conf.o ./Core/Src/USB_DEVICE/Target/usbd_conf.su

.PHONY: clean-Core-2f-Src-2f-USB_DEVICE-2f-Target

