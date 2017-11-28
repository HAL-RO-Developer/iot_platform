// onceDRead
// Created 2017/10/20
// By Hirotaka Nagaoka

#include <DeviceControl.h>
#include "EndFunc.h"

/* onceDRead */
SSHT DRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
  static SSHT old = -1;
	SSHT rtn = RESULT_OK;
	if( cdata->Port.Mode != INPUT ){
		Digital::SetMode( cdata->Port.Pin1, INPUT );
	}	
	rdata->Value = Digital::Read( cdata->Port.Pin1 ); // 値取得
  if(rdata->Value != old){
    old = rdata->Value;
    rdata->Result = rtn;
    return rtn;
    }else{
      rdata->Value = -1;
      }
}
