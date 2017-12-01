/* 
	ef_DigitalWrite.cpp

	末端関数 DigitalWrite

	Created 2017/09/27
	By Hirotaka Nagaoka
*/

#include <DeviceControl.h>
#include "System.h"
#include "Function.h"

/* onceDWrite */
SSHT onceDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
  const int VALUE = 0;
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
  const int VALUE = 0;
  const int TIME = 1;
  static int Flag = 0;
	SSHT rtn = RESULT_OK;
	if( cdata->Port.Mode != OUTPUT ){
	Digital::SetMode( cdata->Port.Pin1, OUTPUT );
  }
  if(Flag == 0){
  static SINT Time = millis( );
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
	const int TIME = 0;
	SSHT rtn = RESULT_OK;
#if PRINT_DEBUG
    Serial.println("----cdata----");
    Serial.println(cdata->Value[0]);
    Serial.println(cdata->Value[1]);
    Serial.println("--------------");
#endif    
	if( cdata->Port.Mode != OUTPUT ){
		Digital::SetMode( cdata->Port.Pin1, OUTPUT );
	}
	
	static SINT Time = millis( );

	if( millis( ) - Time >= cdata->Value[TIME] ){
		Digital::Write( cdata->Port.Pin1, HIGH );
		rdata->Value = HIGH;
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

