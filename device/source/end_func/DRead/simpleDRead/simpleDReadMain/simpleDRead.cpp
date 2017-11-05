// simpleDRead
// Created 2017/10/20
// By Hirotaka Nagaoka

#include <DeviceControl.h>
#include "EndFunc.h"

SSHT simpleDRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata, SINT ms ){
	SSHT rtn = RESULT_OK;
	if( cdata->port.mode != INPUT ){
	Digital::SetMode( cdata->port.pin1, INPUT );
  }
  static SINT Time = millis( );
  if( millis( ) - Time >= ms ){
    rdata->value = Digital::Read( cdata->port.pin1 ); // 値取得
    rdata->result = rtn;
    return rtn; 
  }
}
