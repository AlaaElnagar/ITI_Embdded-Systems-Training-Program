#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "GIE_private.h"
#include "GIE_interface.h"



/*GIE Enable */

void GIE_VidEnable () {

	SET_BIT(SREG , SREG_I_BIT ) ;

}


/*GIE Disable */

void GIE_VidDisable (void) {


	CLEAR_BIT(SREG , SREG_I_BIT ) ;

}

