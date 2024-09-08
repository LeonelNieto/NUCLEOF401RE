#include <stdio.h> 
#include "nucleof401re.h"
#include "globaldefine.h"
#include "uart.h"

int __io_putchar( int text )
{
    SR_UART_Write( text );
    return text;
}

static uint16_t SR_UART_DivBd( uint32_t PeriphClock, uint32_t BaudRate)
{
    /*
        Formula to calculate baudrate 
        Tx/Rx baud = fCK / (8*(2-OVER8)*USARTDIV)    I used OVER8 = 0
        Example:
        fCK = 16 000 000
        Tx/Rx baud = 19 200
        USARTDIV = 16 000 000 / (8 * (2-0) * 19 200)
        USARTDIV = 52.0833333333

        52 -> 0x34 ---> DIV_Mantissa

        16 * (0.83333) = 1.333
        1 -> 0x1 ---> DIV_Fraction

        BRR = 0x00000341

        0x00000000000000000000001101000001
          ||||||||||||||||||||||||||||||||__ DIV_Fraction[3:0]
          ||||||||||||||||||||||||||||           0x1
          ||||||||||||||||||||||||||||______ DIV_Mantissa[11:0]
          ||||||||||||||||                      0x34
          ||||||||||||||||__________________ RESERVED
    */

    if( BaudRate == 9600 )
    {
        return BAUDS_9600;
    }
    return ( ( PeriphClock + ( BaudRate / 2U ) ) / BaudRate );

}

static void SR_UART_SetBaudRate ( USART_t *USARTx, uint32_t PeripchClk, uint32_t BaudRate ) 
{
    USART2->BRR = SR_UART_DivBd( PeripchClk, BaudRate );
}

char UART2_Read( void )
{
    while(!(USART2->SR & USART_SR_RXNE)){}                                       // Make sure the transmit data register is NOT empty 
    
    return USART2->DR;
}

void SR_UART_Write( int ch )
{
    while(!(USART2->SR & USART_SR_TXE)){ }                                       // Make sure the transmit data register is empty
    
    USART2->DR = ( ch & 0xFF);                                                  // Write to transmit data register
}

void SR_Init_UART2 ( void )
{
    // Configure Tx
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOA_EN;                                       // Enable clock access to GPIOA
    GPIOA->MODER &= ~( 1U << 4 );                                               // Clear register
    GPIOA->MODER |= GPIO_MODER_02_ALFM;                                         // Set PA2 mode to alternate function mode
    GPIOA->AFRL  |= GPIO_AFRL_AFRL2_AF7;                                        // Set PA2 type to UART_TX (AF07)
    GPIOA->AFRL  &= ~( 1U << 11 );                                              // Clean bit

    // Configure Rx
    GPIOA->MODER &= ~( 1U << 6 );                                               // Clear register
    GPIOA->MODER |= GPIO_MODER_03_ALFM;                                         // Set PA3 mode to alternate function mode
    GPIOA->AFRL  |= GPIO_AFRL_AFRL3_AF7;                                        // Set PA3 type to UART_RX (AF07)
    GPIOA->AFRL  &= ~( 1U << 15 );                                              // Clean bit

    // Configure UART
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;                                       // Enable clock access to UART2
    SR_UART_SetBaudRate( USART2, APB1_CLK, UART_BAUDRATE );                     // Set the baudrate
    USART2->CR1   = ( USART_CR1_TE_EN | USART_CR1_RX_EN );                      // Enable Transmitter and receptor
    USART2->CR1  |= USART_CR1_USART_EN;                                         // Enable USART
}
