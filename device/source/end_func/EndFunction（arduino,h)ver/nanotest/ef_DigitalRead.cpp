/* 
	ef_DigitalRead.cpp

	末端関数 DigitalRead

	Created 2017/10/24
	By Riku Hashimoto
*/

#include <arduino.h>
#include "EndFunc.h"

/* onceDRead */
SSHT onceDRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	if( cdata->Port.Mode != INPUT ){
		pinMode( cdata->Port.Pin1, INPUT );
	}
	rdata->Value = digitalRead( cdata->Port.Pin1 ); // 値取得
	rdata->Result = rtn;
	return rtn;
}

/* simpleDRead */
SSHT simpleDRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	const SINT VALUE = 0;
  const SINT TIME = 1;
	if( cdata->Port.Mode != INPUT ){
	pinMode( cdata->Port.Pin1, INPUT );
	}
	
	static SINT Time = millis( );
	
	if( millis( ) - Time >= cdata->Value[TIME] ){
		rdata->Value = digitalRead( cdata->Port.Pin1 ); // 値取得
		rdata->Result = rtn;
		return rtn; 
	}
}

/* Copyright HAL College of Technology & Design */

