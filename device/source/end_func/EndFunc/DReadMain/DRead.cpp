#include <DeviceControl.h>
#include "EndFunc.h"
SSHT HLDRead( CONTEXT_DATA cdata, RESULT_DATA rdata );
SSHT LDRead( CONTEXT_DATA cdata, RESULT_DATA rdata );
SSHT HDRead( CONTEXT_DATA cdata, RESULT_DATA rdata );
SSHT DRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
 SSHT rtn = RESULT_OK;
 const SINT HL = 1;
 const SINT H  = 2;
 const SINT L  = 3;
  if( cdata->Port.Mode != INPUT ){
    Digital::SetMode( cdata->Port.Pin1, INPUT );
  } 
 if(cdata->Value[0] ==HL){
   rdata->Value = HLDRead(*cdata,*rdata );
 }
 if(cdata->Value[0] ==H){
    rdata->Value = HDRead(*cdata,*rdata );
 }
 if(cdata->Value[0] ==L){
   rdata->Value = LDRead(*cdata,*rdata );
 }
    return rtn;
}
SSHT HDRead( CONTEXT_DATA cdata, RESULT_DATA rdata ){
   static SSHT old  = LOW;
	rdata.Value = Digital::Read( cdata.Port.Pin1 ); // 値取得
  if(rdata.Value == HIGH && old == LOW){
    old = rdata.Value;
    return rdata.Value;
    }else{
      old = rdata.Value;
      rdata.Value = -1;
      return rdata.Value;
      }

}
SSHT LDRead( CONTEXT_DATA cdata, RESULT_DATA rdata ){
  static SSHT old  = HIGH;
  rdata.Value = Digital::Read( cdata.Port.Pin1 ); // 値取得
  if(rdata.Value == LOW && old == HIGH){
    old = rdata.Value;
    return rdata.Value;
    }else{
      old = rdata.Value;
      rdata.Value = -1;
      return rdata.Value;
      }
}
SSHT HLDRead( CONTEXT_DATA cdata, RESULT_DATA rdata ){
  static SSHT old = -1;
  rdata.Value = Digital::Read( cdata.Port.Pin1 ); // 値取得
  if(rdata.Value != old){
    old = rdata.Value;
    return rdata.Value;
    }else{
      old = rdata.Value;
      rdata.Value = -1;
      return rdata.Value;
      }
}
