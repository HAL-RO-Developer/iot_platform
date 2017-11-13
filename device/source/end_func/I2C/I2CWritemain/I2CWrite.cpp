/* 
  I2CWrite.ino
   
   I2C送信
   
   Created 2017/09/27
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include"EndFunc.h"
#define DATA (0)
#define ID  (1)

SSHT I2CWrite(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
  SSHT rtn = RESULT_OK;
  rdata->result = rtn;
  I2C::beginTransmission(cdata->value[ID]);
  I2C::Write(cdata->value[DATA]);
  I2C::endTransmission();
  return  rtn;
}

