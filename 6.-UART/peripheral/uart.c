#include <stdio.h> 
#include "nucleof401re.h"
#include "globaldefine.h"
#include "uart.h"

int __io_putchar( USART_t *USART, int text )
{
    SR_UART_Write( USART, text );
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
    return ( ( PeriphClock + ( BaudRate / 2U ) ) / BaudRate );

}

static void SR_UART_SetBaudRate ( USART_t *USARTx, uint32_t PeripchClk, uint32_t BaudRate ) 
{
    USARTx->BRR = SR_UART_DivBd( PeripchClk, BaudRate );
}

char USART_Read( USART_t *USART )
{
    while(!(USART->SR & USART_SR_RXNE));                                       // Make sure the transmit data register is NOT empty 
    
    return USART->DR;
}

void SR_UART_Write( USART_t *USART, char ch )
{
    while(!(USART->SR & USART_SR_TXE));                                        // Make sure the transmit data register is empty
    USART->DR = ch;                                                           // Write to transmit data register
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

void SR_Init_USART1( void )
{
    // CONFIGURE Tx
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOA_EN;                                       // Enable clock access to GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_USART1_ClockEnabled;
    
    GPIOA->MODER &= ~( 3U << 18 );                                               // Clear register
    GPIOA->MODER |= GPIO_MODER_09_ALFM;                                         // Set PA9 as alternate function mode
    GPIOA->AFRH  |= GPIO_AFRH_AFRH9_AF7;                                        // Set PA9 type UART_TX (AF07)                                       
    GPIOA->AFRH  &= ~( 1U << 7 );                                               // Clean bit

    // CONFIGURE Rx
    GPIOA->MODER &= ~(3U << 20);                                                // Clear register
    GPIOA->MODER |= GPIO_MODER_10_ALFM;                                         // Set PA10 as altenate function mode
    GPIOA-> AFRH |= GPIO_AFRH_AFRH10_AF7;                                       // Set PA10 type UART_RX (AF07)
    GPIOA->AFRH  &= ~( 1U << 11 );                                               // Clean bit
    

    // Configure UART
    SR_UART_SetBaudRate( USART1, FRECUENCY_16MHZ, UART_BAUDRATE );               // Set the baudrate
    USART1->CR1   = ( USART_CR1_TE_EN | USART_CR1_RX_EN );                      // Enable Transmitter and receptor
    USART1->CR1  |= USART_CR1_USART_EN;                                         // Enable USART
}
