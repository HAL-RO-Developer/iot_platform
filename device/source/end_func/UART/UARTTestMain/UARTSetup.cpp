/* 
   UARTSetup.ino
   
   UARTSetup関数
   
   Created 2017/09/27
   By Hirotaka Nagaoka
*/

#include <DeviceControl.h>
#include "EndFunc.h"

#define BAUDRATE  ( 1 )     // ボーレート

SSHT UARTSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
     SSHT rtn = RESULT_OK;
     UART::begin( cdata->value[BAUDRATE] );
     rdata->result = rtn;
     return rtn;
}

/* Copyright HAL College of Technology & Design */

