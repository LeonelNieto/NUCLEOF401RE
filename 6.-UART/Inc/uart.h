#ifndef UART_H
#define UART_H

extern uint32_t u16BaudRate;
extern int __io_putchar( int text );
extern void SR_UART_Write( int ch );
extern void SR_Init_UART2( void );
extern char UART2_Read( void );

#endif // UART_H
