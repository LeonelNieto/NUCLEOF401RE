#include <stdint.h>
#include "nucleof401re.h"

void ADC1_IN1_IN16_Init2(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOA_EN;  // Habilitar el reloj para GPIOA
    GPIOA->MODER |= GPIO_MODER_01_ANALOG;  // Configurar PA1 como analógico
    RCC->APB2ENR |= RCC_APB2ENR_ADC1_ClockEnabled;  // Habilitar el reloj para ADC1
    ADC1->SQR3 |= ADC1_SQR3_SQ1_CH1;  // Configurar canal 1 como secuencia 1
    ADC1->SQR1 = 0x00;  // Longitud de la secuencia a 1
    ADC1->CR2 |= ADC1_CR2_ADON_EN;  // Encender ADC1
}

void ADC1_StartConversion2(void) {
    ADC1->CR2 |= ADC1_CR2_SWSTART_EN;  // Iniciar conversión
}

int main(void) {
    ADC1_IN1_IN16_Init2();

    while (1) {
        ADC1_StartConversion2();  // Iniciar la conversión

        uint32_t SensorValue = ADC1->DR;  // Leer el valor del ADC

        // Verificar si el valor del ADC es mayor que 0
        if (SensorValue > 0) {
            // Aquí, SensorValue debería ser 1 si es mayor que 0
            SensorValue = 1;
        }
    }
}