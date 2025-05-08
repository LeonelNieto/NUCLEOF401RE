#ifndef UART_H
#define UART_H

#include <stdio.h>
#include "nucleof401re.h"
#include "globaldefine.h"
#include "crc.h"

#define FRAME_SIZE          7
#define UART_BUFFER_SIZE  255
#define BYTE_INIT        0xE2
#define BYTE_END         0xE3
#define FRAME_LENGTH     0x06
#define UART_READ        0xA0
#define UART_WRITE       0xA1

typedef enum
{
    CLOCK_16MHZ = 16000000U,
    CLOCK_42MHZ = 42000000U,
    CLOCK_84MHZ = 84000000U
} ClockFreq_t;

extern void SR_Init_UART( USART_t *USARTx, uint32_t u32baudrate );
extern void SR_UART_WriteByte( USART_t *USARTx, uint8_t byte );
extern uint8_t SR_UART_ReadByte( USART_t *USARTx );
extern void SR_UART_ReadFrame( USART_t *USARTx, uint8_t *Pbuffer, uint8_t U8size );
extern void SR_UART_WriteFrame( USART_t *USARTx, uint8_t *Pframe, uint8_t U8size );
extern bool SR_RecivedUARTFrameIsCorrect( uint8_t *PdataFrame );
extern void SR_SendUARTSensorFrame( USART_t *USARTx, uint8_t U8sensor1, uint8_t U8sensor2, uint8_t U8sensor3);

#endif // UART_H
