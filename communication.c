/*
 * communication.c
 *
 *  Created on: Sep 6, 2024
 *      Author: DOMINIK DUCHNIK
 */
#include "main.h"
#include "communication.h"
#include "i2c.h"

#define DEVICE_ADDRESS_READ 0x08 << 1
#define DEVICE_ADDRESS_WRITE 0x08

#define DEVICE_MODE_REGISTER 0x0000
#define SILICON_ID_REGISTER 0x0002
#define BUS_VOLTAGE_REGISTER  0x100D
#define INTERRUPT_REGISTER 0x0006
#define DEV_RESPONSE_REGISTER 0x007E
#define PD_RESPONSE_REGISTER 0x1400
#define PD_STATUS_REGISTER 0x1008

HAL_StatusTypeDef hpiReadStatus;
HAL_StatusTypeDef hpiWriteStatus;
HAL_StatusTypeDef deviceStatus;

#define CYPD3177_I2C_ADDRESS 0x08
#define REG_ADDRESS_100D 0x100D

uint8_t voltageValue[8];

HAL_StatusTypeDef i2c_error;

void CYPD3177_ReadRegister()
{
  i2c_error = HAL_I2C_Mem_Read(&hi2c1, (CYPD3177_I2C_ADDRESS << 1), 0x20, 1, (uint8_t *) &voltageValue, sizeof(voltageValue), HAL_MAX_DELAY);
}

HAL_StatusTypeDef IsDeviceReady()
{
	  return HAL_I2C_IsDeviceReady(&hi2c1, DEVICE_ADDRESS_READ, 5, 10);
}
