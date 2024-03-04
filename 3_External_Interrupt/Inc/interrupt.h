#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "nucleof401re.h"

extern void enableInterruptIRQn(IRQn_t IRQn);
void EXTI15_10_IRQHandler(void);

#endif // INTERRUPT_H