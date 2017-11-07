/* 
   ef_DigitalRead.cpp
   
   末端関数 DigitalRead
   
   Created 2017/09/27
   By Hirotaka Nagaoka
*/

#include <DeviceControl.h>
#include "EndFunc.h"

#define TIME	( 1 )

/* onceDRead */
SSHT onceDRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	
	if( cdata->port.mode != INPUT ){
		Digital::SetMode( cdata->port.pin1, INPUT );
	}
	
	rdata->value = Digital::Read( cdata->port.pin1 ); // 値取得
	rdata->result = rtn;
	return rtn;
}

/* simpleDRead */
SSHT simpleDRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	
	if( cdata->port.mode != INPUT ){
	Digital::SetMode( cdata->port.pin1, INPUT );
	}
	
	static SINT Time = millis( );
	
	if( millis( ) - Time >= cdata->value[TIME] ){
		rdata->value = Digital::Read( cdata->port.pin1 ); // 値取得
		rdata->result = rtn;
		return rtn; 
	}
}

/* Copyright HAL College of Technology & Design */

