#include "nvic.h"

void enableInterruptIRQn(IRQn_t IRQn)
{
     NVIC->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
}