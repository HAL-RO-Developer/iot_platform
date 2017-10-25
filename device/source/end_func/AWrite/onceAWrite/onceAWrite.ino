// Created 2017/09/20
// By Riku Hashimoto

#include <DeviceControl.h>
#include "EndFunc.h"
//onceAWrite
short onceAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
  
  short rtn = RESULT_OK;
 if(cdata->port.mode != OUTPUT){
Digital::SetMode(cdata->port.pin1, OUTPUT);
 }


Analog::Write(cdata->port.pin1,*cdata->value);
rdata->value = *cdata->value;
rdata->result = rtn;
return rtn;
}


