*
 * EXTI_STM32_L47bRGTb0_Driver.c
 *
 *  Created on: 
 *      Author: badreddine.merareb
 */


#include "GPIO_STM32_L47BRGTB0_DRIVER.h"
#include "EXTI_STM32_L47bRGTb0_Driver.h"


#define SYSCFG_GPIO_EXTI_Mapping(x)	(   (x==GPIOA)?0:\
		                                (x==GPIOB)?1:\
				                        (x==GPIOC)?2:\
						                (x==GPIOD)?3:0  )

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
	//1- Configure GPIO to be AF Input -> AFIO
	GPIO_PINConfig_t PinCfg ;

	PinCfg.GPIO_pinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinCfg.GPIO_MODE = GPIO_Input_mode;
	PinCfg.GPIO_inputType = GPIO_Input_No_pull_up_pull_down ;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port , &PinCfg);

	//==============================================

		///2- UPDATE AFIO to Route between EXTI Line with PORT

	uint8_t SYSCFG_EXTICR_index = EXTI_Config->EXTI_PIN.ETI_InputLineNumber / 4 ;

	uint8_t	SYSCFG_EXTICR_Postion = (EXTI_Config->EXTI_PIN.ETI_InputLineNumber % 4) ;

	SYSCFG->EXTICR[SYSCFG_EXTICR_index ] &= ~(0xF <<SYSCFG_EXTICR_Postion );

	SYSCFG->EXTICR[SYSCFG_EXTICR_index ] |= ((SYSCFG_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) &0xF) << SYSCFG_EXTICR_Postion);

	//==============================================

	//3- Update Rising or falling Register

	//3- Update Rising or falling Register
	 EXTI->RTSR1 &= ~(1<< EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	 EXTI->FTSR1 &= ~(1<< EXTI_Config->EXTI_PIN.ETI_InputLineNumber);

	    if (EXTI_Config->Trigger_Case == EXTI_Trigger_RISING_Enabled)
	 	{
	 		EXTI->RTSR1 |=  (1<< EXTI_Config->EXTI_PIN.ETI_InputLineNumber);

	 	}else if  (EXTI_Config->Trigger_Case == EXTI_Trigger_FALLING_Enabled)
	 	{
	 		EXTI->FTSR1 |= (1<< EXTI_Config->EXTI_PIN.ETI_InputLineNumber);


	 	}else if  (EXTI_Config->Trigger_Case == EXTI_Trigger_RisingAndFalling)
	 	{
	 		EXTI->RTSR1 |=  (1<< EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	 		EXTI->FTSR1 |= (1<< EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	 	}

	 	//==============================================
	    //==============================================
	    	//4- Update IRQ Handling CALLBACK
		GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.ETI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack ;
		//==============================================

		//5- Enable/Disable IRQ EXTI & NVIC

			if (EXTI_Config->IRQ_EN == EXTI_IRQ_Enable )
			{
				EXTI->IMR1 |= (1<< EXTI_Config->EXTI_PIN.ETI_InputLineNumber );
				Enable_NVIC (EXTI_Config->EXTI_PIN.ETI_InputLineNumber ) ;
			}else
			{
				EXTI->IMR1 &= ~(1<< EXTI_Config->EXTI_PIN.ETI_InputLineNumber );
				Disable_NVIC (EXTI_Config->EXTI_PIN.ETI_InputLineNumber) ;
			}
}


///**================================================================
///**================================================================
///**===========			ISR  Functions        =========================
///**================================================================
// */




void EXTI0_IRQHandler (void)
{
	//cleared by writing a ‘1’ into the bit Pending register (EXTI_PR)
	EXTI->PR1 |= 1<<0 ;
	//CALL IRQ_CALL
	GP_IRQ_CallBack[0]() ;
}

void EXTI1_IRQHandler (void) {
	EXTI->PR1 |=  (1<<1) ;

	GP_IRQ_CallBack[1]() ; }


void EXTI2_IRQHandler (void) {
	EXTI->PR1 |=  (1<<2) ;

	GP_IRQ_CallBack[2]() ; }


void EXTI3_IRQHandler (void) {
	EXTI->PR1 |=  (1<<3) ;

	GP_IRQ_CallBack[3]() ; }


void EXTI4_IRQHandler (void) {
	EXTI->PR1 |=  (1<<4) ;
	GP_IRQ_CallBack[4]() ; }


void EXTI9_5_IRQHandler (void)
{
	if (EXTI->PR1 & 1<<5 ) {	EXTI->PR1 |=  (1<<5)    ; GP_IRQ_CallBack[5]() ;   }
	if (EXTI->PR1 & 1<<6 ) {	EXTI->PR1 |=  (1<<6)    ; GP_IRQ_CallBack[6]() ;   }
	if (EXTI->PR1 & 1<<7 ) {	EXTI->PR1 |=  (1<<7)    ; GP_IRQ_CallBack[7]() ;   }
	if (EXTI->PR1 & 1<<8 ) {	EXTI->PR1 |=  (1<<8)    ; GP_IRQ_CallBack[8]() ;   }
	if (EXTI->PR1 & 1<<9 ) {	EXTI->PR1 |=  (1<<9)    ; GP_IRQ_CallBack[9]() ;   }

}
void EXTI15_10_IRQHandler (void)
{
	if (EXTI->PR1 & 1<<10 ) {	EXTI->PR1 |=  (1<<10)    ; GP_IRQ_CallBack[10]() ;   }
	if (EXTI->PR1 & 1<<11 ) {	EXTI->PR1 |=  (1<<11)    ; GP_IRQ_CallBack[11]() ;   }
	if (EXTI->PR1 & 1<<12 ) {	EXTI->PR1 |=  (1<<12)    ; GP_IRQ_CallBack[12]() ;   }
	if (EXTI->PR1 & 1<<13 ) {	EXTI->PR1 |=  (1<<13)    ; GP_IRQ_CallBack[13]() ;   }
	if (EXTI->PR1 & 1<<14 ) {	EXTI->PR1 |=  (1<<14)    ; GP_IRQ_CallBack[14]() ;   }
	if (EXTI->PR1 & 1<<15 ) {	EXTI->PR1 |=  (1<<15)    ; GP_IRQ_CallBack[15]() ;   }

}

