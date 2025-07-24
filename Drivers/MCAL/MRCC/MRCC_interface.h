/*
 * MRCC_interface.h
 *
 *  Author: Khalid Metwally
 *   Layer: MCAL
 *	   SWC: RCC
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_
/*==============================================================================================================*/

/* Bus Defines */
#define  AHB1  0
#define  AHB2  1
#define  APB1  2
#define  APB2  3
/*==============================================================================================================*/

/* AHB1 peripheral clock Enable/Disable Peripherals */
#define  AHB1_GPIOA_EN  0
#define  AHB1_GPIOB_EN  1
#define  AHB1_GPIOC_EN  2
#define  AHB1_GPIOD_EN  3
#define  AHB1_GPIOE_EN  4
#define  AHB1_GPIOH_EN  7
#define  AHB1_CRC_EN    12
#define  AHB1_DMA1_EN   21
#define  AHB1_DMA2_EN   22
/*==============================================================================================================*/

/* AHB2 peripheral clock Enable/Disable Peripherals */
#define  AHB2_OTGFS_EN  7
/*==============================================================================================================*/

/* APB1 peripheral clock Enable/Disable Peripherals */
#define  APB1_TIM2_EN	0
#define  APB1_TIM3_EN	1
#define  APB1_TIM4_EN	2
#define  APB1_TIM5_EN	3
#define  APB1_WWDG_EN	11
#define  APB1_SPI2_EN	14
#define  APB1_SPI3_EN	15
#define  APB1_USART2_EN	17
#define  APB1_I2C1_EN	21
#define  APB1_I2C2_EN	22
#define  APB1_I2C3_EN	23
#define  APB1_PWR_EN	28
/*==============================================================================================================*/

/* APB2 peripheral clock Enable/Disable Peripherals */
#define  APB2_TIM1_EN	0
#define  APB2_USART1_EN	4
#define  APB2_USART6_EN	5
#define  APB2_ADC1_EN	8
#define  APB2_SDIO_EN	11
#define  APB2_SPI1_EN	12
#define  APB2_SPI4_EN	13
#define  APB2_SYSCFG_EN	14
#define  APB2_TIM9_EN	16
#define  APB2_TIM10_EN	17
#define  APB2_TIM11_EN	18
/*==============================================================================================================*/

/* API's */
void MRCC_voidInit				(void);
void MRCC_voidPeripheralEnable	(u8 Copy_u8Bus , u8 Copy_u8Peripheral);
void MRCC_voidPeripheralDisable	(u8 Copy_u8Bus , u8 Copy_u8Peripheral);
/*==============================================================================================================*/

#endif /* MRCC_INTERFACE_H_ */
