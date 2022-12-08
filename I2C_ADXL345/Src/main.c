
#include <stdint.h>

#include "stm32f407xx_gpio.h"


#include "i2c.h"
#include "adxl345.h"


uint8_t data_rec[6];
int16_t x,y,z;
float xG, yG, zG;

uint8_t status;

int main(void)
{
	GPIO_Handle_t gpioLed12 = {GPIOD,{GPIO_PIN_12,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_NO,GPIO_OTYPE_PP,0}};
	GPIO_Handle_t gpioLed13 = {GPIOD,{GPIO_PIN_13,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_NO,GPIO_OTYPE_PP,0}};
	GPIO_Handle_t gpioLed14 = {GPIOD,{GPIO_PIN_14,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_NO,GPIO_OTYPE_PP,0}};
	GPIO_Handle_t gpioLed15 = {GPIOD,{GPIO_PIN_15,GPIO_MODE_OUT,GPIO_SPEED_FAST,GPIO_PUPD_NO,GPIO_OTYPE_PP,0}};

	gpio_clock_en_di(GPIOD, ENABLE);

	gpio_init(&gpioLed12);
	gpio_init(&gpioLed13);
	gpio_init(&gpioLed14);
	gpio_init(&gpioLed15);

	GPIO_Handle_t gpioCLK = {GPIOB,{GPIO_PIN_8,GPIO_MODE_ALTER,GPIO_SPEED_VFAST,GPIO_PUPD_PU,GPIO_OTYPE_OD,0}};
	GPIO_Handle_t gpioSDA = {GPIOB,{GPIO_PIN_9,GPIO_MODE_ALTER,GPIO_SPEED_VFAST,GPIO_PUPD_PU,GPIO_OTYPE_OD,0}};


	gpio_clock_en_di(GPIOB, ENABLE);

	alternate_func_config(GPIOB, GPIO_PIN_8, I2C1_AF);
	alternate_func_config(GPIOB, GPIO_PIN_9, I2C1_AF);

	gpio_init(&gpioCLK);
	gpio_init(&gpioSDA);


	I2C_Handle_t i2c_test={I2C1,{100000,DUTY_CYCLE_HALF}};

	i2c_init(&i2c_test);

	i2c_enable(i2c_test.pI2Cx);


	adxl_init();


	adxl_accelerometer_init();

//	adxl_tap_init();

	while(1)
	{

		  //Accelerometer
		  adxl_read(DATA_REGISTER, data_rec, 6);
		  x = ((data_rec[1]<<8)|data_rec[0]);
		  y = ((data_rec[3]<<8)|data_rec[2]);
		  z = ((data_rec[5]<<8)|data_rec[4]);

		  xG = x * .0087;
		  yG = y * .0087 ;
		  zG = z * .0087;



		  //TAP

		/*  adxl_read(INT_SOURCE_REGISTER, &status, 1);


		  if((status >> 5) & 0x01) // double tap control
		  {
			  gpio_write_out_pin(GPIOD, GPIO_PIN_12, DISABLE);
			  gpio_write_out_pin(GPIOD, GPIO_PIN_13, DISABLE);
			  gpio_write_out_pin(GPIOD, GPIO_PIN_14, DISABLE);
			  gpio_write_out_pin(GPIOD, GPIO_PIN_15, DISABLE);



		  }
		  else if((status >> 6) & 0x01) // single tap control
		  {

			  gpio_write_out_pin(GPIOD, GPIO_PIN_12, ENABLE);
			  gpio_write_out_pin(GPIOD, GPIO_PIN_13, ENABLE);
			  gpio_write_out_pin(GPIOD, GPIO_PIN_14, ENABLE);
			  gpio_write_out_pin(GPIOD, GPIO_PIN_15, ENABLE);

		  }*/




	}
}
