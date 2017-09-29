/* 
  I2CWrite.ino
   
   I2C送信
   
   Created 2017/09/27
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include"EndFunc.h"
SSHT I2CWrite( SINT SleaveID, SINT data, RESULT_DATA *rdata) {
  SSHT rtn = RESULT_OK;
  rdata->result = rtn;
  I2C::beginTransmission(SleaveID);
  I2C::Write(data);
  I2C::endTransmission();
   return  rtn;
  }
