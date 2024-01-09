#include <stdint.h>
#include "rcc.h"
#include "gpio.h"
#include "syscfg.h"
#include "exti.h"

int main(void)
{
  uint32_t button_state;
  
  RCC->AHB1ENR    |=  RCC_AHB1ENR_GPIOA_EN;                // Enable clock port A (Led)
  RCC->AHB1ENR    |=  RCC_AHB1ENR_GPIOC_EN;                // Enable clock port C (Button)
  GPIOA->MODER    &= ~(GPIO_MODER_05_OUTPUT);              // Clen registers port A
  GPIOA->MODER    |=  GPIO_MODER_05_OUTPUT;                // Set output pin 5
  GPIOC->MODER    &= ~(GPIO_MODER_INPUT);                  // Clean resgister port C    
  GPIOC->PUPDR    |= GPIO_PUPDR_NO_PUPD;                   // No pull up, pull down

  RCC->APB2ENR    |= RCC_APB2ENR_SYSCFGEN_ClockEnabled;    // Enable clock System configuration
  SYSCFG->EXTICR4 &= ~(SYSCFG_EXTICR4_PC13);               // Clean register
  SYSCFG->EXTICR4 |= SYSCFG_EXTICR4_PC13;                  // Set the interrupt in PC13
  EXTI->IMR       |= EXTI_IMR_MR13_ISNOTMASKED;
  EXTI->FTSR      |= EXTI_FTSR_TR13_FALLING_TRIGGER_EN;
  EXTI->RTSR      |= EXTI_RTSR_TR13_RISING_TRIGGER_EN;
  RCC->APB2ENR    &= ~(RCC_APB2ENR_SYSCFGEN_ClockEnabled);    // Disable clock System configuration

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