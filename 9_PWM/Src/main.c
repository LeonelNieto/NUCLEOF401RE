#include <stdint.h>
#include <stdio.h>
#include "globaldefine.h"
#include "pwm.h"
#include "timer.h"

void main( void )
{
    SetSystemClockTo16MHz( );
    ConfigPinPA6AsAlternFunctions( );
    InitPwm( 2000 );
    TIM3 -> CCR1 = 400; 

    while (1)
    {
    
    }
}
