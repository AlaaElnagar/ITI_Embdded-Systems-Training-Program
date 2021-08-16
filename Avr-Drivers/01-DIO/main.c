/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: AlaaElnagar
 */
#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "DIO_Interface.h"
#include <avr/delay.h>

void main (void ){

	DIO_VidSetPinDirection(Port_A , Pin_0 , output) ;
	DIO_VidSetPinValue (Port_A , high ,  Pin_0  ) ;
 	while (1){
 		DIO_VidSetPinValue (Port_A , low ,  Pin_0  ) ;
 		_delay_ms (1000) ;
 		DIO_VidSetPinValue (Port_A , high ,  Pin_0  ) ;
 		_delay_ms (1000) ;



	}


}
