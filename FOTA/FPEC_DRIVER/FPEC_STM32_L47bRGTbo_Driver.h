/*
 *  FPEC_STM_L47bRGTbo_Driver.h
 *
 *  Created on:
 *      Author: badreddine.merareb
 */

#ifndef FPEC_STM_L47bRGTbo_Driver_H_
#define FPEC_STM_L47bRGTbo_Driver_H_

#include <STM32_L47bRGTb0_Device_Header.h>




#define FLASH_KEY1        0x45670123
#define FLASH_KEY2        0xCDEF89AB

#define FLASH_CR_PG       (1U << 0)
#define FLASH_SR_BSY1     (1U << 16)
#define FLASH_CR_LOCK     (1U << 31)


#define FLASH_CR_PER       (1U << 1)
#define FLASH_CR_STRT      (1U << 16)
#define FLASH_PAGE_NUMBER_POS       (3U)


#define FLASH_SR_EOP        (1U << 0)

#define FLASH_PAGE_SIZE     2048U

#define FLASH_RDP_LEVEL_0      0xAA
#define FLASH_RDP_LEVEL_1      0xCC
#define FLASH_RDP_LEVEL_2      0xFF

/*
 * -------------------------------------------------------------------------------------------------------
 *                                   APIS Supported By MCAL FPEC DRIVER
 *---------------------------------------------------------------------------------------------------------
 * */

void MCAL_FPEC_Write(uint32_t Address, uint64_t *Data, uint32_t Data_Length);
void MCAL_FPEC_ErasPages(uint32_t Page_Numbre,uint8_t N_OF_Page);
uint8_t MCAL_FPEC_Get_ReadProtectionLevel(void);
uint32_t MCAL_FPEC_GetPageNumber(uint32_t Address);

#endif /* FPEC_STM_L47bRGTbo_Driver_H_ */


