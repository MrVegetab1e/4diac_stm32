/*
 * pcf8574.h
 *
 *  Created on: Apr 1, 2021
 *      Author: vegetab1e
 */

#ifndef HARDWARE_PCF8574_H_
#define HARDWARE_PCF8574_H_

#include "main.h"


extern I2C_HandleTypeDef hi2c2;

#define PCF8574_ADDR 	0X40
#define PCF8574_INT  HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)//PCF8574 INT



#define BEEP_IO         0		//  	P0
#define AP_INT_IO       1   	//		P1
#define DCMI_PWDN_IO    2    	//		P2
#define USB_PWR_IO      3    	//		P3
#define EX_IO      		4    	// 		P4
#define MPU_INT_IO      5   	//		P5
#define RS485_RE_IO     6    	//		P6
#define ETH_RESET_IO    7    	//		P7

uint8_t PCF8574_Init(void);
uint8_t PCF8574_ReadOneByte(void);
void PCF8574_WriteOneByte(uint8_t DataToWrite);
void PCF8574_WriteBit(uint8_t bit,uint8_t sta);

#endif /* HARDWARE_PCF8574_H_ */
