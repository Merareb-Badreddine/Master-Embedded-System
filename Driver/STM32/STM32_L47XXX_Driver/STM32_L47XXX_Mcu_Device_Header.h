
/*
 *stm32l476xx.h
 *
 *  Created on:
 *      Author: Merareb.Badreddine */


#ifndef STM32_L47bRGTb0_Device_Header.h
#define STM32_L47bRGTb0_Device_Header.h

//-----------------------------
//Includes
//-----------------------------
typedef unsigned char    uint8_t;
typedef unsigned short   uint16_t;
typedef unsigned int     uint32_t;

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_BASE            					        0x08000000UL
#define System_Memory_BASE            					0x1FFFF000UL
#define SRAM1_BASE            						    0x20000000UL

#define Peripherals_BASE            					0x40000000UL

#define Cortex_M3_Internal_Peripherals_BASE            	0xE0000000UL
//NVIC register map


#define NVIC_Base					(0xE000E100UL)
#define NVIC_ISER0					*(volatile uint32_t *)(NVIC_Base + 0x0)
#define NVIC_ISER1					*(volatile uint32_t *)(NVIC_Base + 0x4)
#define NVIC_ISER2					*(volatile uint32_t *)(NVIC_Base + 0x8)
#define NVIC_ICER0					*(volatile uint32_t *)(NVIC_Base + 0x80)
#define NVIC_ICER1					*(volatile uint32_t *)(NVIC_Base + 0x84)
#define NVIC_ICER2					*(volatile uint32_t *)(NVIC_Base + 0x88)



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Base addresses for APB1 Peripherals
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define APB1_BUS_BASE       (Peripherals_BASE + 0x00000000UL)

#define USART2_BASE         (APB1_BUS_BASE + 0x4400)
#define USART3_BASE         (APB1_BUS_BASE + 0x4800)

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define AHB1PERIPH_BASE                   (Peripherals_BASE + 0x00020000UL)

#define RCC_BASE                          (Peripherals_BASE + 0x00021000UL)
#define Flash_Registers                   (AHB1PERIPH_BASE + 0x2000UL)

//-----------------------------
//Base addresses for AHB2 Peripherals
//-----------------------------
#define AHB2PERIPH_BASE                   (Peripherals_BASE + 0x08000000UL)

//GPIO
//A,B fully included in LQFP48 Package
#define GPIOA_BASE         (AHB2PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE         (AHB2PERIPH_BASE + 0x0400UL)
//C,D Partial  included in LQFP48 Package
#define GPIOC_BASE         (AHB2PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE         (AHB2PERIPH_BASE + 0x0C00UL)
//E  not  included in LQFP48 Package
#define GPIOE_BASE         (AHB2PERIPH_BASE + 0x1000UL)
//F,G  not  included in LQFP48 Package
#define GPIOF_BASE         (AHB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE         (AHB2PERIPH_BASE + 0x2000)



//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

#define APB2_BUS_BASE         (Peripherals_BASE + 0x00010000UL)


#define SYSCFG_BASE           (APB2_BUS_BASE + 0x0000)
#define EXTI_BASE             (APB2_BUS_BASE + 0x0400)

#define USART1_BASE           (APB2_BUS_BASE + 0x3800)

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
  volatile uint32_t MODER;       // GPIO port mode register,
  volatile uint32_t OTYPER;      // GPIO port output type register,
  volatile uint32_t OSPEEDR;     // GPIO port output speed register,
  volatile uint32_t PUPDR;       // GPIO port pull-up/pull-down register,
  volatile uint32_t IDR;         // GPIO port input data register,
  volatile uint32_t ODR;         // GPIO port output data register,
  volatile uint32_t BSRR;        // GPIO port bit set/reset  register,
  volatile uint32_t LCKR;        // GPIO port configuration lock register,
  volatile uint32_t AFR[2];      // GPIO alternate function registers,
  volatile uint32_t BRR;         // GPIO Bit Reset register,
  volatile uint32_t ASCR;        // GPIO analog switch control register,

} GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
  volatile uint32_t CR;          // Clock control register
  volatile uint32_t ICSCR;       // Internal Clock Sources Calibration Register
  volatile uint32_t CFGR;        // Clock Configuration Register
  volatile uint32_t PLLCFGR;     // PLL Configuration Register
  volatile uint32_t PLLSAI1CFGR; // PLLSAI1 Configuration Register
  volatile uint32_t PLLSAI2CFGR; // PLLSAI2 Configuration Register
  volatile uint32_t CIER;        // Clock Interrupt Enable Register
  volatile uint32_t CIFR;        // Clock Interrupt Flag Register
  volatile uint32_t CICR;        // Clock Interrupt Clear Register
  volatile uint32_t AHB1RSTR;    // AHB1 Peripheral Reset Register
  volatile uint32_t AHB2RSTR;    // AHB2 Peripheral Reset Register
  volatile uint32_t AHB3RSTR;    // AHB3 Peripheral Reset Register
  uint32_t RESERVED0;            // Reserved
  volatile uint32_t APB1RSTR1;   // APB1 Peripheral Reset Register 1
  volatile uint32_t APB1RSTR2;   // APB1 Peripheral Reset Register 2
  volatile uint32_t APB2RSTR;    // APB2 Peripheral Reset Register
  volatile uint32_t AHB1ENR;     // AHB1 Peripheral Clock Enable Register
  volatile uint32_t AHB2ENR;     // AHB2 Peripheral Clock Enable Register
  volatile uint32_t AHB3ENR;     // AHB3 Peripheral Clock Enable Register
  uint32_t RESERVED1;            // Reserved
  volatile uint32_t APB1ENR1;    // APB1 Peripheral Clock Enable Register 1
  volatile uint32_t APB1ENR2;    // APB1 Peripheral Clock Enable Register 2
  volatile uint32_t APB2ENR;     // APB2 Peripheral Clock Enable Register
  volatile uint32_t AHB1SMENR;   // AHB1 Sleep Mode Clock Enable Register
  volatile uint32_t AHB2SMENR;   // AHB2 Sleep Mode Clock Enable Register
  volatile uint32_t AHB3SMENR;   // AHB3 Sleep Mode Clock Enable Register
  uint32_t RESERVED2;            // Reserved
  volatile uint32_t APB1SMENR1;  // APB1 Sleep Mode Clock Enable Register 1
  volatile uint32_t APB1SMENR2;  // APB1 Sleep Mode Clock Enable Register 2
  volatile uint32_t APB2SMENR;   // APB2 Sleep Mode Clock Enable Register
  volatile uint32_t CCIPR;       // Peripherals Independent Clock Configuration Register
  volatile uint32_t RESERVED3;   // Reserved
  volatile uint32_t BDCR;        // Backup Domain Control Register
  volatile uint32_t CSR;         // Control/Status Register
  volatile uint32_t CRRCR;       // Clock Recovery RC Register
  volatile uint32_t CCIPR2;      // Peripherals Independent Clock Configuration Register 2
} RCC_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
  volatile uint32_t IMR1;        // EXTI Interrupt mask register 1,
  volatile uint32_t EMR1;        // EXTI Event mask register 1,
  volatile uint32_t RTSR1;       // EXTI Rising trigger selection register 1,
  volatile uint32_t FTSR1;       // EXTI Falling trigger selection register 1,
  volatile uint32_t SWIER1;      // EXTI Software interrupt event register 1,
  volatile uint32_t PR1;         // EXTI Pending register 1,
  uint32_t  RESERVED1;           // Reserved,
  uint32_t  RESERVED2;           // Reserved,
  volatile uint32_t IMR2;        // EXTI Interrupt mask register 2,
  volatile uint32_t EMR2;        // EXTI Event mask register 2,
  volatile uint32_t RTSR2;       // EXTI Rising trigger selection register 2,
  volatile uint32_t FTSR2;       // EXTI Falling trigger selection register 2,
  volatile uint32_t SWIER2;      // EXTI Software interrupt event register 2,
  volatile uint32_t PR2;         // EXTI Pending register 2,
} EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
  volatile uint32_t CR1;         // USART Control register 1
  volatile uint32_t CR2;         // USART Control register 2
  volatile uint32_t CR3;         // USART Control register 3
  volatile uint32_t BRR;         // USART Baud rate register
  volatile uint16_t GTPR;        // USART Guard time and prescaler register
  uint16_t  RESERVED2;           // Reserved,
  volatile uint32_t RTOR;        // USART Receiver Time Out register
  volatile uint16_t RQR;         // USART Request register,
  uint16_t  RESERVED3;           // Reserved,
  volatile uint32_t ISR;         // USART Interrupt and status register
  volatile uint32_t ICR;         // USART Interrupt flag Clear register
  volatile uint16_t RDR;         // USART Receive Data register
  uint16_t  RESERVED4;           // Reserved
  volatile uint16_t TDR;         // USART Transmit Data register
  uint16_t  RESERVED5;           // Reserved
} USART_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: SYSCFG
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t MEMRMP;       // SYSCFG memory remap register
	volatile uint32_t CFGR1;        // SYSCFG configuration register 1
	volatile uint32_t EXTICR[4];    // SYSCFG external interrupt configuration registers
    uint32_t RESERVED1[2];          // Reserved */
    volatile uint32_t CFGR2;        // SYSCFG configuration register 2
} SYSCFG_TypeDef;

//-----------------------------------
// Peripheral Register : Flash
//-----------------------------------


typedef struct
{
  volatile uint32_t ACR;              // FLASH access control register,
  volatile uint32_t PDKEYR;           // FLASH power down key register,
  volatile uint32_t KEYR;             // FLASH key register,
  volatile uint32_t OPTKEYR;          // FLASH option key register,
  volatile uint32_t SR;               // FLASH status register,
  volatile uint32_t CR;               // FLASH control register,
  volatile uint32_t ECCR;             // FLASH ECC register,
  volatile uint32_t RESERVED1;        // Reserved1,
  volatile uint32_t OPTR;             // FLASH option register,
  volatile uint32_t PCROP1SR;         // FLASH bank1 PCROP start address register,
  volatile uint32_t PCROP1ER;         // FLASH bank1 PCROP end address register,
  volatile uint32_t WRP1AR;           // FLASH bank1 WRP area A address register,
  volatile uint32_t WRP1BR;           // FLASH bank1 WRP area B address register,
  uint32_t RESERVED2[4];              // Reserved2,
  volatile uint32_t PCROP2SR;         // FLASH bank2 PCROP start address register,
  volatile uint32_t PCROP2ER;         // FLASH bank2 PCROP end address register,
  volatile uint32_t WRP2AR;           // FLASH bank2 WRP area A address register,
  volatile uint32_t WRP2BR;           // FLASH bank2 WRP area B address register,
} FLASH_TypeDef;
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

#define SYSCFG              ((SYSCFG_TypeDef *)SYSCFG_BASE)
#define EXTI                ((EXTI_TypeDef *)EXTI_BASE)


#define USART1		       ((USART_Typedef *)USART1_BASE)
#define USART2		       ((USART_Typedef *)USART2_BASE)
#define USART3		       ((USART_Typedef *)USART3_BASE)

#define Flach_R            ((Flash_TypeDef *)Flash_Registers)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
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


// Disable clock

#define RCC_USART1_CLK_DI()	(RCC->APB2RSTR  |= 1 << 14) //USART1 disable is in bit 14
#define RCC_USART2_CLK_DI()	(RCC->APB1RSTR1 |= 1 << 17) //USART1 disable is in bit 17
#define RCC_USART3_CLK_DI()	(RCC->APB1RSTR1 |= 1 << 18) //USART1 disable is in bit 18



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

// Disable Interrupt Requests

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

// ================================================================
// ====================== Generic Macros ==========================
// ================================================================



//******************************************************
//******************************************************
//******************************************************
//******************  Bit definition  *******************
//******************************************************
//******************************************************


#endif // STM32_L47bRGTb0_Device_Header.h
