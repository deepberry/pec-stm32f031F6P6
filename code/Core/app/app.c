/*
 * THE FOLLOWING FIRMWARE IS PROVIDED: (1) "AS IS" WITH NO WARRANTY; AND
 * (2)TO ENABLE ACCESS TO CODING INFORMATION TO GUIDE AND FACILITATE CUSTOMER.
 * CONSEQUENTLY, SEMTECH SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * Copyright (C) SEMTECH S.A.
 */
/*!
 * \file       main.c
 * \brief      Ping-Pong example application on how to use Semtech's Radio
 *             drivers.
 *
 * \version    2.0
 * \date       Nov 21 2012
 * \author     Miguel Luis
 */
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "main.h"

/*
 * Main application entry point.
*/

extern void load_config(void);
extern void modbusInit(void);
extern IWDG_HandleTypeDef hiwdg;

int app_main( void )
{
	load_config();

	__HAL_IWDG_RELOAD_COUNTER(&hiwdg);

	modbusInit();

    while(1){
    	__HAL_IWDG_RELOAD_COUNTER(&hiwdg);
    	eMBPoll();
    }

#ifdef __GNUC__
    return 0;
#endif
}

