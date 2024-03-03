#include "interrupt.h"

static void turnOnOffLedPA5(void)
{
    GPIOA->ODR   ^= (1<<5); 
}

void EXTI15_10_IRQHandler(void)
{
  if ((EXTI->PR & (1<<13)) != 0)
  {
    turnOnOffLedPA5();
    EXTI->PR     |= (1<<13); 
  } 
}
