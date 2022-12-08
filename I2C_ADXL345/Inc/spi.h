/*
 * spi.h
 *
 *  Created on: May 11, 2022
 *      Author: Admin
 */

#ifndef SPI_H_
#define SPI_H_
#include <stdint.h>
#include "stm32f407xx.h"

typedef uint8_t BOOL;
#define TRUE	1
#define FALSE	0


// SPI DEVICE STATE
#define SPI_DEV_MASTER	1
#define SPI_DEV_SLAVE	0

// SPI Software Slave Man.
#define SPI_SSM_DISABLE 0
#define SPI_SSM_ENABLE	1

// SPI Dir.
#define SPI_DIRECTION_2LINES		0
#define SPI_DIRECTION_2LINES_RXONLY	1
#define SPI_DIRECTION_1LINE			2

//SPA Data Size
#define SPI_DATASIZE_8BIT	0
#define SPI_DATASIZE_16BIT	1

//SPI CPOL
#define SPI_POLARITY_LOW	0
#define SPI_POLARITY_HIGH	1

//
#define SPI_PHASE_1EDGE		0
#define SPI_PHASE_2EDGE		1

#define FIRST_BIT_MSB		0
#define FIRST_BIT_LSB		1

typedef struct{

	uint8_t mode;
	uint8_t direction;
	uint8_t data_size;
	uint8_t cpol;
	uint8_t cpha;
	uint8_t nss;
	uint8_t baudrate_presc;
	uint8_t firstbit;

}SPI_Config_t;

typedef struct{
	SPI_RegDef_t *pSPIx;
	SPI_Config_t spi_config;
}SPI_Handle_t;

typedef enum SPI_CR1_BITS{SPI_CR1_CPHA,SPI_CR1_CPOL,SPI_CR1_MSTR,SPI_CR1_BR,\
	SPI_CR1_SPE=6,SPI_CR1_LSB_FIRST,SPI_CR1_SSI,SPI_CR1_SSM,SPI_CR1_RXONLY,\
	SPI_CR1_DFF,SPI_CR1_CRCNEXT,SPI_CR1_CRCEN,SPI_CR1_BIDIOE,SPI_CR1_BIDIMODE}SPI_CR1_BITS;

typedef enum SPI_BR_BITS{SPI_BR_PR2,SPI_BR_PR4,SPI_BR_PR8,SPI_BR_PR16,SPI_BR_PR32,SPI_BR_PR64,\
	SPI_BR_PR128,SPI_BR_PR256}SPI_BR_BITS;

typedef enum SPI_SR_BITS{SPI_SR_RXNE,SPI_SR_TXE,SPI_SR_CHSIDE,SPI_SR_UDR,SPI_SR_CRC_ERR,\
	SPI_SR_MODF,SPI_SR_OVR,SPI_SR_BSY,SPI_SR_FRE}SPI_SR_BITS;

#define CR1_SPE		6



void spi_init(SPI_Handle_t * phandle_spi);
void spi_clock_enable(SPI_RegDef_t *pSPIx);
void spi_send_data(SPI_RegDef_t *pSPIx, uint8_t *ptxbuffer, uint8_t len);
void spi_rec_data(SPI_RegDef_t *pSPIx, uint8_t *prxbuffer, uint8_t len, BOOL dummy);
void spi_enable(SPI_RegDef_t *pSPIx);

#endif /* SPI_H_ */
