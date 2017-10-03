/* 
   SoftwareSerialSetup.ino
   
   SoftwareSerialSetup関数
   
   Created 2017/09/27
   By Hirotaka Nagaoka
*/

#include <DeviceControl.h>
#include "EndFunc.h"

SSHT SoftwareSerialSetup( CONTEXT_DATA* cdata, RESULT_DATA* rdata ){
  SoftwareSerial mySerial( cdata->port[0], cdata->port[1] );
  SSHT rtn = RESULT_OK;
  mySerial.begin( 115200 );
  rdata->result = rtn;
  return rtn;
}

/* Copyright HAL College of Technology & Design */

