/*
 * corem4.h
 *
 *  Created on: Apr. 15, 2022
 *      Author: Admin
 */

#ifndef COREM4_H_
#define COREM4_H_

#include<stdint.h>

#define		NVIC_ISER0	((volatile uint32_t*)0xE000E100)
#define		NVIC_ISER1	((volatile uint32_t*)0xE000E104)
#define		NVIC_ISER2	((volatile uint32_t*)0xE000E108)
#define		NVIC_ISER3	((volatile uint32_t*)0xE000E10C)
#define		NVIC_ISER4	((volatile uint32_t*)0xE000E110)
#define		NVIC_ISER5	((volatile uint32_t*)0xE000E114)
#define		NVIC_ISER6	((volatile uint32_t*)0xE000E118)
#define		NVIC_ISER7	((volatile uint32_t*)0xE000E11C)

// NVIC IcerX  disable registers
#define		NVIC_ICER0	((volatile uint32_t*)0xE000E180)
#define		NVIC_ICER1	((volatile uint32_t*)0xE000E184)
#define		NVIC_ICER2	((volatile uint32_t*)0xE000E188)
#define		NVIC_ICER3	((volatile uint32_t*)0xE000E18C)
#define		NVIC_ICER4	((volatile uint32_t*)0xE000E190)
#define		NVIC_ICER5	((volatile uint32_t*)0xE000E194)
#define		NVIC_ICER6	((volatile uint32_t*)0xE000E198)
#define		NVIC_ICER7	((volatile uint32_t*)0xE000E19C)

// NVIC Priority Registers
#define		NVIC_IPR0	((volatile uint32_t*)0xE000E400)


// IRQ Number EXTI Lines
#define IRQ_NO_EXTI0		6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40

#define EXTI0			0
#define EXTI1			1
#define EXTI2			2
#define EXTI3			3
#define EXTI4			4
#define EXTI5			5
#define EXTI9			5
#define EXTI10			6
#define EXTI15			6

void nvic_enable(uint8_t irq_number);
void nvic_disable(uint8_t irq_number);


#endif /* COREM4_H_ */
