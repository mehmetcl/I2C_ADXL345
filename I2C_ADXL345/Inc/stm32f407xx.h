/*
 * stm32f407xx.h
 *
 *  Created on: Mar 31, 2022
 *      Author: Admin
 */

//manual multiple inclusion guard, pragma once is non standart
#ifndef STM32F407XX_H_
#define STM32F407XX_H_

//#define static PRIVATE
#define PUBLIC

#define		DISABLE		0
#define		ENABLE		1
#define		RESET		DISABLE
#define		SET			ENABLE

//Makrolar = derleyici baslamadan once onislemcinin yaptigi text islemi
//Bus`larin temel adresleri
// APBx and AHBx Peripheral Base Addresses
#define		PERIPH_BASEADDR		0x40000000U
#define 	APB1_BASEADDR		PERIPH_BASEADDR
#define		APB2_BASEADDR		0x40010000U
#define		AHB1_BASEADDR		0x40020000U
#define		AHB2_BASEADDR		0x50000000U
#define		AHB3_BASEADDR		0x60000000U

// Base addresses of peripherals for APB1
#define		TIM2_BASEADDR		APB1_BASEADDR
#define		TIM3_BASEADDR		(APB1_BASEADDR + 0x400)
#define		TIM4_BASEADDR		(APB1_BASEADDR + 0x800)
#define		TIM5_BASEADDR		(APB1_BASEADDR + 0xC00)
#define		TIM6_BASEADDR		(APB1_BASEADDR + 0x1000)
#define		TIM7_BASEADDR		(APB1_BASEADDR + 0x1400)
#define		TIM12_BASEADDR		(APB1_BASEADDR + 0x1800)
#define		TIM13_BASEADDR		(APB1_BASEADDR + 0x1C00)
#define		TIM14_BASEADDR		(APB1_BASEADDR + 0x2000)

#define		RTC_BKP_BASEADDR	(APB1_BASEADDR + 0x2800)
#define		WWDG_BASEADDR		(APB1_BASEADDR + 0x2C00)
#define		IWDG_BASEADDR		(APB1_BASEADDR + 0x3000)
#define		I2S2EXT_BASEADDR	(APB1_BASEADDR + 0x3400)
#define		SPI2_BASEADDR		(APB1_BASEADDR + 0x3800)
#define		SPI3_BASEADDR	 	(APB1_BASEADDR + 0x3C00)
#define		I2S3EXT_BASEADDR	(APB1_BASEADDR + 0x4000)
#define		USART2_BASEADDR		(APB1_BASEADDR + 0x4400)
#define		USART3_BASEADDR		(APB1_BASEADDR + 0x4800)
#define		USART4_BASEADDR		(APB1_BASEADDR + 0x4C00)
#define		USART5_BASEADDR		(APB1_BASEADDR + 0x5000)
#define		I2C1_BASEADDR		(APB1_BASEADDR + 0x5400)
#define		I2C2_BASEADDR		(APB1_BASEADDR + 0x5800)
#define		I2C3_BASEADDR		(APB1_BASEADDR + 0x5C00)
#define		CAN1_BASEADDR		(APB1_BASEADDR + 0x6400)
#define		CAN2_BASEADDR		(APB1_BASEADDR + 0x6800)
#define		PWR_BASEADDR		(APB1_BASEADDR + 0x7000)
#define		DAC_BASEADDR		(APB1_BASEADDR + 0x7400)

// Base address of peripherals for APB2

#define		TIM1_BASEADDR		APB2_BASEADDR
#define		TIM8_BASEADDR		(APB2_BASEADDR + 0x400)
#define		USART1_BASEADDR		(APB2_BASEADDR + 0x1000)
#define		USART6_BASEADDR		(APB2_BASEADDR + 0x1400)
#define		ADC123_BASEADDR		(APB2_BASEADDR + 0x2000)
#define		SDIO_BASEADDR		(APB2_BASEADDR + 0x2C00)
#define		SPI1_BASEADDR		(APB2_BASEADDR + 0x3000)
#define		SYSCFG_BASEADDR		(APB2_BASEADDR + 0x3800)
#define		EXTI_BASEADDR		(APB2_BASEADDR + 0x3C00)
#define		TIM9_BASEADDR		(APB2_BASEADDR + 0x4000)
#define		TIMER10_BASEADDR	(APB2_BASEADDR + 0x4400)
#define		TIMER11_BASEADDR	(APB2_BASEADDR + 0x4800)


// Base address of peripherals for AHB1

#define		GPIOA_BASEADDR		AHB1_BASEADDR
#define		GPIOB_BASEADDR		(AHB1_BASEADDR + 0x400)
#define		GPIOC_BASEADDR		(AHB1_BASEADDR + 0x800)
#define		GPIOD_BASEADDR		(AHB1_BASEADDR + 0xC00)
#define		GPIOE_BASEADDR		(AHB1_BASEADDR + 0x1000)
#define		GPIOF_BASEADDR		(AHB1_BASEADDR + 0x1400)
#define		GPIOG_BASEADDR		(AHB1_BASEADDR + 0x1800)
#define		GPIOH_BASEADDR		(AHB1_BASEADDR + 0x1C00)
#define		GPIOI_BASEADDR		(AHB1_BASEADDR + 0x2000)
#define		CRC_BASEADDR		(AHB1_BASEADDR + 0x3000)
#define		RCC_BASEADDR		(AHB1_BASEADDR + 0x3800)
#define		FLASH_BASEADDR		(AHB1_BASEADDR + 0x3C00)
#define		BKPSRAM_BASEADDR	(AHB1_BASEADDR + 0x4000)

#define		DMA1_BASEADDR			(AHB1_BASEADDR + 0x6000)
#define		DMA2_BASEADDR			(AHB1_BASEADDR + 0x6400)
#define		ETHERNET1_BASEADDR		(AHB1_BASEADDR + 0x8000)
#define		ETHERNET2_BASEADDR		(AHB1_BASEADDR + 0x8400)
#define		ETHERNET3_BASEADDR		(AHB1_BASEADDR + 0x8800)
#define		ETHERNET4_BASEADDR		(AHB1_BASEADDR + 0x8C00)
#define		ETHERNET5_BASEADDR		(AHB1_BASEADDR + 0x9000)
#define		USB_OTG_HS_BASEADDR		(AHB1_BASEADDR + 0x40000) //HOCAYA SOR
#define		USB_OTG_FS_BASEADDR		(0x50000000U)



typedef struct{
	volatile uint32_t RCC_CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
			 uint32_t RESERVED0;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
			 uint32_t RESERVED1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RESERVED2;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
			 uint32_t RESERVED3[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	volatile uint32_t RESERVED4;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
		   	 uint32_t RESERVED5[2];
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
		     uint32_t RESERVED6[2];
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;
	//hocada yok
	volatile uint32_t RCC_PLLSAICFGR;
	volatile uint32_t RCC_DCKCFGR;


}RCC_RegDef_t;

typedef struct{
	volatile uint32_t MODER; // pin mode
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];  // AFR[0] ---> LOW AFR[1] ---> HIGH


}GPIO_RegDef_t;


#define		RCC			((RCC_RegDef_t *)RCC_BASEADDR)


#define		GPIOA		((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define		GPIOB		((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define		GPIOC		((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define		GPIOD		((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define		GPIOE		((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define		GPIOF		((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define		GPIOG		((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define		GPIOH		((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define		GPIOI		((GPIO_RegDef_t*)GPIOI_BASEADDR)

//functional macro
#define GPIOA_CLOCK_EN()	(RCC->AHB1ENR |= (1u<<0))
#define GPIOB_CLOCK_EN()	(RCC->AHB1ENR |= (1u<<1))
#define GPIOC_CLOCK_EN()	(RCC->AHB1ENR |= (1u<<2))
#define GPIOD_CLOCK_EN()	(RCC->AHB1ENR |= (1u<<3))
#define GPIOE_CLOCK_EN()	(RCC->AHB1ENR |= (1u<<4))
#define GPIOF_CLOCK_EN()	(RCC->AHB1ENR |= (1u<<5))
#define GPIOG_CLOCK_EN()	(RCC->AHB1ENR |= (1u<<6))
#define GPIOH_CLOCK_EN()	(RCC->AHB1ENR |= (1u<<7))
#define GPIOI_CLOCK_EN()	(RCC->AHB1ENR |= (1u<<8))


typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;



}EXTI_RegDef_t;


typedef struct{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t RESERVED0;
	volatile uint32_t CMPCR;



}SYSCFG_RegDef_t;


#define		EXTI		((EXTI_RegDef_t *)EXTI_BASEADDR)
#define		SYSCFG		((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)

#define SYSCFG_CLOCK_EN() 		(RCC->APB2ENR |= (1u<<14))


typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;

}SPI_RegDef_t;

#define SPI1			((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2			((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3			((SPI_RegDef_t*)SPI3_BASEADDR)

#define SPI1_CLOCK_EN() 		(RCC->APB2ENR |= (1u<<12))
#define SPI2_CLOCK_EN() 		(RCC->APB1ENR |= (1u<<14))
#define SPI3_CLOCK_EN() 		(RCC->APB1ENR |= (1u<<15))

typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
	volatile uint32_t FLTR;
}I2C_RegDef_t;

#define	I2C1	((I2C_RegDef_t*)I2C1_BASEADDR)
#define	I2C2	((I2C_RegDef_t*)I2C2_BASEADDR)
#define	I2C3	((I2C_RegDef_t*)I2C3_BASEADDR)

#define I2C1_CLOCK_EN() 		(RCC->APB1ENR |= (1u<<21))
#define I2C2_CLOCK_EN() 		(RCC->APB1ENR |= (1u<<22))
#define I2C3_CLOCK_EN() 		(RCC->APB1ENR |= (1u<<23))


#endif /* STM32F407XX_H_ */
