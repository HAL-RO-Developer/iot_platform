/* 
  I2CSetup.ino
   
   I2Cのセットアップ
   
   Created 2017/09/27
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include"endfunc.h"

SSHT I2CSetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
　　 rdata->result = rtn;　//結果を格納
    I2C::begin(cdata->port[0],cdata->port[1]);//マスターとして設定
    rdata->result = rtn;　//結果を格納
     return rtn;
  }
