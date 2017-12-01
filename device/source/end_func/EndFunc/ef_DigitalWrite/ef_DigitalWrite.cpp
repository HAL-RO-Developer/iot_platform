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
  const SINT VALUE = 0;
  const SINT TIME = 1;
	SSHT rtn = RESULT_OK;
	if( cdata->Port.Mode != OUTPUT ){
		Digital::SetMode( cdata->Port.Pin1, OUTPUT );
	}
	
	Digital::Write( cdata->Port.Pin1, cdata->Value[VALUE] );
	rdata->Value = cdata->Value[VALUE];
	rdata->Result = rtn;
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
	if( cdata->Port.Mode != OUTPUT ){
		Digital::SetMode( cdata->Port.Pin1, OUTPUT );
	}
	
	static SINT Time = millis( );

	if( millis( ) - Time >= cdata->Value[TIME] ){
		Digital::Write( cdata->Port.Pin1, cdata->Value[VALUE] );
		rdata->Value = cdata->Value[VALUE];
		rdata->Result = rtn;
	}
	
	if( millis( )-Time >= cdata->Value[TIME] * 2 ){
		Digital::Write( cdata->Port.Pin1, LOW );
		rdata->Value = LOW;
		rdata->Result = rtn;
		Time = millis( );
	}
	return rtn;
}

/* Copyright HAL College of Technology & Design */

