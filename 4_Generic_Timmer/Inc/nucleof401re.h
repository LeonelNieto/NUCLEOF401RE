#ifndef NUCLEOF401RE_H
#define NUCLEOF401RE_H

#include <stdint.h>
#include "globaldefine.h"

// ###################################################################//
//                              EXTI                                  //
// ###################################################################//
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


// ###################################################################//
//                              GPIO                                  //
// ###################################################################//
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
#define GPIOB ((GPIO_t *)(GPIOB_BASE_ADDRESS))
#define GPIOC ((GPIO_t *)(GPIOC_BASE_ADDRESS))


// ###################################################################//
//                              IRQn                                  //
// ###################################################################//
typedef enum IRQn
{
/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
    NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
    MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
    BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
    UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
    SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
    DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
    PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
    SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
    WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
    PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
    TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
    RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
    FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
    RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
    EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
    EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
    EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
    EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
    EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
    DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
    DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
    DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
    DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
    DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
    DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
    DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
    ADC_IRQn                    = 18,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
    CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupt                                                 */
    CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupt                                                */
    CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                                */
    CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                                */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
    TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
    TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
    TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
    TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
    TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
    TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
    TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
    I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
    I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
    I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */
    I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */  
    SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
    SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
    USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
    USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
    USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                           */
    EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
    RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */    
    TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
    TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
    TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
    TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                                    */
    DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                            */
    FSMC_IRQn                   = 48,     /*!< FSMC global Interrupt                                             */
    SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                             */
    TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
    SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
    UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                            */
    UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                            */
    TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
    TIM7_IRQn                   = 55,     /*!< TIM7 global interrupt                                             */
    DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global Interrupt                                    */
    DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global Interrupt                                    */
    DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global Interrupt                                    */
    DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global Interrupt                                    */
    DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global Interrupt                                    */
    ETH_IRQn                    = 61,     /*!< Ethernet global Interrupt                                         */
    ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line Interrupt                       */
    CAN2_TX_IRQn                = 63,     /*!< CAN2 TX Interrupt                                                 */
    CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0 Interrupt                                                */
    CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1 Interrupt                                                */
    CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE Interrupt                                                */
    OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                       */
    DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
    DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
    DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
    USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                           */ 
    I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
    I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
    OTG_HS_EP1_OUT_IRQn         = 74,     /*!< USB OTG HS End Point 1 Out global interrupt                       */
    OTG_HS_EP1_IN_IRQn          = 75,     /*!< USB OTG HS End Point 1 In global interrupt                        */
    OTG_HS_WKUP_IRQn            = 76,     /*!< USB OTG HS Wakeup through EXTI interrupt                          */
    OTG_HS_IRQn                 = 77,     /*!< USB OTG HS global interrupt                                       */
    DCMI_IRQn                   = 78,     /*!< DCMI global interrupt                                             */
    CRYP_IRQn                   = 79,     /*!< CRYP crypto global interrupt                                      */
    HASH_RNG_IRQn               = 80,      /*!< Hash and Rng global interrupt                                     */
    FPU_IRQn                    = 81      /*!< FPU global interrupt                                              */
} IRQn_t;


// ###################################################################//
//                              NVIC                                  //
// ###################################################################//
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


// ###################################################################//
//                              RCC                                   //
// ###################################################################//
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

// ###################################################################//
//                            SYSCFG                                  //
// ###################################################################//
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

typedef struct 
{
    __IO uint32_t CSR;              // Offset 0x00 Control and Status Register
    __IO uint32_t RVR;              // Offset 0x04 Reload Value Register
    __IO uint32_t CVR;              // Offset 0x08 Current Value Register
    __I  uint32_t CALIB;            // Offset 0x08 Calibration Value Register
} SysTick_t;
#define SysTick ((SysTick_t *)(SYSTICK_BASE_ADDRESS))


#endif //NUCLEOF401RE_H