/*
 * MRCC_program.c
 *
 *  Author: Khalid Metwally
 *   Layer: MCAL
 *	   SWC: RCC
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MRCC_private.h"
#include "MRCC_config.h"
/*==============================================================================================================*/
/*
 * Brief : This function initializes the system clock based on the selected configuration.
 *         It supports switching between HSI, HSE (mechanical or electrical), PLL with HSI, and PLL with HSE.
 *
 * Parameters :
 *      => None (configuration is determined through compile-time macros)
 *         - SYSTEM_CLOCK options      : [ HSI , HSE , PLL_HSI , PLL_HSE ]
 *         - HSE_SOURCE_TYPE options   : [ MECHANICAL , ELECTRICAL ] (used only if SYSTEM_CLOCK == HSE or PLL_HSE)
 *
 * Return : void
 */
void MRCC_voidInit(void)
{
	#if SYSTEM_CLOCK == HSI
		/* [1] Enable HSI */
		SET_BIT(RCC->CR , HSION);

		/* [2] Wait for Stability*/
		while(!(GET_BIT(RCC->CR , HSIRDY)))
		{
			/* nothing */
		}

		/* [3] Select HSI as the System Clock */
		RCC->CFGR &= (~3); 	// " to clear both the bits "
		RCC->CFGR |= (0); 	// " to set   both the bits to the desired value which is zero "

	#elif SYSTEM_CLOCK == HSE
		/* [1] Determining HSE Clock Source */
		#if HSE_SOURCE_TYPE == MECHANICAL
			CLR_BIT(RCC->CR , HSEBYP);
		#elif HSE_SOURCE_TYPE == ELECTRICAL
			SET_BIT(RCC->CR , HSEBYP);
		#endif

		/* [2] Enable HSE */
		SET_BIT(RCC->CR , HSEON);

		/* [3] Wait for Stability*/
		while(!(GET_BIT(RCC->CR , HSERDY)))
		{
			/* nothing */
		}

		/* [4] Select HSE as the System Clock */
		RCC->CFGR &= (~3);
		RCC->CFGR |= (1);

		/* [5] Disable HSI */
		CLR_BIT(RCC->CR , HSION);

	#elif SYSTEM_CLOCK == PLL_HSI
		/* [1] Enable HSI */
		SET_BIT(RCC->CR , HSION);

		/* [2] Wait for Stability*/
		while(!(GET_BIT(RCC->CR , HSIRDY)))
		{
			/* nothing */
		}

		/* [3] Select HSI as PLL input */
		CLR_BIT(RCC->PLLCFGR, PLLSRC);

		/* [4] Enable PLL */
		SET_BIT(RCC->CR , PLLON);

		/* [5] Wait for PLL Stability*/
		while(!(GET_BIT(RCC->CR , PLLRDY)))
		{
			/* nothing */
		}

		/* [6] Select PLL as the System Clock */
		RCC->CFGR &= (~3);
		RCC->CFGR |= (2);

	#elif SYSTEM_CLOCK == PLL_HSE
		/* [1] Determining HSE Clock Source */
		#if HSE_SOURCE_TYPE == MECHANICAL
			CLR_BIT(RCC->CR , HSEBYP);
		#elif HSE_SOURCE_TYPE == ELECTRICAL
			SET_BIT(RCC->CR , HSEBYP);
		#endif
		/* [2] Enable HSE */
		SET_BIT(RCC->CR , HSEON);

		/* [3] Wait for Stability*/
		while(!(GET_BIT(RCC->CR , HSERDY)))
		{
			/* nothing */
		}

		/* [4] Select HSE as PLL input */
		SET_BIT(RCC->PLLCFGR , PLLSRC);

		/* [5] Enable PLL */
		SET_BIT(RCC->CR , PLLON);

		/* [6] Wait for PLL Stability*/
		while(!(GET_BIT(RCC->CR , PLLRDY)))
		{
			/* nothing */
		}

		/* [7] Select PLL as the System Clock */
		RCC->CFGR &= (~3);
		RCC->CFGR |= (2);

		/* [8] Disable HSI */
		CLR_BIT(RCC->CR , HSION);
	#endif
}
/*==============================================================================================================*/
/*
 * Brief : This function enables the clock for a specific peripheral on the specified bus.
 * Parameters :
 *      => Copy_u8Bus        --> Bus name      [ AHB1 , AHB2 , APB1 , APB2 ]
 *      => Copy_u8Peripheral --> Peripheral ID [ AHB1_GPIOA_EN , AHB1_DMA1_EN , AHB1_CRC_EN , ... ]
 * Return : void
 */
void MRCC_voidPrephiralEnable(u8 Copy_u8Bus , u8 Copy_u8Peripheral)
{
	switch (Copy_u8Bus)
	{
		case AHB1: SET_BIT(RCC->AHB1ENR , Copy_u8Peripheral); break;
		case AHB2: SET_BIT(RCC->AHB2ENR , Copy_u8Peripheral); break;
		case APB1: SET_BIT(RCC->APB1ENR , Copy_u8Peripheral); break;
		case APB2: SET_BIT(RCC->APB2ENR , Copy_u8Peripheral); break;
	}
}
/*==============================================================================================================*/
/*
 * Brief : This function disables the clock for a specific peripheral on the specified bus.
 * Parameters :
 *      => Copy_u8Bus        --> Bus name      [ AHB1 , AHB2 , APB1 , APB2 ]
 *      => Copy_u8Peripheral --> Peripheral ID [ AHB1_GPIOA_EN , AHB1_DMA1_EN , AHB1_CRC_EN , ... ]
 * Return : void
 */
void MRCC_voidPrephiralDisable(u8 Copy_u8Bus , u8 Copy_u8Peripheral )
{
	switch (Copy_u8Bus)
	{
		case AHB1: CLR_BIT(RCC->AHB1ENR , Copy_u8Peripheral); break;
		case AHB2: CLR_BIT(RCC->AHB2ENR , Copy_u8Peripheral); break;
		case APB1: CLR_BIT(RCC->APB1ENR , Copy_u8Peripheral); break;
		case APB2: CLR_BIT(RCC->APB2ENR , Copy_u8Peripheral); break;
	}
}
/*==============================================================================================================*/
