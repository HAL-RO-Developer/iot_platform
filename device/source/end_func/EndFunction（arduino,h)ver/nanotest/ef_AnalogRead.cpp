/*
ef_AnalogRead.cpp

末端関数 AnalogRead

Created 2017/11/21
By  Riku Hashimoto
*/
#include <arduino.h>
#include "EndFunc.h"

SSHT onceARead( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
    SSHT rtn = RESULT_OK;
  if(cdata->Port.Mode != INPUT){
pinMode(cdata->Port.Pin1, INPUT);
 }
rdata->Value = analogRead(cdata->Port.Pin1);//アナログ値取得
rdata->Result = rtn;
return rtn;
}

SSHT simpleARead(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
	const SINT TIME = 1;
	SSHT rtn = RESULT_OK;
	if (cdata->Port.Mode != INPUT) {
		pinMode(cdata->Port.Pin1, INPUT);
	}
	static SINT Time = millis();
	if (millis() - Time >= cdata->Value[TIME]) {
		rdata->Value = analogRead(cdata->Port.Pin1);//アナログ値取得
		Time = millis();
		rdata->Result = rtn;
		return rtn;
	}
}
/* Copyright HAL College of Technology & Design */
