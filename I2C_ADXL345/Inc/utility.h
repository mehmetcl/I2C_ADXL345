/*
 * utility.h
 *
 *  Created on: Apr. 4, 2022
 *      Author: Admin
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include<stdint.h>

#define SECOND_1			2000000//2014388
#define DELAY_SECOND(x)		((x)*(SECOND_1))


void delay(uint32_t time);

#endif /* UTILITY_H_ */
