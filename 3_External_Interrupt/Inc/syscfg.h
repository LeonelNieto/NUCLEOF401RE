#ifndef SYSCFG_H
#define SYSCFG_H

#include <stdint.h>
#include "globaldefine.h"

typedef struct
{
    __IO uint32_t MEMRMP;           // Offset 0x00
    __IO uint32_t PMC;              // Offset 0x04
    __IO uint32_t EXTICR1;          // Offset 0x08
    __IO uint32_t EXTICR2;          // Offset 0x0C
    __IO uint32_t EXTICR3;          // Offset 0x10
    __IO uint32_t EXTICR4;          // Offset 0x14
    uint32_t RESERVADO0[2];         // Offset 0x18-0x1C
    __IO uint32_t CMPCR;            // Offset 0x20
} SYSCFG_t;

#define SYSCFG ((SYSCFG_t *)(SYSCFG_BASE_ADDRESS))

#endif // SYSCFG_H