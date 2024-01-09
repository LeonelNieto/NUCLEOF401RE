#ifndef EXTI_H
#define EXTI_H

#include <stdint.h>
#include "globaldefine.h"

typedef struct
{
    __IO uint32_t IMR;         // Offset 0x00
    __IO uint32_t EMR;         // Offset 0x04
    __IO uint32_t RTSR;        // Offset 0x08
    __IO uint32_t FTSR;        // Offset 0x0C
    __IO uint32_t SWIER;       // Offset 0x10
    __IO uint32_t PR;          // Offset 0x14
} EXTI_t;

#define EXTI ((EXTI_t *)(EXTI_BASE_ADDRESS))

#endif // EXTI_H