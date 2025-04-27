#include "clock.h"

void SystemClock_Config(void)
{
    RCC->CR |= RCC_CR_HSION;                                                        // Enable HSI oscillator
    while ( ( RCC->CR & RCC_CR_HSIRDY ) == 0 );                                     // Wait untill HSI is ready
    
    RCC->CFGR &= ~(0xF << 4);                                                       // Configure HPRE to dont divide SYSCLK
    
    RCC->CR &= ~RCC_CR_PLLON;                                                       // Desactivate PLL
    while ((RCC->CR & RCC_CR_PLLRDY) != 0);                                         // Wait untill PLL is desactived
    
    RCC->PLLCFGR &= ~(1U << 22);                                                    // Clean bits

    /* Configure PLL parameters:
        HSI = 16 MHz
        PLL_M = 16 (divide by 16)     -> 16MHz / 16 = 1MHz
        PLL_N = 168 (multiply by 168) -> 1MHz * 168 = 168 MHz
        PLL_P = 2 (divide by 2)       -> 168MHz / 2 = 84MHz (max frequency of SYSCLK)
        PLL_Q = 3 (divide by 3)       -> 168MHz / 3 = 56MHz ≈ 48MHz (for USB)

        VCO input  = HSI / PLL_M          = 16 MHz / 16 = 1 MHz
        VCO Output = VCO input * PLL_N    = 1 MHz * 168 = 168 MHz
        SYSCLK     = VCO Output / PLL_P   = 168 MHz / 2 = 84 MHz
    */

    RCC->PLLCFGR &= ~( 0x3F << 0 );                                      // Clean bits
    RCC->PLLCFGR |= ( PLLM_DIV16 );                                      // Configure PLL_M 16

    RCC->PLLCFGR &= ~( 0x1FF << 6 );                                     // Clean bits
    RCC->PLLCFGR |= ( PLLN_MUL168 );                                     // Configure PLL_N 168
 
    RCC->PLLCFGR &= ~( 0x3 << 16 );                                      // Clean bits
    RCC->PLLCFGR |= ( PLLP_DIV2 );                                       // Configure PLL_P 2

    RCC->PLLCFGR &= ~(0xF << 24);                                        // Clean bits
    RCC->PLLCFGR |= ( PLLQ_DIV3 );                                       // Configure PLL_Q 3

    RCC->CR |= RCC_CR_PLLON;                                             // Enable PLL
    while ((RCC->CR & RCC_CR_PLLRDY) == 0);                              // Wait untill PLL is ready
  
    /* Configure FLASH LATENCY
        To see more details, see reference manual RM0368 section 3.4.1 Relation between CPU clock frequency and Flash memory read time
        VR = Voltage Range
        |--------------------------------------------------------------------------------------------------
        |Wait states (WS) Latency |                      HCLK ( MHz )                                     |
        |        LATENCY          |  VR 2.7 - 3.6V  |  VR 2.4 - 2.7V  |  VR 2.1 - 2.4V  |  VR 1.7 - 2.1V  |
        |0 WS (1 CPU Cycle)       |  0 < HCLK <= 30 |  0 < HCLK <= 24 |  0 < HCLK <= 18 |  0 < HCLK <= 16 |
        |1 WS (2 CPU Cycle)       | 30 < HCLK <= 60 | 24 < HCLK <= 48 | 18 < HCLK <= 36 | 16 < HCLK <= 32 |
        |2 WS (3 CPU Cycle)       | 60 < HCLK <= 84 | 48 < HCLK <= 72 | 36 < HCLK <= 54 | 32 < HCLK <= 48 |
        |3 WS (4 CPU Cycle)       |                 | 72 < HCLK <= 84 | 54 < HCLK <= 72 | 48 < HCLK <= 64 |
        |5 WS (5 CPU Cycle)       |                 |                 | 72 < HCLK <= 84 | 64 < HCLK <= 80 |
        |5 WS (6 CPU Cycle)       |                 |                 |                 | 80 < HCLK <= 84 |
        |--------------------------------------------------------------------------------------------------
    */

    FLASH->ACR &= ~( 7U << 0 );                                          // Clean bits
    FLASH->ACR |= ( FLASH_ACR_2WS );                                     // Set Flash LATENCY at 2WS
    
    FLASH->ACR |= ( FLASH_ACR_PRFTEN );                                  // Enable Prefetch
    FLASH->ACR |= ( FLASH_ACR_ICEN );                                    // Enable instructions cache 
    FLASH->ACR |= ( FLASH_ACR_DCEN );                                    // Enable Data cache

    // Seleccionar el PLL como fuente del sistema de reloj
    RCC->CFGR &= ~RCC_CFGR_SW;                                           // Clean bits
    RCC->CFGR |= RCC_CFGR_SW_PLL;                                        // Set PLL as system clock

    // Esperar hasta que el PLL sea la fuente del sistema de reloj
    while ( ( RCC->CFGR & ( 3U << 2 ) ) != ( 2U << 2 ) );                // Wait untill PLL is set as system clock

    /* Configure APB1 and APB2 prescalers
    // APB1 max: 42 MHz -> divide by 2 (PPRE1 = 100)
    // APB2 max: 84 MHz -> not divide  (PPRE2 = 000)
    */
   
    RCC->CFGR &= ~( 7U << 10 );                                          // Clean bits
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;                                    // AHB clock divided by 2

    RCC->CFGR &= ~(7U << 13);                                            // Clean bits
}