/*
 * GPIO_STM32_STM32_L47XXX_Driver.c
 *
 *  Created on:
 *      Author: Merareb.Badreddine
 */


#include <GPIO_STM32_STM32_L47XXX_Driver.h>

/*
 * =======================================================================================
 * 							Generic Macros
 * =======================================================================================
 */




/*
 * =======================================================================================
 * 							Generic Functions
 * =======================================================================================
  */


static uint8_t Get_Position(uint16_t GPIO_PIN_Numbre)
{
    switch (GPIO_PIN_Numbre)
    {
        case GPIO_PIN_0:  return 0;
        case GPIO_PIN_1:  return 1;
        case GPIO_PIN_2:  return 2;
        case GPIO_PIN_3:  return 3;
        case GPIO_PIN_4:  return 4;
        case GPIO_PIN_5:  return 5;
        case GPIO_PIN_6:  return 6;
        case GPIO_PIN_7:  return 7;
        case GPIO_PIN_8:  return 8;
        case GPIO_PIN_9:  return 9;
        case GPIO_PIN_10: return 10;
        case GPIO_PIN_11: return 11;
        case GPIO_PIN_12: return 12;
        case GPIO_PIN_13: return 13;
        case GPIO_PIN_14: return 14;
        case GPIO_PIN_15: return 15;
    }
    return 0;
}



/*
 * =======================================================================================
 * 							APIs Functions Definitions
 * =======================================================================================
 */




/**================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief 			- Initializes the GPIOx peripheral according to the specified parameters in the PinConfig
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinConfig: pointer to a GPIO_PinConfig_t structure that contains
 *         						 the configuration information for the specified GPIO peripheral.
 * @retval 			-none
 * Note				-Stm32L47bRGTb0 MCU has GPIO A,B,C,D,E.H Modules
 * 					 But LQFP64 Package has only GPIO A,B,C,H,PART of E/D exported as external PINS from the MCU
 */
void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PINConfig_t* PinConfig)
{
    uint32_t position = Get_Position(PinConfig->GPIO_PinNumber);
    volatile uint32_t *Config_register = (position < 8) ? &GPIOx->AFR[0] : &GPIOx->AFR[1];

    // Reset MODER, OTYPER, OSPEEDR, PUPDR, ASCR
    GPIOx->MODER   &= ~(0x3U << (position * 2));
    GPIOx->OTYPER  &= ~(0x1U << position);
    GPIOx->OSPEEDR &= ~(0x3U << (position * 2));
    GPIOx->PUPDR   &= ~(0x3U << (position * 2));
    GPIOx->ASCR    &= ~(0x1U << position);

    // Set MODER
    uint8_t MODE = PinConfig->GPIO_MODE & 0x0FU;            // Lower nibble for mode
    uint8_t OTYPER = (PinConfig->GPIO_MODE >> 4) & 0x01U;   // Bit 4 for output type
    GPIOx->MODER |= (MODE << (position * 2));

    // Configure based on mode
    if (MODE == GPIO_MODE_OUTPUT_PP || MODE == GPIO_MODE_OUTPUT_OD)
    {
        GPIOx->OTYPER |= (OTYPER << position);
        GPIOx->OSPEEDR |= (PinConfig->GPIO_OutputSpeed << (position * 2));
        GPIOx->PUPDR |= (PinConfig->GPIO_Pull << (position * 2));
    }
    else if (MODE == GPIO_MODE_AF_PP || MODE == GPIO_MODE_AF_OD)
    {
        GPIOx->OTYPER |= (OTYPER << position);
        GPIOx->OSPEEDR |= (PinConfig->GPIO_OutputSpeed << (position * 2));
        GPIOx->PUPDR |= (PinConfig->GPIO_Pull << (position * 2));
        *Config_register &= ~(0xFU << ((position % 8) * 4));
        *Config_register |= (PinConfig->Alternate_function << ((position % 8) * 4));
    }
    else if (MODE == GPIO_MODE_INPUT)
    {
        GPIOx->PUPDR |= (PinConfig->GPIO_Pull << (position * 2));
    }
    else if (MODE == GPIO_MODE_ANALOG_SWITCH)
    {
        GPIOx->ASCR |= (1U << position); // Enable analog switch connection
    }
}


/**=======================================================================================================================
 * @Fn					-MCAL_GPIO_DeInit
 * @brief 				- reset all the GPIO Registers
 * @param [in] 			-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval 				-none
 * Note					-none
 */

void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx ){

	if (GPIOx == GPIOA)
	{
	    RCC->AHB2RSTR |= (1 << 0);   // Enable reset for GPIOA (bit 0)
	    RCC->AHB2RSTR &= ~(1 << 0);  // Stop reset for GPIOA (bit 0)
	}
	else if (GPIOx == GPIOB)
	{
	    RCC->AHB2RSTR |= (1 << 1);   // Enable reset for GPIOB (bit 1)
	    RCC->AHB2RSTR &= ~(1 << 1);  // Stop reset for GPIOB (bit 1)
	}
	else if (GPIOx == GPIOC)
	{
	    RCC->AHB2RSTR |= (1 << 2);   // Enable reset for GPIOC (bit 2)
	    RCC->AHB2RSTR &= ~(1 << 2);  // Stop reset for GPIOC (bit 2)
	}
	else if (GPIOx == GPIOD)
	{
	    RCC->AHB2RSTR |= (1 << 3);   // Enable reset for GPIOD (bit 3)
	    RCC->AHB2RSTR &= ~(1 << 3);  // Stop reset for GPIOD (bit 3)
	}
	else if (GPIOx == GPIOE)
	{
	    RCC->AHB2RSTR |= (1 << 4);   // Enable reset for GPIOE (bit 4)
	    RCC->AHB2RSTR &= ~(1 << 4);  // Stop reset for GPIOE (bit 4)
	}
	//else if (GPIOx == GPIOH)
	//{
	   // RCC->AHB2RSTR |= (1 << 7);   // Enable reset for GPIOH (bit 7)
	    //RCC->AHB2RSTR &= ~(1 << 7);  // Stop reset for GPIOH (bit 7)
	//}
}


/**=======================================================================================================================
 * @Fn					-MCAL_GPIO_ReadPin
 * @brief 				-Reads the specified input port pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 				-The input port pin value.
 * Note					-none
 */


uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
   return ((GPIOx->IDR & PinNumber) != 0U) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

/**==================================================================================================================
 * @Fn					-MCAL_GPIO_ReadPort
 * @brief 				-read the input port VALUE
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 				-the input port VALUE
 * Note					-none
 */

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	uint16_t port_value ;
	port_value = (uint16_t)(GPIOx->IDR) ;
	return port_value ;
}

/**==================================================================================================================
 * @Fn					-MCAL_GPIO_WritePin
 * @brief 				-write on specific input pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-PinNumber:  specifies the port bit to read. Set by @ref GPIO_PINS_define
 *@param [in] 			-Value: Pin Value
 *
 * @retval 			-none
 * Note				-none
 */
void MCAL_GPIO_WritePin	(GPIO_TypeDef *GPIOx , uint16_t PinNumber, uint8_t Value)
{
	if (Value != GPIO_PIN_RESET)
		{
			// Atomic: Write to BSRR sets the corresponding pin in 1 CPU cycle without affecting other bits
			GPIOx->BSRR = PinNumber;

			// Not Atomic: Reads, modifies, and writes ODR, which can cause race conditions
			// GPIOx->ODR |= PinNumber;
		}
		else
		{

			GPIOx->BSRR = PinNumber << 16U;

		 // GPIOx->ODR &= ~(PinNumber);
		}

}


/**==================================================================================================================
 * @Fn					-MCAL_GPIO_WritePort
 * @brief 				-write on output port
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 				-none
 * Note					-none
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx , uint16_t Value)
{

	GPIOx->ODR = (uint32_t)(Value);
}

/**================================================================
 * @Fn					-MCAL_GPIO_TogglePin
 * @brief 				-Toggles the specified GPIO pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			-none
 * Note				-none
 */
void MCAL_GPIO_TogglePin		(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber);
}
