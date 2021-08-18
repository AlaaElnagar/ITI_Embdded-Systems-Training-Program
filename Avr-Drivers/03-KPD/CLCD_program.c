#include "Lib/STD_TYPES.h"
#include "DIO_Interface.h"
#include "CLCD_config.h"
#include "avr/delay.h"


void CLCD_VidSendCommand (u8 Copy_u8Command) {

	/*Set RS  pin as low*/

	 DIO_VidSetPinValue(CLCD_CTRL_PORT ,low , CLCD_RS_PIN)  ;
	/*Set RW pin as  low to write */

	 DIO_VidSetPinValue(CLCD_CTRL_PORT ,low , CLCD_RW_PIN)  ;

	/*send command to data pins  D0 to D7*/

	 DIO_VidSetPortValue(CLCD_DATA_PORT , Copy_u8Command) ;
	/*Set Enable pin */

	 DIO_VidSetPinValue(CLCD_CTRL_PORT ,high , CLCD_E_PIN)  ;

	/*delay*/

	 _delay_ms(3) ;

	/*ClR Enable pin */

	 DIO_VidSetPinValue(CLCD_CTRL_PORT ,low , CLCD_E_PIN)  ;

}

void CLCD_VidSendData (u8 Copy_u8Data) {

	/*Set RS  pin as high*/

	 DIO_VidSetPinValue(CLCD_CTRL_PORT ,high , CLCD_RS_PIN)  ;
	/*Set RW pin as  low to write */

	 DIO_VidSetPinValue(CLCD_CTRL_PORT ,low , CLCD_RW_PIN)  ;

	/*send data to data pins  D0 to D7*/

	 DIO_VidSetPortValue(CLCD_DATA_PORT , Copy_u8Data) ;
	/*Set Enable pin */

	 DIO_VidSetPinValue(CLCD_CTRL_PORT ,high , CLCD_E_PIN)  ;

	/*delay*/

	 _delay_ms(3) ;

	/*ClR Enable pin */

	 DIO_VidSetPinValue(CLCD_CTRL_PORT ,low , CLCD_E_PIN)  ;


}

void CLCD_VidInit (void) {

_delay_ms(40) ;

/*Function set*/
CLCD_VidSendCommand (0b00111111);


/*Dispaly on off*/
CLCD_VidSendCommand (0b00001100);

/*Display clear */
CLCD_VidSendCommand(1);

}


/*going to any place in LCD */

void CLCD_VidGotoXY ( u8 Copy_u8XPos , u8 Copy_u8YPos ){


	u8 Local_u8Address = 0 ;

	if (Copy_u8XPos == 0 ) {

		Local_u8Address = Copy_u8YPos ;

	}
	else if (Copy_u8XPos == 1){

		Local_u8Address = 0x40 + Copy_u8YPos ;

	}
//0b10000000  ---> 128
	CLCD_VidSendCommand(128+Local_u8Address);



}




void CLCD_VidWriteSpecialCharacter (u8 *Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPOS ,u8 Copy_u8YPOS )
{

u8 Local_u8Address = 0 ;


Local_u8Address = 8 *Copy_u8PatternNumber ;

CLCD_VidSendCommand(64 + Local_u8Address )   ;

for ( u8 i = 0 ; i < 8 ; i++) {

	CLCD_VidSendData(Copy_pu8Pattern[i]) ;
}

CLCD_VidGotoXY(Copy_u8XPOS ,Copy_u8YPOS  )  ;

CLCD_VidSendData(Copy_u8PatternNumber) ;

}
















