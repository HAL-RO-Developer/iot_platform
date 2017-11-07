/*
onceARead.ino

アナログ入力を行う

Created 2017/10/25
By Riku Hashimoto
*/


#include <DeviceControl.h>
#include "EndFunc.h"
SSHT simpleARead( CONTEXT_DATA *cdata,RESULT_DATA *rdata,SINT ms){
    SSHT rtn = RESULT_OK;
  if(cdata->port.pin1 != INPUT){
Digital::SetMode(cdata->port.pin1, INPUT);
 }
 static SINT Time = millis();
if(millis()-Time >= ms ){
rdata->value = Analog::Read(cdata->port.pin1);//アナログ値取得
Time = millis();
rdata->result = rtn;
return rtn;
}
}
