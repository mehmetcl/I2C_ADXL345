/*
 * stm32f407xx_gpio.h
 *
 *  Created on: Mar 31, 2022
 *      Author: Admin
 */
//manual multiple inclusion guard, pragma once is non standart
#ifndef STM32F407XX_GPIO_H_
#define STM32F407XX_GPIO_H_

#include <stdint.h>
#include "stm32f407xx.h"
#include "corem4.h"

typedef uint8_t BOOL;
typedef struct{
	uint8_t pin_number;
	uint8_t pin_mode;
	uint8_t pin_speed;
	uint8_t pin_pu_pd;
	uint8_t pin_otype;
	uint8_t pin_alter_mode;

}GPIO_PinConfig_t;

typedef struct{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t gpio_pin_config;

}GPIO_Handle_t;

#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTER		2
#define	GPIO_MODE_ANALOG	3
//interrupt modes
#define GPIO_MODE_INT_FT	4
#define GPIO_MODE_INT_RT	5
#define GPIO_MODE_INT_FRT	6

#define GPIO_OTYPE_PP		0
#define GPIO_OTYPE_OD		1

#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MED		1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_VFAST	3

#define	GPIO_PUPD_NO		0
#define GPIO_PUPD_PU		1
#define GPIO_PUPD_PD		2

#define GPIO_PIN_0			0
#define GPIO_PIN_1			1
#define GPIO_PIN_2			2
#define GPIO_PIN_3			3
#define GPIO_PIN_4			4
#define GPIO_PIN_5			5
#define GPIO_PIN_6			6
#define GPIO_PIN_7			7
#define GPIO_PIN_8			8
#define GPIO_PIN_9			9
#define GPIO_PIN_1O			10
#define GPIO_PIN_11			11
#define GPIO_PIN_12			12
#define GPIO_PIN_13			13
#define GPIO_PIN_14			14
#define GPIO_PIN_15			15

#define 	GPIO_RESET				0
#define 	GPIO_SET				1
#define 	GPIO_ALL_SET_PINS		0xFFFF
#define 	GPIO_ALL_RESET_PINS		0x0000

#define		 GPIO_SET_PIN_15			(1u<<15)
#define		 GPIO_SET_PIN_14			(1u<<14)
#define		 GPIO_SET_PIN_13			(1u<<13)
#define		 GPIO_SET_PIN_12			(1u<<12)
#define		 GPIO_SET_PIN_11			(1u<<11)
#define		 GPIO_SET_PIN_10			(1u<<10)
#define		 GPIO_SET_PIN_9				(1u<<9)
#define		 GPIO_SET_PIN_8				(1u<<8)
#define		 GPIO_SET_PIN_7				(1u<<7)
#define		 GPIO_SET_PIN_6				(1u<<6)
#define		 GPIO_SET_PIN_5				(1u<<5)
#define		 GPIO_SET_PIN_4				(1u<<4)
#define		 GPIO_SET_PIN_3				(1u<<3)
#define		 GPIO_SET_PIN_2				(1u<<2)
#define		 GPIO_SET_PIN_1				(1u<<1)
#define		 GPIO_SET_PIN_0				(1u<<0)

#define 	AF0			0
#define 	AF1			1
#define 	AF2			2
#define 	AF3			3
#define 	AF4			4
#define 	AF5			5
#define 	AF6			6
#define 	AF7			7
#define 	AF8			8
#define 	AF9			9
#define 	AF10		10
#define 	AF11		11
#define 	AF12		12
#define 	AF13		13
#define 	AF14		14
#define 	AF15		15

#define		 TIM1		AF1
#define		 TIM2		AF1

#define		 TIM3		AF2
#define		 TIM4		AF2
#define		 TIM5		AF2

#define		 TIM8		AF3
#define		 TIM9		AF3
#define		 TIM10		AF3
#define		 TIM11		AF3

#define		 I2C1_AF	AF4
#define		 I2C2_AF	AF4
#define		 I2C3_AF	AF4

#define		 SPI1_AF	AF5
#define		 SPI2_AF	AF5

#define		 SPI3_AF	AF6

#define		 USART1		AF7
#define		 USART2		AF7
#define		 USART3		AF7

#define		 USART4		AF8
#define		 USART5		AF8
#define		 USART6		AF8

#define		 CAN1		AF9
#define		 CAN2		AF9
#define		 TIM12		AF9
#define		 TIM13		AF9
#define		 TIM14		AF9


#define		 OTG_FS		AF10
#define		 OTG_HS		AF10

#define		 ETH		AF11

#define		 FSMC		AF12
#define		 SDIO		AF12
#define		 OTG_HS_1	AF12

#define		 DCMI		AF13



void gpio_init(GPIO_Handle_t *pgpio_handle);
void gpio_write_out_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no,BOOL val);
BOOL gpio_read_input_pin(GPIO_RegDef_t *pgpiox,uint16_t pin_no);
void gpio_toggle_pin(GPIO_RegDef_t *pgpiox,uint8_t pin_no);
void gpio_write_port(GPIO_RegDef_t *pgpiox,uint16_t val);
uint16_t gpio_read_input_port(GPIO_RegDef_t *pgpiox);

typedef enum{Port_CodeA,Port_CodeB,Port_CodeC,Port_CodeD,Port_CodeE,Port_CodeF,Port_CodeG,Port_CodeH}ExtiCR_PortCode;

ExtiCR_PortCode get_exticr_port_code(const GPIO_RegDef_t *pGPIOx);


void alternate_func_config(GPIO_RegDef_t *pgpiox, uint8_t pin_no, uint8_t GPIO_AF);


#endif /* STM32F407XX_GPIO_H_ */
