/*
 * GPIO_STM32_STM32_L47XXX_Driver.h
 *
 *  Created on:
 *      Author: badreddine.merareb
 */


#ifndef GPIO_STM32_STM32_L47XXX_DRIVER_H_
#define GPIO_STM32_STM32_L47XXX_DRIVER_H_


#include <STM32_STM32_L47XXX_Device_Header.h>



typedef struct
{
    uint16_t GPIO_PinNumber;             // @ref GPIO_PINS_define

    uint8_t  GPIO_MODE;                  // @ref GPIO_MODE_define

    uint8_t  GPIO_OutputSpeed;           // @ref GPIO_SPEED_define

    uint8_t  GPIO_Pull;                  // @ref GPIO_PUPD_define

    uint8_t  GPIO_OutputType;            // @ref GPIO_OTYPE_define

    uint8_t  Alternate_function;         // @ref GPIO_AF_define

} GPIO_PINConfig_t;



//@ref GPIO_MODE_define
#define GPIO_MODE_INPUT             0x00U
#define GPIO_MODE_OUTPUT_PP         0x01U   // Output Push-Pull
#define GPIO_MODE_OUTPUT_OD         0x11U   // Output Open-Drain
#define GPIO_MODE_AF_PP             0x02U   // Alternate Function Push-Pull
#define GPIO_MODE_AF_OD             0x12U   // Alternate Function Open-Drain
#define GPIO_MODE_ANALOG            0x03U
#define GPIO_MODE_ANALOG_SWITCH     0x13U



/*	@ref GPIO_output_type
	0: Output push-pull (reset state)
    1: Output open-drain
 */
//@ref GPIO_OTYPE_define
#define GPIO_OTYPE_PUSHPULL         0x00U
#define GPIO_OTYPE_OPENDRAIN        0x01U





/*	@ref GPIO_ pull-up/pull-down
	00: No pull-up, pull-down
    01: Pull-up
    10: Pull-down
    11: Reserved
 */

//@ref GPIO_PUPD_define
#define GPIO_NOPULL                 0x00U
#define GPIO_PULLUP                 0x01U
#define GPIO_PULLDOWN               0x02U



/*	@ref GPIO_SPEED_define
		01: Output mode, max speed 10 MHz.
		10: Output mode, max speed 2 MHz.
		11: Output mode, max speed 50 MHz.
 */


//@ref GPIO_SPEED_define
#define GPIO_SPEED_LOW              0x00U
#define GPIO_SPEED_MEDIUM           0x01U
#define GPIO_SPEED_HIGH             0x02U
#define GPIO_SPEED_VERY_HIGH        0x03U




/*	@ref GPIO_Analog_define
		0: Disconnect analog switch to the ADC input (reset state)
        1: Connect analog switch to the ADC input
 */

#define GPIO_Disconnect_analog     0x00000000u   //
#define GPIO_Connect_analog        0x00000001u   //






//@ref GPIO_Alternate_function

/*
0000: AF0
0001: AF1
0010: AF2
0011: AF3
0100: AF4
0101: AF5
0110: AF6
0111: AF7
1000: AF8
1001: AF9
1010: AF10
1011: AF11
1100: AF12
1101: AF13
1110: AF14
1111: AF15
 */
#define GPIO_Alternate_function0     0x00000000u
#define GPIO_Alternate_function1     0x00000001u
#define GPIO_Alternate_function2     0x00000002u
#define GPIO_Alternate_function3     0x00000003u
#define GPIO_Alternate_function4     0x00000004u
#define GPIO_Alternate_function5     0x00000005u
#define GPIO_Alternate_function6     0x00000006u
#define GPIO_Alternate_function7     0x00000007u
#define GPIO_Alternate_function8     0x00000008u
#define GPIO_Alternate_function9     0x00000009u
#define GPIO_Alternate_function10    0x0000000Au
#define GPIO_Alternate_function11    0x0000000Bu
#define GPIO_Alternate_function12    0x0000000Cu
#define GPIO_Alternate_function13    0x0000000Du
#define GPIO_Alternate_function14    0x0000000Eu
#define GPIO_Alternate_function15    0x0000000Fu


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
#define GPIO_PIN_MASK  ((uint16_t)0x0001)          // Base mask for shifting: GPIO_PIN_x = (GPIO_PIN_MASK << x)


/*	@ref GPIO_PIN_OUTPUT_defines
 */

#define GPIO_PIN_SET            1
#define GPIO_PIN_RESET          0




/*
 * -------------------------------------------------------------------------------------------------------
 *                                   APIS Supported By MCAL GPIO DRIVER
 *---------------------------------------------------------------------------------------------------------
 * */

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx , GPIO_PINConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx );


//READ  APIs
uint8_t  MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort	(GPIO_TypeDef *GPIOx);


//WRITE  APIs
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx , uint16_t Value);
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx , uint16_t PinNumber, uint8_t Value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx , uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber);

#endif /* GPIO_STM32_STM32_L47XXX_DRIVER_H_ */
