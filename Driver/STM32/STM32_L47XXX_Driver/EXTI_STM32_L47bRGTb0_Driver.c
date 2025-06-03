/*
 * EXTI_STM32_L47bRGTb0_Driver.c
 *
 *  Created on: Jun 1, 2025
 *      Author: badreddine.merareb
 */




#include "EXTI_STM32_L47bRGTb0_Driver.h"
  //EXTI_TypeDef EXTI;
/*
 * =======================================================================================
 * 							Generic Variables
 * =======================================================================================
 */
 void(* GP_IRQ_CallBack[15])(void) ;

 /*
  * =======================================================================================
  * 							Generic Macros
  * =======================================================================================
  */

  void Enable_NVIC (uint16_t IRQ)
 {
 	switch (IRQ)
 	{
 	case 0:
 		NVIC_IRQ6_EXTI0_Enable();
 		break;
 	case 1:
 		NVIC_IRQ7_EXTI1_Enable();
 		break ;
 	case 2:
 		NVIC_IRQ8_EXTI2_Enable() ;
 		break ;
 	case 3:
 		NVIC_IRQ9_EXTI3_Enable() ;
 		break ;
 	case 4:
 		NVIC_IRQ10_EXTI4_Enable() ;
 		break ;
 	case 5:
 	case 6:
 	case 7:
 	case 8:
 	case 9:
 		NVIC_IRQ23_EXTI5_9_Enable();
 		break ;

 	case 10:
 	case 11:
 	case 12:
 	case 13:
 	case 14:
 	case 15:
 		NVIC_IRQ40_EXTI10_15_Enable();
 		break ;

 	}
 }

 void Disable_NVIC (uint16_t IRQ)
 {
 	switch (IRQ)
 		{
 		case 0:
 			NVIC_IRQ6_EXTI0_Disable();
 			break;
 		case 1:
 			NVIC_IRQ7_EXTI1_Disable();
 			break ;
 		case 2:
 			NVIC_IRQ8_EXTI2_Disable();
 			break ;
 		case 3:
 			NVIC_IRQ9_EXTI3_Disable();
 			break ;
 		case 4:
 			NVIC_IRQ10_EXTI4_Disable();
 			break ;
 		case 5:
 		case 6:
 		case 7:
 		case 8:
 		case 9:
 			NVIC_IRQ23_EXTI5_9_Disable();
 			break ;

 		case 10:
 		case 11:
 		case 12:
 		case 13:
 		case 14:
 		case 15:
 			NVIC_IRQ40_EXTI10_15_Disable();
 			break ;

 		}

 }


void MCAL_EXTI_GPIO_DeInit (void)
{

	//EXTI->IMR1 = 0x00000000;
	//EXTI->EMR1 = 0x00000000;

	//EXTI->RTSR1 = 0x00000000;

	//EXTI->FTSR1 = 0x00000000;
	//EXTI->SWIER1 = 0x00000000;

		//rc_w1  cleared by writing a ‘1’ into the PR
	//EXTI->PR1  = 0xFFFFFFFF ;

		//Disable EXTI IRQ From NVIC
		NVIC_IRQ6_EXTI0_Disable() ;
		NVIC_IRQ7_EXTI1_Disable() ;
		NVIC_IRQ8_EXTI2_Disable() ;
		NVIC_IRQ9_EXTI3_Disable() ;
		NVIC_IRQ10_EXTI4_Disable() ;
		NVIC_IRQ23_EXTI5_9_Disable() ;
		NVIC_IRQ40_EXTI10_15_Disable() ;

}

/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_Init
 * @brief 			-this is used to inialize EXTI from SpecifiC GPIO PIN and specify the Mask/Trigger Condition and IRQ CallBack
 * @param [in]   	-EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @retval 			-none
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 				 	But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 * 				 	- Also Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
 */
void MCAL_EXTI_GPIO_Init (EXTI_PinConfig_t* EXTI_Config)
{
	//Update_EXTI(EXTI_Config);
}

/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_Update
 * @brief 			-this is used to inialize EXTI from SpecifiC GPIO PIN and specify the Mask/Trigger Condition and IRQ CallBack
 * @param [in]   	-EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @retval 			-none
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 				 	But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 * 				 	- Also Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
 */
void MCAL_EXTI_GPIO_Update (EXTI_PinConfig_t* EXTI_Config)
{
	//Update_EXTI(EXTI_Config) ;

}


///**================================================================
///**================================================================
///**===========			ISR  Functions        =========================
///**================================================================
// */




void EXTI0_IRQHandler (void)
{
	//EXIT->PR1 |= 1<<0 ;

   GP_IRQ_CallBack[0]();
}
