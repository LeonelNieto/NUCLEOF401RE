#include "timer.h"
#include "interrupt.h"

void SetSystemClockTo16MHz( void )
{
    if ((RCC->CR & RCC_CR_HSIRDY) == 0)             // Enable the internal clock (HSI) if not enable and ready
    {
        RCC->CR |= RCC_CR_HSION;                    // Enable Internal High speed clock
    
        while ((RCC->CR & RCC_CR_HSIRDY) == 0);     // Wait until HSI is ready    
    }

    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;                // Select the AHB prescaler to 1
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;               // Set APB1 prescaler to 1
    RCC->CFGR &= ~(RCC_CFGR_SW_NOTALLOW);           // Clear register
    RCC->CFGR |= RCC_CFGR_SW_HSI;                   // Select the internal clock HSI

    /* Configure Flash prefetch, Instruction cache, Data cache and wait state */
    // FLASH->ACR = FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_3WS;        Is this necesary?

    RCC->CR &= ~(RCC_CR_HSEON);                     // Disable external clock HSE
}

void EnableTim2( void )
{
    RCC->APB1ENR |= RCC_APB1ENR_TIME2EN;            // Enable the APB1 for TIM2
    
    /*  The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1)
        (16 MHz / (15+1)) = 1 MHz timer clock speed                                 */
    TIM2->PSC =  15;

    /*  (1 MHz / 1000) = 1KHz = 1ms          */
    /*  So, this will generate the 1ms delay */
    TIM2->ARR = 999;
    TIM2->CR1 = TIMx_CR1_CEN;                       // Enable TIM2 
}

void TimDelayMs(uint32_t u32Time_Ms)
{
    TIM2->CNT = 0;                                  // Clear the count

    for (uint32_t i = 0; i <= u32Time_Ms; i++)
    {
        while ((TIM2->SR & TIMx_SR_UIF) == 0);      // Wait until UIF is set        
        TIM2->SR &= ~TIMx_SR_UIF;                   // Clean register
    }
}

void EnableTIM2Interrupt( uint32_t TimFrecuency )
{
    RCC->APB1ENR |= RCC_APB1ENR_TIME2EN;            // Enable the APB1 for TIM2

    /* fCK_PSC / (PSC[15:0] + 1)
       (16 MHz / (0+1)) = 16 MHz timer clock speed */
    TIM2->PSC = 0;

    /*  (16 MHz / TimTickTime) = xHz = 1/xHz = Time          */
    /*  So, this will generate the 1ms delay */
    TIM2->ARR = ( FRECUENCY16MHZ / TimFrecuency ) - 1;
    TIM2->DIER |= TIMx_DIER_UIE;                    // Enable Interrupt
    TIM2->SR &= ~TIMx_SR_UIF;                       // Clean register
    NVIC_EnableIRQ( TIM2_IRQn );                    // Enable NVIC Interrupt for Timer 2
    TIM2->CR1 = TIMx_CR1_CEN;                       // Enable TIM2 
}