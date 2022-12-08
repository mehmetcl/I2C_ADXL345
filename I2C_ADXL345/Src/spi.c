/*
 * spi.c
 *
 *  Created on: May 11, 2022
 *      Author: Admin
 */

#include "spi.h"

void spi_clock_enable(SPI_RegDef_t *pSPIx)
{
	if(pSPIx == SPI1)
		SPI1_CLOCK_EN();

	else if(pSPIx == SPI2)
		SPI2_CLOCK_EN();


	else if(pSPIx == SPI3)
		SPI3_CLOCK_EN();

}

void spi_init(SPI_Handle_t * phandle_spi)
{


	spi_clock_enable(phandle_spi->pSPIx);
	uint32_t temp_cr1=0;
	//1.mode
	temp_cr1 |= phandle_spi->spi_config.mode <<SPI_CR1_MSTR;
	//2.direction

	//3.data size
	temp_cr1 |= phandle_spi->spi_config.data_size <<SPI_CR1_DFF;
	//4.cpol
	temp_cr1 |= phandle_spi->spi_config.cpol <<SPI_CR1_CPOL;
	//5.cpha
	temp_cr1 |= phandle_spi->spi_config.cpha <<SPI_CR1_CPHA;

	//6.nss

	if(phandle_spi->spi_config.nss == SPI_SSM_ENABLE)
	{
		temp_cr1 |= phandle_spi->spi_config.nss <<SPI_CR1_SSM;
		temp_cr1 |= (1u) <<SPI_CR1_SSI;
	}

	//7.baudrate_pres
	temp_cr1 |= phandle_spi->spi_config.baudrate_presc <<SPI_CR1_BR;
	//8.firstbit ??ODEV
	temp_cr1 |= phandle_spi->spi_config.firstbit <<SPI_CR1_LSB_FIRST;

	phandle_spi->pSPIx->CR1 = temp_cr1;




}


void spi_send_data(SPI_RegDef_t *pSPIx, uint8_t *ptxbuffer, uint8_t len)
{
	// ABC her bir karakter ters cevriliyor
	while(len)
	{
		while(!(SPI1->SR & (1u<<SPI_SR_TXE)))
			;
		if(pSPIx->CR1 & 1<<SPI_CR1_DFF) // dff 16bit
		{
			pSPIx->DR = *((uint16_t*)ptxbuffer);
			len--;
			len--;
			(uint16_t*)ptxbuffer++; //ptxbuffer++ ptxbuffer++

		}
		else
		{
			pSPIx->DR = *ptxbuffer;
			len--;
			ptxbuffer++;
		}


	}

}

void spi_rec_data(SPI_RegDef_t *pSPIx, uint8_t *prxbuffer, uint8_t len, BOOL dummy)
{


	uint8_t dummy_value=0;
	while(len)
	{
			if(dummy)
				spi_send_data(SPI1, &dummy_value, 1);
			while(!(SPI1->SR & (1u<<SPI_SR_RXNE)))
				;
			if(pSPIx->CR1 & 1<<SPI_CR1_DFF) // dff 16bit
			{
				*((uint16_t*)prxbuffer) = pSPIx->DR;
				len--;
				len--;
				(uint16_t*)prxbuffer++; //prxbuffer++ prxbuffer++

			}
			else
			{
				*prxbuffer = pSPIx->DR;
				len--;
				prxbuffer++;
			}


	}


}


void spi_enable(SPI_RegDef_t *pSPIx)
{


	pSPIx->CR1 |= 	1 << CR1_SPE;

}

