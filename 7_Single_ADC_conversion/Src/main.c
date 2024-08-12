#include <stdint.h>
#include <stdio.h>
#include "globaldefine.h"
#include "adc.h"
#include "uart.h"


void main( void )
{
    uint32_t SensorValue;
    ADC1_IN1_IN16_Init( );
    
    while (1)
    {
        SensorValue = ADC_Read( );
    }
}
