/*
 * stm32l476xx.h
 *
 *  Created on:
 *      Author: Merareb.Badreddine
 */

#ifndef STM32_L47bRGTb0_DEVICE_HEADER_H_
#define STM32_L47bRGTb0_DEVICE_HEADER_H_

// Includes
#include "Platform_Types.h"

// Base addresses for Memories
#define FLASH_BASE                              0x08000000UL
#define System_Memory_BASE                      0x1FFF0000UL
#define SRAM1_BASE                              0x20000000UL

#define Peripherals_BASE                        0x40000000UL
#define Cortex_M3_Internal_Peripherals_BASE     0xE0000000UL

// NVIC register map
#define NVIC_BASE                    (0xE000E100UL)
#define NVIC_ISER0                  *(vuint32_t *)(NVIC_BASE + 0x0)
#define NVIC_ISER1                  *(vuint32_t *)(NVIC_BASE + 0x4)
#define NVIC_ISER2                  *(vuint32_t *)(NVIC_BASE + 0x8)
#define NVIC_ICER0                  *(vuint32_t *)(NVIC_BASE + 0x80)
#define NVIC_ICER1                  *(vuint32_t *)(NVIC_BASE + 0x84)
#define NVIC_ICER2                  *(vuint32_t *)(NVIC_BASE + 0x88)

// Base addresses for APB1 Peripherals
#define APB1_BUS_BASE               (Peripherals_BASE + 0x00000000UL)
#define USART2_BASE                 (APB1_BUS_BASE + 0x4400)
#define USART3_BASE                 (APB1_BUS_BASE + 0x4800)
#define TIM6_BASE                   (APB1_BUS_BASE + 0x1000UL)
#define TIM7_BASE                   (APB1_BUS_BASE + 0x1400UL)

// Base addresses for AHB Peripherals
#define AHB1PERIPH_BASE             (Peripherals_BASE + 0x00020000UL)
#define RCC_BASE                    (Peripherals_BASE + 0x00021000UL)
#define Flash_Registers             (AHB1PERIPH_BASE + 0x2000UL)

// Base addresses for AHB2 Peripherals
#define AHB2PERIPH_BASE             (0x48000000UL)
#define GPIOA_BASE                  (AHB2PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE                  (AHB2PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE                  (AHB2PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE                  (AHB2PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE                  (AHB2PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE                  (AHB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE                  (AHB2PERIPH_BASE + 0x2000)

// Base addresses for APB2 Peripherals
#define APB2_BUS_BASE               (Peripherals_BASE + 0x00010000UL)
#define SYSCFG_BASE                 (APB2_BUS_BASE + 0x0000)
#define EXTI_BASE                   (APB2_BUS_BASE + 0x0400)
#define USART1_BASE                 (APB2_BUS_BASE + 0x3800)

// GPIO structure
typedef struct {
    vuint32_t MODER;
    vuint32_t OTYPER;
    vuint32_t OSPEEDR;
    vuint32_t PUPDR;
    vuint32_t IDR;
    vuint32_t ODR;
    vuint32_t BSRR;
    vuint32_t LCKR;
    vuint32_t AFR[2];
    vuint32_t BRR;
    vuint32_t ASCR;
} GPIO_TypeDef;

// RCC structure
typedef struct {
    vuint32_t CR;
    vuint32_t ICSCR;
    vuint32_t CFGR;
    vuint32_t PLLCFGR;
    vuint32_t PLLSAI1CFGR;
    vuint32_t PLLSAI2CFGR;
    vuint32_t CIER;
    vuint32_t CIFR;
    vuint32_t CICR;
    vuint32_t AHB1RSTR;
    vuint32_t AHB2RSTR;
    vuint32_t AHB3RSTR;
    uint32_t   RESERVED0;
    vuint32_t APB1RSTR1;
    vuint32_t APB1RSTR2;
    vuint32_t APB2RSTR;
    vuint32_t AHB1ENR;
    vuint32_t AHB2ENR;
    vuint32_t AHB3ENR;
    uint32_t   RESERVED1;
    vuint32_t APB1ENR1;
    vuint32_t  APB1ENR2;
    vuint32_t APB2ENR;
    vuint32_t AHB1SMENR;
    vuint32_t AHB2SMENR;
    vuint32_t AHB3SMENR;
    uint32_t   RESERVED2;
    vuint32_t APB1SMENR1;
    vuint32_t APB1SMENR2;
    vuint32_t APB2SMENR;
    vuint32_t CCIPR;
    vuint32_t RESERVED3;
    vuint32_t BDCR;
    vuint32_t CSR;
    vuint32_t CRRCR;
    vuint32_t CCIPR2;
} RCC_TypeDef;

// EXTI structure
typedef struct {
    vuint32_t IMR1;
    vuint32_t EMR1;
    vuint32_t RTSR1;
    vuint32_t FTSR1;
    vuint32_t SWIER1;
    vuint32_t PR1;
    uint32_t   RESERVED1;
    uint32_t   RESERVED2;
    vuint32_t IMR2;
    vuint32_t EMR2;
    vuint32_t RTSR2;
    vuint32_t FTSR2;
    vuint32_t SWIER2;
    vuint32_t PR2;
} EXTI_TypeDef;

// USART structure
typedef struct {
    vuint32_t CR1;
    vuint32_t CR2;
    vuint32_t CR3;
    vuint32_t BRR;
    vuint32_t GTPR;
    vuint32_t RTOR;
    vuint32_t RQR;
    vuint32_t ISR;
    vuint32_t ICR;
    vuint32_t RDR;
    vuint32_t TDR;
    vuint32_t PRESC;
} USART_TypeDef;

// SYSCFG structure
typedef struct {
    vuint32_t MEMRMP;
    vuint32_t CFGR1;
    vuint32_t EXTICR[4];
    uint32_t  RESERVED1[2];
    vuint32_t CFGR2;
} SYSCFG_TypeDef;

// TIM structure
typedef struct {
    vuint32_t CR1;
    vuint32_t CR2;
    vuint32_t RESERVED0;
    vuint32_t DIER;
    vuint32_t SR;
    vuint32_t EGR;
    vuint32_t RESERVED1;
    vuint32_t RESERVED2;
    vuint32_t CNT;
    vuint32_t PSC;
    vuint32_t ARR;
} TIM_TypeDef;

// FLASH structure
typedef struct {
    vuint32_t ACR;
    vuint32_t PDKEYR;
    vuint32_t KEYR;
    vuint32_t OPTKEYR;
    vuint32_t SR;
    vuint32_t CR;
    vuint32_t ECCR;
    vuint32_t RESERVED1;
    vuint32_t OPTR;
    vuint32_t PCROP1SR;
    vuint32_t PCROP1ER;
    vuint32_t WRP1AR;
    vuint32_t WRP1BR;
    uint32_t   RESERVED2[4];
    vuint32_t PCROP2SR;
    vuint32_t PCROP2ER;
    vuint32_t WRP2AR;
    vuint32_t WRP2BR;
} FLASH_TypeDef;

// Peripheral instances
#define GPIOA               ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *)GPIOE_BASE)
#define RCC                 ((RCC_TypeDef *)RCC_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *)SYSCFG_BASE)
#define EXTI                ((EXTI_TypeDef *)EXTI_BASE)
#define USART1              ((USART_TypeDef *)USART1_BASE)
#define USART2              ((USART_TypeDef *)USART2_BASE)
#define USART3              ((USART_TypeDef *)USART3_BASE)
#define FLASH_R             ((FLASH_TypeDef *)Flash_Registers)
#define TIM6                ((TIM_TypeDef *)TIM6_BASE)
#define TIM7                ((TIM_TypeDef *)TIM7_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

// Enable GPIO clocks - on AHB2 bus
#define RCC_GPIOA_CLK_EN()   (RCC->AHB2ENR |= (1 << 0))
#define RCC_GPIOB_CLK_EN()   (RCC->AHB2ENR |= (1 << 1))
#define RCC_GPIOC_CLK_EN()   (RCC->AHB2ENR |= (1 << 2))
#define RCC_GPIOD_CLK_EN()   (RCC->AHB2ENR |= (1 << 3))
#define RCC_GPIOE_CLK_EN()   (RCC->AHB2ENR |= (1 << 4))


#define RCC_SYSCFG_CLK_EN()   (RCC->APB2ENR |= (1 << 0))  // Enable SYSCFG clock

// USARTs
#define RCC_USART1_CLK_EN()  (RCC->APB2ENR  |= (1 << 14)) // USART1 is on APB2
#define RCC_USART2_CLK_EN()  (RCC->APB1ENR1 |= (1 << 17)) // USART2 is on APB1ENR1
#define RCC_USART3_CLK_EN()  (RCC->APB1ENR1 |= (1 << 18)) // USART3 is on APB1ENR1

// Basic Timers
#define RCC_TIM6_CLK_EN()    (RCC->APB1ENR1 |= (1 << 4))
#define RCC_TIM7_CLK_EN()    (RCC->APB1ENR1 |= (1 << 5))


// Disable clock
#define RCC_GPIOA_CLK_DI()   (RCC->AHB2ENR &= ~(1 << 0))
#define RCC_GPIOB_CLK_DI()   (RCC->AHB2ENR &= ~(1 << 1))
#define RCC_GPIOC_CLK_DI()   (RCC->AHB2ENR &= ~(1 << 2))
#define RCC_GPIOD_CLK_DI()   (RCC->AHB2ENR &= ~(1 << 3))
#define RCC_GPIOE_CLK_DI()   (RCC->AHB2ENR &= ~(1 << 4))

#define RCC_TIM6_CLK_DI()    (RCC->APB1ENR1 &= ~(1 << 4))
#define RCC_TIM7_CLK_DI()    (RCC->APB1ENR1 &= ~(1 << 5))

#define RCC_USART1_CLK_DI()	 (RCC->APB2ENR  &= ~(1 << 14)) // USART1 Disable
#define RCC_USART2_CLK_DI()	 (RCC->APB1ENR1 &= ~(1 << 17)) // USART2 Disable
#define RCC_USART3_CLK_DI()	 (RCC->APB1ENR1 &= ~(1 << 18)) // USART3 Disable



//-*-*-*-*-*-*-*-*-*-*-*-
//IVT
//-*-*-*-*-*-*-*-*-*-*-*
//EXTI

#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40


// USART

#define USART1_IRQ		37
#define USART2_IRQ		38
#define USART3_IRQ		39

// Basic Timers

#define TIM6_DAC_IRQ   54
#define TIM7_IRQ       55




//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*


// Enable Interrupt Requests

#define NVIC_IRQ6_EXTI0_EN()			(NVIC_ISER0 |= 1<<6)				// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_EN()			(NVIC_ISER0 |= 1<<7)				// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_EN()			(NVIC_ISER0 |= 1<<8)				// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_EN()			(NVIC_ISER0 |= 1<<9)				// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_EN()			(NVIC_ISER0 |= 1<<10)				// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_EN()			(NVIC_ISER0 |= 1<<23)				// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC

// 40 - 32 = 8
#define NVIC_IRQ40_EXTI10_15_EN()		(NVIC_ISER1 |= 1<<8)				// EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15
																		    //  ---> PIN40 in NVIC

#define NVIC_IRQ37_USART1_EN()			(NVIC_ISER1 |= 1<<(USART1_IRQ - 32))// USART1
#define NVIC_IRQ38_USART2_EN()			(NVIC_ISER1 |= 1<<(USART2_IRQ - 32))// USART2
#define NVIC_IRQ39_USART3_EN()			(NVIC_ISER1 |= 1<<(USART3_IRQ - 32))// USART3

#define NVIC_IRQ54_TIM6_EN()           (NVIC_ISER1 |= (1 << (TIM6_DAC_IRQ - 32)))    // TIM6_DAC  ---> PIN54 in NVIC
#define NVIC_IRQ55_TIM7_EN()           (NVIC_ISER1 |= (1 << (TIM7_IRQ - 32)))        // TIM7      ---> PIN55 in NVIC

// Disable Interrupt Requests


#define NVIC_IRQ6_EXTI0_DI()			(NVIC_ICER0 |= 1<<6)				// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_DI()			(NVIC_ICER0 |= 1<<7)				// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_DI()			(NVIC_ICER0 |= 1<<8)				// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_DI()			(NVIC_ICER0 |= 1<<9)				// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_DI()			(NVIC_ICER0 |= 1<<10)				// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_DI()			(NVIC_ICER0 |= 1<<23)				// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC


// 40 - 32 = 8
#define NVIC_IRQ40_EXTI10_15_DI()		(NVIC_ICER1 |= 1<<8)				  // EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15
																			  //  ---> PIN40 in NVIC

#define NVIC_IRQ37_USART1_DI()			(NVIC_ICER1 |= 1<<(USART1_IRQ - 32))  // USART1
#define NVIC_IRQ38_USART2_DI()			(NVIC_ICER1 |= 1<<(USART2_IRQ - 32))  // USART2
#define NVIC_IRQ39_USART3_DI()			(NVIC_ICER1 |= 1<<(USART3_IRQ - 32))  // USART3


#define NVIC_IRQ54_TIM6_DI()           (NVIC_ICER1 |= (1 << (TIM6_DAC_IRQ - 32))) // TIM6_DAC --->  PIN54 in NVIC
#define NVIC_IRQ55_TIM7_DI()           (NVIC_ICER1 |= (1 << (TIM7_IRQ - 32)))     // TIM7      ---> PIN55 in NVIC


// ================================================================
// ====================== Generic Macros ==========================
// ================================================================



//*****************************************************************
//*****************************************************************
//*****************************************************************
//******************  Bit definition  *****************************
//*****************************************************************
//*****************************************************************


#endif /* STM32_L47bRGTb0_DEVICE_HEADER_H_ */
