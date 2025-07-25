
/*
 * stm32f103x8_gpio_driver.h
 *
 *  Created on: 
 *      Author: Merareb Badreddine 
 *     
 */

#include "GPIO_Stm32_F103C6_Driver.h"


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
uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0 ;
		break ;
	case GPIO_PIN_1:
		return 4 ;
		break ;

	case GPIO_PIN_2:
		return 8 ;
		break ;

	case GPIO_PIN_3:
		return 12 ;
		break ;

	case GPIO_PIN_4:
		return 16 ;
		break ;


	case GPIO_PIN_5:
		return 20 ;
		break ;

	case GPIO_PIN_6:
		return 24 ;
		break ;

	case GPIO_PIN_7:
		return 28 ;
		break ;

	case GPIO_PIN_8:
		return 0 ;
		break ;
	case GPIO_PIN_9:
		return 4 ;
		break ;

	case GPIO_PIN_10:
		return 8 ;
		break ;

	case GPIO_PIN_11:
		return 12 ;
		break ;

	case GPIO_PIN_12:
		return 16 ;
		break ;


	case GPIO_PIN_13:
		return 20 ;
		break ;

	case GPIO_PIN_14:
		return 24 ;
		break ;

	case GPIO_PIN_15:
		return 28 ;
		break ;


	}
return 0 ;

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
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 					 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 */
void MCAL_GPIO_Init  (GPIO_TypeDef *GPIOx , GPIO_PinConfig_t* PinConfig)
{
	volatile uint32_t* configregister = NULL ;
	uint8_t	PIN_Config = 0 ;

	 
	//if Pin is output
	if ( (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP ) ||  (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD ) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD ) ||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP ))
	{
		PIN_Config  =  (  ( ( (PinConfig->GPIO_MODE - 4) <<2 ) |  PinConfig->GPIO_Output_Speed   ) & 0x0F );
		(*configregister) |= (  (  PIN_Config  ) << ( Get_CRLH_Position( PinConfig->GPIO_PinNumber) ) ) ;
	}
	//if pin is input
	else //MODE =  00: Input mode (reset state)
	{
		if (  (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG ) || (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO ) )
		{
			PIN_Config  =  (  ( ( PinConfig->GPIO_MODE <<2 ) |  0x0   ) & 0x0F );
			(*configregister) |= (  (  PIN_Config  ) << ( Get_CRLH_Position( PinConfig->GPIO_PinNumber) ) ) ;
		}
		else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT )
		{
			PIN_Config  =  (  ( ( GPIO_MODE_INPUT_FLO <<2 ) |  0x0   ) & 0x0F );
			(*configregister) |= (  (  PIN_Config  ) << ( Get_CRLH_Position( PinConfig->GPIO_PinNumber) ) ) ;
		}
		//Input with pull-up / pull-down
		else
		{
			PIN_Config  =  (  ( ( GPIO_MODE_INPUT_PU <<2 ) |  0x0   ) & 0x0F );
			(*configregister) |= (  (  PIN_Config  ) << ( Get_CRLH_Position( PinConfig->GPIO_PinNumber) ) ) ;

			if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				//PxODR = 1 Input pull-up :Table 20. Port bit configuration table
				GPIOx->ODR |= PinConfig->GPIO_PinNumber ;
			}else
			{
				//PxODR = 0 Input pull-down :Table 20. Port bit configuration table
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber) ;

			}

		}
	}

}

/**================================================================
 * @Fn					-MCAL_GPIO_DeInit
 * @brief 				- reset all the GPIO Registers
 * @param [in] 			-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval 				-none
 * Note					-none
 */
void MCAL_GPIO_DeInit    (GPIO_TypeDef *GPIOx )
{

	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);  //Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);

	}else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);  //Bit 3 IOPBRST: IO port B reset
		RCC->APB2RSTR &= ~(1<<3);

	}else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);  //Bit 4 IOPCRST: IO port C reset
		RCC->APB2RSTR &= ~(1<<4);

	}else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);  //Bit 5 IOPDRST: IO port D reset
		RCC->APB2RSTR &= ~(1<<5);

	}else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);  //Bit 6 IOPERST: IO port E reset
		RCC->APB2RSTR &= ~(1<<6);

	}

}

/**================================================================
 * @Fn					-MCAL_GPIO_ReadPin
 * @brief 				-Reads the specified input port pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 				-The input port pin value.
 * Note					-none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
   uint8_t BitStatus;
   if ((GPIOx->IDR & PinNumber) != (uint32_t)GPIO_PIN_SET)
   {
	   BitStatus = GPIO_PIN_SET;
   }else
   {
	   BitStatus = GPIO_PIN_RESET;
   }
   return BitStatus;
}


/**================================================================
 * @Fn					-MCAL_GPIO_ReadPort
 * @brief 				-read the input port VALUE
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 				-the input port VALUE
 * Note					-none
 */
uint16_t MCAL_GPIO_ReadPort		(GPIO_TypeDef *GPIOx)
{
	uint16_t port_value ;
	port_value = (uint16_t)(GPIOx->IDR) ;
	return port_value ;
}

/**================================================================
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

//		Not Atomic: Reads, modifies, and writes ODR, which can cause race conditions
//		GPIOx->ODR |= PinNumber ;
	}
	else
	{

		GPIOx->BRR = (uint32_t)PinNumber ;

//		or
//		GPIOx->ODR &= ~(PinNumber) ;
	}

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

