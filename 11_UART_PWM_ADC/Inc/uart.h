#ifndef UART_H
#define UART_H

#define UART_BUFFER_SIZE  255
#define BYTE_INTIT       0xE2
#define BYTE_END         0xE3
#define FRAME_LENGTH     0x06
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

#endif // UART_H
