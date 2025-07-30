/*
 * HSSD_interface.h
 *
 *  Author: Khalid Metwally
 *   Layer: HAL
 *	   SWC: HSSD
 */

#ifndef HSSD_INTERFACE_H_
#define HSSD_INTERFACE_H_
/*==============================================================================================================*/

/* SSD TYPE */
#define SSD_COMMON_CATHODE  0
#define SSD_COMMON_ANODE    1
/*==============================================================================================================*/

/* PORTs */
#define  SSD_PORTA  0
#define  SSD_PORTB  1
#define  SSD_PORTC  2
/*==============================================================================================================*/

/* Port Sections */
#define SSD_LSPART	0 /* Least Significant Part */
#define SSD_MSPART	1 /* Most Significant Part */
/*==============================================================================================================*/

/* PINs */
#define SSD_PIN0   0
#define SSD_PIN1   1
#define SSD_PIN2   2
#define SSD_PIN3   3
#define SSD_PIN4   4
#define SSD_PIN5   5
#define SSD_PIN6   6
#define SSD_PIN7   7
#define SSD_PIN8   8
#define SSD_PIN9   9
#define SSD_PIN10  10
#define SSD_PIN11  11
#define SSD_PIN12  12
#define SSD_PIN13  13
#define SSD_PIN14  14
#define SSD_PIN15  15
/*==============================================================================================================*/
typedef struct{

	u8 Type       ;                 // SSD_COMMON_CATHODE or SSD_COMMON_ANODE
	u8 DataPort   ;                 // SSD_PORTA or SSD_PORTB or SSD_PORTC
	u8 DataSection;					// SSD_LSPART or SSD_MSPART
	u8 OutputType ;					// PUSH_PULL or OPEN_DRAIN
	u8 Speed	  ;					// LOW_SPEED or MEDIUM_SPEED or HIGH_SPEED or VERY_HIGH_SPEED
	u8 EnablePort ;                 // SSD_PORTA or SSD_PORTB or SSD_PORTC
	u8 EnablePin  ;                 // SSD_PIN0 , SSD_PIN1 , ... SSD_PIN15

}SSD_Type;
/*==============================================================================================================*/
void SSD_voidInitialDataPort  ( SSD_Type Copy_SSDConfig );
void SSD_voidEnable           ( SSD_Type Copy_SSDConfig );
void SSD_voidDisable          ( SSD_Type Copy_SSDConfig );
void SSD_voidSendNumber       ( SSD_Type Copy_SSDConfig , u8 Copy_u8Number );
/*==============================================================================================================*/
#endif /* HSSD_INTERFACE_H_ */
