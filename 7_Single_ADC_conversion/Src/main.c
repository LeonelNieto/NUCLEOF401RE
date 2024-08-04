#include <stdint.h>
#include <stdio.h>
#include "globaldefine.h"
#include "adc.h"
#include "uart.h"


void main( void )
{
    uint32_t SensorValue;
    ADC1_IN1_IN16_Init( );
    SR_Init_UART2( );
    
    while (1)
    {
        SensorValue = ADC_Read( );
        printf("Sensor value: %d \n\r", SensorValue);
    }
}
