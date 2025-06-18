
/*
 * Stm32_F103X6.h
 *
 *  Created on: 
 *      Author: Merareb Badreddine
 */

#ifndef STM32_L47XXX_Mcu_Device_Header_H_
#define STM32_L47XXX_Mcu_Device_Header_H_

//-----------------------------
//Includes
//-----------------------------

typedef unsigned int unit32_t;

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_Memory_BASE            					0x08000000UL
#define System_Memory_BASE            					0x1FFFF000UL
#define SRAM_BASE            						0x20000000UL

#define Peripherals_BASE            					0x40000000UL

#define Cortex_M3_Internal_Peripherals_BASE            	                0xE0000000UL
//NVIC register map


#define NVIC_Base					(0xE000E100UL)
#define NVIC_ISER0					*(volatile uint32_t *)(NVIC_Base + 0x0 )
#define NVIC_ISER1					*(volatile uint32_t *)(NVIC_Base + 0x4)
#define NVIC_ISER2					*(volatile uint32_t *)(NVIC_Base + 0x8)
#define NVIC_ICER0					*(volatile uint32_t *)(NVIC_Base + 0x80)
#define NVIC_ICER1					*(volatile uint32_t *)(NVIC_Base + 0x84)
#define NVIC_ICER2					*(volatile uint32_t *)(NVIC_Base + 0x88)

#define USART1_BASE         (APB2_BUS_BASE + 0x3800)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Base addresses for APB1 Peripherals
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define USART2_BASE         (APB1_BUS_BASE + 0x4400)
#define USART3_BASE         (APB1_BUS_BASE + 0x4800)

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define AHB1PERIPH_BASE                   (Peripherals_BASE + 0x00020000UL)
#define RCC_BASE              (Peripherals_BASE + 0x00021000UL)
#define Flash_Registers                   (AHB1PERIPH_BASE + 0x2000UL)
//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//GPIO
//A,B fully included in LQFP48 Package
#define GPIOA_BASE            (Peripherals_BASE + 0x00010800UL)
#define GPIOB_BASE            (Peripherals_BASE + 0x00010C00UL)
//C,D Partial  included in LQFP48 Package
#define GPIOC_BASE            (Peripherals_BASE + 0x00011000UL)
#define GPIOD_BASE            (Peripherals_BASE + 0x00011400UL)
//EP not  included in LQFP48 Package
#define GPIOE_BASE            (Peripherals_BASE + 0x00011800UL)
//-------

#define AFIO_BASE             (Peripherals_BASE + 0x00010000UL)
#define EXTI_BASE             (Peripherals_BASE + 0x00010400UL)


//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;

} RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	 uint32_t SR;				/* Status register, 						Address offset: 0x00 */
	 uint32_t DR;				/* Data register , 							Address offset: 0x04 */
	 uint32_t BRR;				/* Baud rate register, 						Address offset: 0x08 */
	 uint32_t CR1;				/* Control register 1, 						Address offset: 0x0C */
	 uint32_t CR2;				/* Control register 2, 						Address offset: 0x10 */
	 uint32_t CR3;				/* Control register 3, 						Address offset: 0x14 */
	 uint32_t GTPR;			/* Guard time and pre-scaler register, 		Address offset: 0x18 */
}USART_TypeDef;
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	uint32_t RESERVED0;
	volatile uint32_t MAPR2;
} AFIO_TypeDef;

//-----------------------------------
// Peripheral Register : Flash
//-----------------------------------


typedef struct
{
        volatile uint32_t ACR;
        volatile uint32_t PDKEYR;
        volatile uint32_t KEYR;
        volatile uint32_t OPTKEYR;
        volatile uint32_t SR;
        volatile uint32_t CR;
        volatile uint32_t ECCR;
        volatile uint32_t OPTR;
        volatile uint32_t PCROP1SR;;
        volatile uint32_t PCROP1ER;
        volatile uint32_t WRP1AR;
} Flash_TypeDef
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA               ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *)GPIOE_BASE)


#define RCC                 ((RCC_TypeDef *)RCC_BASE)

#define AFIO                ((AFIO_TypeDef *)AFIO_BASE)
#define EXTI                ((EXTI_TypeDef *)EXTI_BASE)


#define USART1		    ((USART_Typedef_t*)USART1_BASE)
#define USART2		    ((USART_Typedef_t*)USART2_BASE)
#define USART3		    ((USART_Typedef_t*)USART3_BASE)

#define Flach_R              ((Flash_TypeDef *)Flash_Registers)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//Enable clock GPIOX
#define RCC_GPIOA_CLK_EN()	( RCC->APB2ENR |= (1<<2) )
#define RCC_GPIOB_CLK_EN()	( RCC->APB2ENR |= (1<<3) )
#define RCC_GPIOC_CLK_EN()	( RCC->APB2ENR |= (1<<4) )
#define RCC_GPIOD_CLK_EN()	( RCC->APB2ENR |= (1<<5) )
#define RCC_GPIOE_CLK_EN()	( RCC->APB2ENR |= (1<<6) )

#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= 1 << 0)  //AFIO enable is in bit 0

#define RCC_USART1_CLK_EN()	(RCC->APB2ENR |= 1 << 14) //USART1 enable is in bit 14
#define RCC_USART2_CLK_EN()	(RCC->APB1ENR |= 1 << 17) //USART1 enable is in bit 17
#define RCC_USART3_CLK_EN()	(RCC->APB1ENR |= 1 << 18) //USART1 enable is in bit 18

/*
 * Disable clock
 */
#define RCC_USART1_CLK_DI()	(RCC->APB2RSTR |= 1 << 14) //USART1 disable is in bit 14
#define RCC_USART2_CLK_DI()	(RCC->APB1RSTR |= 1 << 17) //USART1 disable is in bit 17
#define RCC_USART3_CLK_DI()	(RCC->APB1RSTR |= 1 << 18) //USART1 disable is in bit 18



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

/*
 * USART
 */
#define USART1_IRQ		37
#define USART2_IRQ		38
#define USART3_IRQ		39


//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
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

/* Disable Interrupt Requests */

// We Started From IRQ6 Due To DataSheet
// ICER : Interrupt Clear Register

#define NVIC_IRQ6_EXTI0_DI()			(NVIC_ICER0 |= 1<<6)				// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_DI()			(NVIC_ICER0 |= 1<<7)				// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_DI()			(NVIC_ICER0 |= 1<<8)				// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_DI()			(NVIC_ICER0 |= 1<<9)				// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_DI()			(NVIC_ICER0 |= 1<<10)				// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_DI()			(NVIC_ICER0 |= 1<<23)				// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC

// 40 - 32 = 8
#define NVIC_IRQ40_EXTI10_15_DI()		(NVIC_ICER1 |= 1<<8)				// EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15
																			//  ---> PIN40 in NVIC

#define NVIC_IRQ37_USART1_DI()			(NVIC_ICER1 |= 1<<(USART1_IRQ - 32))// USART1
#define NVIC_IRQ38_USART2_DI()			(NVIC_ICER1 |= 1<<(USART2_IRQ - 32))// USART2
#define NVIC_IRQ39_USART3_DI()			(NVIC_ICER1 |= 1<<(USART3_IRQ - 32))// USART3

/* ================================================================ */
/* ====================== Generic Macros ========================== */
/* ================================================================ */



/********************************************************/
/********************************************************/
/********************************************************/
/*******************  Bit definition  ********************/
/********************************************************/
/********************************************************/


#endif /* STM32_L47XXX_Mcu_Device_Header_H_ */
