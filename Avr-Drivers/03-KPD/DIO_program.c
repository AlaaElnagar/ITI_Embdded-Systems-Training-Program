
#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_Interface.h"

void DIO_VidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Value , u8 Copy_u8PinNumber)
{
	if (Copy_u8Value == high) {
		switch (Copy_u8Port) {

					case (Port_A) : SET_BIT(PORTA,Copy_u8PinNumber) ;  break ;
					case (Port_B) : SET_BIT(PORTB,Copy_u8PinNumber) ;  break ;
					case (Port_C) : SET_BIT(PORTC,Copy_u8PinNumber) ;  break ;
					case (Port_D) : SET_BIT(PORTD,Copy_u8PinNumber) ;  break ;

					}

	}

	else if (Copy_u8Value == low) {
		switch (Copy_u8Port) {

					case (Port_A) : CLEAR_BIT(PORTA,Copy_u8PinNumber) ;  break ;
					case (Port_B) : CLEAR_BIT(PORTB,Copy_u8PinNumber) ;  break ;
					case (Port_C) : CLEAR_BIT(PORTC,Copy_u8PinNumber) ;  break ;
					case (Port_D) : CLEAR_BIT(PORTD,Copy_u8PinNumber) ;  break ;

					}

	}

	}
	


void DIO_VidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8PinNumber , u8 Copy_u8PinDirection) {
	/*check for input direction  0 for input */
	if (Copy_u8PinDirection == input){
				/*Set pin as input  */
			switch (Copy_u8Port) {

			case (Port_A) : CLEAR_BIT(DDRA,Copy_u8PinNumber) ;  break ;
			case (Port_B) : CLEAR_BIT(DDRB,Copy_u8PinNumber) ;  break ;
			case (Port_C) : CLEAR_BIT(DDRC,Copy_u8PinNumber) ;  break ;
			case (Port_D) : CLEAR_BIT(DDRD,Copy_u8PinNumber) ;  break ;

			}

	}
	/*check for input direction  1 for output */

	else if (Copy_u8PinDirection == output ){

		switch (Copy_u8Port) {
				/*Set pin as output */
		case (Port_A) : SET_BIT(DDRA,Copy_u8PinNumber) ;  break ;
		case (Port_B) : SET_BIT(DDRB,Copy_u8PinNumber) ;  break ;
		case (Port_C) : SET_BIT(DDRC,Copy_u8PinNumber) ;  break ;
		case (Port_D) : SET_BIT(DDRD,Copy_u8PinNumber) ;  break ;

		}

	}

}


void DIO_VidGetPinValue (u8 Copy_u8Port , u8 Copy_u8PinNumber , u8 *Copy_Pu8PinValue){
	
	switch (Copy_u8Port) {
			/*Set pin as output */
	case (Port_A) : *Copy_Pu8PinValue =  GET_BIT(PINA,Copy_u8PinNumber) ;  break ;
	case (Port_B) : *Copy_Pu8PinValue =  GET_BIT(PINB,Copy_u8PinNumber) ;  break ;
	case (Port_C) : *Copy_Pu8PinValue =  GET_BIT(PINC,Copy_u8PinNumber) ;  break ;
	case (Port_D) : *Copy_Pu8PinValue =  GET_BIT(PIND,Copy_u8PinNumber) ;  break ;

	}
}

/*set_Port*/

void DIO_VidSetPortValue (u8 Copy_u8Port , u8 Copy_u8Value) {
	
	switch (Copy_u8Port) {
				/*Set pin as output */
		case (Port_A) : PORTA = Copy_u8Value ;  break ;
		case (Port_B) : PORTB = Copy_u8Value ;  break ;
		case (Port_C) : PORTC = Copy_u8Value ;  break ;
		case (Port_D) : PORTD = Copy_u8Value ;  break ;

		}

}

void DIO_VidSetPortDirection (u8 Copy_u8Port , u8 Copy_u8PortDirection) {
	
	switch (Copy_u8Port) {
			/*Set pin as output */
	case (Port_A) : DDRA = Copy_u8PortDirection ;  break ;
	case (Port_B) : DDRB = Copy_u8PortDirection ;  break ;
	case (Port_C) : DDRC = Copy_u8PortDirection ;  break ;
	case (Port_D) : DDRD = Copy_u8PortDirection ;  break ;

	}
}

void DIO_VidGetPortValue (u8 Copy_u8Port , u8 *Copy_Pu8PortVlue) {
	
	switch (Copy_u8Port) {
			/*Set pin as output */
	case (Port_A) : *Copy_Pu8PortVlue =  PINA ;  break ;
	case (Port_B) : *Copy_Pu8PortVlue =  PINB ;  break ;
	case (Port_C) : *Copy_Pu8PortVlue =  PINC ;  break ;
	case (Port_D) : *Copy_Pu8PortVlue =  PIND ;  break ;

	}


}
