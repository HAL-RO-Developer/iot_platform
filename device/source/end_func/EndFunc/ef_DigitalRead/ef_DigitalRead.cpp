/* 
   ef_DigitalRead.cpp
   
   末端関数 DigitalRead
   
   Created 2017/11/22
     By Riku Hashimoto
*/

#include <DeviceControl.h>
#include "System.h"
#include "Function.h"



/* onceDRead */
SSHT onceDRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	if( cdata->Port.Mode != INPUT ){
		Digital::SetMode( cdata->Port.Pin1, INPUT );
	}
	
	rdata->Value = Digital::Read( cdata->Port.Pin1 ); // 値取得
	rdata->Result = rtn;
	return rtn;
}

/* simpleDRead */
SSHT simpleDRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	const SINT TIME = 1;
	if( cdata->Port.Mode != INPUT ){
	Digital::SetMode( cdata->Port.Pin1, INPUT );
	}
	
	static SINT Time = millis( );
	
	if( millis( ) - Time >= cdata->Value[TIME] ){
		rdata->Value = Digital::Read( cdata->Port.Pin1 ); // 値取得
		rdata->Result = rtn;
		return rtn; 
	}
}
SSHT blinkDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	const SINT TIME = 1;
	SSHT rtn = RESULT_OK;
	if( cdata->Port.Mode != OUTPUT ){
	Digital::SetMode( cdata->Port.Pin1, OUTPUT );
  }
	
  static int Time = millis();

  if( millis( ) - Time >= cdata->value[TIME] ){
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

