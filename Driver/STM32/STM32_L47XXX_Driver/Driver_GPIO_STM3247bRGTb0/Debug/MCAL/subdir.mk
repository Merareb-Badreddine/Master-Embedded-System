################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO_STM32_L47bRGTb0_Driver.c 

OBJS += \
./MCAL/GPIO_STM32_L47bRGTb0_Driver.o 

C_DEPS += \
./MCAL/GPIO_STM32_L47bRGTb0_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o MCAL/%.su MCAL/%.cyclo: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -I../Inc -I"C:/Users/badreddine.merareb/STM32CubeIDE/workspace_1.19.0/STM32_47bRGTb0/Driver_GPIO_STM3247bRGTb0/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/GPIO_STM32_L47bRGTb0_Driver.cyclo ./MCAL/GPIO_STM32_L47bRGTb0_Driver.d ./MCAL/GPIO_STM32_L47bRGTb0_Driver.o ./MCAL/GPIO_STM32_L47bRGTb0_Driver.su

.PHONY: clean-MCAL

