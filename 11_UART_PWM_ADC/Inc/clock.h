#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>
#include "nucleof401re.h"

#define RCC_PLLCFGR_PLLM_Pos   ( 0U )
#define RCC_PLLCFGR_PLLN_Pos   ( 6U )
#define RCC_PLLCFGR_PLLP_Pos   ( 16U )
#define RCC_PLLCFGR_PLLQ_Pos   ( 24U )
#define RCC_PLLCFGR_PLLSRC_Pos ( 22U )

#define PLLM_DIV16             ( 16U  << RCC_PLLCFGR_PLLM_Pos )   // 0x00000010
#define PLLN_MUL168            ( 168U << RCC_PLLCFGR_PLLN_Pos )   // 0x00005400
#define PLLP_DIV2              ( 0U   << RCC_PLLCFGR_PLLP_Pos )   // 0x00040000
#define PLLQ_DIV3              ( 3U   << RCC_PLLCFGR_PLLQ_Pos )   // 0x00000003
#define PLL_SRC_HSI            ( 1U   << RCC_PLLCFGR_PLLSRC_Pos ) // 0x00400000

void SystemClock_Config( void );

#endif // CLOCK_H