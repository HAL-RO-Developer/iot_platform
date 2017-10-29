/* 
  I2CSetup.ino
   
   I2Cのセットアップ
   
   Created 2017/10/27
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include"EndFunc.h"

SSHT I2CSetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
  SSHT rtn = RESULT_OK;
    rdata->result = rtn;
    I2C::begin(cdata->port.pin1,cdata->port.pin2); //マスターとして設定
     return rtn;
  }
