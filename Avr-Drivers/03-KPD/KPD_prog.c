#include "Lib/STD_TYPES.h"
#include "DIO_Interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"


u8 KPD_u8GetPressdKey(void){

	u8 Local_KeyPressd = NOT_PRESSED ;
	u8 Local_u8KPDArr [4][4] =  KPD_U8ARR ;
	u8 Local_u8ColumnIdx =   0 ;
	u8 Local_u8ROWIdx    =   0 ;
/*Switch pressed or not  -----hold the value of row*/
	u8 Local_u8State     =   1  ;

u8 Local_u8ColumnArr [] = {KPD_u8COLUMN0_PIN ,KPD_u8COLUMN1_PIN ,KPD_u8COLUMN2_PIN,KPD_u8COLUMN3_PIN} ;
u8 Local_u8RowArr[]     = {KPD_u8ROW0_PIN , KPD_u8ROW1_PIN ,KPD_u8ROW2_PIN , KPD_u8ROW3_PIN } ;
/*loop through the columns */
for (Local_u8ColumnIdx = 0 ; Local_u8ColumnIdx < 4 ; Local_u8ColumnIdx++ ){
/*set each column with 0 one time per loop*/
	DIO_VidSetPinValue(KPD_u8PORT , low ,Local_u8ColumnArr[Local_u8ColumnIdx]) ;
/*check each row according to this column state */
	for (Local_u8ROWIdx = 0 ; Local_u8ROWIdx <4 ; Local_u8ROWIdx ++){
/*check if row get 0  vale */
		DIO_VidGetPinValue(KPD_u8PORT ,Local_u8RowArr[Local_u8ROWIdx] , &Local_u8State ) ;
/*if key pressed */
		if (Local_u8State == low ){
/*get number which represent  coulmn and row */
			Local_KeyPressd = Local_u8KPDArr[Local_u8ColumnIdx][Local_u8ROWIdx] ;
			/*check if someone press without realise */
			while (Local_u8State == low ){
				DIO_VidGetPinValue(KPD_u8PORT ,Local_u8RowArr[Local_u8ROWIdx] , &Local_u8State ) ;
			}
			DIO_VidSetPinValue(KPD_u8PORT , high ,Local_u8ColumnArr[Local_u8ColumnIdx]) ;

			return Local_KeyPressd ;
		}


	}


	DIO_VidSetPinValue(KPD_u8PORT , high ,Local_u8ColumnArr[Local_u8ColumnIdx]) ;



}

return Local_KeyPressd ;





}
