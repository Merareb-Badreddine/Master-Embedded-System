/*
 * USART_STM32_L47bRGTb0_Driver.c
 *
 *  Created on:
 *      Author: Merareb.Badreddine
 */

#include <USart_STM32_L47bRGTb0_Driver.h>

USARt_Config_t * Global_USART_ConFig[3] = {NULL};

void MCAL_USart_Init(USart_TypeDef* USartx , USARt_Config_t* USart_Config )
{

     if (USartx == USART1)
        {

    	 RCC_USART1_CLK_Enable();
    	 Global_USART_ConFig[0] = USart_Config;

        }
     if (USartx == USART2)
         {

    	 RCC_USART2_CLK_Enable();
    	 Global_USART_ConFig[1] = USart_Config;

         }
     if (USartx == USART3)
        {

    	RCC_USART3_CLK_Enable();
    	Global_USART_ConFig[2] = USart_Config;

        }


	USartx->CR1 |= USART_Config_Enabled;


	USartx->CR1 |= USart_Config->USart_Mode;


	USartx->CR1 |= USart_Config->Payload_Lenght;


	USartx->CR1 |= USart_Config->Parity;


	USartx->CR2 |= USart_Config->Stop_Bit;


	USartx->CR3 |= USart_Config->HwFlowCt;


	if(USartx == USART1)
			{
				pclk = MCAL_RCC_Get_PCLK2Freq;
			}
	else
			{
		        pclk = MCAL_RCC_Get_PCLK1Freq;
			}

	BRR = USART_BRR_Register(pclk,USartx->BaudRate);
	USartx->BaudRate = BRR;


	if (USart_Config->IRQ_Enable != USART_IRQ_Enable_NONE)
	{
		if(USartx == USART1)
		{
			NVIC_IRQ37_USART1_EN();
		}
		else if(USartx == USART2)
		{
			NVIC_IRQ38_USART2_EN();
		}
		else if(USartx == USART3)
		{
			NVIC_IRQ39_USART3_EN();
		}

	}

}


void MCAL_USart_DeInit(USart_TypeDef* USartx)
{
  if (USartx == USart1)
  {
	  RCC_USART1_CLK_DI();
	  NVIC_IRQ37_USART1_DI();
  }
  if (USartx == USart2)
   {
	  RCC_USART2_CLK_DI();
	  NVIC_IRQ38_USART2_DI();
   }
  if (USartx == USart3)
   {
	  RCC_USART3_CLK_DI();
	  NVIC_IRQ39_USART3_DI();
   }
}



void MCAL_Usart_SendData(USart_TypeDef * USartx, uint16_t *pTxBuffer, Polling_Mechanism PollingEN)
{

   if (PollingEN == Enable)
   {

  while (!(USartx->SR & 1<<7));

   }

   if (USartx == USart1)
    {

	   if (Global_USART_ConFig[0]->Payload_Lenght == USART_Payload_Length_8B || Global_USART_ConFig[0]->Payload_Lenght == USART_Payload_Length_7B)
	   {
		   USartx->DR = (*pTxBuffer) & (uint8_t)0xFF ;
	   }
	   else if (Global_USART_ConFig[0]->Payload_Lenght == USART_Payload_Length_9B)
	   {
		   USartx->DR = (*pTxBuffer) & (uint16_t)0x1FF ;
	   }
    }


}

void MCAL_USart_GPIO_SET_PINs(USart_TypeDef * USartx)
{

	GPIO_PINConfig_t Pin_Config;

	if (USartx == USart1)
	{
		Pin_Config.GPIO_pinNumber = GPIO_PIN_9;
		Pin_Config.GPIO_MODE = Alternate_function_mode;
		Pin_Config.Alternate_function = GPIO_AF7;
		Pin_Config.GPIO_Output_Speed = 	GPIO_speed_10_MHz;
		MCAL_GPIO_Init(GPIOA , &Pin_Config);

		Pin_Config.GPIO_pinNumber = GPIO_PIN_10;
		Pin_Config.GPIO_MODE = Alternate_function_mode;
		Pin_Config.Alternate_function = GPIO_AF7;
		MCAL_GPIO_Init(GPIOA , &Pin_Config);
	}



}
void USART1_IRQHandler (void)
{
	Global_USART_ConFig[0]->P_IRQ_CallBack();
}
void USART2_IRQHandler (void)
{
	Global_USART_ConFig[1]->P_IRQ_CallBack();
}
void USART3_IRQHandler (void)
{
	Global_USART_ConFig[2]->P_IRQ_CallBack();
}
