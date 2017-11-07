/* 
   SoftwareSerialSetup.ino
   
   SoftwareSerialSetup関数
   
   Created 2017/09/27
   By Hirotaka Nagaoka
*/

#include <DeviceControl.h>
#include "EndFunc.h"

#define BAUDRATE  ( 1 )     // ボーレート

SSHT SoftwareSerialSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
  SoftwareSerial mySerial( cdata->port.pin1, cdata->port.pin2 );
  SSHT rtn = RESULT_OK;
  mySerial.begin( cdata->value[BAUDRATE] );
  rdata->result = rtn;
  return rtn;
}

/* Copyright HAL College of Technology & Design */

