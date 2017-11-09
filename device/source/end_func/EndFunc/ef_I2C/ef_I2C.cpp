/* 
  ef_I2C.ino
   末端関数 I2C
   Created 2017/10/27
   By Riku Hashimoto
   */
#include <DeviceControl.h>
#include"EndFunc.h"

#define DATA (0)
#define ID  (1)

SSHT I2CSetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
  SSHT rtn = RESULT_OK;
    rdata->result = rtn;
    I2C::begin(cdata->port.pin1,cdata->port.pin2); //マスターとして設定
     return rtn;
  }

SSHT I2CWrite(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
	SSHT rtn = RESULT_OK;
	rdata->result = rtn;
	I2C::beginTransmission(cdata->value[ID]);
	I2C::Write(cdata->value[DATA]);
	I2C::endTransmission();
	return  rtn;
}

SSHT I2CRead(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
	SSHT rtn = RESULT_OK; //結果
	rdata->value = I2C::Read();//データを受け取る
	rdata->result = rtn;
	return rtn;
}

SSHT I2CRequestonebyte(CONTEXT_DATA *cdata,RESULT_DATA *rdata) {
	SSHT rtn = RESULT_OK;//結果
	I2C::reqFrom(cdata->value[ID], 1);//Slaveに1バイトの送信をリクエスト
	rdata->result = rtn;
	return rtn;
}
