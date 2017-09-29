/*
onceDRead.ino

アナログ入力を行う

Created 2017/9/29
By Riku Hashimoto
*/


#include <DeviceControl.h>
#include "EndFunc.h"
SSHT onceARead( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
    SSHT rtn = RESULT_OK;
  if(cdata->port[0] != INPUT){
Digital::SetMode(cdata->port[1], INPUT);
 }
rdata->value = Analog::Read(cdata->port[1]);//アナログ値取得
rdata->result = rtn;
return rtn;
}

