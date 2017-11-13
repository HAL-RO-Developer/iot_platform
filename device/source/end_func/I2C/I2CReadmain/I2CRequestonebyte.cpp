/* 
  I2CRequestonebyte.ino
   
   Slaveに1バイトの送信をリクエスト
   
   Created 2017/09/27
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include"EndFunc.h"
#define DATA (0)
#define ID  (1)
SSHT I2CRequestonebyte(CONTEXT_DATA *cdata,RESULT_DATA *rdata) {
  SSHT rtn = RESULT_OK;//結果
  I2C::reqFrom(cdata->value[ID], 1);//Slaveに1バイトの送信をリクエスト
  rdata->result = rtn;
  return rtn;
}
