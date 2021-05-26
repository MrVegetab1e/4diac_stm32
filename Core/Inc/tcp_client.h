/*
 * tcp_client.h
 *
 *  Created on: May 20, 2021
 *      Author: vegetab1e
 */



#ifndef _TCP_CLIENT_H_
#define _TCP_CLIENT_H_

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

void tcp_client_task(void const * argument);

#endif
