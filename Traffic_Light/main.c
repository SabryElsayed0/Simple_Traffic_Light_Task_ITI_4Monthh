/****************************************************************/
/****   Author :  Sabry                   ***********************/
/****   SWC:      Traffic_Light_Assighnement_2 ******************/
/****   Date :    3/8/2023        *******************************/
/****   Version : 1.00                ***************************/
/***************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/SSD/SSD_interface.h"
#define F_CPU    8000000UL
#include <util/delay.h>
/****************Traffic Light colors names*******************/
#define RED        0
#define YELLOW     1
#define GREEN      2
/************************************************************/

/**************************decleration array of leds***************/
 LED_t Traffic_Leds[3] ={{DIO_PORTA , DIO_PIN7 , LED_ACTIVE_HIGH},
		                 {DIO_PORTA , DIO_PIN6 , LED_ACTIVE_HIGH},
		                 {DIO_PORTA , DIO_PIN5 , LED_ACTIVE_HIGH}};
 /*******************************************************************/
 SSD_t seg_1 = {DIO_PORTB , SSD_COMMON_ANODE};
 SSD_t seg_2 = {DIO_PORTC , SSD_COMMON_ANODE};
/*******************************************************************/
 u8 rem = 0;
 u8 num = 0;


int main(void)
{
//initialize traffic leds
for(int i = 0 ; i < 3 ; i++)
{
	LED_voidInit(&Traffic_Leds[i]);

}

//initialize sevevn segment
SSD_voidInit(&seg_1);
SSD_voidInit(&seg_2);
while(1)
{
/*********for red color 10 seconds on********************/
	LED_voidOn(&Traffic_Leds[RED]);
	for(s8 i = 30 ; i >=0  ; i--)
	{
		rem = i % 10;
		num = i / 10;
		SSD_voidEnable(&seg_1 , rem);
		SSD_voidEnable(&seg_2 , num);
		_delay_ms(500);

	}
	LED_voidOff(&Traffic_Leds[RED]);
/*********for Yellow color 10 seconds on********************/
	LED_voidOn(&Traffic_Leds[YELLOW]);
	for(s8 i = 10 ; i >= 0 ; i--)
	{
		rem = i % 10;
		num = i / 10;
		SSD_voidEnable(&seg_1 , rem);
		SSD_voidEnable(&seg_2 , num);
		_delay_ms(500);

	}
	LED_voidOff(&Traffic_Leds[YELLOW]);
/*********for Green color 10 seconds on********************/
	LED_voidOn(&Traffic_Leds[GREEN]);
	for(s8 i = 30 ; i >= 0 ; i--)
	{
		rem = i % 10;
		num = i / 10;
		SSD_voidEnable(&seg_1 , rem);
		SSD_voidEnable(&seg_2 , num);
		_delay_ms(500);

	}
	LED_voidOff(&Traffic_Leds[GREEN]);
}


  return 0;
}


