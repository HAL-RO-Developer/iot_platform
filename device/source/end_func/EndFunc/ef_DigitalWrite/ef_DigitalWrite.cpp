/* 
   ef_DigitalWrite.cpp
   
   末端関数 DigitalWrite
   
   Created 2017/10/21
   By Riku Hashimoto
*/

#include <DeviceControl.h>
#include "EndFunc.h"



/* onceDWrite */
SSHT onceDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	if( cdata->port.mode != OUTPUT ){
		Digital::SetMode( cdata->port.pin1, OUTPUT );
	}
	
	Digital::Write( cdata->port.pin1, cdata->value[VALUE] );
	rdata->value = cdata->value[VALUE];
	rdata->result = rtn;
	return rtn;
}

/* simpleDWrite */
SSHT simpleDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
  const SINT VALUE = 0;
  const SINT TIME = 1;
  static SINT Flag = 0;
  static SINT Time;
  SSHT rtn = RESULT_OK;
  if( cdata->Port.Mode != OUTPUT ){
  Digital::SetMode( cdata->Port.Pin1, OUTPUT );
  }
  if(Flag == 0){
 Time = millis( );
  Flag = 1;
}
  if( millis( ) - Time <= cdata->Value[TIME] ){
  Digital::Write( cdata->Port.Pin1, cdata->Value[VALUE] );
  rdata->Value = cdata->Value[VALUE];
  rdata->Result = rtn;
  } else {
  Digital::Write( cdata->Port.Pin1, !(cdata->Value[VALUE]) );
  Flag = 0;
  rdata->Value = !(cdata->Value[VALUE]);
  rdata->Result = rtn;
  }
  return rtn;
}

/* blinkDWrite */
SSHT blinkDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	const SINT VALUE = 0;
  const SINT TIME = 1;
	SSHT rtn = RESULT_OK;
	if( cdata->port.mode != OUTPUT ){
		Digital::SetMode( cdata->port.pin1, OUTPUT );
	}
	
	static SINT Time = millis( );

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

/* Copyright HAL College of Technology & Design */

