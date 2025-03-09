#include <stdio.h> 
#include "nucleof401re.h"
#include "globaldefine.h"
#include "uart.h"

int __io_putchar( USART_t *USARTx, int text )
{
    SR_UART_Write( USARTx, text );
    return text;
}

static void SR_Init_GPIO( GPIO_t *GPIOx, uint8_t txPin, uint8_t rxPin, uint8_t altFunction )
{
    // Config Tx
    GPIOx->MODER &= ~( 3U << ( txPin * 2 ) );                               // Clean bits
    GPIOx->MODER |=  ( 2U << ( txPin * 2 ) );                               // Set as Alternate mode
    // Config Rx
    GPIOx->MODER &= ~( 3U << ( rxPin * 2 ) );                               // Clean bits
    GPIOx->MODER |=  ( 2U << ( rxPin * 2 ) );                               // Set as Alternate mode

    if( txPin < 8 )
    {
        GPIOx->AFRL |= ( altFunction << ( txPin * 4 ) );
        GPIOx->AFRL |= ( altFunction << ( rxPin * 4 ) );
    }
    else
    {
        GPIOx->AFRL |= ( altFunction << ( ( txPin - 8 ) * 4) );
        GPIOx->AFRL |= ( altFunction << ( ( rxPin - 8 ) * 4) );
    }
}

static void SR_UART_SetBaudRate ( USART_t *USARTx, uint32_t PeripchClk, uint32_t BaudRate ) 
{
    uint32_t usartDiv = ( PeripchClk + ( BaudRate / 2U ) ) / BaudRate;
    USARTx->BRR = usartDiv;
}

char UART_Read( USART_t *USARTx )
{
    while( !( USARTx->SR & USART_SR_RXNE ) ){}                                       // Make sure the transmit data register is NOT empty 
    
    return USARTx->DR;
}

void SR_UART_Write( USART_t *USARTx, int ch )
{
    while( !( USARTx->SR & USART_SR_TXE ) ){ }                                      // Make sure the transmit data register is empty
    
    USARTx->DR = ( ch & 0xFF);                                                      // Write to transmit data register
}

void SR_Init_UART ( USART_t *USARTx, uint32_t u32baudrate )
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOA_EN;                                           // Enable clock access to GPIOA
    
    if( USARTx == USART1 )
    {
        SR_Init_GPIO( GPIOA, 9, 10, 7 );
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;                                       // Enable clock access to UART1
        SR_UART_SetBaudRate( USARTx, CLOCK_84MHZ, u32baudrate );                    // Set the baudrate
    }
    else if( USARTx == USART2 )
    {
        SR_Init_GPIO( GPIOA, 2, 3, 7 );
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;                                       // Enable clock access to UART2 
        SR_UART_SetBaudRate( USARTx, CLOCK_42MHZ, u32baudrate );                    // Set the baudrate
    }
    else if( USARTx == USART6 )
    {
        SR_Init_GPIO( GPIOA, 11, 12, 8 );
        RCC->APB2ENR |= RCC_APB2ENR_USART6EN;                                       // Enable clock access to UART6
        SR_UART_SetBaudRate( USARTx, CLOCK_84MHZ, u32baudrate );                    // Set the baudrate  
    }
    USARTx->CR1   = ( USART_CR1_TE_EN | USART_CR1_RX_EN );                          // Enable Transmitter and receptor
    USARTx->CR1  |= USART_CR1_USART_EN;                                             // Enable USART
}