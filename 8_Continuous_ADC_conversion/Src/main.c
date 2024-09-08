#include <stdint.h>
#include <stdio.h>
#include "globaldefine.h"
#include "adc.h"
#include "uart.h"

uint32_t SensorValue;

void main( void )
{
    ADC1_IN1_IN16_Init( );
    ADC1_StartConversion( );
    
    while (1)
    {
        SensorValue = ADC_Read( );
    }
}
