#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


void CLCD_VidSendCommand (u8 Copy_u8Command) ;

void CLCD_VidSendData (u8 Copy_u8Data) ; 

void CLCD_VidInit (void) ;

void CLCD_VidGotoXY ( u8 Copy_u8XPos , u8 Copy_u8YPos ) ;


void CLCD_VidWriteSpecialCharacter (u8 *Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPOS ,u8 Copy_u8YPOS ) ;









#endif 
