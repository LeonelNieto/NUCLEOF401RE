#ifndef NVIC_H
#define NVIC_H

#include <stdint.h>
#include "globaldefine.h"
#include "irqn.h"

void enableInterruptIRQn(IRQn_t IRQn);

typedef struct
{
	__IO uint32_t ISER[8];            // Enable Interrupts
         uint32_t RESERVED0[24];
    __IO uint32_t ICER[8];            // Disable Interrupts
         uint32_t RSERVED1[24];
    __IO uint32_t ISPR[8];            // Conjunto de interrupciones pendientes
         uint32_t RESERVED2[24];
    __IO uint32_t ICPR[8];            // Conjunto de interrupciones pendientes
         uint32_t RESERVED3[24];
    __IO uint32_t IABR[8];            // Active Interrupts
         uint32_t RESERVED4[56];
    __IO uint8_t IP[240];             // Priority Interrupts
         uint32_t RESERVED5[644];
    __IO uint32_t STIR;               // Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_t;

#define NVIC ((NVIC_t *)(NVIC_BASE_ADDRESS))

#endif // NVIC_H