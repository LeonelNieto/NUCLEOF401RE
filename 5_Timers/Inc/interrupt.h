#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "nucleof401re.h"

extern void NVIC_EnableIRQ( IRQn_t IRQn );
extern void NVIC_SetPriority( IRQn_t IRQn, uint32_t priority );
void EXTI15_10_IRQHandler( void );
void TIM2_IRQHandler( void );

#endif // INTERRUPT_H