/*
 * USart_STM32_L47bRGTb0_Driver.h
 *
 *  Created on:
 *      Author: Merareb.Badreddine
 */

#ifndef USart_STM32_L47BRGTB0_DRIVER_H_
#define USart_STM32_L47BRGTB0_DRIVER_H_

#include <STM32_L47bRGTb0_Device_Header.h>
#include "GPIO_STM32_L47bRGTb0_Driver.h"

typedef struct
{
	uint8_t  USart_Mode;

	uint32_t BaudRate;

	uint8_t  Payload_Lenght;

	uint8_t  Stop_Bit;

	uint8_t  IRQ_Enable;

	uint8_t  Parity;

	uint8_t  HwFlowCt;

	void (* P_IRQ_CallBack)(void);

}USARt_Config_t;


#define USART_Config_Enabled   ((uint32_t)(1<<0))
#define USART_Config_Disabled  (uint32_t)(0)

#define USART_Mode_RX        ((uint32_t)(1<<2))
#define USART_Mode_TX        ((uint32_t)(1<<3))
#define USART_Mode_TX_RX     ((uint32_t)(USART_Mode_RX | USART_Mode_TX))


#define USART_Payload_Length_7B  ((uint32_t)(1 << 28))
#define USART_Payload_Length_8B  ((uint32_t)(0))
#define USART_Payload_Length_9B  ((uint32_t)(1 << 12))


#define USART_PARITY_NONE    ((uint32_t)(0<<10))
#define USART_PARITY_EVEN    ((uint32_t)(1<<10))
#define USART_PARITY_ODD     ((uint32_t)(1<<10 | 1<<9))


#define USART_STOP_BITS_1     ((uint32_t)(0<<12))
#define USART_STOP_BITS_0_5   ((uint32_t)(1<<12))
#define USART_STOP_BITS_2     ((uint32_t)(2<<12))
#define USART_STOP_BITS_1_5   ((uint32_t)(3<<12))


#define USART_HwFlowCt1_NONE   ((uint32_t)(0))
#define USART_HwFlowCtSE       ((uint32_t)(1<<9))
#define USART_HwFlowRtSE       ((uint32_t)(1<<8))



#define USART_IRQ_Enable_NONE  ((uint32_t)(0))
#define USART_IRQ_Enable_TXE   ((uint32_t)(1<<7))
#define USART_IRQ_Enable_TC    ((uint32_t)(1<<6))
#define USART_IRQ_Enable_RXNE  ((uint32_t)(1<<5))




typedef enum
{
	Disable,
	Enable
}Polling_Mechanism;



#define USARTDIV(_PCLK_, _BAUD_)                     (uint32_t) (_PCLK_/(16 * _BAUD_)
#define USARTDIV_MUL100(_PCLK_, _BAUD_)              (uint32_t) ((25 * _PCLK_ ) /(4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_, _BAUD_)              (uint32_t) (USARTDIV(_PCLK_, _BAUD_) *100)
#define Mantissa(_PCLK_, _BAUD_)                     (uint32_t) (USARTDIV(_PCLK_, _BAUD_))
#define DIV_Fraction(_PCLK_, _BAUD_)                 (uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) -  Mantissa_MUL100(_PCLK_, _BAUD_)) *16) /100)
#define USART_BRR_Register(_PCLK_,_BAUD_)            (( Mantissa (_PCLK_, _BAUD_)) << 4 )| DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )



void MCAL_USart_Init(USart_TypeDef * USartx , USARt_Config_t * USart_Config );
void MCAL_USart_DeInit(USart_TypeDef * USartx);
void MCAL_USart_GPIO_SET_PINs(USart_TypeDef * USartx);
void MCAL_Usart_SendData(USart_TypeDef * USartx,uint16_t *pTxBuffer,Polling_Mechanism PollingEN );
void MCAL_Usart_ReceiveData(USart_TypeDef * USartx,uint16_t *pRxBuffer,Polling_Mechanism PollingEN);
void MCAL_USart_Wait_TC(USart_TypeDef * USartx);


#endif /*USart_STM32_L47BRGTB0_DRIVER_H_ */
