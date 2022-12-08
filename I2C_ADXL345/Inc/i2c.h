/*
 * i2c.h
 *
 *  Created on: May 25, 2022
 *      Author: Admin
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#include "stm32f407xx.h"
#include "utility.h"

#define ADXL345_I2C_SLAVE_ADDRESS 0xA6
#define abp1_clock_freq		16000000

//CR1
#define START_BIT			(1u<<8)
#define STOP_BIT		 	(1u<<9)
#define ACK_EN				(1u<<10)
#define I2C_PE				(1u<<0)

//CR2
#define DUTY_CYCLE_HALF			0
#define DUTY_CYCLE_16_9			1
#define DUTY_CYCLE				(1u<<14)
#define FAST_STANDART_MODE		(1u<<15)


typedef struct{

	uint32_t clock_speed;
	uint8_t duty_cycle;

}I2C_Config_t;

typedef struct{
	I2C_RegDef_t *pI2Cx;
	I2C_Config_t i2c_config;
}I2C_Handle_t;

//SR1
typedef enum I2C_SR_BITS{I2C_SB,I2C_ADDR,I2C_BTF,I2C_STOPF=4,I2C_RxNE=6,I2C_TxE=7}I2C_SR_BITS;
//SR2
#define I2C_MSL		0


void i2c_clock_enable(I2C_RegDef_t *pI2Cx);
void i2c_init(I2C_Handle_t * phandle_i2c);
void i2c_read(uint8_t saddr, uint8_t reg_addr, uint8_t *prxbuffer, uint8_t size);
void i2c_write(uint8_t saddr, uint8_t reg_addr, uint8_t data, uint8_t size);
void i2c_wait(flag);


#endif /* I2C_H_ */
