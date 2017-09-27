/* 
  I2CRequestonebyte.ino
   
   Slaveに1バイトの送信をリクエスト
   
   Created 2017/09/27
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include"endfunc.h"

SSHT I2CRequestonebyte( SINT SlaveID,RESULT_DATA *rdata) {
 SSHT rtn = RESULT_OK;　//結果
I2C::reqFrom(SlaveID,1);//Slaveに1バイトの送信をリクエスト
 rdata->result = rtn;　//結果を格納
     return rtn;
  }
