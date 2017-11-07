// Created 2017/09/20
// By Riku Hashimoto

#include <DeviceControl.h>
#include "EndFunc.h"

SSHT blinkAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata,SINT ms){
 short rtn = RESULT_OK;
 if(cdata->port.mode != OUTPUT){
Digital::SetMode(cdata->port.pin1, OUTPUT);
 }
 static int Time = millis();
if(millis()-Time >= ms ){
Analog::Write(cdata->port.pin1,*cdata->value);
rdata->value = *cdata->value;
rdata->result = rtn;
 }
if(millis()-Time >= ms*2){
Analog::Write(cdata->port.pin1,0);
rdata->value = 0;
rdata->result = rtn;
Time = millis();
 }
return rtn;
}

