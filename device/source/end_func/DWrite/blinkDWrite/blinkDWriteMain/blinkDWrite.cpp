// blinkDWrite
// Created 2017/09/20
// By Hirotaka Nagaoka

#include <DeviceControl.h>
#include "EndFunc.h"

#define VALUE        ( 0 )
#define TIME         ( 1 )

SSHT blinkDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	if( cdata->port.mode != OUTPUT ){
	Digital::SetMode( cdata->port.pin1, OUTPUT );
  }
	
  static int Time = millis();

  if( millis( ) - Time >= cdata->value[TIME] ){
  	Digital::Write( cdata->port.pin1, cdata->value[VALUE] );
  	rdata->value = cdata->value[VALUE];
  	rdata->result = rtn;
  }
  if( millis( )-Time >= cdata->value[TIME] * 2 ){
  	Digital::Write( cdata->port.pin1, LOW );
  	rdata->value = LOW;
  	rdata->result = rtn;
  	Time = millis( );
  	}
  return rtn;
}
