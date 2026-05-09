################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/fmc-display/rpiDisplaySceneBuilder.cpp \
../Core/Src/fmc-display/rpiSceneBuilderUser.cpp 

C_SRCS += \
../Core/Src/fmc-display/lcd_io.c \
../Core/Src/fmc-display/rpiDisplayShapes.c 

C_DEPS += \
./Core/Src/fmc-display/lcd_io.d \
./Core/Src/fmc-display/rpiDisplayShapes.d 

OBJS += \
./Core/Src/fmc-display/lcd_io.o \
./Core/Src/fmc-display/rpiDisplaySceneBuilder.o \
./Core/Src/fmc-display/rpiDisplayShapes.o \
./Core/Src/fmc-display/rpiSceneBuilderUser.o 

CPP_DEPS += \
./Core/Src/fmc-display/rpiDisplaySceneBuilder.d \
./Core/Src/fmc-display/rpiSceneBuilderUser.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fmc-display/%.o Core/Src/fmc-display/%.su Core/Src/fmc-display/%.cyclo: ../Core/Src/fmc-display/%.c Core/Src/fmc-display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Core/Src/lvgl-master -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/cathy/STM32CubeIDE/workspace_1.17.0/G26 Display/Core/Src/Drivers" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/fmc-display/%.o Core/Src/fmc-display/%.su Core/Src/fmc-display/%.cyclo: ../Core/Src/fmc-display/%.cpp Core/Src/fmc-display/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Core/Src/lvgl-master -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-fmc-2d-display

clean-Core-2f-Src-2f-fmc-2d-display:
	-$(RM) ./Core/Src/fmc-display/lcd_io.cyclo ./Core/Src/fmc-display/lcd_io.d ./Core/Src/fmc-display/lcd_io.o ./Core/Src/fmc-display/lcd_io.su ./Core/Src/fmc-display/rpiDisplaySceneBuilder.cyclo ./Core/Src/fmc-display/rpiDisplaySceneBuilder.d ./Core/Src/fmc-display/rpiDisplaySceneBuilder.o ./Core/Src/fmc-display/rpiDisplaySceneBuilder.su ./Core/Src/fmc-display/rpiDisplayShapes.cyclo ./Core/Src/fmc-display/rpiDisplayShapes.d ./Core/Src/fmc-display/rpiDisplayShapes.o ./Core/Src/fmc-display/rpiDisplayShapes.su ./Core/Src/fmc-display/rpiSceneBuilderUser.cyclo ./Core/Src/fmc-display/rpiSceneBuilderUser.d ./Core/Src/fmc-display/rpiSceneBuilderUser.o ./Core/Src/fmc-display/rpiSceneBuilderUser.su

.PHONY: clean-Core-2f-Src-2f-fmc-2d-display

