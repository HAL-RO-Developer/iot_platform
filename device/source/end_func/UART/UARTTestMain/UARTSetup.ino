/* 
   UARTSetup.ino
   
   UARTSetup関数
   
   Created 2017/09/27
   By Hirotaka Nagaoka
*/

#include <DeviceControl.h>
#include "EndFunc.h"

SSHT UARTSetup( RESULT_DATA* rdata ){
  SSHT rtn = RESULT_OK;
  UART::begin( BAUDRATE );
  rdata->result = rtn;
  return rtn;
}

/* Copyright HAL College of Technology & Design */

