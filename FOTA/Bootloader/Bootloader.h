/*
*  BootLoader.h
*
*
*Created on : 
* Author : Merareb.Badreddine
*/
  

#define BL_HOST_RX_BUFFER_LENGHT    200;



#define CMD_GET_Version           0x10
#define CMD_RDP_Status            0x12
#define CMD_FLASH_ERASE           0x13
#define CMD_MEM_Write             0x14
#define CMD_GO_TO_Main_APP        0x15


static void BootLoader_Get_Version(uint8_t BL_Host_Buffer);
static void BootLoader_Get_Chip_ID(uint8_t BL_Host_Buffer);
static void BootLoader_Get_RDP_Status(uint8_t BL_Host_Buffer);
static void BootLoader_Get_Application_Erase(uint8_t BL_Host_Buffer);
static void BootLoader_Upload_Application(uint8_t BL_Host_Buffer);
static void BootLoader_Jump_TO_Application(uint8_t BL_Host_Buffer);

void BL_USART_Fetch_Host_CMD(void);



static void BootLoader_Get_Version(uint8_t BL_Host_Buffer)
{
	
}
static void BootLoader_Get_Chip_ID(uint8_t BL_Host_Buffer)
{
	
}
static void BootLoader_Get_RDP_Status(uint8_t BL_Host_Buffer)
{
	
}
static void BootLoader_Get_Application_Erase(uint8_t BL_Host_Buffer)
{
	
}
static void BootLoader_Upload_Application(uint8_t BL_Host_Buffer)
{
	
}
static void BootLoader_Jump_TO_Application(uint8_t BL_Host_Buffer)
{
	
}
