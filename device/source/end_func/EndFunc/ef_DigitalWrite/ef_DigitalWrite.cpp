/* 
   ef_DigitalWrite.cpp
   
   末端関数 DigitalWrite
   
   Created 2017/09/27
   By Hirotaka Nagaoka
*/

#include <DeviceControl.h>
#include "EndFunc.h"

#define VALUE	( 0 )
#define TIME	( 1 )

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
	SSHT rtn = RESULT_OK;
	if( cdata->port.mode != OUTPUT ){
	Digital::SetMode( cdata->port.pin1, OUTPUT );
  }
	
  static SINT Time = millis( );

  if( millis( ) - Time <= cdata->value[TIME] ){
	Digital::Write( cdata->port.pin1, cdata->value[VALUE] );
	rdata->value = cdata->value[VALUE];
	rdata->result = rtn;
  } else {
	Digital::Write( cdata -> port.pin1, LOW );
	rdata->value = 0;
	rdata->result = rtn;
	}
	return rtn;
}

/* blinkDWrite */
SSHT blinkDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
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

