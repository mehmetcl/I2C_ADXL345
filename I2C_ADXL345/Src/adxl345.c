/*
 * adxl345.c
 *
 *  Created on: May 12, 2022
 *      Author: Admin
 */


#include "adxl345.h"

#define SLAVE_ADDRESS 0x53 // 0x53 << 1, 0xA6:Write, 0xA7:Read
extern uint8_t data_rec[6];


void adxl_init()
{

	uint8_t device_id;
	adxl_read(0x00, &device_id, 1); // if the read data is 0xE5, device is ready

	if(device_id!=0xE5)
		exit(1);



	adxl_write(0x2D, 0); // Reset power control all bits

	// Setup ->
	adxl_write(0x2D, 0x08); // Measure bit 1, wake up bit 0, autosleep 0, sleep 0,
	//wake up frequency 8 hz bcs we are not using it does not matter



}

void adxl_write(uint8_t reg_address, uint8_t data)
{
	i2c_write(SLAVE_ADDRESS, reg_address, data, 1);

}

void adxl_read(uint8_t reg_address, uint8_t *prxbuffer, uint8_t size)
{
	i2c_read(SLAVE_ADDRESS, reg_address, prxbuffer, size);

}

void adxl_accelerometer_init(void)
{
	adxl_write(0x31, 0x01); // +- 4g range, 4-wire SPI mode
}

void adxl_tap_init(void)
{
	// Z eksenini basma algilama icin etkinlestir
		adxl_write(0x2A, 0x01);

		// 62.5 mg/LSB 40 * .0625 = 2.5 g
		adxl_write(0x1D, 27);

		//en az 0.02s durmali ki tap olsun
		// Basma suresini ayarla. 625uS/LSB * 32 = 0.02s
		adxl_write(0x21, 27);

		//1.tap ve 2.tap arasindaki min sure
		//0.01s sonra 2. tapi yapabilirsin
		// Dokunma gecikmesini ayarla. 1.25ms/LSB * 80 = 0,01s
		adxl_write(0x22, 80);


		//window 2.tap icin uygun sure basladiktan sonra 0.01snde basmalisin
		// Dokunma gecikmesini ayarla. 1.25ms/LSB * 80 = 0,01s
		adxl_write(0x23, 240);


		// INT MAP`i INT1 olarak ayarla
		adxl_write(0x2F, 0x00);

		// Tekli ve Ikili basmayi aktif et
		adxl_write(0x2E, 0x60);
}
