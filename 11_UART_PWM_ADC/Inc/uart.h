#ifndef UART_H
#define UART_H

typedef enum
{
    CLOCK_16MHZ = 16000000U,
    CLOCK_42MHZ = 42000000U,
    CLOCK_84MHZ = 84000000U
} ClockFreq_t;

extern int __io_putchar( USART_t *USARTx, int text );
extern void SR_UART_Write( USART_t *USARTx, int ch );
extern void SR_Init_UART( USART_t *USARTx, uint32_t u32baudrate );
extern char UART_Read( USART_t *USARTx );

#endif // UART_H
