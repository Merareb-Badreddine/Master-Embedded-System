*
 * GPIO_STM32_L47bRGTb0_Driver.h
 *
 *  Created on: May 28, 2025
 *      Author: badreddine.merareb
 */

#ifndef GPIO_GPIO_STM32_L47BRGTB0_DRIVER_H_
#define GPIO_GPIO_STM32_L47BRGTB0_DRIVER_H_

#include <STM32_L47bRGTb0_Device_Header.h>

typedef struct
{
    uint16_t GPIO_pinNumber;

    uint8_t  GPIO_MODE;

    uint8_t  GPIO_OutputType;

    uint8_t  GPIO_Output_Speed;

    uint8_t  GPIO_inputType;


} GPIO_PINConfig_t;

/*	@ref GPIO_MODE_define

00: Input mode
01: General purpose output mode
10: Alternate function mode
11: Analog mode (reset state)
*/

#define GPIO_Input_mode          0x00000000u   //

#define GPIO_output_mode         0x00000001u   //

#define Alternate_function_mode  0x00000010u   //

#define GPIO_Analog_mode         0x00000011u   //(reset state)



/*	@ref GPIO_output_type
	0: Output push-pull (reset state)
    1: Output open-drain
 */
#define GPIO_Output_push_pull     0x00000000u   //(reset state)

#define GPIO_Output_open_drain    0x00000001u   //


/*	@ref GPIO_ pull-up/pull-down
	00: No pull-up, pull-down
    01: Pull-up
    10: Pull-down
    11: Reserved
 */

#define GPIO_Input_No_pull_up_pull_down     0x00000000u   //

#define GPIO_Input_Pull_up                  0x00000001u   //

#define GPIO_Input_Pull_down                0x00000010u   //


/*	@ref GPIO_SPEED_define
		01: Output mode, max speed 10 MHz.
		10: Output mode, max speed 2 MHz.
		11: Output mode, max speed 50 MHz.
 */


#define GPIO_speed_2_MHz          0x00000000u   // Low speed

#define GPIO_speed_10_MHz         0x00000001u   //  Medium speed

#define GPIO_speed_50_MHz         0x00000010u   //  High speed

#define GPIO_speed_80_MHz         0x00000011u   //  Very high speed



/*	@ref GPIO_PINS_define
 */


#define GPIO_PIN_0             ((uint16_t)0x0001) //pin 0
#define GPIO_PIN_1             ((uint16_t)0x0002) //pin 1
#define GPIO_PIN_2             ((uint16_t)0x0004) //pin 2
#define GPIO_PIN_3             ((uint16_t)0x0008) //pin 3
#define GPIO_PIN_4             ((uint16_t)0x0010) //pin 4
#define GPIO_PIN_5             ((uint16_t)0x0020) //pin 5
#define GPIO_PIN_6             ((uint16_t)0x0040) //pin 6
#define GPIO_PIN_7             ((uint16_t)0x0080) //pin 7
#define GPIO_PIN_8             ((uint16_t)0x0100) //pin 8
#define GPIO_PIN_9             ((uint16_t)0x0200) //pin 9
#define GPIO_PIN_10            ((uint16_t)0x0400) //pin 10
#define GPIO_PIN_11            ((uint16_t)0x0800) //pin 11
#define GPIO_PIN_12            ((uint16_t)0x1000) //pin 12
#define GPIO_PIN_13            ((uint16_t)0x2000) //pin 13
#define GPIO_PIN_14            ((uint16_t)0x4000) //pin 14
#define GPIO_PIN_15            ((uint16_t)0x8000) //pin 15

#define GPIO_PIN_ALL            ((uint16_t)0xFFFF) //pin 15
#define GPIO_PIN_MASK           ((uint16_t)0x001) //pin 15


/*	@ref GPIO_PIN_OUTPUT_defines
 */

#define GPIO_PIN_SET            1
#define GPIO_PIN_RESET          0



/*
 * -------------------------------------------------------------------------------------------------------
 *                                   APIS Supported By MCAL GPIO DRIVER
 *---------------------------------------------------------------------------------------------------------
 * */

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx , GPIO_PINConfig_t* PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx );


//READ  APIs
uint8_t  MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort	(GPIO_TypeDef *GPIOx);


//WRITE  APIs
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx , uint16_t Value);
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx , uint16_t PinNumber, uint8_t Value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx , uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber);



#endif /* GPIO_GPIO_STM32_L47BRGTB0_DRIVER_H_ */
