/*
*  STM32L47.h
*
*
*Created on : 
* Author : Merareb Badreddine
*/

#ifndef STM32_L47bRGTb0_Device_Header_H
#define STM32_L47bRGTb0_Device_Header_H
//-----------------------------
//Includes 
//-----------------------------

#include <stdint.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_BASE            (0x08000000UL) 

#define SRAM1_BASE            (0x20000000UL) 

#define SRAM2_BASE            (0x20040000UL)

#define Peripherals_BASE      (0x40000000UL) 


#define APB2PERIPH_BASE       (Peripherals_BASE + 0x00010000UL)

#define Cortex_M4_Internal_Peripherals_BASE   (0xE000E000)


//-----------------------------------
//  NVIC register map
//-----------------------------------
#define NVIC_BASE    (0xE000E100)

// Interrupt Set-Enable Registers
/* ==============  Interrupt Set‑Enable Registers  ============== */
#define NVIC_ISER0      (*(volatile uint32_t *)(NVIC_BASE + 0x000))
#define NVIC_ISER1      (*(volatile uint32_t *)(NVIC_BASE + 0x004))
#define NVIC_ISER2      (*(volatile uint32_t *)(NVIC_BASE + 0x008))
#define NVIC_ISER3      (*(volatile uint32_t *)(NVIC_BASE + 0x00C))
#define NVIC_ISER4      (*(volatile uint32_t *)(NVIC_BASE + 0x010))
#define NVIC_ISER5      (*(volatile uint32_t *)(NVIC_BASE + 0x014))
#define NVIC_ISER6      (*(volatile uint32_t *)(NVIC_BASE + 0x018))
#define NVIC_ISER7      (*(volatile uint32_t *)(NVIC_BASE + 0x01C))

/* ==============  Interrupt Clear‑Enable Registers  ============== */
#define NVIC_ICER0      (*(volatile uint32_t *)(NVIC_BASE + 0x080))
#define NVIC_ICER1      (*(volatile uint32_t *)(NVIC_BASE + 0x084))
#define NVIC_ICER2      (*(volatile uint32_t *)(NVIC_BASE + 0x088))
#define NVIC_ICER3      (*(volatile uint32_t *)(NVIC_BASE + 0x08C))
#define NVIC_ICER4      (*(volatile uint32_t *)(NVIC_BASE + 0x090))
#define NVIC_ICER5      (*(volatile uint32_t *)(NVIC_BASE + 0x094))
#define NVIC_ICER6      (*(volatile uint32_t *)(NVIC_BASE + 0x098))
#define NVIC_ICER7      (*(volatile uint32_t *)(NVIC_BASE + 0x09C))

//-----------------------------------
//Base addresses for AHB1 Peripherals
//-----------------------------------
#define AHB1PERIPH_BASE                   (Peripherals_BASE + 0x00020000UL)

#define RCC_BASE                          (AHB1PERIPH_BASE + 0x1000UL)

//-----------------------------------
//Base addresses for AHB2 Peripherals
//-----------------------------------

#define AHB2PERIPH_BASE                   (Peripherals_BASE + 0x08000000UL) 


// A,B,C,H fully included in LQFP64 Package 

#define GPIOA_BASE                         (AHB2PERIPH_BASE + 0x0000UL)

#define GPIOB_BASE                         (AHB2PERIPH_BASE + 0x0400UL)

#define GPIOC_BASE                         (AHB2PERIPH_BASE + 0x0800UL)    

//E,D Partial included in LQFP64 Package

#define GPIOD_BASE                        (AHB2PERIPH_BASE + 0x0C00UL)

#define GPIOE_BASE                        (AHB2PERIPH_BASE + 0x1000UL)

//F,G NOT included in LQFP64 Package

#define GPIOF_BASE                        (AHB2PERIPH_BASE + 0x1400UL)

#define GPIOG_BASE                        (AHB2PERIPH_BASE + 0x1800UL)

#define GPIOH_BASE                        (AHB2PERIPH_BASE + 0x1C00UL)



//-----------------------------------
//Base addresses for APB1 Peripherals
//-----------------------------------

#define APB1PERIPH_BASE        Peripherals_BASE

//-----------------------------------
//Base addresses for APB2 Peripherals
//-----------------------------------

#define APB2PERIPH_BASE        (Peripherals_BASE + 0x00010000UL)

#define SYSCFG_BASE            (APB2PERIPH_BASE + 0x0000UL)   //

#define EXTI_BASE              (APB2PERIPH_BASE + 0x0400UL)
//--------------------------------------
// Peripheral Register : RCC
//--------------------------------------

typedef struct {
        volatile uint32_t CR;
        volatile uint32_t ICSCR;
        volatile uint32_t CFGR;
        volatile uint32_t PLLCFGR;
        volatile uint32_t PLLSAI1CFGR;
        volatile uint32_t PLLSAI2CFGR;
        volatile uint32_t CIER;
        volatile uint32_t CIFR;
        volatile uint32_t CICR;
        uint32_t RESERVED0;
        volatile uint32_t AHB1RSTR;
        volatile uint32_t AHB2RSTR;
        volatile uint32_t AHB3RSTR;
        uint32_t RESERVED1;
        volatile uint32_t APB1RSTR1;
        volatile uint32_t APB1RSTR2;
        volatile uint32_t APB2RSTR;
        uint32_t RESERVED2;
        volatile uint32_t AHB1ENR;
        volatile uint32_t AHB2ENR;
        volatile uint32_t AHB3ENR;
        uint32_t RESERVED3;
        volatile uint32_t APB1ENR1;
        volatile uint32_t APB1ENR2;
        volatile uint32_t APB2ENR;
        uint32_t RESERVED4;
        volatile uint32_t AHB1SMENR;
        volatile uint32_t AHB2SMENR;
        volatile uint32_t AHB3SMENR;
        uint32_t RESERVED5;
        volatile uint32_t APB1SMENR1;
        volatile uint32_t APB1SMENR2;
        volatile uint32_t APB2SMENR;
        uint32_t RESERVED6;
        volatile uint32_t CCIPR;
        uint32_t RESERVED7;
        volatile uint32_t BDCR;
        volatile uint32_t CSR;

} RCC_TypeDef;

//-----------------------------------
// Peripheral Register : GPIO 
//-----------------------------------

typedef struct 
{
       volatile uint32_t MODER;
       volatile uint32_t OTYPER;
       volatile uint32_t OSPEEDR;
       volatile uint32_t PUPDR;
       volatile uint32_t IDR;
       volatile uint32_t ODR;
       volatile uint32_t BSRR;
       volatile uint32_t LCKR;
       volatile uint32_t AFRL; 
       volatile uint32_t AFRH;
       volatile uint32_t BRR;
       volatile uint32_t ASCR;       
} GPIO_TypeDef;



//-----------------------------------
// Peripheral Register : SYSCFG                 //AFIO
//-----------------------------------


typedef struct
{
       volatile uint32_t MEMRMP;      
       volatile uint32_t CFGR1;       
       volatile uint32_t EXTICR[4];   
       volatile uint32_t SCSR;        
       volatile uint32_t CFGR2;       
       volatile uint32_t SWPR;        
       volatile uint32_t SKR;        
} SYSCFG_TypeDef;

//-----------------------------------
// Peripheral Register : EXTI
//-----------------------------------
 typedef struct
{
        volatile uint32_t IMR1;        
        volatile uint32_t EMR1;       
        volatile uint32_t RTSR1;       
        volatile uint32_t FTSR1;       
        volatile uint32_t SWIER1;     
        volatile uint32_t PR1;         
        uint32_t RESERVED1;   
        uint32_t RESERVED2;                              
        volatile uint32_t IMR2;        
        volatile uint32_t EMR2;        
        volatile uint32_t RTSR2;       
        volatile uint32_t FTSR2;       
        volatile uint32_t SWIER2;      
        volatile uint32_t PR2;         
} EXTI_TypeDef;    

//-----------------------------------
// Peripheral Register : NVIC
//-----------------------------------


typedef struct
{
        volatile uint32_t ISER[8U];              
        volatile uint32_t RESERVED0[24U];
        volatile uint32_t ICER[8U];              
        volatile uint32_t RESERVED1[24U];
        volatile uint32_t ISPR[8U];              
        volatile uint32_t RESERVED2[24U];
        volatile uint32_t ICPR[8U];              
        volatile uint32_t RESERVED3[24U];
        volatile uint32_t IABR[8U];               
        volatile uint32_t RESERVED4[56U];
        volatile uint32_t  IP[240U];               
        volatile uint32_t RESERVED5[644U];
        volatile uint32_t STIR;                   
}  NVIC_Type;
//----------------------------------------------
//Peripheral Instants :
//----------------------------------------------

#define GPIOA     ((GPIO_TypeDef * )GPIOA_BASE)

#define GPIOB     ((GPIO_TypeDef * )GPIOB_BASE)

#define GPIOC     ((GPIO_TypeDef * )GPIOC_BASE)

#define GPIOD     ((GPIO_TypeDef * )GPIOD_BASE)

#define GPIOE     ((GPIO_TypeDef * )GPIOE_BASE)

#define GPIOH     ((GPIO_TypeDef * )GPIOH_BASE)

#define RCC       ((RCC_TypeDef * ) RCC_BASE)

//-----------------------------------
//Base addresses for APB1 Peripherals
//-----------------------------------

#define SYSCFG   ((SYSCFG_TypeDef *) SYSCFG_BASE)

#define EXTI     ((EXTI_TypeDef *) EXTI_BASE)

//-----------------------------------------------
//Clock enable Macros :
//-----------------------------------------------

// Enable clock GPIOX

#define RCC_GPIOA_CLK_EN()       (RCC->AHB2ENR |= (1<< 0))
#define RCC_GPIOB_CLK_EN()       (RCC->AHB2ENR |= (1<< 1))
#define RCC_GPIOC_CLK_EN()       (RCC->AHB2ENR |= (1<< 2))
#define RCC_GPIOD_CLK_EN()       (RCC->AHB2ENR |= (1<< 3))
#define RCC_GPIOE_CLK_EN()       (RCC->AHB2ENR |= (1<< 4))
#define RCC_GPIOH_CLK_EN()       (RCC->AHB2ENR |= (1<< 7))
#define RCC_SYSCFG_CLK_EN()      (RCC->APB2ENR |= (1 << 0))
//-----------------------------------------------
//IVT
//-----------------------------------------------
//EXTI

#define EXTI0_IRQ =      6
#define EXTI1_IRQ =      7
#define EXTI2_IRQ =      8
#define EXTI3_IRQ =      9
#define EXTI4_IRQ =      10
#define EXTI5_IRQ =      23
#define EXTI6_IRQ =      23
#define EXTI7_IRQ =      23
#define EXTI8_IRQ =      23
#define EXTI9_IRQ =      23
#define EXTI10_IRQ =     40
#define EXTI11_IRQ =     40
#define EXTI12_IRQ =     40
#define EXTI13_IRQ =     40
#define EXTI14_IRQ =     40
#define EXTI15_IRQ =     40


//-----------------------------------------------
//NVIC IRQ Enable/Disable
//-----------------------------------------------

//NVIC IRQ Enable

#define NVIC_IRQ6_EXTI0_Enable()			(NVIC_ISER0 |= 1<<6)				// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_Enable()			(NVIC_ISER0 |= 1<<7)				// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_Enable()			(NVIC_ISER0 |= 1<<8)				// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_Enable()			(NVIC_ISER0 |= 1<<9)				// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_Enable()			(NVIC_ISER0 |= 1<<10)				// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_Enable()			(NVIC_ISER0 |= 1<<23)				// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC

// 40 - 32 = 8
#define NVIC_IRQ40_EXTI10_15_Enable()		(NVIC_ISER1 |= 1<<8)				// EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15

//NVIC IRQ Disable
#define NVIC_IRQ6_EXTI0_Disable()			(NVIC_ICER0 |= 1<<6)				// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_Disable()			(NVIC_ICER0 |= 1<<7)				// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_Disable()			(NVIC_ICER0 |= 1<<8)				// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_Disable()			(NVIC_ICER0 |= 1<<9)				// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_Disable()			(NVIC_ICER0 |= 1<<10)				// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_Disable()			(NVIC_ICER0 |= 1<<23)				// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC

// 40 - 32 = 8
#define NVIC_IRQ40_EXTI10_15_Disable()		(NVIC_ICER1 |= 1<<8)				// EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15
																			//  ---> PIN40 in NVIC
																			//  ---> PIN40 in NVIC
/*******************  Bit definition for Peripheral register  ******************/


#endif /* STM32_L47bRGTb0_Device_Header_H */
