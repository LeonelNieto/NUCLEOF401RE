#ifndef NUCLEOF401RE_H
#define NUCLEOF401RE_H

#include <stdint.h>
#include <stdbool.h>

#define __IO volatile                        // Volatile Read and Write
#define __I  volatile                        // Volatile only read
#define __O volatile                         // volatile write only

// ################################################################# //
//                                RCC                                //
// ################################################################# //
#define RCC_BASE_ADDRESS                        ((uint32_t)0x40023800)
#define RCC_CR_HSION                            ((uint32_t)0x00000001)
#define RCC_CR_HSIRDY                           ((uint32_t)0x00000002)
#define RCC_CR_HSEON                            ((uint32_t)0x00010000)
#define RCC_CR_PLLRDY                           ((uint32_t)0x02000000)
#define RCC_CR_PLLON                            ((uint32_t)0x01000000)
#define RCC_CFGR_SW_HSI                         ((uint32_t)0x00000000)
#define RCC_CFGR_SW_HSE                         ((uint32_t)0x00000001)
#define RCC_CFGR_SW_PLL                         ((uint32_t)0x00000002)
#define RCC_CFGR_SW_NOTALLOW                    ((uint32_t)0x00000003)
#define RCC_CFGR_HPRE_DIV1                      ((uint32_t)0x00000000)
#define RCC_CFGR_HPRE_DIV2                      ((uint32_t)0x00000080)
#define RCC_CFGR_HPRE_DIV4                      ((uint32_t)0x00000090)
#define RCC_CFGR_HPRE_DIV8                      ((uint32_t)0x000000A0)
#define RCC_CFGR_HPRE_DIV16                     ((uint32_t)0x000000B0)
#define RCC_CFGR_HPRE_DIV64                     ((uint32_t)0x000000C0)
#define RCC_CFGR_HPRE_DIV128                    ((uint32_t)0x000000D0)
#define RCC_CFGR_HPRE_DIV256                    ((uint32_t)0x000000E0)
#define RCC_CFGR_HPRE_DIV512                    ((uint32_t)0x000000F0)
#define RCC_CFGR_PPRE1_DIV1                     ((uint32_t)0x00000000)
#define RCC_CFGR_PPRE1_DIV2                     ((uint32_t)0x00001000)
#define RCC_CFGR_PPRE1_DIV4                     ((uint32_t)0x00001400)
#define RCC_CFGR_PPRE1_DIV8                     ((uint32_t)0x00001800)
#define RCC_CFGR_PPRE1_DIV16                    ((uint32_t)0x00001C00)
#define RCC_CFGR_PPRE2_DIV1                     ((uint32_t)0x00000000)
#define RCC_CFGR_SW                             ((uint32_t)0x00000003)
#define RCC_CFGR_SW_PLL                         ((uint32_t)0x00000002)
#define RCC_CFGR_SWS_PLL                        ((uint32_t)0x00000008)
#define RCC_AHB1ENR_GPIOA_EN	                ((uint32_t)0x00000001)
#define RCC_AHB1ENR_GPIOB_EN                    ((uint32_t)0x00000002)
#define RCC_AHB1ENR_GPIOC_EN                    ((uint32_t)0x00000004)
#define RCC_AHB1ENR_GPIOD_EN                    ((uint32_t)0x00000008)
#define RCC_AHB1ENR_GPIOE_EN                    ((uint32_t)0x00000010)
#define RCC_AHB1ENR_GPIOH_EN                    ((uint32_t)0x00000080)
#define RCC_AHB1ENR_CRC_EN                      ((uint32_t)0x00001000)
#define RCC_AHB1ENR_DMA1_EN                     ((uint32_t)0x00020000)
#define RCC_AHB1ENR_DMA2_EN                     ((uint32_t)0x00040000)
#define RCC_APB1ENR_TIME2EN                     ((uint32_t)0x00000001)
#define RCC_APB1ENR_TIME3EN                     ((uint32_t)0x00000002)
#define RCC_APB1ENR_USART2EN                    ((uint32_t)0x00020000)
#define RCC_APB2ENR_USART6EN                    ((uint32_t)0x00000020)
#define RCC_APB2ENR_USART1EN                    ((uint32_t)0x00000010)
#define RCC_APB2ENR_TIM1EN_ClockDisable         ((uint32_t)0x00000000)
#define RCC_APB2ENR_TIM1EN_ClockEnabled         ((uint32_t)0x00000001)
#define RCC_APB2ENR_USART1_ClockEnabled         ((uint32_t)0x00000010)
#define RCC_APB2ENR_USART6_ClockEnabled         ((uint32_t)0x00000020)
#define RCC_APB2ENR_ADC1_ClockEnabled           ((uint32_t)0x00000100)
#define RCC_APB2ENR_SDOIOEN_ClockEnabled        ((uint32_t)0x00000800)
#define RCC_APB2ENR_SPI1EN_ClockEnabled         ((uint32_t)0x00001000)
#define RCC_APB2ENR_SPI4EN_ClockEnabled         ((uint32_t)0x00002000)
#define RCC_APB2ENR_SYSCFGEN_ClockEnabled       ((uint32_t)0x00004000)
#define RCC_APB2ENR_TIM9EN_ClockEnabled         ((uint32_t)0x00010000)
#define RCC_APB2ENR_TIM10EN_ClockEnabled        ((uint32_t)0x00020000)
#define RCC_APB2ENR_TIM11EN_ClockEnabled        ((uint32_t)0x00040000)

// ################################################################# //
//                                     GPIO                          //
// ################################################################# //
#define GPIOA_BASE_ADDRESS                      ((uint32_t)0x40020000)
#define GPIOB_BASE_ADDRESS                      ((uint32_t)0x40020400)
#define GPIOC_BASE_ADDRESS                      ((uint32_t)0x40020800)
#define GPIOD_BASE_ADDRESS                      ((uint32_t)0x40020C00)
#define GPIOE_BASE_ADDRESS                      ((uint32_t)0x40021000)
#define GPIOH_BASE_ADDRESS                      ((uint32_t)0x40021C00)
//                                     MODER                         //
#define GPIO_MODER_INPUT                        ((uint32_t)0x00000000)
#define GPIO_MODER_00_OUTPUT                    ((uint32_t)0x00000001)
#define GPIO_MODER_00_ALFM                      ((uint32_t)0x00000002)
#define GPIO_MODER_00_ANALOG                    ((uint32_t)0x00000003)
#define GPIO_MODER_01_OUTPUT                    ((uint32_t)0x00000004)
#define GPIO_MODER_01_ALFM                      ((uint32_t)0x00000008)
#define GPIO_MODER_01_ANALOG                    ((uint32_t)0x0000000C)
#define GPIO_MODER_02_OUTPUT                    ((uint32_t)0x00000010)
#define GPIO_MODER_02_ALFM                      ((uint32_t)0x00000020)
#define GPIO_MODER_02_ANALOG                    ((uint32_t)0x00000030)
#define GPIO_MODER_03_OUTPUT                    ((uint32_t)0x00000040)
#define GPIO_MODER_03_ALFM                      ((uint32_t)0x00000080)
#define GPIO_MODER_03_ANALOG                    ((uint32_t)0x000000C0)
#define GPIO_MODER_04_OUTPUT                    ((uint32_t)0x00000100)
#define GPIO_MODER_04_ALFM                      ((uint32_t)0x00000200)
#define GPIO_MODER_04_ANALOG                    ((uint32_t)0x00000300)
#define GPIO_MODER_05_OUTPUT                    ((uint32_t)0x00000400)
#define GPIO_MODER_05_ALFM                      ((uint32_t)0x00000800)
#define GPIO_MODER_05_ANALOG                    ((uint32_t)0x00000C00)
#define GPIO_MODER_06_OUTPUT                    ((uint32_t)0x00001000)
#define GPIO_MODER_06_ALFM                      ((uint32_t)0x00002000)
#define GPIO_MODER_06_ANALOG                    ((uint32_t)0x00003000)
#define GPIO_MODER_07_OUTPUT                    ((uint32_t)0x00004000)
#define GPIO_MODER_07_ALFM                      ((uint32_t)0x00008000)
#define GPIO_MODER_07_ANALOG                    ((uint32_t)0x0000C000)
#define GPIO_MODER_08_OUTPUT                    ((uint32_t)0x00010000)
#define GPIO_MODER_08_ALFM                      ((uint32_t)0x00020000)
#define GPIO_MODER_08_ANALOG                    ((uint32_t)0x00030000)
#define GPIO_MODER_09_OUTPUT                    ((uint32_t)0x00040000)
#define GPIO_MODER_09_ALFM                      ((uint32_t)0x00080000)
#define GPIO_MODER_09_ANALOG                    ((uint32_t)0x000C0000)
#define GPIO_MODER_10_OUTPUT                    ((uint32_t)0x00100000)
#define GPIO_MODER_10_ALFM                      ((uint32_t)0x00200000)
#define GPIO_MODER_10_ANALOG                    ((uint32_t)0x00300000)
#define GPIO_MODER_11_OUTPUT                    ((uint32_t)0x00400000)
#define GPIO_MODER_11_ALFM                      ((uint32_t)0x00800000)
#define GPIO_MODER_11_ANALOG                    ((uint32_t)0x00C00000)
#define GPIO_MODER_12_OUTPUT                    ((uint32_t)0x01000000)
#define GPIO_MODER_12_ALFM                      ((uint32_t)0x02000000)
#define GPIO_MODER_12_ANALOG                    ((uint32_t)0x03000000)
#define GPIO_MODER_13_OUTPUT                    ((uint32_t)0x04000000)
#define GPIO_MODER_13_ALFM                      ((uint32_t)0x08000000)
#define GPIO_MODER_13_ANALOG                    ((uint32_t)0x0C000000)
#define GPIO_MODER_14_OUTPUT                    ((uint32_t)0x10000000)
#define GPIO_MODER_14_ALFM                      ((uint32_t)0x20000000)
#define GPIO_MODER_14_ANALOG                    ((uint32_t)0x30000000)
#define GPIO_MODER_15_OUTPUT                    ((uint32_t)0x40000000)
#define GPIO_MODER_15_ALFM                      ((uint32_t)0x80000000)
#define GPIO_MODER_15_ANALOG                    ((uint32_t)0xC0000000)

//                                     PUPDR                         //
#define GPIO_PUPDR_NO_PUPD                      ((uint32_t)0x00000000)
#define GPIO_PUPDR_00_PULL_UP                   ((uint32_t)0x00000001)
#define GPIO_PUPDR_00_PULL_DOWN                 ((uint32_t)0x00000002)
#define GPIO_PUPDR_00_PULL_RESERVED             ((uint32_t)0x00000003)    
#define GPIO_PUPDR_01_PULL_UP                   ((uint32_t)0x00000004)
#define GPIO_PUPDR_01_PULL_DOWN                 ((uint32_t)0x00000008)
#define GPIO_PUPDR_01_PULL_RESERVED             ((uint32_t)0x0000000C)
#define GPIO_PUPDR_02_PULL_UP                   ((uint32_t)0x00000010)
#define GPIO_PUPDR_02_PULL_DOWN                 ((uint32_t)0x00000020)
#define GPIO_PUPDR_02_PULL_RESERVED             ((uint32_t)0x00000030)
#define GPIO_PUPDR_03_PULL_UP                   ((uint32_t)0x00000040)
#define GPIO_PUPDR_03_PULL_DOWN                 ((uint32_t)0x00000080)
#define GPIO_PUPDR_03_PULL_RESERVED             ((uint32_t)0x000000C0)
#define GPIO_PUPDR_04_PULL_UP                   ((uint32_t)0x00000100)
#define GPIO_PUPDR_04_PULL_DOWN                 ((uint32_t)0x00000200)
#define GPIO_PUPDR_04_PULL_RESERVED             ((uint32_t)0x00000300)
#define GPIO_PUPDR_05_PULL_UP                   ((uint32_t)0x00000400)
#define GPIO_PUPDR_05_PULL_DOWN                 ((uint32_t)0x00000800)
#define GPIO_PUPDR_05_PULL_RESERVED             ((uint32_t)0x00000C00)
#define GPIO_PUPDR_06_PULL_UP                   ((uint32_t)0x00001000)
#define GPIO_PUPDR_06_PULL_DOWN                 ((uint32_t)0x00002000)
#define GPIO_PUPDR_06_PULL_RESERVED             ((uint32_t)0x00003000)
#define GPIO_PUPDR_07_PULL_UP                   ((uint32_t)0x00004000)
#define GPIO_PUPDR_07_PULL_DOWN                 ((uint32_t)0x00008000)
#define GPIO_PUPDR_07_PULL_RESERVED             ((uint32_t)0x0000C000)
#define GPIO_PUPDR_08_PULL_UP                   ((uint32_t)0x00010000)
#define GPIO_PUPDR_08_PULL_DOWN                 ((uint32_t)0x00020000)
#define GPIO_PUPDR_08_PULL_RESERVED             ((uint32_t)0x00030000)
#define GPIO_PUPDR_09_PULL_UP                   ((uint32_t)0x00040000)
#define GPIO_PUPDR_09_PULL_DOWN                 ((uint32_t)0x00080000)
#define GPIO_PUPDR_09_PULL_RESERVED             ((uint32_t)0x000C0000)
#define GPIO_PUPDR_10_PULL_UP                   ((uint32_t)0x00100000)
#define GPIO_PUPDR_10_PULL_DOWN                 ((uint32_t)0x00200000)
#define GPIO_PUPDR_10_PULL_RESERVED             ((uint32_t)0x00300000)
#define GPIO_PUPDR_11_PULL_UP                   ((uint32_t)0x00400000)
#define GPIO_PUPDR_11_PULL_DOWN                 ((uint32_t)0x00800000)
#define GPIO_PUPDR_11_PULL_RESERVED             ((uint32_t)0x00C00000)
#define GPIO_PUPDR_12_PULL_UP                   ((uint32_t)0x01000000)
#define GPIO_PUPDR_12_PULL_DOWN                 ((uint32_t)0x02000000)
#define GPIO_PUPDR_12_PULL_RESERVED             ((uint32_t)0x03000000)
#define GPIO_PUPDR_13_PULL_UP                   ((uint32_t)0x04000000)
#define GPIO_PUPDR_13_PULL_DOWN                 ((uint32_t)0x08000000)
#define GPIO_PUPDR_13_PULL_RESERVED             ((uint32_t)0x0C000000)      
#define GPIO_PUPDR_14_PULL_UP                   ((uint32_t)0x10000000)
#define GPIO_PUPDR_14_PULL_DOWN                 ((uint32_t)0x20000000)
#define GPIO_PUPDR_14_PULL_RESERVED             ((uint32_t)0x30000000)
#define GPIO_PUPDR_15_PULL_UP                   ((uint32_t)0x40000000)
#define GPIO_PUPDR_15_PULL_DOWN                 ((uint32_t)0x80000000)
#define GPIO_PUPDR_15_PULL_RESERVED             ((uint32_t)0xC0000000)

//                                     ODER                          //
#define GPIO_ODR_00_ON                          ((uint32_t)0x00000001)
#define GPIO_ODR_01_ON                          ((uint32_t)0x00000002)
#define GPIO_ODR_02_ON                          ((uint32_t)0x00000004)
#define GPIO_ODR_03_ON                          ((uint32_t)0x00000008)
#define GPIO_ODR_04_ON                          ((uint32_t)0x00000010)
#define GPIO_ODR_05_ON                          ((uint32_t)0x00000020)
#define GPIO_ODR_06_ON                          ((uint32_t)0x00000040)
#define GPIO_ODR_07_ON                          ((uint32_t)0x00000080)
#define GPIO_ODR_08_ON                          ((uint32_t)0x00000100)
#define GPIO_ODR_09_ON                          ((uint32_t)0x00000200)
#define GPIO_ODR_10_ON                          ((uint32_t)0x00000400)
#define GPIO_ODR_11_ON                          ((uint32_t)0x00000800)
#define GPIO_ODR_12_ON                          ((uint32_t)0x00001000)
#define GPIO_ODR_13_ON                          ((uint32_t)0x00002000)
#define GPIO_ODR_14_ON                          ((uint32_t)0x00004000)
#define GPIO_ODR_15_ON                          ((uint32_t)0x00008000)
#define GPIO_BSRR_BS13                          ((uint32_t)0x00002000)
#define GPIO_BSRR_BR13                          ((uint32_t)0x20000000)
//                                  AFRL                             //
#define GPIO_AFRL_AFRL2_AF7                     ((uint32_t)0x00000700)
#define GPIO_AFRL_AFRL3_AF7                     ((uint32_t)0x00007000)
#define GPIO_AFRL_AFRL6_AF2                     ((uint32_t)0x02000000)

// ################################################################# //
//                                EXTI                               //
// ################################################################# //
#define EXTI_BASE_ADDRESS                       ((uint32_t)0x40013C00)
#define EXTI_IMR_MR13_ISNOTMASKED               ((uint32_t)0x00002000)
#define EXTI_RTSR_TR13_RISING_TRIGGER_EN        ((uint32_t)0x00002000)
#define EXTI_FTSR_TR13_FALLING_TRIGGER_EN       ((uint32_t)0x00002000)
#define EXTI_PR_PR13_TRIGGER_OCCURRED           ((uint32_t)0x00002000)

// ################################################################# //
//                                SYSCFG                             //
// ################################################################# //
#define SYSCFG_BASE_ADDRESS                     ((uint32_t)0x40013800)
#define SYSCFG_EXTICR4_PC13                     ((uint32_t)0x00000020)

// ################################################################# //
//                                NVIC                               //
// ################################################################# //
#define NVIC_BASE_ADDRESS                       ((uint32_t)0xE000E100)
#define NVIC_PRIORITY_4                         ((uint8_t)0x40)
#define NVIC_ISER_ENABLE_EXTI15_10_IRQn         ((uint32_t)0x00800000)

// ################################################################# //
//                              SysTick                              //
// ################################################################# //
#define SYSTICK_BASE_ADDRESS                    ((uint32_t)0xE000E010)
#define SYSTICK_RVR_VAL                         16000
#define SYSTICK_CSR_ENABLE                      (1U <<  0)
#define SYSTICK_CSR_CLKSRC_INTERNAL             (1U <<  2)
#define SYSTICK_CSR_COUNTFLAG                   (1U << 16)

// ################################################################# //
//                                TIM                                //
// ################################################################# //
#define TIM1_BASE_ADDRESS                       ((uint32_t)0x40010000)
#define TIM2_BASE_ADDRESS                       ((uint32_t)0x40000000)
#define TIM3_BASE_ADDRESS                       ((uint32_t)0x40000400)
#define TIM4_BASE_ADDRESS                       ((uint32_t)0x40000800)
#define TIM5_BASE_ADDRESS                       ((uint32_t)0x40000C00)
#define TIM9_BASE_ADDRESS                       ((uint32_t)0x40014000)
#define TIM10_BASE_ADDRESS                      ((uint32_t)0x40014400)
#define TIM11_BASE_ADDRESS                      ((uint32_t)0x40014800)
#define TIMx_CR1_CEN                            ((uint32_t)0x00000001)
#define TIMx_SR_UIF                             ((uint32_t)0x00000001)
#define TIMx_DIER_UIE                           ((uint32_t)0x00000001)
#define TIMx_CCMR1_OC1M_PWM_Mode_1              ((uint32_t)0x00000060)
#define TIMx_CCER_CC1E_ON                       ((uint32_t)0x00000001)

// ################################################################# //
//                                 USART                             //
// ################################################################# //
#define USART1_BASE_ADDRESS                     ( ( uint32_t )0x40011000 )
#define USART2_BASE_ADDRESS                     ( ( uint32_t )0x40004400 )
#define USART6_BASE_ADDRESS                     ( ( uint32_t )0x40011400 )
#define USART_CR1_TE_EN                         ( 1U << 3 )
#define USART_CR1_RX_EN                         ( 1U << 2 )
#define USART_CR1_USART_EN                      ( ( uint32_t )0x00002000 )
#define USART_SR_TXE                            ( 1U << 7 )
#define USART_SR_RXNE                           ( 1U << 5 )

// ################################################################# //
//                                ADC1                               //
// ################################################################# //
#define ADC1_BASE_ADDRESS                       ((uint32_t)0x40012000)
#define ADC1_SQR3_SQ1_CH1                       ((uint32_t)0x00000001)
#define ADC1_SQR3_SQ2_CH16                      ((uint32_t)0x00000200)
#define ADC1_SQR1_LENGTH_1CHANNEL               ((uint32_t)0x00000000)
#define ADC1_SQR1_LENGTH_2CHANNELS              ((uint32_t)0x00100000)
#define ADC1_CR2_ADON_EN                        ((uint32_t)0x00000001)
#define ADC1_CR2_SWSTART_EN                     ((uint32_t)0x40000000)
#define ADC1_SR_EOC_Finish                      ((uint32_t)0x00000002)
#define ADC1_CR2_CONT_CONTMODE                  ((uint32_t)0x00000002)

// ################################################################# //
//                                 FLASH                             //
// ################################################################# //
#define FLASH_BASE                              (( uint32_t ) 0x40023C00 )
#define FLASH_ACR_2WS                           (( uint32_t ) 0x00000002 )
#define FLASH_ACR_PRFTEN                        (( uint32_t ) 0x00000100 )
#define FLASH_ACR_ICEN                          (( uint32_t ) 0x00000200 )
#define FLASH_ACR_DCEN                          (( uint32_t ) 0x00000400 )

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

// ###################################################################//
//                            SYSTICK                                 //
// ###################################################################//
typedef struct 
{
    __IO uint32_t CSR;              // Offset 0x00 Control and Status Register
    __IO uint32_t RVR;              // Offset 0x04 Reload Value Register
    __IO uint32_t CVR;              // Offset 0x08 Current Value Register
    __I  uint32_t CALIB;            // Offset 0x08 Calibration Value Register
} SysTick_t;

#define SysTick ((SysTick_t *)(SYSTICK_BASE_ADDRESS))

// ###################################################################//
//                                TIM                                 //
// ###################################################################//
typedef struct 
{
    __IO uint32_t CR1;             // Offset 0x00 control register 1
    __IO uint32_t CR2;             // Offset 0x04 control register 2
    __IO uint32_t SMCR;            // Offset 0x08 slave mode control register
    __IO uint32_t DIER;            // Offset 0x0C DMA/Interrupt enable register
    __IO uint32_t SR;              // Offset 0x10 status register
    __IO uint32_t EGR;             // Offset 0x14 event generation register
    __IO uint32_t CCMR1;           // Offset 0x18 capture/compare mode register 1
    __IO uint32_t CCMR2;           // Offset 0x1C capture/compare mode register 2
    __IO uint32_t CCER;            // Offset 0x20 capture/compare enable register
    __IO uint32_t CNT;             // Offset 0x24 counter
    __IO uint32_t PSC;             // Offset 0x28 prescaler
    __IO uint32_t ARR;             // Offset 0x2C auto-reload register
         uint32_t RESERVADO0;      // Offset 0x30
    __IO uint32_t CCR1;            // Offset 0x34 capture/compare register 1
    __IO uint32_t CCR2;            // Offset 0x38 capture/compare register 2
    __IO uint32_t CCR3;            // Offset 0x3C capture/compare register 3
    __IO uint32_t CCR4;            // Offset 0x40 capture/compare register 4
         uint32_t RESERVADO1;      // Offset 0x44
    __IO uint32_t DCR;             // Offset 0x48 control register
    __IO uint32_t DMAR;            // Offset 0x4C address for full transfer
    __IO uint32_t OR;              // Offset 0x50 option register
} TIM_t;

#define TIM1  ((TIM_t *)(TIM1_BASE_ADDRESS))
#define TIM2  ((TIM_t *)(TIM2_BASE_ADDRESS))
#define TIM3  ((TIM_t *)(TIM3_BASE_ADDRESS))
#define TIM4  ((TIM_t *)(TIM4_BASE_ADDRESS))
#define TIM5  ((TIM_t *)(TIM5_BASE_ADDRESS))
#define TIM9  ((TIM_t *)(TIM9_BASE_ADDRESS))
#define TIM10 ((TIM_t *)(TIM10_BASE_ADDRESS))
#define TIM11 ((TIM_t *)(TIM11_BASE_ADDRESS))

// ###################################################################//
//                                USART                               //
// ###################################################################//
typedef struct
{
    __IO uint32_t SR;                                                                // Offset 0x00 Status register 
    __IO uint32_t DR;                                                                // Offset 0x04 Data register 
    __IO uint32_t BRR;                                                               // Offset 0x08 Baud rate register 
    __IO uint32_t CR1;                                                               // Offset 0x0C Control register 1 
    __IO uint32_t CR2;                                                               // Offset 0x10 Control register 2 
    __IO uint32_t CR3;                                                               // Offset 0x14 Control register 3 
    __IO uint32_t GPTR;                                                              // Offset 0x18 Guard time and prescaler register 
} USART_t;
#define USART1 ( ( USART_t * )( USART1_BASE_ADDRESS ) )
#define USART2 ( ( USART_t * )( USART2_BASE_ADDRESS ) )
#define USART6 ( ( USART_t * )( USART6_BASE_ADDRESS ) )

// ###################################################################//
//                                ADC                                 //
// ###################################################################//
typedef struct
{
    __IO uint32_t SR;
    __IO uint32_t CR1;
    __IO uint32_t CR2;
    __IO uint32_t SMPR1;
    __IO uint32_t SMPR2;
    __IO uint32_t JOFR1;
    __IO uint32_t JOFR2;
    __IO uint32_t JOFR3;
    __IO uint32_t JOFR4;
    __IO uint32_t HTR;
    __IO uint32_t LTR;
    __IO uint32_t SQR1;
    __IO uint32_t SQR2;
    __IO uint32_t SQR3;
    __I  uint32_t JSQR;
    __I  uint32_t JDR1;
    __I  uint32_t JDR2;
    __I  uint32_t JDR3;
    __I  uint32_t JDR4;
    __I  uint32_t DR;
         uint32_t RESERV0[172];
    __IO uint32_t CCR;                  // Validate if this is the address 0x300
} ADC1_t;

#define ADC1 ( ( ADC1_t * )( ADC1_BASE_ADDRESS ) )

// ###################################################################//
//                              FLASH                                 //
// ###################################################################//

typedef struct
{
    __IO uint32_t ACR;
    __O  uint32_t KEYR;
    __O  uint32_t OPTKEYR;
    __IO uint32_t SR;
    __IO uint32_t CR;
    __IO uint32_t OPTCR;
} FLASH_t;

#define FLASH ( ( FLASH_t * )( FLASH_BASE ) )

#endif //NUCLEOF401RE_H
