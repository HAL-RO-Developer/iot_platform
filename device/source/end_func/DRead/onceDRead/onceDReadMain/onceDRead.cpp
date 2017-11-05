// onceDRead
// Created 2017/10/20
// By Hirotaka Nagaoka

#include <DeviceControl.h>
#include "EndFunc.h"

SSHT onceDRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	if( cdata->port.mode != INPUT ){
	Digital::SetMode( cdata->port.pin1, INPUT );
  }
  rdata->value = Digital::Read( cdata->port.pin1 ); // 値取得
  rdata->result = rtn;
  return rtn;
}
