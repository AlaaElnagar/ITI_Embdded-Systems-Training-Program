/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: AlaaElnagar
 */
#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "DIO_Interface.h"
#include "CLCD_interface.h"
#include <avr/delay.h>


void main (void ){
	DIO_VidSetPortDirection(Port_A ,Port_High ) ;

	DIO_VidSetPinDirection (Port_C , Pin_0 , output) ;
	DIO_VidSetPinDirection (Port_C , Pin_1 , output) ;
	DIO_VidSetPinDirection (Port_C , Pin_2 , output) ;

	CLCD_VidInit() ;
	//CLCD_VidGotoXY(1 , 3) ;
	CLCD_VidSendString("A");
	char customChar[] = {
			  0b0000111,
			  0b0000101,
			  0b0010001,
			  0b0010101,
			  0b0010001,
			  0b0000101,
			  0b0000001,
			  0b0011111
	};
	CLCD_VidWriteSpecialCharacter(customChar , 1 , 1 , 2)  ;
	CLCD_VidSendString("b");

	while (1){




	}


}
