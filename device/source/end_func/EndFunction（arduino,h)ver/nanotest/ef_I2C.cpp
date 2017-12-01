/* 
  ef_I2C.ino
   末端関数 I2C
   Created 2017/11/23
   By Riku Hashimoto
   */
#include <arduino.h>
#include <Wire.h>
#include "EndFunc.h"



SSHT I2CSetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
const int DATA = 0;
const int ID =1;
  SSHT rtn = RESULT_OK;
    rdata->Result = rtn;
    Wire.begin(); //マスターとして設定 4と5
     return rtn;
  }

SSHT I2CWrite(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
const int DATA = 0;
const int ID =1;
	SSHT rtn = RESULT_OK;
	rdata->Result = rtn;
	Wire.beginTransmission(cdata->Value[ID]);
	Wire.write(cdata->Value[DATA]);
	Wire.endTransmission();
	return  rtn;
}

SSHT I2CRead(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
const int DATA = 0;
const int ID =1;
	SSHT rtn = RESULT_OK; //結果
	rdata->Value = Wire.read();//データを受け取る
	rdata->Result = rtn;
	return rtn;
}

SSHT I2CRequestonebyte(CONTEXT_DATA *cdata,RESULT_DATA *rdata) {
const int DATA = 0;
const int ID =1;
	SSHT rtn = RESULT_OK;//結果
	Wire.requestFrom(cdata->Value[ID], 1);//Slaveに1バイトの送信をリクエスト
	rdata->Result = rtn;
	return rtn;
}
