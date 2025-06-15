/*
 * FPEC_STM32_L47bRGTbo_Driver.c
 *
 *  Created on:
 *      Author: badreddine.merareb
 */
#include "FPEC_STM_L47bRGTbo_Driver.h"



void MCAL_FPEC_Write(uint32_t Address, uint32_t *Data, uint32_t Data_Length)
{
	uint32_t Local_Counter = 0;

		if (FLASH_R->CR & FLASH_CR_LOCK)
		    {
			FLASH_R->KEYR = FLASH_KEY1;
			FLASH_R->KEYR = FLASH_KEY2;
		    }

	 for (Local_Counter = 0; Local_Counter < Data_Length; Local_Counter += 2)
	  {

		 while (FLASH_R->SR & FLASH_SR_BSY1);
		 FLASH_R->CR |= FLASH_CR_PG;

		 uint64_t data64 = ((uint64_t)Data[Local_Counter + 1] << 32) | Data[Local_Counter];
		 *(volatile uint64_t *)(Address) = data64;

		  while (FLASH_R->SR & FLASH_SR_BSY1);
		  FLASH_R->CR &= ~FLASH_CR_PG;;
		  if (FLASH_R->SR & FLASH_SR_EOP)
	        {
			  FLASH_R->SR |= FLASH_SR_EOP;
	        }

	        Address += 8;
	    }

}

void MCAL_FPEC_ErasPages(uint8_t Page_Numbre, uint8_t N_OF_Page)
{

 uint32_t Local_Counter = 0;
  if (FLASH_R->CR & FLASH_CR_LOCK)
 		    {
	  FLASH_R->KEYR = FLASH_KEY1;
	  FLASH_R->KEYR = FLASH_KEY2;
 		    }
  for (Local_Counter = 0; Local_Counter < N_OF_Page; Local_Counter++)
  	  {

		 while (FLASH_R->SR & FLASH_SR_BSY1);

		 FLASH_R->CR |= FLASH_CR_PER;

		 FLASH_R->CR &= ~(0xFF << FLASH_PAGE_NUMBER_POS);
		 FLASH_R->CR |= (Page_Numbre << FLASH_PAGE_NUMBER_POS);

		 FLASH_R->CR |= FLASH_CR_STRT;


		while (FLASH_R->SR & FLASH_SR_BSY1);


		    if (FLASH_R->SR & FLASH_SR_EOP)
		    {
		    	FLASH_R->SR |= FLASH_SR_EOP;
		    }


		    FLASH_R->CR &= ~FLASH_CR_PER;

  	  }
  Page_Numbre++;
}

uint8_t MCAL_FPEC_Get_ReadProtectionLevel(void)
{

	 uint8_t rdp_level = (uint8_t)(FLASH->OPTR & 0xFF);

	    return rdp_level;
}
