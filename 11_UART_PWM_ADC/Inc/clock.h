#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>
#include "nucleof401re.h"

#define RCC_PLLCFGR_PLLM_Pos   ( 0U )
#define RCC_PLLCFGR_PLLN_Pos   ( 6U )
#define RCC_PLLCFGR_PLLP_Pos   ( 16U )
#define RCC_PLLCFGR_PLLSRC_Pos ( 22U )
#define PLLM_DIV16             ( 16U  << RCC_PLLCFGR_PLLM_Pos )
#define PLLN_MUL336            ( 336U << RCC_PLLCFGR_PLLN_Pos )
#define PLLP_DIV4              ( 4U   << RCC_PLLCFGR_PLLP_Pos )
#define PLL_SRC_HSI            ( RCC_PLLCFGR_PLLSRC_Pos )

extern void SR_Init_Clock( void );

#endif // CLOCK_H