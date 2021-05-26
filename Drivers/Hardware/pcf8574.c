/*
 * pcf8574.c
 *
 *  Created on: Apr 1, 2021
 *      Author: vegetab1e
 */

#include "pcf8574.h"
/*初始化PCF8574*/
uint8_t PCF8574_Init(void){
  uint8_t temp=0;
  uint8_t data = 0xf0;
  HAL_I2C_Mem_Write(&hi2c2,PCF8574_ADDR,255,I2C_MEMADD_SIZE_8BIT,&data,1,0xff);
  if(HAL_OK == HAL_I2C_Mem_Read(&hi2c2,PCF8574_ADDR|0x01,255,I2C_MEMADD_SIZE_8BIT,&temp,1,0xff)){
	printf("TEMP = %x!\r\n",temp);
  }
  return temp;
}

/*读取PCF8574的8位IO值；返回读到的数据*/
uint8_t PCF8574_ReadOneByte(void){
  uint8_t temp=0;
  HAL_I2C_Mem_Read(&hi2c2,PCF8574_ADDR|0x01,255,I2C_MEMADD_SIZE_8BIT,&temp,1,0xff);
  return temp;
}

/*向PCF8574写入8位IO值；DataToWrite为要写入的数据*/
void PCF8574_WriteOneByte(uint8_t DataToWrite){
  HAL_I2C_Mem_Write(&hi2c2,PCF8574_ADDR,255,I2C_MEMADD_SIZE_8BIT,&DataToWrite,1,0xff);
}

/*设置PCF8574某个IO的高低电平*/
//bit:要设置的IO编号，0~7
//sta:IO的状态，0或1
void PCF8574_WriteBit(uint8_t bit,uint8_t sta){
  uint8_t data;
  data=PCF8574_ReadOneByte(); //先读出原来的数据
  if(sta==0)
	data&=~(1<<bit);
  else
	data|=1<<bit;
  PCF8574_WriteOneByte(data); //写入新的数据
}

/*读取PCF8574某个IO的值*/
//bit:要设置的IO编号，0~7
//返回值:IO的值，0或1
uint8_t PCF8574_ReadBit(uint8_t bit){
  uint8_t data;
  data=PCF8574_ReadOneByte(); //先读取8位IO的值
  if(data&(1<<bit))
	return 1;
  else
	return 0;
}
