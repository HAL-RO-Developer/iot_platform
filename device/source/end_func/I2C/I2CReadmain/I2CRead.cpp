/* 
  I2CRead.ino
   
   I2C受信
   
   Created 2017/09/27
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include"EndFunc.h"
#define DATA (0)
#define ID  (1)
SSHT I2CRead(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
  SSHT rtn = RESULT_OK; //結果
  rdata->value = I2C::Read();//データを受け取る
  rdata->result = rtn;
  return rtn;
}

