#include <stdint.h>
#include "interrupt.h"
#include "delay.h"
#include "timer.h"

int main(void)
{

  SetSystemClockTo16MHz();
  EnableTim2();

  RCC->AHB1ENR    |=  RCC_AHB1ENR_GPIOA_EN;                // Enable clock port A (Led)
  RCC->AHB1ENR    |=  RCC_AHB1ENR_GPIOC_EN;                // Enable clock port C (Button)
  GPIOA->MODER    &= ~(GPIO_MODER_05_OUTPUT);              // Clen registers port A
  GPIOA->MODER    |=  GPIO_MODER_05_OUTPUT;                // Set output pin 5
  GPIOC->MODER    &= ~(GPIO_MODER_INPUT);                  // Clean resgister port C    

  RCC->APB2ENR    |= RCC_APB2ENR_SYSCFGEN_ClockEnabled;    // Enable clock System configuration
  SYSCFG->EXTICR4 |= SYSCFG_EXTICR4_PC13;                  // Set the interrupt in PC13
  EXTI->IMR       |= EXTI_IMR_MR13_ISNOTMASKED;            // Enable external interruption PC13
  EXTI->FTSR      |= EXTI_FTSR_TR13_FALLING_TRIGGER_EN;    // Set the falling trigger enable 

  enableInterruptIRQn(EXTI15_10_IRQn);


  while (1)
  {
    GPIOA->ODR ^= (1<<5);
    TimDelayMs(1000);
  }
}