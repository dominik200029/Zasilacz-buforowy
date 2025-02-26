/*
 * communication.h
 *
 *  Created on: Sep 6, 2024
 *      Author: DOMINIK DUCHNIK
 */

#ifndef DRIVERS_COMMUNICATION_H_
#define DRIVERS_COMMUNICATION_H_

HAL_StatusTypeDef IsDeviceReady();
void CYPD3177_ReadRegister(void);

#endif /* DRIVERS_COMMUNICATION_H_ */
