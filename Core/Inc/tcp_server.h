/*
 * tcp_server.h
 *
 *  Created on: May 25, 2021
 *      Author: vegetab1e
 */

#ifndef INC_TCP_SERVER_H_
#define INC_TCP_SERVER_H_

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

void tcpecho_thread(void const * argument);

#endif /* INC_TCP_SERVER_H_ */
