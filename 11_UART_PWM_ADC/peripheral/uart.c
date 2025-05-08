#include "uart.h"

static void SR_Init_UART_GPIO( GPIO_t *GPIOx, uint8_t txPin, uint8_t rxPin, uint8_t altFunction )
{
    // Config Tx
    GPIOx->MODER &= ~( 3U << ( txPin * 2 ) );                               // Clean bits
    GPIOx->MODER |=  ( 2U << ( txPin * 2 ) );                               // Set as Alternate mode
    // Config Rx
    GPIOx->MODER &= ~( 3U << ( rxPin * 2 ) );                               // Clean bits
    GPIOx->MODER |=  ( 2U << ( rxPin * 2 ) );                               // Set as Alternate mode

    GPIOx->OSPEEDR |= ( 3U << ( rxPin * 2 ) );
    GPIOx->OSPEEDR |= ( 3U << ( txPin * 2 ) );

    if (txPin < 8) 
    {
        GPIOx->AFRL &= ~(0xF << (txPin * 4));
        GPIOx->AFRL |= (altFunction << (txPin * 4));
        
        GPIOx->AFRL &= ~(0xF << (rxPin * 4));
        GPIOx->AFRL |= (altFunction << (rxPin * 4));
    } 
    else 
    {
        GPIOx->AFRH &= ~(0xF << ((txPin - 8) * 4));
        GPIOx->AFRH |= (altFunction << ((txPin - 8) * 4));
        
        GPIOx->AFRH &= ~(0xF << ((rxPin - 8) * 4));
        GPIOx->AFRH |= (altFunction << ((rxPin - 8) * 4));
    }
}

static void SR_UART_SetBaudRate ( USART_t *USARTx, uint32_t PeripchClk, uint32_t BaudRate ) 
{
    uint32_t usartDiv = ( PeripchClk + ( BaudRate / 2U ) ) / BaudRate;
    USARTx->BRR = usartDiv;
}

uint8_t SR_UART_ReadByte( USART_t *USARTx )
{
    while( !( USARTx->SR & USART_SR_RXNE ) ){}                                       // Make sure the transmit data register is NOT empty 
    return ( uint8_t )( USARTx->DR );
}

void SR_UART_ReadFrame( USART_t *USARTx, uint8_t *Pbuffer, uint8_t U8size )
{
    for( uint8_t i = 0; i < U8size; i++ )
    {
        Pbuffer[ i ] = SR_UART_ReadByte( USARTx );
    }
}

void SR_UART_WriteByte( USART_t *USARTx, uint8_t byte )
{
    while( !( USARTx->SR & USART_SR_TXE ) ){ }                                        // Make sure the transmit data register is empty
    USARTx->DR = ( byte & 0xFF);                                                      // Write to transmit data register
}

void SR_UART_WriteFrame( USART_t *USARTx, uint8_t *Pframe, uint8_t U8size )
{
    for( uint8_t i = 0; i < U8size; i++ )
    {
        SR_UART_WriteByte( USARTx, Pframe[ i ] );
    }
}

void SR_SendUARTSensorFrame( USART_t *USARTx, uint8_t U8sensor1, uint8_t U8sensor2, uint8_t U8sensor3)
{
    uint8_t U8frameToSend[ 7 ];

    U8frameToSend[ 0 ] = BYTE_INIT;
    U8frameToSend[ 1 ] = UART_READ;
    U8frameToSend[ 2 ] = U8sensor1;
    U8frameToSend[ 3 ] = U8sensor2;
    U8frameToSend[ 4 ] = U8sensor3;
    U8frameToSend[ 5 ] = SR_CalculateCRC( U8frameToSend );
    U8frameToSend[ 6 ] = BYTE_END;

    SR_UART_WriteFrame( USARTx, U8frameToSend, FRAME_SIZE );
}

bool SR_RecivedUARTFrameIsCorrect( uint8_t *PdataFrame )
{
    if( PdataFrame[ 0 ] != BYTE_INIT )
    {
        return false;
    } 

    if( PdataFrame[ 5 ] != SR_CalculateCRC( PdataFrame ) )
    {
        return false;
    }

    if( PdataFrame[ 6 ] != BYTE_END )
    {
        return false;
    }

    return true;
}

void SR_Init_UART ( USART_t *USARTx, uint32_t u32baudrate )
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOA_EN;                                           // Enable clock access to GPIOA
    
    if( USARTx == USART1 )
    {
        SR_Init_UART_GPIO( GPIOA, 9, 10, 7 );
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;                                       // Enable clock access to UART1
        SR_UART_SetBaudRate( USARTx, CLOCK_84MHZ, u32baudrate );                    // Set the baudrate
    }
    else if( USARTx == USART2 )
    {
        SR_Init_UART_GPIO( GPIOA, 2, 3, 7 );
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;                                       // Enable clock access to UART2 
        SR_UART_SetBaudRate( USARTx, CLOCK_42MHZ, u32baudrate );                    // Set the baudrate
    }
    else if( USARTx == USART6 )
    {
        SR_Init_UART_GPIO( GPIOA, 11, 12, 8 );
        RCC->APB2ENR |= RCC_APB2ENR_USART6EN;                                       // Enable clock access to UART6
        SR_UART_SetBaudRate( USARTx, CLOCK_84MHZ, u32baudrate );                    // Set the baudrate  
    }
    USARTx->CR1   = ( USART_CR1_TE_EN | USART_CR1_RX_EN );                          // Enable Transmitter and receptor
    USARTx->CR1  |= USART_CR1_USART_EN;                                             // Enable USART
}
