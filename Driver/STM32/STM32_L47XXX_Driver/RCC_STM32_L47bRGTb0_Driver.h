/*
 * RCC_STM32_L47bRGTb0_Driver.h
 *
 *  Created on:
 *      Author: Merareb.Badreddine
 */

#ifndef  RCC_STM32_L47bRGTb0_Driver_H_
#define  RCC_STM32_L47bRGTb0_Driver_H_

#include <STM32_L47bRGTb0_Device_Header.h>





#define HSE_CLK      ((uint32_t)16000000U)

#define HSI_RC_CLK   ((uint32_t)16000000U)

#define MSI_CLK      ((uint32_t)4000000U)


uint32_t MCAL_RCC_GetSYS_CLKFreq(void);
uint32_t MCAL_RCC_Get_HCLKFreq(void);
uint32_t MCAL_RCC_Get_PCLK1Freq(void);
uint32_t MCAL_RCC_Get_PCLK2Freq(void);

#endif /*RCC_STM32_L47bRGTb0_Driver_H_ */
