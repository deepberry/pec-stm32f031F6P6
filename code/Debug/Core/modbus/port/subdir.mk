################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/modbus/port/portevent.c \
../Core/modbus/port/portserial.c \
../Core/modbus/port/porttimer.c 

OBJS += \
./Core/modbus/port/portevent.o \
./Core/modbus/port/portserial.o \
./Core/modbus/port/porttimer.o 

C_DEPS += \
./Core/modbus/port/portevent.d \
./Core/modbus/port/portserial.d \
./Core/modbus/port/porttimer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/modbus/port/%.o Core/modbus/port/%.su Core/modbus/port/%.cyclo: ../Core/modbus/port/%.c Core/modbus/port/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F031x6 -c -I../Core/Inc -I"D:/deepberry/pec-stm32f031F6P6/code/Core/app" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/modbus/include" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/modbus/port" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/modbus/rtu" -I"D:/deepberry/pec-stm32f031F6P6/code/Core/Bsp" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-modbus-2f-port

clean-Core-2f-modbus-2f-port:
	-$(RM) ./Core/modbus/port/portevent.cyclo ./Core/modbus/port/portevent.d ./Core/modbus/port/portevent.o ./Core/modbus/port/portevent.su ./Core/modbus/port/portserial.cyclo ./Core/modbus/port/portserial.d ./Core/modbus/port/portserial.o ./Core/modbus/port/portserial.su ./Core/modbus/port/porttimer.cyclo ./Core/modbus/port/porttimer.d ./Core/modbus/port/porttimer.o ./Core/modbus/port/porttimer.su

.PHONY: clean-Core-2f-modbus-2f-port

