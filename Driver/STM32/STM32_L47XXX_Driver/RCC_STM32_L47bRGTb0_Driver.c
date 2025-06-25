/*
 * RCC_STM32_L47bRGTb0_Driver.c
 *
 *  Created on:
 *      Author: Merareb.Badreddine
 */

#include  <RCC_STM32_L47bRGTb0_Driver.h>

const uint8_t AHBPrescTable[16U] = {0,0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};

const uint8_t APBPrescTable[8U] = {0,0,0,0,1,2,3,4};


uint32_t MCAL_RCC_GetSYS_CLKFreq(void)
{

	switch ((RCC->CFGR >> 2) & 0x3)
	    {
	        case 0:
	        	return (uint32_t)4000000;
	        case 1:
	            return HSI_RC_CLK;
	        case 2:
	            return HSE_CLK;
	        case 3:
	            return 0;
	        default:
	            return 0;
	    }
	}



uint32_t MCAL_RCC_Get_HCLKFreq(void)
{
	return (MCAL_RCC_GetSYS_CLKFreq() >> AHBPrescTable[(RCC->CFGR >> 4) & 0xf]);
}
uint32_t MCAL_RCC_Get_PCLK1Freq(void)
{
	return (MCAL_RCC_Get_HCLKFreq() >> APBPrescTable[(RCC->CFGR >> 8) & 0b111]);
}
uint32_t MCAL_RCC_Get_PCLK2Freq(void)
{
	return (MCAL_RCC_Get_HCLKFreq() >> APBPrescTable[(RCC->CFGR >> 11) & 0b111]);
}


