#include <stdint.h>
#include <stdio.h>
#include "globaldefine.h"
#include "interrupt.h"
#include "delay.h"
#include "timer.h"
#include "uart.h"

char DataRecived;
char DATATOSEND0 = '0';
char DATATOSEND1 = '1';

int main( void )
{
  SR_Init_UART2( );
  SetSystemClockTo16MHz( );
  SR_Init_USART1( );


  RCC->AHB1ENR    |=  RCC_AHB1ENR_GPIOA_EN;                // Enable clock port A (Led)
  RCC->AHB1ENR    |=  RCC_AHB1ENR_GPIOC_EN;                // Enable clock port C (Button)
  GPIOA->MODER    &= ~(GPIO_MODER_05_OUTPUT);              // Clen registers port A
  GPIOA->MODER    |=  GPIO_MODER_05_OUTPUT;                // Set output pin 5
  GPIOC->MODER    &= ~(GPIO_MODER_INPUT);                  // Clean resgister port C    

  RCC->APB2ENR    |= RCC_APB2ENR_SYSCFGEN_ClockEnabled;    // Enable clock System configuration

  while (1)
  {
    DataRecived = USART_Read( USART1 );
    if( DataRecived == '1' )
    {
      GPIOA->ODR  |= (1<<5);
      SR_UART_Write( USART1, DATATOSEND1);
    }
    else
    {
      GPIOA->ODR  &= ~(1<<5);
      SR_UART_Write( USART1, DATATOSEND0);
    }
  }
}
