/*
ef_AnalogWrite.cpp
末端関数 AnalogWrite

Created 2017/11/24
By  Riku Hashimoto
*/


#include <arduino.h>
#include "EndFunc.h"

SSHT blinkAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata) {
  const SINT VALUE = 0;
  const SINT TIME = 1;
  SSHT rtn = RESULT_OK;
  if(cdata->Port.Mode != OUTPUT){
    pinMode(cdata->Port.Pin1, OUTPUT);
   }
   
  static SINT Time = millis();
  if(millis()-Time >= cdata->Value[TIME]) {
    analogWrite(cdata->Port.Pin1, cdata->Value[VALUE]);
    rdata->Value = cdata->Value[VALUE];
    rdata->Result = rtn;
   }
  if(millis()-Time >= cdata->Value[TIME] *2){
    analogWrite(cdata->Port.Pin1,LOW);
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
    pinMode(cdata->Port.Pin1, OUTPUT);
  }
  if(Flag == 0) {
  Time = millis( );
  Flag = 1;
}
  if (millis() - Time <= cdata->Value[TIME]) {
    analogWrite(cdata->Port.Pin1, cdata->Value[VALUE]);
    rdata->Value = cdata->Value[VALUE];
    rdata->Result = rtn;
  }
  else {
    analogWrite(cdata->Port.Pin1, 0);
    Flag = 0;
    rdata->Value = 0;
    rdata->Result = rtn;
  }
  return rtn;
}


SSHT onceAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
  
SSHT rtn = RESULT_OK;
 if(cdata->Port.Mode != OUTPUT){
pinMode(cdata->Port.Pin1, OUTPUT);
 }
analogWrite(cdata->Port.Pin1,*cdata->Value);
rdata->Value = *cdata->Value;
rdata->Result = rtn;
return rtn;
}

/* Copyright HAL College of Technology & Design */
