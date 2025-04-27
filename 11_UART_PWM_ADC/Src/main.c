#include <stdint.h>
#include <stdio.h>
#include "globaldefine.h"
#include "clock.h"
#include "uart.h"

int main( void )
{
    SystemClock_Config( );
    SR_Init_UART( USART1, 115200 );
    
    while (1)
    {
        SR_SendUARTSensorFrame( USART1, 0x4C, 0x45, 0x4F );
    }

    return 0;
}
