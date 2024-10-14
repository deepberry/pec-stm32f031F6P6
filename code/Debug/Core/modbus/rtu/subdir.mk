################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/modbus/rtu/mbcrc.c \
../Core/modbus/rtu/mbrtu.c 

OBJS += \
./Core/modbus/rtu/mbcrc.o \
./Core/modbus/rtu/mbrtu.o 

C_DEPS += \
./Core/modbus/rtu/mbcrc.d \
./Core/modbus/rtu/mbrtu.d 


# Each subdirectory must supply rules for building sources it contributes
Core/modbus/rtu/%.o Core/modbus/rtu/%.su Core/modbus/rtu/%.cyclo: ../Core/modbus/rtu/%.c Core/modbus/rtu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F031x6 -c -I../Core/Inc -I"D:/deepberry/pec-stm32f031F6P6/code/Core/app" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/modbus/include" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/modbus/port" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/modbus/rtu" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/Bsp" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-modbus-2f-rtu

clean-Core-2f-modbus-2f-rtu:
	-$(RM) ./Core/modbus/rtu/mbcrc.cyclo ./Core/modbus/rtu/mbcrc.d ./Core/modbus/rtu/mbcrc.o ./Core/modbus/rtu/mbcrc.su ./Core/modbus/rtu/mbrtu.cyclo ./Core/modbus/rtu/mbrtu.d ./Core/modbus/rtu/mbrtu.o ./Core/modbus/rtu/mbrtu.su

.PHONY: clean-Core-2f-modbus-2f-rtu

