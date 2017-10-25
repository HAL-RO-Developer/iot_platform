/*
simpleDRead.ino

指定時間毎にデジタル入力を行う

Created 2017/10/25
By Riku Hashimoto
*/


#include <DeviceControl.h>
#include "EndFunc.h"
SSHT simpleDRead( CONTEXT_DATA *cdata,RESULT_DATA *rdata,int ms){
  short rtn = RESULT_OK;
 if(cdata->port.mode != INPUT){
Digital::SetMode(cdata->port.pin1, INPUT);
 }
static int Time = millis();
if(millis()-Time >= ms ){
rdata->value = Digital::Read(cdata->port.pin1);
Time = millis();
}
rdata->result = rtn;
return rtn;
}

