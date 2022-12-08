/*
 * i2c.c
 *
 *  Created on: May 25, 2022
 *      Author: Admin
 */


#include "i2c.h"

void i2c_wait(int flag)
{
	int i=0;
	while(!(I2C1->SR1 & (1u<<flag)))
	{

		i++;
		if(i==1000)
		{
			I2C1->CR1 |= (1u<<STOP_BIT); // stop condition
			exit (1);
		}


	}
}



void i2c_read(uint8_t saddr, uint8_t reg_addr, uint8_t *prxbuffer, uint8_t size)
{
	I2C1->CR1 |= START_BIT;
	while(!(I2C1->SR1 & (1u<<I2C_SB))); // wait for start

	saddr <<=1;
	I2C1->DR =saddr; // slave address, 7-bit addressing mode write
	i2c_wait(I2C_ADDR); // wait send address

	// clear address
	volatile uint16_t dummy_byte_read =I2C1->SR1;
	dummy_byte_read = I2C1->SR2;

	wait(I2C_TxE); // wait TXE empty
	I2C1->DR =reg_addr;

	wait(I2C_TxE); // wait TXE empty

	// generate restart
	I2C1->CR1 |= START_BIT;
	while(!(I2C1->SR1 & (1u<<I2C_SB))); // wait for start
	saddr |= (1u<<0);
	I2C1->DR =saddr; // slave address, 7-bit addressing mode read
	i2c_wait(I2C_ADDR); // wait send address

	//clear address
	dummy_byte_read =I2C1->SR1;
	dummy_byte_read = I2C1->SR2;


	while(size)
	{
		I2C1->CR1 |= ACK_EN;
		if(size==1)
			I2C1->CR1 &= ~(1u<<10);
		i2c_wait(I2C_RxNE); // wait RXE not empty

		*prxbuffer=I2C1->DR;
		prxbuffer++;
		size--;


	}

	wait(I2C_BTF); // BTF

	I2C1->CR1 |= STOP_BIT; // stop condition

}

void i2c_write(uint8_t saddr, uint8_t reg_addr, uint8_t data, uint8_t size)
{
	I2C1->CR1 |= START_BIT;
	while(!(I2C1->SR1 & (1u<<I2C_SB))); // wait for start

	saddr <<=1;
	I2C1->DR = saddr; // slave address, 7-bit addressing mode write
	i2c_wait(I2C_ADDR); // wait send address

	// clear address
	volatile uint16_t dummy_byte_read =I2C1->SR1;
	dummy_byte_read = I2C1->SR2;

	wait(I2C_TxE); // wait TXE empty
	I2C1->DR = reg_addr;

	while(size--)
	{
		i2c_wait(I2C_TxE); // wait TXE empty
			;
		I2C1->DR=data;
		data++;

	}

	i2c_wait(I2C_BTF); // BTF
		;

	I2C1->CR1 |= STOP_BIT; // stop condition





}

void i2c_clock_enable(I2C_RegDef_t *pI2Cx)
{
	if(pI2Cx == I2C1)
		I2C1_CLOCK_EN();

	else if(pI2Cx == I2C2)
		I2C2_CLOCK_EN();


	else if(pI2Cx == I2C3)
		I2C3_CLOCK_EN();

}

void i2c_init(I2C_Handle_t * phandle_i2c)
{

	i2c_clock_enable(phandle_i2c->pI2Cx);
	uint32_t ccr_temp=0;
	uint32_t trise_temp=0;
	i2c_clock_enable(phandle_i2c->pI2Cx);

	I2C1->CR2 &=~ 0x3F;
	I2C1->CR2 = abp1_clock_freq/1000000;

	I2C1->CCR &=~ 0xFFF;
	I2C1->TRISE &=~ 0x3F;

	trise_temp=abp1_clock_freq/1000000;

	//standart mode
	if(phandle_i2c->i2c_config.clock_speed <=100000)
	{

		ccr_temp = abp1_clock_freq / (phandle_i2c->i2c_config.clock_speed << 1);

		if(ccr_temp < 0x04)
			ccr_temp = 0x04;

		ccr_temp &=~ FAST_STANDART_MODE;
		trise_temp = trise_temp + 1;


	}
	//fast mode
	else
	{
		if(!phandle_i2c->i2c_config.duty_cycle)
		{
			ccr_temp = (abp1_clock_freq / phandle_i2c->i2c_config.clock_speed)/3;
			ccr_temp &=~ DUTY_CYCLE;

		}
		else
		{
			ccr_temp = (abp1_clock_freq / phandle_i2c->i2c_config.clock_speed)/25;
			ccr_temp |= DUTY_CYCLE;
		}
		if(ccr_temp < 0x01)
			ccr_temp = 0x01;

		ccr_temp |= FAST_STANDART_MODE;
		trise_temp = (trise_temp*300)/1000+1;
	}

 	I2C1->CCR = ccr_temp;
	I2C1->TRISE = trise_temp;



}

void i2c_enable(I2C_RegDef_t *pI2Cx)
{


	pI2Cx->CR1 |= I2C_PE;

}

