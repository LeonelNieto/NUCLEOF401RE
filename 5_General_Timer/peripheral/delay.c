#include "delay.h"
#include "nucleof401re.h"

void SystickDelayMs(uint32_t delay)
{
    SysTick->RVR = SYSTICK_RVR_VAL;                                  // Reload with number of click per milliseconds
    SysTick->CVR = 0;                                                // Clear Systick current value register
    SysTick->CSR = SYSTICK_CSR_ENABLE | SYSTICK_CSR_CLKSRC_INTERNAL; // Enable systick and select internal clock

    for( uint32_t i = 0; i < delay; i++ )
    {
        while ( (SysTick->CSR & SYSTICK_CSR_COUNTFLAG) == 0 ){}
    }

    SysTick->CSR = 0;                                                // Disable systick
}