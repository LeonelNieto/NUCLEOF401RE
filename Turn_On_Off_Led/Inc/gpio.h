#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "globaldefine.h"

typedef struct {
    __IO uint32_t MODER;            // Offset 0x00
    __IO uint32_t OTYPER;           // Offset 0x04
    __IO uint32_t OSPEEDR;          // Offset 0x08
    __IO uint32_t PUPDR;            // Offset 0x0C
    __IO uint32_t IDR;              // Offset 0x10
    __IO uint32_t ODR;              // Offset 0x14
    __IO uint32_t BSRR;             // Offset 0x18
    __IO uint32_t LCKR;             // Offset 0x1C
    __IO uint32_t AFRL;             // Offset 0x20
    __IO uint32_t AFRH;             // Offset 0x24
} GPIO_t;
 
#define GPIOA ((GPIO_t *)(GPIOA_BASE_ADDRESS))

#endif // GPIO_H