/* 
  ef_I2C.ino
   末端関数 I2C
   Created 2017/10/27
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include "System.h"
#include "Function.h"

#define DATA (0)
#define ID  (1)

SSHT I2CSetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
  SSHT rtn = RESULT_OK;
    rdata->Result = rtn;
    I2C::begin(cdata->Port.Pin1,cdata->Port.Pin2); //マスターとして設定
     return rtn;
  }

SSHT I2CWrite(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
	SSHT rtn = RESULT_OK;
	rdata->Result = rtn;
	I2C::beginTransmission(cdata->Value[ID]);
	I2C::Write(cdata->Value[DATA]);
	I2C::endTransmission();
	return  rtn;
}

SSHT I2CRead(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
	SSHT rtn = RESULT_OK; //結果
	rdata->Value = I2C::Read();//データを受け取る
	rdata->Result = rtn;
	return rtn;
}

SSHT I2CRequestonebyte(CONTEXT_DATA *cdata,RESULT_DATA *rdata) {
	SSHT rtn = RESULT_OK;//結果
	I2C::reqFrom(cdata->Value[ID], 1);//Slaveに1バイトの送信をリクエスト
	rdata->Result = rtn;
	return rtn;
}
