// Created 2017/09/20
// By Riku Hashimoto

#include <DeviceControl.h>
#include "EndFunc.h"
//onceAWrite
short onceAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
  short rtn = RESULT_OK;
//INPUTになっていたらOUTPUTに
 if(cdata->port[0] != OUTPUT){
Digital::SetMode(cdata->port[1], OUTPUT);
 }
//出力する
Analog::Write(cdata->port[1],cdata->value);
rdata->value = cdata->value;
rdata->result = rtn;
return rtn;
}

