#include "crc.h"

uint8_t SR_CalculateCRC( uint8_t *Pdata )
{
    uint8_t crc = 0;
    for( uint8_t i = 1; i <= DATA_SIZE_CRC; i++ )
    {
        crc ^= Pdata[ i ]; 
    }
    return crc;
}