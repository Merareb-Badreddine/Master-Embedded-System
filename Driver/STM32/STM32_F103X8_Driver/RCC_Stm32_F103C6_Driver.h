/*
 * stm32f103x6_RCC_driver.h
 *
 *  Created on:
 *      Author: Merareb Badreddine 
 */

#ifndef RCC_Stm32_F103C6_Driver_H_
#define RCC_Stm32_F103C6_Driver_H_

#include "Stm32_F103X6_Mcu_Device_Header"
#include "GPIO_Stm32_F103C6_Driver.h"

#define HSE_CLK 		(uint32_t)16000000
#define HSI_RC_CLK 		(uint32_t)8000000

uint32_t MCAL_RCC_GetSYS_CLKFreq(void);

uint32_t MCAL_RCC_GetHCLKFreq(void);

uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);

#endif /* RCC_Stm32_F103C6_Driver_H_ */
