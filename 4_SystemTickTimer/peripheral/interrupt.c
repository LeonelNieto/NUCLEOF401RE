#include "interrupt.h"
#include "nucleof401re.h"

void enableInterruptIRQn(IRQn_t IRQn)
{
    NVIC->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
}

void NVIC_SetPriority(IRQn_t IRQn, uint32_t priority)
{
    NVIC->IP[((uint32_t)IRQn)] = (uint8_t)((priority << (8U - 3U)) & (uint32_t)0xFFUL);
}

static void turnOnOffLedPA5(void)
{
    GPIOA->ODR   ^= (1<<5);           // Togle state of bit 
}

void EXTI15_10_IRQHandler(void)
{
  if ((EXTI->PR & (1<<13)) != 0)    // Verify if interrupt of button was set
  {
    turnOnOffLedPA5();
    EXTI->PR     |= (1<<13);        // clear the flag interrupcion
  } 
}
