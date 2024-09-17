#include "globaldefine.h"
#include "nucleof401re.h"
#include "pwm.h"

void InitPwm( uint32_t TimFrecuencyHz )
{
    RCC->APB1ENR  |= RCC_APB1ENR_TIME3EN;                   // Enable the APB1 for TIM3
    TIM3 -> PSC    = 15;                                    // Set prescaler in 1 (To get 1 MHz)
    TIM3 -> ARR    = (Frecuency_1MHz / TimFrecuencyHz) - 1; //Set the frecuency of the clock (Fpsc/FrecuencyPWM) - 1
    TIM3 -> CCR1  |= 0;                                     // Initial duty cycle 0%
    TIM3 -> CCMR1 |= TIMx_CCMR1_OC1M_PWM_Mode_1;            // Set timer as PWM Mode
    TIM3 -> CCER  |= TIMx_CCER_CC1E_ON;                     // Enable channel 1 output 
    TIM3 -> CR1   |= TIMx_CR1_CEN;                          // Enable TIM3              
}   

void ConfigPinPA6AsAlternFunctions( )
{
    RCC   -> AHB1ENR |= RCC_AHB1ENR_GPIOA_EN;               // Enable clock for GPIOA
    GPIOA -> MODER   |= GPIO_MODER_06_ALFM;                 // Set PA6 as Alternate function mode 
    GPIOA -> AFRL    |= GPIO_AFRL_AFRL6_AF2;                // Set the alternate functions as TIM3_CH1
}
