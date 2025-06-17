/*
 * FPEC_STM32_L47bRGTbo_Driver.c
 *
 *  Created on:
 *      Author: Merareb.Badreddine
 */
#include "FPEC_STM_L47bRGTbo_Driver.h"

void MCAL_FPEC_Write(uint32_t Address, uint64_t *Data, uint32_t Data_Length)
{
	uint32_t Local_Counter = 0;

		if (FLASH_R->CR & FLASH_CR_LOCK)
		    {
			FLASH_R->KEYR = FLASH_KEY1;
			FLASH_R->KEYR = FLASH_KEY2;
		    }

	 for (Local_Counter = 0; Local_Counter < Data_Length; Local_Counter += 1)
	  {

		 while (FLASH_R->SR & FLASH_SR_BSY1);
		 FLASH_R->CR |= FLASH_CR_PG;

		*(volatile uint64_t *)(Address) = Data[Local_Counter]; 

		  while (FLASH_R->SR & FLASH_SR_BSY1);
		  
		  FLASH_R->CR &= ~FLASH_CR_PG;;
		  
		  if (FLASH_R->SR & FLASH_SR_EOP)
	        {
			  FLASH_R->SR |= FLASH_SR_EOP;
	        }

	        Address += 8;
	    }

}

void MCAL_FPEC_ErasPages(uint32_t pageNumber, uint8_t N_OF_Page)
{
    uint32_t L_Counter;
    //  
    if (FLASH_R->CR & FLASH_CR_LOCK)
    {
        FLASH_R->KEYR = FLASH_KEY1;
        FLASH_R->KEYR = FLASH_KEY2;
    }

    // 2. 
    while (FLASH_R->SR & FLASH_SR_BSY1);

    // 3. 
    FLASH_R->CR &= ~FLASH_CR_PG;
    FLASH_R->CR |= FLASH_CR_PER;

   for (L_Counter = 0; L_Counter < N_OF_Page; L_Counter++){
    // 4. 
    FLASH_R->CR &= ~(0xFF << 3);
    FLASH_R->CR |= ((pageNumber + L_Counter) << 3);
    
    // 5. 
    FLASH_R->CR |= FLASH_CR_STRT;
    
     // 6. 
    while (FLASH_R->SR & FLASH_SR_BSY1);

    if (FLASH_R->SR & FLASH_SR_EOP)
    {
        FLASH_R->SR |= FLASH_SR_EOP;
    }
    
    }
    
    // 
    FLASH_R->CR &= ~FLASH_CR_PER;
}


uint8_t MCAL_FPEC_Get_ReadProtectionLevel(void)
{

	 uint8_t rdp_level = (uint8_t)(FLASH_R->OPTR & 0xFF);

	    return rdp_level;
}

uint32_t MCAL_FPEC_GetPageNumber(uint32_t Address)
{
    return (Address -  FLASH_BASE) / FLASH_PAGE_SIZE ;
}
