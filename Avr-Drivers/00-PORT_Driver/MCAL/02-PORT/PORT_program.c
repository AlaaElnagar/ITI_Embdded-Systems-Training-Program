

#include "../../Lib/STD_TYPES.h"


#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"


void PORT_VidInit () {
	
	/*SET DDRA INITIAL VALEUE*/
	DDRA = PORTA_DIR ; 
	DDRB = PORTB_DIR ; 
	DDRC = PORTC_DIR ;
	DDRD = PORTD_DIR ;

	/*SET PORT INITIAL VALEUE*/
	
	PORTA = PORTA_INITIAL_VALUE ;
	PORTB = PORTB_INITIAL_VALUE ;
	PORTC = PORTC_INITIAL_VALUE ;
	PORTD = PORTD_INITIAL_VALUE ;
	
}
