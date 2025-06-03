/*
 * GPIO_STM32_L47bRGTb0_Driver.c
 *
 *  Created on:
 *      Author: badreddine.merareb
 */
#include "GPIO_STM32_L47bRGTb0_Driver.h"
/*
 * =======================================================================================
 * 							Generic Macros
 * =======================================================================================
 */




/*
 * =======================================================================================
 * 							Generic Functions
 * =======================================================================================
*/  static uint8_t Get_Position(uint16_t GPIO_PIN_Numbre)
{
	switch (GPIO_PIN_Numbre)
	{
	case GPIO_PIN_0 :
		       return 0;
		         break ;

		case GPIO_PIN_1 :
		       return 2;
		         break ;

		case GPIO_PIN_2 :
			   return 4;
			     break ;

		case GPIO_PIN_3 :
		       return 6;
		         break ;

		case GPIO_PIN_4 :
		       return 8;
		         break ;

		case GPIO_PIN_5 :
		       return 10;
		         break ;

		case GPIO_PIN_6 :
		       return 12;
		         break ;

		case GPIO_PIN_7 :
		       return 14;
		         break ;

		case GPIO_PIN_8 :
		       return 16;
		         break ;

		case GPIO_PIN_9 :
		       return 18;
		         break ;

		case GPIO_PIN_10 :
		       return 20;
		         break ;

		case GPIO_PIN_11 :
		       return 22;
		         break ;

		case GPIO_PIN_12 :
		       return 24;
		         break ;

		case GPIO_PIN_13 :
		       return 26;
		         break ;

		case GPIO_PIN_14 :
		       return 28;
		         break ;

		case GPIO_PIN_15 :
		       return 30;
		         break ;
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


	volatile uint32_t *Config_register = (Get_Position(PinConfig->GPIO_pinNumber) < 16) ? &GPIOx->AFRL : &GPIOx->AFRH;


	//clears the mode bits for the pin, preparing it for a new mode configuration.
	GPIOx->MODER &= ~(0x3U << (Get_Position(PinConfig->GPIO_pinNumber ))); //
    GPIOx->OTYPER &= ~(PinConfig->GPIO_pinNumber); //
    GPIOx->OSPEEDR &= ~(0x3U << (Get_Position(PinConfig->GPIO_pinNumber )));  //
    GPIOx->PUPDR &= ~(0x3U << (Get_Position(PinConfig->GPIO_pinNumber )));
    GPIOx->ASCR &= ~(PinConfig->GPIO_pinNumber);  //

    // configure the GPIOx mode input OR output OR Alternate_function OR _Analog_mode.
    GPIOx->MODER |= (PinConfig->GPIO_MODE << (Get_Position(PinConfig->GPIO_pinNumber)));
	// if output
    if (PinConfig->GPIO_MODE == GPIO_output_mode)
    {
    	//if ((PinConfig->GPIO_OutputType == GPIO_Output_push_pull) ||  (PinConfig->GPIO_OutputType == GPIO_Output_open_drain))
    	//{
    	    GPIOx->OTYPER |= (PinConfig->GPIO_OutputType ? PinConfig->GPIO_pinNumber : 0);
        //}
        	//if ((PinConfig->GPIO_Output_Speed == GPIO_speed_2_MHz) || (PinConfig->GPIO_Output_Speed == GPIO_speed_10_MHz) || (PinConfig->GPIO_Output_Speed == GPIO_speed_50_MHz) || (PinConfig->GPIO_Output_Speed == GPIO_speed_80_MHz))
        //{
        	GPIOx->OSPEEDR |= (PinConfig->GPIO_Output_Speed << (Get_Position(PinConfig->GPIO_pinNumber)));
        //}
    }

    // if input
    else if (PinConfig->GPIO_MODE == GPIO_Input_mode)
    {
    	//if ((PinConfig->GPIO_inputType == GPIO_Input_No_pull_up_pull_down) || (PinConfig->GPIO_inputType == GPIO_Input_Pull_up) || (PinConfig->GPIO_inputType == GPIO_Input_Pull_down))
    	//{
    	 GPIOx->PUPDR |= (PinConfig->GPIO_inputType << (Get_Position(PinConfig->GPIO_pinNumber)));//
        //}
    }

    // if Alternate_function
    else if (PinConfig->GPIO_MODE == Alternate_function_mode)
    {
    	*Config_register |= PinConfig->Alternate_function << ((Get_Position(PinConfig->GPIO_pinNumber) % 8) * 4);
    }

    // if _Analog_mode
    else if (PinConfig->GPIO_MODE == GPIO_Analog_mode)
    {
    	//if ((PinConfig->GPIO_inputType == GPIO_Disconnect_analog) || (PinConfig->GPIO_inputType == GPIO_Connect_analog))
    	//{
    	     GPIOx->ASCR |=  (PinConfig->GPIO_inputType ? PinConfig->GPIO_pinNumber : 0);
    	//}
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
	else if (GPIOx == GPIOH)
	{
	    RCC->AHB2RSTR |= (1 << 7);   // Enable reset for GPIOH (bit 7)
	    RCC->AHB2RSTR &= ~(1 << 7);  // Stop reset for GPIOH (bit 7)
	}
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
   uint8_t BitStatus;
   if ((GPIOx->IDR & PinNumber) != GPIO_PIN_RESET)
   {
	   BitStatus = GPIO_PIN_SET;
   }else
   {
	   BitStatus = GPIO_PIN_RESET;
   }
   return BitStatus;
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

#endif /* GPIO_GPIO_STM32_L47BRGTB0_DRIVER_H_ */
