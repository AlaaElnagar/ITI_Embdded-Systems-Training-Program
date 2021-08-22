/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: AlaaElnagar
 */
#include "Lib/STD_TYPES.h"
#include "DIO_Interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "util/delay.h"


void task1(){

	DIO_VidSetPinValue(Port_A , high , Pin_2 ) ;

}


void main () {

	EXTI_INT0_CallBack(task1) ;

	/*Blink */
	DIO_VidSetPinDirection(Port_A , Pin_2 , output) ;


	/*Set interrupt pin as input */
	DIO_VidSetPinDirection(Port_D , Pin_2 , input) ;
	DIO_VidSetPinValue(Port_D , high , Pin_2 ) ;

	GIE_VidEnable() ;
	EXTI0_vidInit() ;

	while (1) {

		/*Infity loop*/

	}

}


