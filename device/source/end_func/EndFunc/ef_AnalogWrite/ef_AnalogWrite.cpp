/*
ef_AnalogWrite.cpp
末端関数 AnalogWrite

Created 2017/10/07
By  Riku Hashimoto
*/


#include <DeviceControl.h>
#include "EndFunc.h"

#define Value (0)
#define TIME  (1)

SSHT blinkAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata) {
SSHT rtn = RESULT_OK;
 if(cdata->port.mode != OUTPUT){
Digital::SetMode(cdata->port.pin1, OUTPUT);
 }
 
 static SINT Time = millis();
if(millis()-Time >= cdata->value[TIME]) {
Analog::Write(cdata->port.pin1, cdata->value[Value]);
rdata->value = cdata->value[Value];
rdata->result = rtn;
 }
if(millis()-Time >= cdata->value[TIME] *2){
Analog::Write(cdata->port.pin1,0);
rdata->value = 0;
rdata->result = rtn;
Time = millis();
 }
return rtn;
}

SSHT simpleAWrite(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
	SSHT rtn = RESULT_OK;
	if (cdata->port.mode != OUTPUT) {
		Digital::SetMode(cdata->port.pin1, OUTPUT);
	}
	static SINT Time = millis();
	if (millis() - Time <= cdata->value[TIME]) {
		Analog::Write(cdata->port.pin1, cdata->value[Value]);
		rdata->value = cdata->value[Value];
		rdata->result = rtn;
	}
	else {
		Analog::Write(cdata->port.pin1, 0);
		rdata->value = 0;
		rdata->result = rtn;
	}
	return rtn;
}

SSHT onceAWrite(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {

	SSHT rtn = RESULT_OK;
	if (cdata->port.mode != OUTPUT) {
		Digital::SetMode(cdata->port.pin1, OUTPUT);
	}
	Analog::Write(cdata->port.pin1, cdata->value[Value]);
	rdata->value = cdata->value[Value];
	rdata->result = rtn;
	return rtn;
}
/* Copyright HAL College of Technology & Design */