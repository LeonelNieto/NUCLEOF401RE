#include <stdint.h>
#include <stdio.h>
#include "rcc.h"
#include "gpio.h"

int main(void)
{
  RCC->AHB1ENR |=  RCC_AHB1ENR_GPIOA_EN;
  GPIOA->MODER &= ~(GPIO_MODER_05_OUTPUT);
  GPIOA->MODER |=  GPIO_MODER_05_OUTPUT;
  GPIOA->ODR   |=  GPIO_ODR_05_ON;
  GPIOA->ODR   &= ~(GPIO_ODR_05_ON);
}