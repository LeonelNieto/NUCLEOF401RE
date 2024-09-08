#include <stdint.h>
#include <stdio.h>
#include "globaldefine.h"
#include "adc.h"
#include "interrupt.h"
#include "timer.h"
#include "pwm.h"


void main( void )
{
    SetSystemClockTo16MHz( );
    ADC1_IN1_IN16_Init( );
    ADC1_StartConversion( );
    ConfigPinPA6AsAlternFunctions( );
    InitPwm( 2000 );
    EnableTIM2Interrupt( 5000 );

    while (1)
    {

    }

}
