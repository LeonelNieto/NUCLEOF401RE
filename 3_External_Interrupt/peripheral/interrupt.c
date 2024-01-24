#include "interrupt.h"

void EXTI15_10_IRQHandler(void)
{
  if ((EXTI->PR & (1<<13)) != 0)
  {
    GPIOA->ODR   ^= (1<<5); 
    EXTI->PR     |= (1<<13); 
  } 
}