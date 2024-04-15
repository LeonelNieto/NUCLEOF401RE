#ifndef UART_H
#define UART_H

#include "nucleof401re.h"
#include "globaldefine.h"

extern void SR_InitTx_UART2( void );
extern void SR_UART_Write( int ch );

#endif // UART_H
