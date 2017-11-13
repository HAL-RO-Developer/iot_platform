/*
onceARead.ino

アナログ入力を行う

Created 2017/10/25
By Riku Hashimoto
*/


#include <DeviceControl.h>
#include "EndFunc.h"
#define Value (0)
#define TIME  (1)

SSHT onceARead( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
    SSHT rtn = RESULT_OK;
  if(cdata->port.mode != INPUT){
Digital::SetMode(cdata->port.pin1, INPUT);
 }
rdata->value = Analog::Read(cdata->port.pin1);//アナログ値取得
rdata->result = rtn;
return rtn;
}
