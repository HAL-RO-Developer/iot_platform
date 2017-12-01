/*
ef_AnalogRead.cpp

末端関数 AnalogRead

Created 2017/10/21
By  Riku Hashimoto
*/


#include <DeviceControl.h>
#include "System.h"
#include "Function.h"




SSHT onceARead( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
    SSHT rtn = RESULT_OK;
  if(cdata->Port.Mode != INPUT){
Digital::SetMode(cdata->Port.Pin1, INPUT);
 }
rdata->Value = Analog::Read(cdata->Port.Pin1);//アナログ値取得
rdata->Result = rtn;
return rtn;
}

SSHT simpleARead(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
	const SINT TIME = 1;
	SSHT rtn = RESULT_OK;
	if (cdata->Port.Mode != INPUT) {
		Digital::SetMode(cdata->Port.Pin1, INPUT);
	}
	static SINT Time = millis();
	if (millis() - Time >= cdata->Value[TIME]) {
		rdata->Value = Analog::Read(cdata->Port.Pin1);//アナログ値取得
		Time = millis();
		rdata->Result = rtn;
		return rtn;
	}
}
SSHT blinkARead(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
const SINT VALUE = 0;
  const SINT TIME = 1;
	SSHT rtn = RESULT_OK;
	if (cdata->port.pin1 != INPUT) {
		Digital::SetMode(cdata->port.pin1, INPUT);
	}
	static SINT Time = millis();
	if (millis() - Time >= cdata->value[TIME]) {
		rdata->value = Analog::Read(cdata->port.pin1);//アナログ値取得
		Time = millis();
		rdata->result = rtn;
		return rtn;
	}
}
/* Copyright HAL College of Technology & Design */
