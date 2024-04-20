#ifndef UART_H
#define UART_H

extern uint32_t u16BaudRate;
extern void SR_InitTx_UART2( void );
extern void SR_UART_Write( int ch );

#endif // UART_H
