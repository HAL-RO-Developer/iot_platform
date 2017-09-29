/*
onceDRead.ino

デジタル入力を行う

Created 2017/9/29
By Riku Hashimoto
*/


#include <DeviceControl.h>
#include "EndFunc.h"
SSHT onceDRead( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
    SSHT rtn = RESULT_OK;
  if(cdata->port[0] != INPUT){
Digital::SetMode(cdata->port[1], INPUT);
 }
rdata->value = Digital::Read(cdata->port[1]);//アナログ値取得
rdata->result = rtn;
return rtn;
}

