#include "clock.h"

void SR_Init_Clock( void )
{
    if ((RCC->CR & RCC_CR_HSIRDY) == 0)                 // Enable the internal clock (HSI) if not enable and ready
    {
        RCC->CR |= RCC_CR_HSION;                        // Enable Internal High speed clock    
        while ( ( RCC->CR & RCC_CR_HSIRDY ) == 0 );     // Wait until HSI is ready    
    }
    // Configure clock at maxium speed
    RCC->PLLCFGR =  PLLM_DIV16  |
                    PLLN_MUL336 |
                    PLLP_DIV4   |
                    PLL_SRC_HSI ;

    RCC->CR |= RCC_CR_PLLON;                            // Enable PLL
    while ( !( RCC->CR & RCC_CR_PLLRDY ) );             // Wait untill pll is locked
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;                   // APB1 = SYSCLK/2 (42 MHz)
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;                   // APB2 = SYSCLK (84 MHz)
    RCC->CFGR &= ~RCC_CFGR_SW;                          // Clear flags
    RCC->CFGR |= RCC_CFGR_SW_PLL;                       // Set system clock switch to PLL 
    while ( !( RCC->CFGR & RCC_CFGR_SWS_PLL ) );        // Wait untill PLL is set as PLL
}