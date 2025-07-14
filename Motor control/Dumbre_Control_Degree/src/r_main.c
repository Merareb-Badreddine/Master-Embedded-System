/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_main.c
* Version      : CodeGenerator for RL78/G14 V2.05.08.02 [03 Jun 2024]
* Device(s)    : R5F104GF
* Tool-Chain   : GCCRL78
* Description  : This file implements main function.
* Creation Date: 14/07/2025
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

#define STEPS_PER_DEGREE   20  // DEGRE * 1800 / 90

volatile uint16_t step_counter     = 0;
volatile uint8_t  motor_direction  = 0;
volatile int      current_degree   = 0;
volatile uint16_t TOTAL_STEPS_OPEN = 0;
volatile uint16_t TOTAL_STEPS_CLOSE = 0;

/* End user code. Do not edit comment generated here */
void R_MAIN_UserInit(void);
void set_step(uint8_t step);
void Dumbre_Control_Degree(int degree);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
int main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */

    Dumbre_Control_Degree(45);
    while (motor_direction != 0);  //

    Dumbre_Control_Degree(25);
    while (motor_direction != 0);  //

    Dumbre_Control_Degree(65);
    while (motor_direction != 0);  //

    Dumbre_Control_Degree(0);
    while (motor_direction != 0);  //

    while (1)
       {
             ;
       }
    /* End user code. Do not edit comment generated here */
}


/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
	R_TAU0_Channel0_Start();
    EI();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
void Dumbre_Control_Degree(int target_degree)
{
    if (target_degree > current_degree) {
    	TOTAL_STEPS_OPEN = (uint16_t)((target_degree - current_degree) * STEPS_PER_DEGREE);
        step_counter = 0;
        motor_direction = 1;
        current_degree = target_degree;
    }
    else if (target_degree < current_degree) {
        TOTAL_STEPS_CLOSE = (uint16_t)((current_degree - target_degree) * STEPS_PER_DEGREE);
        step_counter = 0;
        motor_direction = 2;
        current_degree = target_degree;
    }
}


void set_step(uint8_t step) {
    switch (step) {
        case 0: P1_bit.no0 = 1; P1_bit.no1 = 0; P1_bit.no2 = 0; P1_bit.no3 = 1; break;
        case 1: P1_bit.no0 = 1; P1_bit.no1 = 1; P1_bit.no2 = 0; P1_bit.no3 = 0; break;
        case 2: P1_bit.no0 = 0; P1_bit.no1 = 1; P1_bit.no2 = 1; P1_bit.no3 = 0; break;
        case 3: P1_bit.no0 = 0; P1_bit.no1 = 0; P1_bit.no2 = 1; P1_bit.no3 = 1; break;
    }
}
