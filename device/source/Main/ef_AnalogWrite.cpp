/*
ef_AnalogWrite.cpp
末端関数 AnalogWrite

Created 2017/10/07
By  Riku Hashimoto
*/


#include <DeviceControl.h>
#include "System.h"
#include "Function.h"

SSHT blinkAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata) {
	const SINT TIME = 0;
	SSHT rtn = RESULT_OK;
	if(cdata->Port.Mode != OUTPUT){
		Digital::SetMode(cdata->Port.Pin1, OUTPUT);
	 }
	 
	static SINT Time = millis();
	if(millis()-Time >= cdata->Value[TIME]) {
		Analog::Write(cdata->Port.Pin1, HIGH);
		rdata->Value = HIGH;
		rdata->Result = rtn;
	 }
	if(millis()-Time >= cdata->Value[TIME] *2){
		Analog::Write(cdata->Port.Pin1,LOW);
		rdata->Value = LOW;
		rdata->Result = rtn;
		Time = millis();
	 }
	return rtn;
}

SSHT simpleAWrite(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
  const SINT VALUE = 0;
  const SINT TIME = 1;
  static SINT Flag = 0;
  static SINT Time;
  SSHT rtn = RESULT_OK;
  if (cdata->Port.Mode != OUTPUT) {
    Digital::SetMode(cdata->Port.Pin1, OUTPUT);
  }
  if(Flag == 0) {
  Time = millis( );
  Flag = 1;
}
  if (millis() - Time <= cdata->Value[TIME]) {
    Analog::Write(cdata->Port.Pin1, cdata->Value[VALUE]);
    rdata->Value = cdata->Value[VALUE];
    rdata->Result = rtn;
  }
  else {
    Analog::Write(cdata->Port.Pin1, 0);
    Flag = 0;
    rdata->Value = 0;
    rdata->Result = rtn;
  }
  return rtn;
}

SSHT onceAWrite(CONTEXT_DATA *cdata, RESULT_DATA *rdata) {
	const SINT VALUE = 0;
	SSHT rtn = RESULT_OK;
	if (cdata->Port.Mode != OUTPUT) {
		Digital::SetMode(cdata->Port.Pin1, OUTPUT);
	}
	Analog::Write(cdata->Port.Pin1, cdata->Value[VALUE]);
	rdata->Value = cdata->Value[VALUE];
	rdata->Result = rtn;
	return rtn;
}
