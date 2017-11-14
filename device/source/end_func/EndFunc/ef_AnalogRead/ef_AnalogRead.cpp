/*
ef_AnalogRead.cpp

末端関数 AnalogRead

Created 2017/10/07
By  Riku Hashimoto
*/

#include <DeviceControl.h>
#include "System.h"
#include "Function.h"

#define VALUE (0)
#define TIME  (1)

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
/* Copyright HAL College of Technology & Design */
