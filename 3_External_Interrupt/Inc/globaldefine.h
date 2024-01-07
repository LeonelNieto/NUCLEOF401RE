#define __IO volatile

#define RCC_AHB1ENR_GPIOA_EN	    ((uint32_t)0x00000001)
#define RCC_BASE_ADDRESS            ((uint32_t)0x40023800)
#define RCC_AHB1ENR_GPIOB_EN        ((uint32_t)0x00000002)
#define RCC_AHB1ENR_GPIOC_EN        ((uint32_t)0x00000004)
#define RCC_AHB1ENR_GPIOD_EN        ((uint32_t)0x00000008)
#define RCC_AHB1ENR_GPIOE_EN        ((uint32_t)0x00000010)
#define RCC_AHB1ENR_GPIOH_EN        ((uint32_t)0x00000080)
#define RCC_AHB1ENR_CRC_EN          ((uint32_t)0x00001000)
#define RCC_AHB1ENR_DMA1_EN         ((uint32_t)0x00020000)
#define RCC_AHB1ENR_DMA2_EN         ((uint32_t)0x00040000)

// ################################################ //
//                    GPIO                          //
// ################################################ //
#define GPIOB_BASE_ADDRESS          ((uint32_t)0x40020400)
#define GPIOA_BASE_ADDRESS          ((uint32_t)0x40020000)
#define GPIOC_BASE_ADDRESS          ((uint32_t)0x40020800)
#define GPIOD_BASE_ADDRESS          ((uint32_t)0x40020C00)
#define GPIOE_BASE_ADDRESS          ((uint32_t)0x40021000)
#define GPIOH_BASE_ADDRESS          ((uint32_t)0x40021C00)
//                    MODER                         //
#define GPIO_MODER_INPUT            ((uint32_t)0x00000000)
#define GPIO_MODER_00_OUTPUT        ((uint32_t)0x00000001)
#define GPIO_MODER_00_ALFM          ((uint32_t)0x00000002)
#define GPIO_MODER_00_ANALOG        ((uint32_t)0x00000003)
#define GPIO_MODER_01_OUTPUT        ((uint32_t)0x00000004)
#define GPIO_MODER_01_ALFM          ((uint32_t)0x00000008)
#define GPIO_MODER_01_ANALOG        ((uint32_t)0x0000000C)
#define GPIO_MODER_02_OUTPUT        ((uint32_t)0x00000010)
#define GPIO_MODER_02_ALFM          ((uint32_t)0x00000020)
#define GPIO_MODER_02_ANALOG        ((uint32_t)0x00000030)
#define GPIO_MODER_03_OUTPUT        ((uint32_t)0x00000040)
#define GPIO_MODER_03_ALFM          ((uint32_t)0x00000080)
#define GPIO_MODER_03_ANALOG        ((uint32_t)0x000000C0)
#define GPIO_MODER_04_OUTPUT        ((uint32_t)0x00000100)
#define GPIO_MODER_04_ALFM          ((uint32_t)0x00000200)
#define GPIO_MODER_04_ANALOG        ((uint32_t)0x00000300)
#define GPIO_MODER_05_OUTPUT        ((uint32_t)0x00000400)
#define GPIO_MODER_05_ALFM          ((uint32_t)0x00000800)
#define GPIO_MODER_05_ANALOG        ((uint32_t)0x00000C00)
#define GPIO_MODER_06_OUTPUT        ((uint32_t)0x00001000)
#define GPIO_MODER_06_ALFM          ((uint32_t)0x00002000)
#define GPIO_MODER_06_ANALOG        ((uint32_t)0x00003000)
#define GPIO_MODER_07_OUTPUT        ((uint32_t)0x00004000)
#define GPIO_MODER_07_ALFM          ((uint32_t)0x00008000)
#define GPIO_MODER_07_ANALOG        ((uint32_t)0x0000C000)
#define GPIO_MODER_08_OUTPUT        ((uint32_t)0x00010000)
#define GPIO_MODER_08_ALFM          ((uint32_t)0x00020000)
#define GPIO_MODER_08_ANALOG        ((uint32_t)0x00030000)
#define GPIO_MODER_09_OUTPUT        ((uint32_t)0x00040000)
#define GPIO_MODER_09_ALFM          ((uint32_t)0x00080000)
#define GPIO_MODER_09_ANALOG        ((uint32_t)0x000C0000)
#define GPIO_MODER_10_OUTPUT        ((uint32_t)0x00100000)
#define GPIO_MODER_10_ALFM          ((uint32_t)0x00200000)
#define GPIO_MODER_10_ANALOG        ((uint32_t)0x00300000)
#define GPIO_MODER_11_OUTPUT        ((uint32_t)0x00400000)
#define GPIO_MODER_11_ALFM          ((uint32_t)0x00800000)
#define GPIO_MODER_11_ANALOG        ((uint32_t)0x00C00000)
#define GPIO_MODER_12_OUTPUT        ((uint32_t)0x01000000)
#define GPIO_MODER_12_ALFM          ((uint32_t)0x02000000)
#define GPIO_MODER_12_ANALOG        ((uint32_t)0x03000000)
#define GPIO_MODER_13_OUTPUT        ((uint32_t)0x04000000)
#define GPIO_MODER_13_ALFM          ((uint32_t)0x08000000)
#define GPIO_MODER_13_ANALOG        ((uint32_t)0x0C000000)
#define GPIO_MODER_14_OUTPUT        ((uint32_t)0x10000000)
#define GPIO_MODER_14_ALFM          ((uint32_t)0x20000000)
#define GPIO_MODER_14_ANALOG        ((uint32_t)0x30000000)
#define GPIO_MODER_15_OUTPUT        ((uint32_t)0x40000000)
#define GPIO_MODER_15_ALFM          ((uint32_t)0x80000000)
#define GPIO_MODER_15_ANALOG        ((uint32_t)0xC0000000)

//                    PUPDR                         //
#define GPIO_PUPDR_NO_PUPD          ((uint32_t)0x00000000)
#define GPIO_PUPDR_00_PULL_UP        ((uint32_t)0x00000001)
#define GPIO_PUPDR_00_PULL_DOWN      ((uint32_t)0x00000002)
#define GPIO_PUPDR_00_PULL_RESERVED  ((uint32_t)0x00000003)    
#define GPIO_PUPDR_01_PULL_UP        ((uint32_t)0x00000004)
#define GPIO_PUPDR_01_PULL_DOWN      ((uint32_t)0x00000008)
#define GPIO_PUPDR_01_PULL_RESERVED  ((uint32_t)0x0000000C)
#define GPIO_PUPDR_02_PULL_UP        ((uint32_t)0x00000010)
#define GPIO_PUPDR_02_PULL_DOWN      ((uint32_t)0x00000020)
#define GPIO_PUPDR_02_PULL_RESERVED  ((uint32_t)0x00000030)
#define GPIO_PUPDR_03_PULL_UP        ((uint32_t)0x00000040)
#define GPIO_PUPDR_03_PULL_DOWN      ((uint32_t)0x00000080)
#define GPIO_PUPDR_03_PULL_RESERVED  ((uint32_t)0x000000C0)
#define GPIO_PUPDR_04_PULL_UP        ((uint32_t)0x00000100)
#define GPIO_PUPDR_04_PULL_DOWN      ((uint32_t)0x00000200)
#define GPIO_PUPDR_04_PULL_RESERVED  ((uint32_t)0x00000300)
#define GPIO_PUPDR_05_PULL_UP        ((uint32_t)0x00000400)
#define GPIO_PUPDR_05_PULL_DOWN      ((uint32_t)0x00000800)
#define GPIO_PUPDR_05_PULL_RESERVED  ((uint32_t)0x00000C00)
#define GPIO_PUPDR_06_PULL_UP        ((uint32_t)0x00001000)
#define GPIO_PUPDR_06_PULL_DOWN      ((uint32_t)0x00002000)
#define GPIO_PUPDR_06_PULL_RESERVED  ((uint32_t)0x00003000)
#define GPIO_PUPDR_07_PULL_UP        ((uint32_t)0x00004000)
#define GPIO_PUPDR_07_PULL_DOWN      ((uint32_t)0x00008000)
#define GPIO_PUPDR_07_PULL_RESERVED  ((uint32_t)0x0000C000)
#define GPIO_PUPDR_08_PULL_UP        ((uint32_t)0x00010000)
#define GPIO_PUPDR_08_PULL_DOWN      ((uint32_t)0x00020000)
#define GPIO_PUPDR_08_PULL_RESERVED  ((uint32_t)0x00030000)
#define GPIO_PUPDR_09_PULL_UP        ((uint32_t)0x00040000)
#define GPIO_PUPDR_09_PULL_DOWN      ((uint32_t)0x00080000)
#define GPIO_PUPDR_09_PULL_RESERVED  ((uint32_t)0x000C0000)
#define GPIO_PUPDR_10_PULL_UP        ((uint32_t)0x00100000)
#define GPIO_PUPDR_10_PULL_DOWN      ((uint32_t)0x00200000)
#define GPIO_PUPDR_10_PULL_RESERVED  ((uint32_t)0x00300000)
#define GPIO_PUPDR_11_PULL_UP        ((uint32_t)0x00400000)
#define GPIO_PUPDR_11_PULL_DOWN      ((uint32_t)0x00800000)
#define GPIO_PUPDR_11_PULL_RESERVED  ((uint32_t)0x00C00000)
#define GPIO_PUPDR_12_PULL_UP        ((uint32_t)0x01000000)
#define GPIO_PUPDR_12_PULL_DOWN      ((uint32_t)0x02000000)
#define GPIO_PUPDR_12_PULL_RESERVED  ((uint32_t)0x03000000)
#define GPIO_PUPDR_13_PULL_UP        ((uint32_t)0x04000000)
#define GPIO_PUPDR_13_PULL_DOWN      ((uint32_t)0x08000000)
#define GPIO_PUPDR_13_PULL_RESERVED  ((uint32_t)0x0C000000)      
#define GPIO_PUPDR_14_PULL_UP        ((uint32_t)0x10000000)
#define GPIO_PUPDR_14_PULL_DOWN      ((uint32_t)0x20000000)
#define GPIO_PUPDR_14_PULL_RESERVED  ((uint32_t)0x30000000)
#define GPIO_PUPDR_15_PULL_UP        ((uint32_t)0x40000000)
#define GPIO_PUPDR_15_PULL_DOWN      ((uint32_t)0x80000000)
#define GPIO_PUPDR_15_PULL_RESERVED  ((uint32_t)0xC0000000)

//                    ODER                          //
#define GPIO_ODR_00_ON              ((uint32_t)0x000000001)
#define GPIO_ODR_01_ON              ((uint32_t)0x000000002)
#define GPIO_ODR_02_ON              ((uint32_t)0x000000004)
#define GPIO_ODR_03_ON              ((uint32_t)0x000000008)
#define GPIO_ODR_04_ON              ((uint32_t)0x000000010)
#define GPIO_ODR_05_ON              ((uint32_t)0x000000020)
#define GPIO_ODR_06_ON              ((uint32_t)0x000000040)
#define GPIO_ODR_07_ON              ((uint32_t)0x000000080)
#define GPIO_ODR_08_ON              ((uint32_t)0x000000100)
#define GPIO_ODR_09_ON              ((uint32_t)0x000000200)
#define GPIO_ODR_10_ON              ((uint32_t)0x000000400)
#define GPIO_ODR_11_ON              ((uint32_t)0x000000800)
#define GPIO_ODR_12_ON              ((uint32_t)0x000001000)
#define GPIO_ODR_13_ON              ((uint32_t)0x000002000)
#define GPIO_ODR_14_ON              ((uint32_t)0x000004000)
#define GPIO_ODR_15_ON              ((uint32_t)0x000008000)