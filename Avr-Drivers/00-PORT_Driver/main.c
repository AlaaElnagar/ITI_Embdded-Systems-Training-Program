/*
 * main.c

 *
 *  Created on: Aug 18, 2021
 *      Author: AlaaElnagar
 */

#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "MCAL/02-PORT/PORT_interface.h"
#include "MCAL/01_DIO/DIO_Interface.h"
#include "avr/delay.h"
#include "HAL/01-CLCD/CLCD_interface.h"




void main (void){



	PORT_VidInit () ;
	CLCD_VidInit () ;
	CLCD_VidGotoXY ( 1 , 7) ;
	CLCD_VidSendData ('I') ;
	CLCD_VidSendData ('T') ;
	CLCD_VidSendData ('I') ;

    _delay_ms(500) ;



	while (1) {

		CLCD_VidWriteSpecialCharacter( customChar , 1 , 1 , 13 ) ;

	    _delay_ms(1000) ;
		CLCD_VidGotoXY ( 1 , 13) ;

	    CLCD_VidSendData(' ') ;
	    _delay_ms(100) ;

		CLCD_VidWriteSpecialCharacter( customChar1 , 1 , 1 , 14 ) ;

	    _delay_ms(1000) ;
		CLCD_VidGotoXY ( 1 , 14) ;

	    CLCD_VidSendData(' ') ;
	    _delay_ms(100) ;

	}





}

