/* 
  I2CSetup.ino
   
   I2Cのセットアップ
   
   Created 2017/09/27
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include"EndFunc.h"

SSHT I2CSetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
  SSHT rtn = RESULT_OK;
    rdata->result = rtn;
    I2C::begin(cdata->port[0],cdata->port[1]); //マスターとして設定
     return rtn;
  }
