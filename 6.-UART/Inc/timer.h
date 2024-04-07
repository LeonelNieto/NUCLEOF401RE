#ifndef TIMER_H
#define TIMER_H

#include "nucleof401re.h"

extern void SetSystemClockTo16MHz( void );
extern void EnableTim2( void );
extern void TimDelayMs(uint32_t u32Time_Ms);
extern void EnableTIM2Interrupt( uint32_t TimFrecuency );

#endif // TIMER_H