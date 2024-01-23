#include <stdint.h>
#include "rcc.h"
#include "gpio.h"
#include "syscfg.h"
#include "exti.h"
#include "nvic.h"

uint32_t button_state;

int main(void)
{
  RCC->AHB1ENR    |=  RCC_AHB1ENR_GPIOA_EN;                // Enable clock port A (Led)
  RCC->AHB1ENR    |=  RCC_AHB1ENR_GPIOC_EN;                // Enable clock port C (Button)
  GPIOA->MODER    &= ~(GPIO_MODER_05_OUTPUT);              // Clen registers port A
  GPIOA->MODER    |=  GPIO_MODER_05_OUTPUT;                // Set output pin 5
  GPIOC->MODER    &= ~(GPIO_MODER_INPUT);                  // Clean resgister port C    

  RCC->APB2ENR    |= RCC_APB2ENR_SYSCFGEN_ClockEnabled;    // Enable clock System configuration
  SYSCFG->EXTICR4 |= SYSCFG_EXTICR4_PC13;                  // Set the interrupt in PC13
  EXTI->IMR       |= EXTI_IMR_MR13_ISNOTMASKED;
  EXTI->FTSR      |= EXTI_FTSR_TR13_FALLING_TRIGGER_EN;

  enableInterruptIRQn(EXTI15_10_IRQn);

  while (1);
}

void EXTI15_10_IRQHandler(void)
{
  if ((EXTI->PR & (1<<13)) != 0)
  {
    GPIOA->ODR   ^= (1<<5); 
    EXTI->PR     |= (1<<13); 
  } 
}