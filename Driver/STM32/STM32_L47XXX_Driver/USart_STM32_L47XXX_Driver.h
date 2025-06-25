*
 * USart_STM32_L47bRGTb0_Driver.h
 *
 *  Created on:
 *      Author: Merareb.Badreddine
 */

#ifndef USart_STM32_L47BRGTB0_DRIVER_H_
#define USart_STM32_L47BRGTB0_DRIVER_H_

#include <STM32_L47bRGTb0_Device_Header.h>
#include <GPIO_STM32_L47bRGTb0_Driver.h>
#include <RCC_STM32_L47bRGTb0_Driver.h>
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


#define USART_BAUDRATE_9600        9600U
#define USART_BAUDRATE_19200       19200U
#define USART_BAUDRATE_38400       38400U
#define USART_BAUDRATE_57600       57600U
#define USART_BAUDRATE_115200      115200U
#define USART_BAUDRATE_230400      230400U
#define USART_BAUDRATE_460800      460800U
#define USART_BAUDRATE_921600      921600U
#define USART_BAUDRATE_1000000     1000000U


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


#define USART_HwFlowCtl_NONE       0x00000000U
#define USART_HwFlowCtl_RTS        0x00000001U
#define USART_HwFlowCtl_CTS        0x00000002U
#define USART_HwFlowCtl_RTS_CTS    0x00000003U

typedef enum
{
	Disable,
	Enable
}Polling_Mechanism;



#define USARTDIV(_PCLK_, _BAUD_)                     ((uint32_t)((_PCLK_)/(16 * (_BAUD_))))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)              ((uint32_t)((25 * (_PCLK_)) /(4 * (_BAUD_))))
#define Mantissa_MUL100(_PCLK_, _BAUD_)              ((uint32_t)(USARTDIV(_PCLK_, _BAUD_) * 100))
#define Mantissa(_PCLK_, _BAUD_)                     ((uint32_t)(USARTDIV(_PCLK_, _BAUD_)))
#define DIV_Fraction(_PCLK_, _BAUD_)                 ((uint32_t)(((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_, _BAUD_)) * 16) / 100))
#define USART_BRR_Register(_PCLK_, _BAUD_)           (((Mantissa(_PCLK_, _BAUD_) << 4) | (DIV_Fraction(_PCLK_, _BAUD_) & 0x0F)))



void MCAL_USart_Init(USART_TypeDef* USartx , USARt_Config_t * USart_Config );
void MCAL_USart_DeInit(USART_TypeDef* USartx);
void MCAL_UART_GPIO_Set_Pins(USART_TypeDef * USARTx);
void MCAL_Usart_SendData(USART_TypeDef* USartx,uint16_t *pTxBuffer,Polling_Mechanism PollingEN );
void MCAL_USART_ReceiveData(USART_TypeDef* USartx,uint16_t *pRxBuffer,Polling_Mechanism PollingEN);
void MCAL_UART_WAIT_TC(USART_TypeDef* USARTx);


#endif /*USart_STM32_L47BRGTB0_DRIVER_H_ */
