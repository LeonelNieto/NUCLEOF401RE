#include <stdint.h>
#include "rcc.h"
#include "gpio.h"

int main(void)
{
  uint32_t button_state;
  
  RCC->AHB1ENR |=  RCC_AHB1ENR_GPIOA_EN;      // Enable clock port A (Led)
  RCC->AHB1ENR |=  RCC_AHB1ENR_GPIOC_EN;      // Enable clock port C (Button)
  GPIOA->MODER &= ~(GPIO_MODER_05_OUTPUT);    // Clen registers port A
  GPIOA->MODER |=  GPIO_MODER_05_OUTPUT;      // Set output pin 5
  GPIOC->MODER &= ~(GPIO_MODER_INPUT);        // Clean resgister port C    
  GPIOC->PUPDR |= GPIO_PUPDR_13_PULL_UP;
  
  while (1)
  {
    button_state = GPIOC->IDR;
    if (button_state == 0x00002000)
    {
      GPIOA->ODR   &= ~(GPIO_ODR_05_ON);
    }
    else
    {
      GPIOA->ODR   |=  GPIO_ODR_05_ON;
    }
  }

}