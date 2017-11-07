/* 
   UARTRead.ino
   
   UARTRead関数
   
   Created 2017/09/27
   By Hirotaka Nagaoka
*/

#include <DeviceControl.h>
#include "EndFunc.h"

SSHT UARTRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
  SSHT rtn = RESULT_OK;
  rdata->value = UART::Read();
  rdata->result = rtn;
  return rtn;
}

/* Copyright HAL College of Technology & Design */

