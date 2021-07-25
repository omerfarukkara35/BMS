################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User_Src/Inits/can_inits.c \
../Core/User_Src/Inits/gpio_inits.c \
../Core/User_Src/Inits/timer_inits.c 

OBJS += \
./Core/User_Src/Inits/can_inits.o \
./Core/User_Src/Inits/gpio_inits.o \
./Core/User_Src/Inits/timer_inits.o 

C_DEPS += \
./Core/User_Src/Inits/can_inits.d \
./Core/User_Src/Inits/gpio_inits.d \
./Core/User_Src/Inits/timer_inits.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User_Src/Inits/%.o: ../Core/User_Src/Inits/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/Users/Stable/Documents/STM32EMBED/Test1/Node2UartTest/USB_DEVICE/App" -I"C:/Users/Stable/Documents/STM32EMBED/Test1/Node2UartTest/USB_DEVICE/Target" -I"C:/Users/Stable/Documents/STM32EMBED/Test1/Node2UartTest/Core/Inc" -I"C:/Users/Stable/Documents/STM32EMBED/Test1/Node2UartTest/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/Stable/Documents/STM32EMBED/Test1/Node2UartTest/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Stable/Documents/STM32EMBED/Test1/Node2UartTest/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Stable/Documents/STM32EMBED/Test1/Node2UartTest/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Users/Stable/Documents/STM32EMBED/Test1/Node2UartTest/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/Stable/Documents/STM32EMBED/Test1/Node2UartTest/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


