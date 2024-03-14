#ifndef TIMER_H
#define TIMER_H

#include "nucleof401re.h"

extern void SetSystemClockTo16MHz( void );
extern void EnableTim2( void );
extern void TimDelayMs(uint32_t u32Time_Ms);

#endif // TIMER_H