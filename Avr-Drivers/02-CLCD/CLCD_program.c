
#include "Lib/STD_TYPES.h"
#include "DIO_Interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

#include <avr/delay.h>


void CLCD_VidSendCommand (u8 Copy_u8Command ) {

	/*Prepare Rs to be low to receive command */
	DIO_VidSetPinValue(CLCD_CTRL_PORT,low ,CLCD_RS_PIN)  ;

	/*Set rw to 0 for write */
	DIO_VidSetPinValue(CLCD_CTRL_PORT,low ,CLCD_RW_PIN)  ;

	/*Send command to data pins  */

	DIO_VidSetPortValue( CLCD_DATA_PORT , Copy_u8Command) ;

	/*Send enable pulse */

    DIO_VidSetPinValue(CLCD_CTRL_PORT, high ,CLCD_E_PIN ) ;
    _delay_ms(2) ;
    DIO_VidSetPinValue(CLCD_CTRL_PORT, low ,CLCD_E_PIN ) ;

}

void CLCD_VidSendData (u8 Copy_u8Data ) {
	/*Prepare Rs to be low to receive Data */
	DIO_VidSetPinValue(CLCD_CTRL_PORT,high ,CLCD_RS_PIN)  ;

	/*Set rw to 0 for write */
	DIO_VidSetPinValue(CLCD_CTRL_PORT,low ,CLCD_RW_PIN)  ;

	/*Send Data to data pins  */

	DIO_VidSetPortValue( CLCD_DATA_PORT , Copy_u8Data) ;

	/*Send enable pulse */

    DIO_VidSetPinValue(CLCD_CTRL_PORT, high ,CLCD_E_PIN ) ;
    _delay_ms(2) ;
    DIO_VidSetPinValue(CLCD_CTRL_PORT, low ,CLCD_E_PIN ) ;


}

void CLCD_VidInit(void) {

/*wait for more than 40 ms*/


	_delay_ms(40) ;
	/*Function set command : 2 Lines  , 5*8 Font size */

	CLCD_VidSendCommand(0b00111000) ;

	/*Display on off controll : Display enable ,Disble cursor , no blinlk cursor*/

	CLCD_VidSendCommand(0b00001100) ;

	/*Display Clear */
	CLCD_VidSendCommand(0b00000001) ;




}

void CLCD_VidSendString(const char* Copy_pcString ) {


	for (int i = 0 ; Copy_pcString[i]!='\0' ; i++){

		CLCD_VidSendData(Copy_pcString[i]) ;
	}


}

void CLCD_VidClear(void){

	CLCD_VidSendCommand(0b00000001) ;

}


void CLCD_VidGotoXY(u8 Copy_u8XPos , u8 Copy_u8YPos){

u8 Local_u8Address = 0 ;

if (Copy_u8XPos == 0 ){
	Local_u8Address  = Copy_u8YPos ;
}

else if (Copy_u8XPos == 1 ){

	Local_u8Address = 0x40+Copy_u8YPos ;

}

/*send this adderess to the ddram  128 + Local_u8Address   because of the 1 in bit 7 of
 * data sheet */
CLCD_VidSendCommand(0b010000000+Local_u8Address) ;

}


/*Write custom character to Lcd */



void CLCD_VidWriteSpecialCharacter(u8* Copy_u8Pattern , u8 Copy_u8PatternNumber , u8 XPose , u8 YPose) {


	u8 Local_u8CGRAMAddress  = 0 ;


	/*Calculate the CGRAM Address */
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8 ;
	/*Send CGRAAM Address command to LCD  WITH SETTING BIT  6 -  --- -  >64 */
	CLCD_VidSendCommand(Local_u8CGRAMAddress+64 ) ;
	/*Write pattern into CGRAM*/
	for (u8 i = 0 ; i < 8 ; i++ ){

		CLCD_VidSendData(Copy_u8Pattern[i] )   ;

	}

	/*bACK TO DDRAM */

	CLCD_VidGotoXY (XPose , YPose )  ;

  /*Disply the pattern */
	CLCD_VidSendData(Copy_u8PatternNumber )   ;

}










