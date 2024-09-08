#include "interrupt.h"
#include <stdbool.h>
#include "nucleof401re.h"

static volatile bool led_on = 0;

static void TurnOnOffLedPA5(void)
{
    GPIOA->ODR   ^= (1<<5);           // Togle state of bit 
}

void NVIC_EnableIRQ(IRQn_t IRQn)
{
    NVIC->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
}

void NVIC_SetPriority(IRQn_t IRQn, uint32_t priority)
{
    NVIC->IP[((uint32_t)IRQn)] = (uint8_t)((priority << (8U - 3U)) & (uint32_t)0xFFUL);
}

void EXTI15_10_IRQHandler(void)
{
  if ((EXTI->PR & (1<<13)) != 0)      // Verify if interrupt of button was set
  {
    TurnOnOffLedPA5();
    EXTI->PR     |= (1<<13);          // clear the flag interrupcion
  } 
}

void TIM2_IRQHandler( void )
{
    if( TIM2->SR & TIMx_SR_UIF )      // If UIF flag is set
    {
      TurnOnOffLedPA5();
      TIM2->SR &= ~TIMx_SR_UIF;       // Clean register
    }
}