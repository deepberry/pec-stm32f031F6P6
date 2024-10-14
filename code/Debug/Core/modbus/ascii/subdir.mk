################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/modbus/ascii/mbascii.c 

OBJS += \
./Core/modbus/ascii/mbascii.o 

C_DEPS += \
./Core/modbus/ascii/mbascii.d 


# Each subdirectory must supply rules for building sources it contributes
Core/modbus/ascii/%.o Core/modbus/ascii/%.su Core/modbus/ascii/%.cyclo: ../Core/modbus/ascii/%.c Core/modbus/ascii/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F031x6 -c -I../Core/Inc -I"D:/deepberry/pec-stm32f031F6P6/code/Core/app" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/modbus/include" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/modbus/port" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/modbus/rtu" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/Bsp" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-modbus-2f-ascii

clean-Core-2f-modbus-2f-ascii:
	-$(RM) ./Core/modbus/ascii/mbascii.cyclo ./Core/modbus/ascii/mbascii.d ./Core/modbus/ascii/mbascii.o ./Core/modbus/ascii/mbascii.su

.PHONY: clean-Core-2f-modbus-2f-ascii

