/* 
   AWrite.ino
   
   アナログ出力
   
   Created 2017/09/22
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include "endfunc.h"
//onceAWrite
SSHT onceAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
SSHT rtn = RESULT_OK;
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

/* Copyright HAL College of Technology & Design */
