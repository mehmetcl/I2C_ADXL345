/*
 * corem4.c
 *
 *  Created on: Apr. 15, 2022
 *      Author: Admin
 */

#include "corem4.h"


void nvic_enable(uint8_t irq_number)
{
	if(irq_number < 32)
		*NVIC_ISER0 |= (1u<<irq_number);
	else if(irq_number>31 && irq_number < 64)
		*NVIC_ISER1 |= (1u<<(irq_number %32));
	else if(irq_number>63 && irq_number < 96)
		*NVIC_ISER2 |= (1u<<(irq_number%32));
	else if(irq_number>95 && irq_number < 128)
		*NVIC_ISER3 |= (1u<<(irq_number%32));
	else if(irq_number>127 && irq_number < 160)
		*NVIC_ISER4 |= (1u<<(irq_number%32));

}

void nvic_disable(uint8_t irq_number)
{
	if(irq_number < 32)
		*NVIC_ICER0 |= (1u<<irq_number);
	else if(irq_number>31 && irq_number < 64)
		*NVIC_ICER1 |= (1u<<(irq_number %32));
	else if(irq_number>63 && irq_number < 96)
		*NVIC_ICER2 |= (1u<<(irq_number%32));
	else if(irq_number>95 && irq_number < 128)
		*NVIC_ICER3 |= (1u<<(irq_number%32));
	else if(irq_number>127 && irq_number < 160)
		*NVIC_ICER4 |= (1u<<(irq_number%32));



}
