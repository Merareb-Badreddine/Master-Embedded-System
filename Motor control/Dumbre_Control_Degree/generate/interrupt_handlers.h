/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F104GF.DVF                                                     */
/*    V2.30 (2018/04/03)                                                */
/*    Copyright(C) 2018 Renesas                                         */
/* Tool Version: 4.0.0                                                  */
/* Date Generated: 2020/01/17                                           */
/************************************************************************/
#ifndef INTERRUPT_HANDLERS_H
#define INTERRUPT_HANDLERS_H

/*
 * INT_WDTI (0x4)
 */
void INT_WDTI(void) __attribute__ ((interrupt));

/*
 * INT_LVI (0x6)
 */
void INT_LVI(void) __attribute__ ((interrupt));

/*
 * INT_P0 (0x8)
 */
void INT_P0(void) __attribute__ ((interrupt));

/*
 * INT_P1 (0xA)
 */
void INT_P1(void) __attribute__ ((interrupt));

/*
 * INT_P2 (0xC)
 */
void INT_P2(void) __attribute__ ((interrupt));

/*
 * INT_P3 (0xE)
 */
void INT_P3(void) __attribute__ ((interrupt));

/*
 * INT_P4 (0x10)
 */
void INT_P4(void) __attribute__ ((interrupt));

/*
 * INT_P5 (0x12)
 */
void INT_P5(void) __attribute__ ((interrupt));

/*
 * INT_CSI20/INT_IIC20/INT_ST2 (0x14)
 */
void INT_ST2(void) __attribute__ ((interrupt));
//void INT_CSI20(void) __attribute__ ((interrupt));
//void INT_IIC20(void) __attribute__ ((interrupt));

/*
 * INT_CSI21/INT_IIC21/INT_SR2 (0x16)
 */
void INT_SR2(void) __attribute__ ((interrupt));
//void INT_CSI21(void) __attribute__ ((interrupt));
//void INT_IIC21(void) __attribute__ ((interrupt));

/*
 * INT_SRE2 (0x18)
 */
void INT_SRE2(void) __attribute__ ((interrupt));

/*
 * INT_CSI00/INT_IIC00/INT_ST0 (0x1E)
 */
void INT_ST0(void) __attribute__ ((interrupt));
//void INT_CSI00(void) __attribute__ ((interrupt));
//void INT_IIC00(void) __attribute__ ((interrupt));

/*
 * INT_CSI01/INT_IIC01/INT_SR0 (0x20)
 */
void INT_SR0(void) __attribute__ ((interrupt));
//void INT_CSI01(void) __attribute__ ((interrupt));
//void INT_IIC01(void) __attribute__ ((interrupt));

/*
 * INT_SRE0/INT_TM01H (0x22)
 */
void INT_TM01H(void) __attribute__ ((interrupt));
//void INT_SRE0(void) __attribute__ ((interrupt));

/*
 * INT_ST1 (0x24)
 */
void INT_ST1(void) __attribute__ ((interrupt));

/*
 * INT_CSI11/INT_IIC11/INT_SR1 (0x26)
 */
void INT_SR1(void) __attribute__ ((interrupt));
//void INT_CSI11(void) __attribute__ ((interrupt));
//void INT_IIC11(void) __attribute__ ((interrupt));

/*
 * INT_SRE1/INT_TM03H (0x28)
 */
void INT_TM03H(void) __attribute__ ((interrupt));
//void INT_SRE1(void) __attribute__ ((interrupt));

/*
 * INT_IICA0 (0x2A)
 */
void INT_IICA0(void) __attribute__ ((interrupt));

/*
 * INT_TM00 (0x2C)
 */
void INT_TM00(void) __attribute__ ((interrupt));

/*
 * INT_TM01 (0x2E)
 */
void INT_TM01(void) __attribute__ ((interrupt));

/*
 * INT_TM02 (0x30)
 */
void INT_TM02(void) __attribute__ ((interrupt));

/*
 * INT_TM03 (0x32)
 */
void INT_TM03(void) __attribute__ ((interrupt));

/*
 * INT_AD (0x34)
 */
void INT_AD(void) __attribute__ ((interrupt));

/*
 * INT_RTC (0x36)
 */
void INT_RTC(void) __attribute__ ((interrupt));

/*
 * INT_IT (0x38)
 */
void INT_IT(void) __attribute__ ((interrupt));

/*
 * INT_KR (0x3A)
 */
void INT_KR(void) __attribute__ ((interrupt));

/*
 * INT_TRJ0 (0x40)
 */
void INT_TRJ0(void) __attribute__ ((interrupt));

/*
 * INT_P6 (0x4A)
 */
void INT_P6(void) __attribute__ ((interrupt));

/*
 * INT_P8 (0x4E)
 */
void INT_P8(void) __attribute__ ((interrupt));

/*
 * INT_P9 (0x50)
 */
void INT_P9(void) __attribute__ ((interrupt));

/*
 * INT_CMP0 (0x52)
 */
void INT_CMP0(void) __attribute__ ((interrupt));

/*
 * INT_CMP1 (0x54)
 */
void INT_CMP1(void) __attribute__ ((interrupt));

/*
 * INT_TRD0 (0x56)
 */
void INT_TRD0(void) __attribute__ ((interrupt));

/*
 * INT_TRD1 (0x58)
 */
void INT_TRD1(void) __attribute__ ((interrupt));

/*
 * INT_TRG (0x5A)
 */
void INT_TRG(void) __attribute__ ((interrupt));

/*
 * INT_FL (0x62)
 */
void INT_FL(void) __attribute__ ((interrupt));

/*
 * INT_BRK_I (0x7E)
 */
void INT_BRK_I(void) __attribute__ ((interrupt));

//Hardware Vectors
//PowerON_Reset (0x0)
void PowerON_Reset(void) __attribute__ ((interrupt));
#endif
