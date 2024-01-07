#ifndef RCC_H
#define RCC_H

#include <stdint.h>
#include "globaldefine.h"

typedef struct {
	__IO uint32_t CR;
	__IO uint32_t PLLCFGR;
	__IO uint32_t CFGR;
	__IO uint32_t CIR;
	__IO uint32_t AHB1RSTR;
	__IO uint32_t AHB2RSTR;
	uint32_t RESERVADO0;
	__IO uint32_t APB1RSTR;
	__IO uint32_t APB2RSTR;
	uint32_t RESERVADO1[3];
	__IO uint32_t AHB1ENR;
	__IO uint32_t AHB2ENR;
} RCC_t;

#define RCC ((RCC_t *)(RCC_BASE_ADDRESS))

#endif // RCC_H
