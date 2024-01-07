#ifndef RCC_H
#define RCC_H

#include <stdint.h>
#include "globaldefine.h"

typedef struct {
	__IO uint32_t CR;			// Offset 0x00
	__IO uint32_t PLLCFGR;		// Offset 0x04
	__IO uint32_t CFGR;			// Offset 0x08
	__IO uint32_t CIR;			// Offset 0x0C
	__IO uint32_t AHB1RSTR;		// Offset 0x10
	__IO uint32_t AHB2RSTR;		// Offset 0x14
	uint32_t RESERVADO0;		// Offset 0x18
	__IO uint32_t APB1RSTR;		// Offset 0x1C
	__IO uint32_t APB2RSTR;		// Offset 0x20
	uint32_t RESERVADO1[3];		// Offset 0x24-0x2C
	__IO uint32_t AHB1ENR;		// Offset 0x30
	__IO uint32_t AHB2ENR;		// Offset 0x34
	uint32_t RESERVADO2[2]; 	// Ofsset 0x38-0x3C
	__IO uint32_t APB1ENR;		// Ofsset 0x40
	__IO uint32_t APB2ENR;		// Ofsset 0x44
	uint32_t RESERVADO3[2]; 	// Ofsset 0x48-0x4C
	__IO uint32_t AHB1LPENR; 	// Offset 0x50
	__IO uint32_t AHB2LPENR; 	// Offset 0x54
	uint32_t RESERVADO4[2]; 	// Ofsset 0x58-0x5C
	__IO uint32_t APB1LPENR;	// Offset 0x60
	__IO uint32_t APB2LPENR;	// Offset 0x64
	uint32_t RESERVADO5[2]; 	// Ofsset 0x68-0x6C
	__IO uint32_t BDCR;			// Offset 0x70
	__IO uint32_t CSR;			// Offset 0x74
	uint32_t RESERVADO6[2]; 	// Ofsset 0x78-0x7C
	__IO uint32_t SSCGR;		// Offset 0x80
	__IO uint32_t PLLI2SCFGR;	// Offset 0x84
	__IO uint32_t DCKCFGR;		// Offset 0x8C


} RCC_t;

#define RCC ((RCC_t *)(RCC_BASE_ADDRESS))

#endif // RCC_H
