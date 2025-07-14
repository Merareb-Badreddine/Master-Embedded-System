################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../src/r_reset_program.asm 

C_SRCS += \
../src/r_cg_cgc.c \
../src/r_cg_cgc_user.c \
../src/r_cg_port.c \
../src/r_cg_port_user.c \
../src/r_cg_timer.c \
../src/r_cg_timer_user.c \
../src/r_cg_vector_table.c \
../src/r_hardware_setup.c \
../src/r_main.c 

LST += \
r_cg_cgc.lst \
r_cg_cgc_user.lst \
r_cg_port.lst \
r_cg_port_user.lst \
r_cg_timer.lst \
r_cg_timer_user.lst \
r_cg_vector_table.lst \
r_hardware_setup.lst \
r_main.lst \
r_reset_program.lst 

C_DEPS += \
./src/r_cg_cgc.d \
./src/r_cg_cgc_user.d \
./src/r_cg_port.d \
./src/r_cg_port_user.d \
./src/r_cg_timer.d \
./src/r_cg_timer_user.d \
./src/r_cg_vector_table.d \
./src/r_hardware_setup.d \
./src/r_main.d 

OBJS += \
./src/r_cg_cgc.o \
./src/r_cg_cgc_user.o \
./src/r_cg_port.o \
./src/r_cg_port_user.o \
./src/r_cg_timer.o \
./src/r_cg_timer_user.o \
./src/r_cg_vector_table.o \
./src/r_hardware_setup.o \
./src/r_main.o \
./src/r_reset_program.o 

ASM_DEPS += \
./src/r_reset_program.d 

MAP += \
Control_Dumber_Degree.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-Og -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wstack-usage=40 -g2 -mcpu=s3 -std=gnu99 -I"C:/Users/badreddine.merareb/e2_studio/Workspace_stepper_Motor/Control_Dumber_Degree/generate" -I"C:\\Users\\badreddine.merareb\\e2_studio\\Workspace_stepper_Motor\\Control_Dumber_Degree\\src" -Wa,-adlnh="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@rl78-elf-gcc @"$@.in"
src/%.o: ../src/%.asm
	@echo 'Building file: $<'
	$(file > $@.in,-Og -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wstack-usage=40 -g2 -mcpu=s3 -x assembler-with-cpp -Wa,--gdwarf2 -I"C:/Users/badreddine.merareb/e2_studio/Workspace_stepper_Motor/Control_Dumber_Degree/src" -Wa,-adlhn="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c "$<" -o "$@")
	@rl78-elf-gcc @"$@.in"

