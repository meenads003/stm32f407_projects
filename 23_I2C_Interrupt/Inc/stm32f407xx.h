#ifndef STM32F407XX_H_
#define STM32F407XX_H_

#include <stdint.h>

#define __vo volatile

/******** RCC ********/
#define RCC_BASE            0x40023800

#define RCC_AHB1ENR         (*(__vo uint32_t*)(RCC_BASE + 0x30))
#define RCC_APB1ENR         (*(__vo uint32_t*)(RCC_BASE + 0x40))

/******** GPIOB ********/
#define GPIOB_BASE          0x40020400

#define GPIOB_MODER         (*(__vo uint32_t*)(GPIOB_BASE + 0x00))
#define GPIOB_OTYPER        (*(__vo uint32_t*)(GPIOB_BASE + 0x04))
#define GPIOB_OSPEEDR       (*(__vo uint32_t*)(GPIOB_BASE + 0x08))
#define GPIOB_PUPDR         (*(__vo uint32_t*)(GPIOB_BASE + 0x0C))
#define GPIOB_AFRH          (*(__vo uint32_t*)(GPIOB_BASE + 0x24))

/******** I2C1 ********/
#define I2C1_BASE           0x40005400

#define I2C1_CR1            (*(__vo uint32_t*)(I2C1_BASE + 0x00))
#define I2C1_CR2            (*(__vo uint32_t*)(I2C1_BASE + 0x04))
#define I2C1_DR             (*(__vo uint32_t*)(I2C1_BASE + 0x10))
#define I2C1_SR1            (*(__vo uint32_t*)(I2C1_BASE + 0x14))
#define I2C1_SR2            (*(__vo uint32_t*)(I2C1_BASE + 0x18))
#define I2C1_CCR            (*(__vo uint32_t*)(I2C1_BASE + 0x1C))
#define I2C1_TRISE          (*(__vo uint32_t*)(I2C1_BASE + 0x20))

/******** NVIC ********/
#define NVIC_ISER0          (*(__vo uint32_t*)0xE000E100)

#endif
