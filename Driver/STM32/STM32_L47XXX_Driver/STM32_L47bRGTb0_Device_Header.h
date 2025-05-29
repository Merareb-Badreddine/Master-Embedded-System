/*
*  STM32L47.h
*
*
*Created on : 
* Author : Merareb Badreddine
*/


//-----------------------------
//Includes 
//-----------------------------

#include <stdint.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_BASE            (0x08000000UL) 

#define SRAM1_BASE            (0x20000000UL) 

#define SRAM2_BASE            (0x10000000UL) 

#define Peripherals_BASE      (0x40000000UL) 


#define APB2PERIPH_BASE       (Peripherals_BASE + 0x00010000UL)


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

#define GPIOB     ((GPIO_TypeDef * )GPIOA_BASE)

#define GPIOC     ((GPIO_TypeDef * )GPIOA_BASE)

#define GPIOD     ((GPIO_TypeDef * )GPIOA_BASE)

#define GPIOE     ((GPIO_TypeDef * )GPIOA_BASE)

#define GPIOH     ((GPIO_TypeDef * )GPIOA_BASE)

#define RCC       ((RCC_TypeDef * ) RCC_BASE)

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

/*******************  Bit definition for Peripheral register  ******************/




