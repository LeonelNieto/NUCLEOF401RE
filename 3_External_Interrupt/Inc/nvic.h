#ifndef NVIC_H
#define NVIC_H

#include <stdint.h>
#include "globaldefine.h"

typedef struct
{
  __IO uint32_t ISER;                 /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
    uint32_t RESERVED0[31];
  __IO uint32_t ICER;                 /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register          */
    uint32_t RSERVED1[31];
  __IO uint32_t ISPR;                 /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register           */
    uint32_t RESERVED2;
  __IO uint32_t ICPR;                 /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register         */
    uint32_t RESERVED3;
    uint32_t RESERVED4[64];
  __IO uint32_t IP;                   /*!< Offset: 0x300 (R/W)  Interrupt Priority Register              */
}  NVIC_t;

#define NVIC ((NVIC_t *)(NVIC_BASE_ADDRESS))

#endif // NVIC_H