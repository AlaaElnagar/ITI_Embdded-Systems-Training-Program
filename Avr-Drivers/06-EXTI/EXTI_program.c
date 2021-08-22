#include  "Lib/STD_TYPES.h"
#include  "Lib/BIT_MATH.h"
#include  "EXTI_config.h"
#include  "EXTI_private.h"
#include  "EXTI_interface.h"






/*EXTI Enable */
void EXTI0_vidInit (){

	/*sense control */
#if EXTI_SENSE_CONTROL     ==     EXTI_LOW_LEVEL_SC


#elif EXTI_SENSE_CONTROL   ==     EXTI_FALLING_EDGE_SC

	SET_BIT  (MCUCR , MCUCR_ISC01_PIN) ;
	CLEAR_BIT(MCUCR , MCUCR_ISC00_PIN) ;


#elif EXTI_SENSE_CONTROL   ==    EXTI_RISING_EDGE_SC


#elif EXTI_SENSE_CONTROL   ==    EXTI_ONCHANGE_SC


#else
	#error  "No sense controll selected kindly back to line Config File"


#endif
	/*Enable interrupt */

	SET_BIT(GICR ,GICR_INT0_PIN  )  ;


}


void EXTI1_vidInit(){


}
void EXTI2_vidInit (){


}

void (*EXTI0_func)(void ) = NULL ;

void EXTI_INT0_CallBack(void (*func)(void )) {

	EXTI0_func = &func ;

}



void __vector_1 (void ) __attribute__((signal)) ;

void __vector_1 (void ){

if (EXTI0_func != NULL){
	EXTI0_func() ;

}

}

