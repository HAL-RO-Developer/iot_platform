// blinkDWrite
// Created 2017/09/20
// By Hirotaka Nagaoka

#include <DeviceControl.h>
#include "EndFunc.h"

SSHT blinkDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata, SINT ms ){
	SSHT rtn = RESULT_OK;
	if( cdata->port.mode != OUTPUT ){
	Digital::SetMode( cdata->port.pin1, OUTPUT );
  }
	
  static int Time = millis();

  if( millis( ) - Time >= ms ){
  	Digital::Write( cdata->port.pin1, *cdata->value );
  	rdata->value = *cdata->value;
  	rdata->result = rtn;
  }
  if( millis( )-Time >= ms * 2 ){
  	Digital::Write( cdata->port.pin1, LOW );
  	rdata->value = LOW;
  	rdata->result = rtn;
  	Time = millis( );
  	}
  return rtn;
}
