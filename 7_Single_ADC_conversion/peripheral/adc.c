#include "nucleof401re.h"
#include "adc.h"

void ADC1_IN1_IN16_Init( void )
{
    /* Configure Channel ADC1_IN1*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOA_EN;                    // Enable clock acces to GPIOA
    GPIOA->MODER |= GPIO_MODER_01_ANALOG;                    // Set PA1 to analog mode
    RCC->APB2ENR |= RCC_APB2ENR_ADC1_ClockEnabled;           // Enable clock acces to ADC
    ADC1->SQR3   |= ADC1_SQR3_SQ1_CH1;                       // Set channel 1 as sequence 1
    
    /*  COMMON  */
    ADC1->SQR1   = ADC1_SQR1_LENGTH_1CHANNEL;               // Set two channels to monitor
    ADC1->CR2   |= ADC1_CR2_ADON_EN;                         // Enable ADC 
} 

void ADC1_StartConversion( void )
{
    ADC1->CR2  |= ADC1_CR2_CONT_CONTMODE;
    ADC1->CR2  |= ADC1_CR2_SWSTART_EN;                       // Start Conversion    
    while(!(ADC1->SR & ADC1_SR_EOC_Finish)){ }               // Wait for conversion   
}

uint32_t ADC_Read( void ) 
{
    ADC1_StartConversion( );
    return ADC1->DR;
}
