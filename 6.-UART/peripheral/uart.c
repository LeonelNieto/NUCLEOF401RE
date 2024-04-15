#include "uart.h"

static uint16_t SR_UART_DivBd( uint32_t PeriphClock, uint32_t BaudRate)
{
    return ( ( PeriphClock + ( BaudRate / 2U ) ) / BaudRate );
}

static void SR_UART_SetBaudRate ( USART_t *USARTx, uint32_t PeripchClk, uint32_t BaudRate ) 
{
    USART2->BRR = SR_UART_DivBd( PeripchClk, BaudRate );
}

void SR_InitTx_UART2 ( void )
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOA_EN;                                       // Enable clock access to GPIOA
    GPIOA->MODER &= ~(1U << 4);                                                 // Clear register
    GPIOA->MODER |= GPIO_MODER_02_ALFM;                                         // Set PA2 mode to alternate function mode
    GPIOA->AFRL  |= GPIO_AFRL_AFRL2_AF7;                                        // Set PA2 type to UART_TX (AF07)

    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;                                       // Enable clock access to UART2
    SR_UART_SetBaudRate( USART2, APB1_CLK, UART_BAUDRATE );                     // Set the baudrate
    USART2->CR1   = USART_CR1_TE_EN;                                            // Enable Transmitter
    USART2->CR1  |= USART_CR1_USART_EN;                                         // Enable USART
}

void SR_UART_Write( int ch )
{
    while(!(USART2->SR & USART_SR_TXE)){}                                       // Make sure the transmit data register is empty
    
    USART2->DR = ( ch & 0xFF);                                                  // Write to transmit data register

}

void SR_Init_UART2( void )
{

}
