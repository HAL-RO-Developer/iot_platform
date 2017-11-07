// Created 2017/09/20
// By Riku Hashimoto

#include <DeviceControl.h>
#include "EndFunc.h"

SSHT simpleAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata,SINT ms){
SSHT rtn = RESULT_OK;
 if(cdata->port.mode != OUTPUT){
Digital::SetMode(cdata->port.pin1, OUTPUT);
 }
 static SINT Time = millis();
if(millis()-Time <= ms ){
Analog::Write(cdata->port.pin1,*cdata->value);
rdata->value = *cdata->value;
rdata->result = rtn;
 }else{
Analog::Write(cdata->port.pin1,0);
rdata->value = 0;
rdata->result = rtn;
 }
return rtn;
}

