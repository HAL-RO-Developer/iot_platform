/*
    onceDWrite.ino
    Created 2017/09/20
    By Hirotaka Nagaoka
*/
#include <DeviceControl.h>
#include "Endfunc.h"

SSHT onceDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
  SSHT rtn = RESULT_OK;
  // モードチェック
  if( cdata->port[0] != OUTPUT ){
    Digital::SetMode( cdata->port[1], OUTPUT );
  }
  // 出力
  Digital::Write( cdata->port[1], cdata->value );
  rdata->value = cdata->value;
  rdata->result = rtn;
  return rtn;
}

