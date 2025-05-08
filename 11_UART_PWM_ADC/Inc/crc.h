#ifndef CRC_H
#define CRC_H

#include <stdint.h>

#define DATA_SIZE_CRC 4

extern uint8_t SR_CalculateCRC( uint8_t *Pdata );

#endif // CRC