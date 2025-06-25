/*
 * USART_STM32_L47bRGTb0_Driver.c
 *
 *  Created on:
 *      Author: Merareb.Badreddine
 */

#include <USart_STM32_L47bRGTb0_Driver.h>


USARt_Config_t * Global_USART_Config[3] = {NULL};

void MCAL_USart_Init(USART_TypeDef * USartx , USARt_Config_t* USart_Config )
{


	uint32_t pclk, BRR;

     if (USartx == USART1)
        {

    	 RCC_USART1_CLK_EN();
    	 Global_USART_Config[0] = USart_Config;

        }
     if (USartx == USART2)
         {

    	 RCC_USART2_CLK_EN();
    	 Global_USART_Config[1] = USart_Config;

         }
     if (USartx == USART3)
        {

    	 RCC_USART3_CLK_EN();
    	Global_USART_Config[2] = USart_Config;

        }


	USartx->CR1 |= USART_Config_Enabled;


	USartx->CR1 |= USart_Config->USart_Mode;


	USartx->CR1 |= USart_Config->Payload_Lenght;


	USartx->CR1 |= USart_Config->Parity;


	USartx->CR2 |= USart_Config->Stop_Bit;


	USartx->CR3 |= USart_Config->HwFlowCt;


	if(USartx == USART1)
			{
				pclk = MCAL_RCC_Get_PCLK2Freq();
			}
	else
			{
		        pclk = MCAL_RCC_Get_PCLK1Freq();
			}

	BRR = USART_BRR_Register(pclk, USart_Config->BaudRate);
	USartx->BRR = BRR;


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


void MCAL_USart_DeInit(USART_TypeDef * USartx)
{
  if (USartx == USART1)
  {
	  RCC_USART1_CLK_DI();
	  NVIC_IRQ37_USART1_DI();
  }
  if (USartx == USART2)
   {
	  RCC_USART2_CLK_DI();
	  NVIC_IRQ38_USART2_DI();
   }
  if (USartx == USART3)
   {
	  RCC_USART3_CLK_DI();
	  NVIC_IRQ39_USART3_DI();
   }
}

/*----------------------------------------------------------------------------------------------------------
 *  @Fn                                                                      - MCAL_USART_SendData
 *  @brief                                                                   -Send Buffer on USart
 *  @Param [in]                                                              -USARTX Where X can be (1 .. 5 Depending on Device)
 *  @param [in]                                                              -pTxBuffer Buffer
 *  @param [in]                                                              -Polling Enable OR Disable
 *  @retval                                                                  _NOne
 *  Note
 */

void MCAL_UART_SendData(USART_TypeDef * USARTx, uint16_t* pTxBuffer, Polling_Mechanism PollingEn)
{
    /* 1. Wait until TXE flag is set in the SR */
    if (PollingEn == Enable)
    {
        while (!(USARTx->ISR & (1 << 7)));  // TXE = 1
    }

    /* 2. Check the USART_WordLength and Parity */

    if (USARTx == USART1)
    {
        if (Global_USART_Config[0]->Payload_Lenght == USART_Payload_Length_8B)
        {
            USARTx->TDR = (*pTxBuffer) & (uint8_t)0xFF;
        }
        else if (Global_USART_Config[0]->Payload_Lenght == USART_Payload_Length_9B)
        {
            if (Global_USART_Config[0]->Parity == USART_PARITY_NONE)
            {
                USARTx->TDR = (*pTxBuffer) & (uint16_t)0x1FF;
            }
            else
            {
                USARTx->TDR = (*pTxBuffer) & (uint8_t)0xFF;
            }
        }
    }
    else if (USARTx == USART2)
    {
        if (Global_USART_Config[1]->Payload_Lenght == USART_Payload_Length_8B)
        {
            USARTx->TDR = (*pTxBuffer) & (uint8_t)0xFF;
        }
        else if (Global_USART_Config[1]->Payload_Lenght == USART_Payload_Length_9B)
        {
            if (Global_USART_Config[1]->Parity == USART_PARITY_NONE)
            {
                USARTx->TDR = (*pTxBuffer) & (uint16_t)0x1FF;
            }
            else
            {
                USARTx->TDR = (*pTxBuffer) & (uint8_t)0xFF;
            }
        }
    }
    else if (USARTx == USART3)
    {
        if (Global_USART_Config[2]->Payload_Lenght == USART_Payload_Length_8B)
        {
            USARTx->TDR = (*pTxBuffer) & (uint8_t)0xFF;
        }
        else if (Global_USART_Config[2]->Payload_Lenght == USART_Payload_Length_9B)
        {
            if (Global_USART_Config[2]->Parity == USART_PARITY_NONE)
            {
                USARTx->TDR = (*pTxBuffer) & (uint16_t)0x1FF;
            }
            else
            {
                USARTx->TDR = (*pTxBuffer) & (uint8_t)0xFF;
            }
        }
    }
}



/*---------------------------------------------------------------------------------------------------------
 *    @Fn                                 MCAL_Usart_ReceiveData
 *    @brief                              Receive Buffer on USart
 *    @param [in]                         USARTX Where X can be (1 .. 5 Depending on Device)
 *    @param [in]                        -pRxBuffer Buffer
 *    @param [in]                         Polling Enable OR Disable
 *    Note

 */


void MCAL_USART_ReceiveData(USART_TypeDef* USARTx, uint16_t* pRxBuffer, Polling_Mechanism PollingEn)
{
	/* 1. Wait until RXNE flag is set in the SR */
	if (PollingEn == Enable)
	{
		while (!(USARTx->ISR & 1<<5));
	}

	/* 2. Check the USART_WordLength item for 9-bit or 8-bit in a frame */
	if (USARTx == USART1)
	{
		/* 9 Bits Data */
		if (Global_USART_Config[0]->Payload_Lenght == USART_Payload_Length_9B)
		{
			if (Global_USART_Config[0]->Parity == USART_PARITY_NONE)
			{
				/* All 9 bits are data */
				*pRxBuffer = USARTx->RDR ;
			}
			else
			{
				/* Just least byte is data */
				*pRxBuffer = USARTx->RDR & (uint8_t)0xFF ;
			}
		}
		/* 8 Bits Data */
		else
		{
			if (Global_USART_Config[0]->Parity == USART_PARITY_NONE)
			{
				/* All 8 bits are data */
				*pRxBuffer = USARTx->RDR & (uint8_t)0xFF  ;
			}
			else
			{
				/* just least 7 bits are data */
				*pRxBuffer = USARTx->RDR & (uint8_t)0x7F ;
			}
		}
	}
	else if (USARTx == USART2)
	{
		/* 9 Bits Data */
		if (Global_USART_Config[1]->Payload_Lenght == USART_Payload_Length_9B)
		{
			if (Global_USART_Config[1]->Parity == USART_PARITY_NONE)
			{
				/* All 9 bits are data */
				*pRxBuffer = USARTx->RDR ;
			}
			else
			{
				/* Just least byte is data */
				*pRxBuffer = USARTx->RDR & (uint8_t)0xFF ;
			}
		}
		/* 8 Bits Data */
		else
		{
			if (Global_USART_Config[1]->Parity == USART_PARITY_NONE)
			{
				/* All 8 bits are data */
				*pRxBuffer = USARTx->RDR & (uint8_t)0xFF  ;
			}
			else
			{
				/* just least 7 bits are data */
				*pRxBuffer = USARTx->RDR & (uint8_t)0x7F ;
			}
		}
	}
	else if (USARTx == USART3)
	{
		/* 9 Bits Data */
		if (Global_USART_Config[2]->Payload_Lenght == USART_Payload_Length_9B)
		{
			if (Global_USART_Config[2]->Parity == USART_PARITY_NONE)
			{
				/* All 9 bits are data */
				*pRxBuffer = USARTx->RDR ;
			}
			else
			{
				/* Just least byte is data */
				*pRxBuffer = USARTx->RDR & (uint8_t)0xFF ;
			}
		}
		/* 8 Bits Data */
		else
		{
			if (Global_USART_Config[2]->Parity == USART_PARITY_NONE)
			{
				/* All 8 bits are data */
				*pRxBuffer = USARTx->RDR & (uint8_t)0xFF  ;
			}
			else
			{
				/* just least 7 bits are data */
				*pRxBuffer = USARTx->RDR & (uint8_t)0x7F ;
			}
		}
	}
}



void MCAL_UART_GPIO_Set_Pins(USART_TypeDef * USARTx)
{
	GPIO_PINConfig_t Pin_Config;

	if (USARTx == USART1)
	{
		// PA9 Tx
		// PA10 Rx
		// PA11 CTS
		// PA12 RTS

		// PA9 Tx
		Pin_Config.GPIO_pinNumber = GPIO_PIN_9;
		Pin_Config.GPIO_MODE = Alternate_function_mode;
		Pin_Config.Alternate_function = GPIO_AF7;
		Pin_Config.GPIO_Output_Speed = GPIO_speed_10_MHz;
		MCAL_GPIO_Init(GPIOA, &Pin_Config);

		// PA10 Rx
		Pin_Config.GPIO_pinNumber = GPIO_PIN_10;
		Pin_Config.GPIO_MODE = Alternate_function_mode;
		Pin_Config.Alternate_function = GPIO_AF7;
		MCAL_GPIO_Init(GPIOA, &Pin_Config);

		if (Global_USART_Config[0]->HwFlowCt == USART_HwFlowCtl_CTS || Global_USART_Config[0]->HwFlowCt == USART_HwFlowCtl_RTS_CTS)
		{
			// PA11 CTS
			Pin_Config.GPIO_pinNumber = GPIO_PIN_11;
			Pin_Config.GPIO_MODE = Alternate_function_mode;
			Pin_Config.Alternate_function = GPIO_AF7;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}

		if (Global_USART_Config[0]->HwFlowCt == USART_HwFlowCtl_RTS || Global_USART_Config[0]->HwFlowCt == USART_HwFlowCtl_RTS_CTS)
		{
			// PA12 RTS
			Pin_Config.GPIO_pinNumber = GPIO_PIN_12;
			Pin_Config.GPIO_MODE = Alternate_function_mode;
			Pin_Config.Alternate_function = GPIO_AF7;
			Pin_Config.GPIO_Output_Speed = GPIO_speed_10_MHz;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}

	}
	else if (USARTx == USART2)
	{
		// PA2 Tx
		// PA3 Rx
		// PA0 CTS
		// PA1 RTS

		// PA2 Tx
		Pin_Config.GPIO_pinNumber = GPIO_PIN_2;
		Pin_Config.GPIO_MODE = Alternate_function_mode;
		Pin_Config.Alternate_function = GPIO_AF7;
		Pin_Config.GPIO_Output_Speed = GPIO_speed_10_MHz;
		MCAL_GPIO_Init(GPIOA, &Pin_Config);

		// PA3 Rx
		Pin_Config.GPIO_pinNumber = GPIO_PIN_3;
		Pin_Config.GPIO_MODE = Alternate_function_mode;
		Pin_Config.Alternate_function = GPIO_AF7;
		MCAL_GPIO_Init(GPIOA, &Pin_Config);

		if (Global_USART_Config[1]->HwFlowCt == USART_HwFlowCtl_CTS || Global_USART_Config[1]->HwFlowCt == USART_HwFlowCtl_RTS_CTS)
		{
			// PA0 CTS
			Pin_Config.GPIO_pinNumber = GPIO_PIN_0;
			Pin_Config.GPIO_MODE = Alternate_function_mode;
			Pin_Config.Alternate_function = GPIO_AF7;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}



		if (Global_USART_Config[1]->HwFlowCt == USART_HwFlowCtl_RTS || Global_USART_Config[1]->HwFlowCt == USART_HwFlowCtl_RTS_CTS)
		{
			// PA1 RTS
			Pin_Config.GPIO_pinNumber = GPIO_PIN_1;
			Pin_Config.GPIO_MODE = Alternate_function_mode;
			Pin_Config.Alternate_function = GPIO_AF7;
			Pin_Config.GPIO_Output_Speed = GPIO_speed_10_MHz;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}

	}
	else if (USARTx == USART3)
	{
		// PB10 Tx
		// PB11 Rx
		// PA13 CTS
		// PA14 RTS

		// PB10 Tx
		Pin_Config.GPIO_pinNumber = GPIO_PIN_10;
		Pin_Config.GPIO_MODE = Alternate_function_mode;
		Pin_Config.Alternate_function = GPIO_AF7;
		Pin_Config.GPIO_Output_Speed = GPIO_speed_10_MHz;
		MCAL_GPIO_Init(GPIOB, &Pin_Config);

		// PB11 Rx
		Pin_Config.GPIO_pinNumber = GPIO_PIN_11;
		Pin_Config.GPIO_MODE = Alternate_function_mode;
		Pin_Config.Alternate_function = GPIO_AF7;
		MCAL_GPIO_Init(GPIOB, &Pin_Config);

		if (Global_USART_Config[2]->HwFlowCt == USART_HwFlowCtl_CTS || Global_USART_Config[2]->HwFlowCt == USART_HwFlowCtl_RTS_CTS)
		{
			// PA13 CTS
			Pin_Config.GPIO_pinNumber = GPIO_PIN_13;
			Pin_Config.GPIO_MODE = Alternate_function_mode;
			Pin_Config.Alternate_function = GPIO_AF7;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}



		if (Global_USART_Config[2]->HwFlowCt == USART_HwFlowCtl_RTS || Global_USART_Config[2]->HwFlowCt == USART_HwFlowCtl_RTS_CTS)
		{
			// PA12 RTS
			Pin_Config.GPIO_pinNumber = GPIO_PIN_14;
			Pin_Config.GPIO_MODE = Alternate_function_mode;
			Pin_Config.Alternate_function = GPIO_AF7;
			Pin_Config.GPIO_Output_Speed = GPIO_speed_10_MHz;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}
	}
}

void MCAL_UART_WAIT_TC(USART_TypeDef * USARTx)
{
	/* Wait till TC flag is set in the SR */
	while(!(USARTx->ISR & 1<<6));
}

void USART1_IRQHandler (void)
{
	Global_USART_Config[0]->P_IRQ_CallBack();
}
void USART2_IRQHandler (void)
{
	Global_USART_Config[1]->P_IRQ_CallBack();
}
void USART3_IRQHandler (void)
{
	Global_USART_Config[2]->P_IRQ_CallBack();
}

