/*
 * MRCC_private.h
 *
 *  Author: Khalid Metwally
 *   Layer: MCAL
 *	   SWC: RCC
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#define RCC_BASE_ADDRESS (0x40023800)
/*==============================================================================================================*/

/* System Clocks */
#define HSI		0
#define HSE		1
#define PLL_HSI	2
#define PLL_HSE	0
/*==============================================================================================================*/

/* HSE Source Types */
#define MECHANICAL 0
#define ELECTRICAL 1
/*==============================================================================================================*/

/* System Clock Control Bits */
#define HSION 	0
#define HSIRDY 	1
#define HSEON 	16
#define HSERDY 	17
#define HSEBYP 	18
#define PLLON 	24
#define PLLRDY	25
#define PLLSRC	22 	//0 for PLL_HSI, 1 for PLL_HSE
/*==============================================================================================================*/

typedef struct {
    u32 CR;
    u32 PLLCFGR;
    u32 CFGR;
    u32 CIR;
    u32 AHB1RSTR;
    u32 AHB2RSTR;
    u32 RESERVED0[2];     /* 0x18, 0x1C */
    u32 APB1RSTR;
    u32 APB2RSTR;
    u32 RESERVED1[2];     /* 0x28, 0x2C */
    u32 AHB1ENR;
    u32 AHB2ENR;
    u32 RESERVED2[2];     /* 0x38, 0x3C */
    u32 APB1ENR;
    u32 APB2ENR;
    u32 RESERVED3[2];     /* 0x48, 0x4C */
    u32 AHB1LPENR;
    u32 AHB2LPENR;
    u32 RESERVED4[2];     /* 0x58, 0x5C */
    u32 APB1LPENR;
    u32 APB2LPENR;
    u32 RESERVED5[2];     /* 0x68, 0x6C */
    u32 BDCR;
    u32 CSR;
    u32 RESERVED6[2];     /* 0x78, 0x7C */
    u32 SSCGR;
    u32 PLLI2SCFGR;
    u32 RESERVED7; 		  /* 0x88 */
    u32 DCKCFGR;
}S_RCC;
/*==============================================================================================================*/

#define RCC ( (volatile S_RCC *) RCC_BASE_ADDRESS )
/*==============================================================================================================*/

#endif /* MRCC_PRIVATE_H_ */
