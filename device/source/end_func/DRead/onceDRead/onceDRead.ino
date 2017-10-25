/*
onceDRead.ino

デジタル入力を行う

Created 2017/9/29
By Riku Hashimoto
*/


#include <DeviceControl.h>
#include "EndFunc.h"
SSHT onceDRead( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
  short rtn = RESULT_OK;
 if(cdata->port.mode != INPUT){
Digital::SetMode(cdata->port.pin1, INPUT);
 }
rdata->value = Digital::Read(cdata->port.pin1);
rdata->result = rtn;
return rtn;
}

